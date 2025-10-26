{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }:
  let
    system = "x86_64-linux";
    pkgs = nixpkgs.legacyPackages.${system};

    windows = "mingwW64";
    crossPkgs = pkgs.pkgsCross.${windows};

    debug = "debug";
    release = "release";
  in 
  {
    devShells.${system}.default = pkgs.mkShell {
      packages = with pkgs; [
        clang-tools
        valgrind
        gef
        bear

        llvmPackages_21.libcxxClang
        llvmPackages_21.libcxx
        cmake
        raylib
      ];
      shellHook = ''
        echo "Entering Spoopy Jam 7 shell - Ghost Gallery!"
      '';
    };
    packages.${system} = {

      # nix build .#packages.x86_64-linux.debug
      ${debug} = pkgs.stdenv.mkDerivation (finalAttrs: {
        pname = "app-debug";
        version = "1.0.0";
        dontStrip = true;
        src = ./.;

        nativeBuildInputs = with pkgs; [
          llvmPackages_21.libcxxClang
          llvmPackages_21.libcxx
          cmake
          raylib
        ];

        buildInputs = with pkgs; [
          llvmPackages_21.libcxx
          raylib
        ];

        cmakeFlags = [
          "-DCMAKE_BUILD_TYPE=Debug"
        ];
      });

      # nix build .#packages.x86_64-linux.release
      ${release} = pkgs.stdenv.mkDerivation (finalAttrs: {
        pname = "app";
        version = "1.0.0";
        src = ./.;

        nativeBuildInputs = with pkgs; [
          llvmPackages_21.libcxxClang
          llvmPackages_21.libcxx
          cmake
          raylib
        ];

        buildInputs = with pkgs; [
          llvmPackages_21.libcxx
          raylib
        ];

        cmakeFlags = [
          "-DCMAKE_BUILD_TYPE=Release"
        ];
      });

      # nix build .#packages.x86_64-linux.mingwW64
      ${windows} = crossPkgs.stdenv.mkDerivation {
        pname = "app-mingwW64";
        version = "1.0.0";
        src = ./.;
        dontFixup = true;

        nativeBuildInputs = with pkgs; [
          cmake
        ];

        buildInputs = with crossPkgs; [
          raylib
        ];

        cmakeFlags = [
          "-DCMAKE_BUILD_TYPE=Release"
          "-DCMAKE_C_COMPILER=${crossPkgs.stdenv.cc.targetPrefix}gcc"
          "-DCMAKE_CXX_COMPILER=${crossPkgs.stdenv.cc.targetPrefix}g++"
        ];


        installPhase = ''
          mkdir -p $out/bin
          cp app.exe $out/bin/

          # Move DLL's with the exe
          cp "${crossPkgs.raylib}/bin/libraylib.dll" $out/bin/ || true
          cp "${crossPkgs.glfw}/bin/glfw3.dll" $out/bin/ || true
          cp "/nix/store/gikxh7vvkq3s91qga2lzrmbf4k8503rs-mcfgthread-x86_64-w64-mingw32-2.1.1/bin/libmcfgthread-2.dll" $out/bin/ || true
         '';
      };
    };
  };
}

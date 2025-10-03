{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }:
  let
    system = "x86_64-linux";
    pkgs = nixpkgs.legacyPackages.${system};

    debug = "debug";
  in 
  {
    devShells.${system}.default = pkgs.mkShell {
      packages = with pkgs; [
        # neovim
        clang-tools

        llvmPackages_21.libcxxClang
        llvmPackages_21.libcxx
        cmake
        raylib
      ];
      shellHook = ''
        echo "Entering Spoopy Jam 7 shell!"

        export CC=clang
        export CXX=clang++
        export CXXFLAGS="-stdlib=libc++ -I${pkgs.llvmPackages_21.libcxx}/share/libc++/v1"
        export LDFLAGS="-L${pkgs.llvmPackages_21.libcxx}/lib -lc++ -lc++abi"

        export PATH="$PATH:${pkgs.llvmPackages_21.clang-tools}/bin"

        echo "Packages:"
        echo "${pkgs.llvmPackages_21.libcxxClang}"
        echo "${pkgs.llvmPackages_21.clang-tools}"
        echo "${pkgs.raylib}"
      '';
    };
    packages.${system} = {
      # nix build .#packages.x86_64-linux.debug
      ${debug} = pkgs.stdenv.mkDerivation (finalAttrs: {
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
          "-DCMAKE_BUILD_TYPE=Debug"
        ];
      });
    };
  };
}

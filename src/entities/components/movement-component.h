#pragma once

class MovementComponent {
public:
  MovementComponent(int x_pos = 0, int y_pos = 0);

  void setNewPosition(int x_pos, int y_pos);
  void moveYPosition(int y_pos);
  void moveXPosition(int x_pos);

  int x_position{0};
  int y_position{0};
};

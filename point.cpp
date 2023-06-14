#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

class point {
  public:
    float x_coordinate, y_coordinate;
    point(float x = 0, float y = 0) {
      this->x_coordinate = x;
      this->y_coordinate = y;
    }
    point get() {
      point result;
      result.x_coordinate = this->x_coordinate;
      result.y_coordinate = this->y_coordinate;
      return result;
    }
    float dist(const point& other_point) {
      return (float)sqrt(pow((other_point.x_coordinate - this->x_coordinate), 2) + pow((other_point.y_coordinate - this->y_coordinate), 2));
    }
    point operator+(const point& operand) {
      point result;
      result.x_coordinate = this->x_coordinate + operand.x_coordinate;
      result.y_coordinate = this->y_coordinate + operand.y_coordinate;
      return result;
    }
    point operator-(const point& operand) {
      point result;
      result.x_coordinate = this->x_coordinate - operand.x_coordinate;
      result.y_coordinate = this->y_coordinate - operand.y_coordinate;
      return result;
    }
};

int main() {
  point p1(5, 3), p2(1, 4);
  point res = p1 - p2;
  // cout << res.x_coordinate << " " << res.y_coordinate;
  cout << fixed << setprecision(5) << p1.dist(p2);
  return 0;
}



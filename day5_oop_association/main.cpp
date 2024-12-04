#include <iostream>
//#include <graphics.h>
using namespace std;




class Point{
 int x;
 int y;
 public:
  Point()
  {
      x=y=0;
  }
    Point(int x1,int y1)
  {
      this->x=x1;
      this->y=y1;
  }
  void setx(int x){this->x=x;}
  void sety(int y){this->y=y;}
  int  getx(){ return x;
  }
   int  gety(){ return y;
  }


};


class Circle
{
    Point center;
    int rad;

public:
    Circle()
    {
        rad = 0;
    }

     Circle(Circle &c)
    {

    }
    Circle(int m, int n, int r) : center (m,n)
    {
        rad = r;
    }
    Circle (Point p, int r):center(p)
    {
        rad = r;
    }
    void Draw()
    {
       // circle(center.getx(),center.gety(),rad);
    }

    // Getters
    int getRadius() const { return rad; }
    Point getCenter() const { return center; }

    // Setters
    void setRadius(int r) { rad = r; }
    void setCenter(Point p) { center = p; }
    void setCenter(int x, int y) { center = Point(x, y); }

};


int main()
{
//     circle(200, 300, 50);
    cout << "Hello world!" << endl;
    Point p(2,3);
    cout<<p.getx();
    return 0;
}

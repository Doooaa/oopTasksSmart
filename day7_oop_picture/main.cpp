#include <iostream>
#include <graphics.h>

using namespace std;

class Point {
    int x, y;

public:
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
    Point(const Point& p) : x(p.x), y(p.y) {}

    void setx(int x) { this->x = x; }
    void sety(int y) { this->y = y; }
    int getx() { return x; }
    int gety() { return y; }
};

class Shape {

protected:
    int color;

public:
    Shape(){ color =0;}
    Shape(int color){this->color = color;}

    void setColor(int color) { this->color = color; }
    int getColor() { return color; }

    virtual void draw() = 0;
};


class Circle : public Shape {
    Point center;
    int rad;

public:
    Circle() : Shape(){
        rad =0;
    }
    Circle(int x, int y, int r, int color) : Shape(color), center(x, y){
        rad = r;
    }
    Circle(Point p, int r, int color) : Shape(color), center(p){
        rad = r;
    }

    void setCenter(Point p) { center = p; }
    void setRadius(int r) { rad = r; }

    Point getCenter() { return center; }
    int getRadius() { return rad; }

    void draw(){
        setcolor(color);
        circle(center.getx(), center.gety(), rad);
    }
};

class Line : public Shape {
    Point startp, endp;

public:
    Line() : Shape() {}
    Line(int x1, int y1, int x2, int y2, int color) : Shape(color), startp(x1, y1), endp(x2, y2) {}
    Line(Point p1, Point p2, int color) : Shape(color), startp(p1), endp(p2) {}

    void setStart(Point p) { startp = p; }
    void setEnd(Point p) { endp = p; }

    Point getStart() { return startp; }
    Point getEnd() { return endp; }

    void draw() {
        setcolor(color);
        line(startp.getx(), startp.gety(), endp.getx(), endp.gety());
    }
};

class Rect : public Shape {
    Point topLeft, bottomRight;

public:
    Rect() : Shape() {}
    Rect(int x1, int y1, int x2, int y2, int color) : Shape(color), topLeft(x1, y1), bottomRight(x2, y2) {}
    Rect(Point tl, Point br, int color) : Shape(color), topLeft(tl), bottomRight(br) {}

    void setTopLeft(Point p) { topLeft = p; }
    void setBottomRight(Point p) { bottomRight = p; }

    Point getTopLeft() { return topLeft; }
    Point getBottomRight() { return bottomRight; }

    void draw(){
        setcolor(color);
        rectangle(topLeft.getx(), topLeft.gety(), bottomRight.getx(), bottomRight.gety());
    }
};


class Picture {
    Shape** shapes;
    int shapeCount;

public:
     Picture()
    {
        shapeCount = 0;
        shapes = NULL;
    }
     Picture(Shape** s, int count)
    {
      shapes = s;
      shapeCount = count;
    }

   void draw() {
        for (int i = 0; i < shapeCount; ++i) {
            if (shapes[i]) {
                shapes[i]->draw();
            }
        }
    }

    ~Picture() {
        delete[] shapes;
    }
};

int main() {
    initgraph();

    Circle* c1 = new Circle(200, 200, 50, 4);
    Line* l1 = new Line(250, 250, 350, 350, 2);
    Rect* r1 = new Rect(400, 400, 500, 500, 14);

    //Shape s;
    Shape* shapes[] = { c1, l1, r1 };

    Picture picture(shapes, 3);

    picture.draw();


    delete c1;
    delete l1;
    delete r1;
    return 0;
}

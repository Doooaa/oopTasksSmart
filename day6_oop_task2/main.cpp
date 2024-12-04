/*#include <iostream>

using namespace std;
class shape{
 float d1,d2;

int getL(){return l;}
int getw(){return w;}
int getdi(){return di;}

setl(int l){this->l=l;}
setl(int w){this->w=w;}
};










class rectangle{
float l ,w,area;
int di;
rectangle(){
l=w=di=area=0;
}

rectangle(int l,int w,)
{

}
float area() {};


};
int main()
{
    //cout << "Hello world!" << endl;





    return 0;
}

*/



#include <iostream>
#include <graphics.h>

using namespace std;


class shape
{

   int color;
public :
      shape()
      {
         color=9;

      }
       shape(int co){ co=color;}
       void setcol(int  c) { color=c;}

       int  getcol(){return color;}

};



class Point :public shape {
    int x, y;

public:
    Point() {
        x = 0;
        y = 0;
    }

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Point(const Point& p) {
        this->x = p.x;
        this->y = p.y;
    }

    void setx(int x) {
        this->x = x;
    }

    void sety(int y) {
        this->y = y;
    }

    int getx() {
        return x;
    }

    int gety() {
        return y;
    }
};

class Circle :public shape {
    Point center;
    int rad;

public:
    Circle() {
        rad = 0;
    }

    Circle(int x, int y, int r) : center(x, y) {
        rad = r;
    }

    Circle(Point p, int r) : center(p) {
        rad = r;
    }

   /*  Circle(Point p, int r,int color) : center(p): public shape(color) {
        rad = r;

    }*/
    void setx(int x) {
        center.setx(x);
    }

    void sety(int y) {
        center.sety(y);
    }

    void setp(Point p) {
        center = p;
    }
    void setp(Point p,int r) {
        center = p;
        this->rad=r;
    }
    int getx() {
        return center.getx();
    }

    int gety() {
        return center.gety();
    }

    Point getp() {
        return center;
    }

    void draw() {
        circle(center.getx(), center.gety(), rad);
        }
};

class Line :public shape{
    Point startp, endp;

public:
    Line() {}

    Line(int x1, int y1, int x2, int y2,int c) : startp(x1, y1), endp(x2, y2) {}

    Line(Point p1, Point p2) : startp(p1), endp(p2) {}

    void setStart(Point p) {
        startp = p;
    }

    void setEnd(Point p) {
        endp = p;
    }

    Point getStart() {
        return startp;
    }

    Point getEnd() {
        return endp;
    }

    void draw() {
        line(startp.getx(),startp.gety(),endp.getx(),endp.gety());
    }
};

class Rect :public shape{
    Point topLeft, bottomRight;

public:
    Rect() {}

    Rect(int x1, int y1, int x2, int y2) : topLeft(x1, y1), bottomRight(x2, y2) {}

    Rect(Point tl, Point br) : topLeft(tl), bottomRight(br) {}

    void setTopLeft(Point p) {
        topLeft = p;
    }

    void setBottomRight(Point p) {
        bottomRight = p;
    }

    Point getTopLeft() {
        return topLeft;
    }

    Point getBottomRight() {
        return bottomRight;
    }

    void draw() {
        cout << "Drawing Rectangle with top-left (" << topLeft.getx() << ", " << topLeft.gety()
             << ") and bottom-right (" << bottomRight.getx() << ", " << bottomRight.gety() << ")" << endl;
    }
};

class Picture :public shape
{
    Circle *c;
    Line *l;
    Rect *r;
    int cs,ls,rs;
public:
    Picture()
    {
        cs = ls = rs = 0;
        c = NULL;
        l = NULL;
        r = NULL;
    }

    Picture(Circle *pc,Line *pl, Rect *pr, int cn,int ln,int rn)
    {
       c = pc;
       l = pl;
       r = pr;
       cs = cn;
       ls = ln;
       rs = rn;
    }
    void setCircles(Circle *pc, int cn) {
        c = pc;
        cs = cn;
    }

    void setLines(Line *pl, int ln) {
        l = pl;
        ls = ln;
    }

    void setRectangles(Rect *pr, int rn) {
        r = pr;
        rs = rn;
    }

     Circle* getCircles() {
        return c;
    }

    int getCircleCount() {
        return cs;
    }

    Line* getLines() {
        return l;
    }

    int getLineCount() {
        return ls;
    }

    Rect* getRectangles() {
        return r;
    }

    int getRectangleCount() {
        return rs;
    }

    void draw() {
        cout << "Drawing Picture with:" << endl;

        for (int i = 0; i < cs; ++i) {
            cout << "  Circle " << i + 1 << ": ";
            setcol(8);
            c[i].draw();
        }

        for (int i = 0; i < ls; ++i) {
            cout << "  Line " << i + 1 << ": ";
            l[i].draw();
        }

        for (int i = 0; i < rs; ++i) {
            cout << "  Rectangle " << i + 1 << ": ";
            r[i].draw();
        }
    }

    ~Picture() {
        delete[] c;
        delete[] l;
        delete[] r;
    }

};
int main() {
    initgraph();

     /* circle(200,122,100);
      line(300,150,300,300);*/
      Point  p1(300,400),p2(400,200),p3(221,303),p4(400,600);

      int n=4;
    //  Circle c(p2,70);
      //c.draw();

     Circle *c=new Circle[2];
     c[0].setp(p1,40);
     c[1].setp(p2,100);
     Picture p;
      c->setcol(7);
      setcolor(c->getcol());

      Line  *l=new Line[2];
      l[0].setStart(p3);
      l[0].setEnd(p4);
      l[1].setStart(p2);
      l[1].setEnd(p3);

       l->setcol(8);
      setcolor(l->getcol());

     p.setCircles(c,2);
    p.setLines(l,  2);


     p.draw();
    return 0;
}




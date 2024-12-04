#include <iostream>

using namespace std;

class shape
{
protected:
    float d1,d2;
public :
      shape()
      {
          d1=d2=0;

      }
     shape(float f){
      d1=d2=f;
     }

      shape(float f1 ,float f2){
      d1=f1;
      d2=f2;
     }
      void setd2(float f) { d2=f;}
     void setd1(float f) { d1=f;}


      float getd1() {return d1;}
      float getd2() {return d2;}
      float area(){
         return 0.0;
     }


};


class rectangle :protected shape{

  public:
  rectangle(float f): shape( f, f)
  {}
   rectangle(float l,float w):shape( l, w)
  {}
  float area()
  {
      return getd1() * getd2();
  }
};

class circle :protected shape{
    //float r;
    public:
    circle(){}
    circle(float d):shape(d){
    }
    float area()
    {
        return 3.14*d1*d1;
    }

};
class triangle :protected shape{

public :
    triangle(){}
    triangle(float b , float h): shape(b,h)
    {}
     float area(){
    return 0.5 * d1*d1;
    }
};



int main()
{
    circle c(40);
    triangle t(33,33.3);
    rectangle r(33,33);
    cout<<c.area()<<endl;
    cout<<t.area()<<endl;
    cout<<r.area()<<endl;
    return 0;
}

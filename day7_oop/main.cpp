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
     virtual float area()=0;
       void base_function(){
       cout<<"hi i can not access me from my children"<<endl;
      }

};


class rectangle :public shape{

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

class circle :public shape{
    //float r;
    public:
    circle(){}
    circle(float d):shape(d){
    }
    float area()
    {
        return 3.14*d1*d1;
    }
    void cicleonlyyy()
    {
        cout<<"hhhhhhhhhhhhiiii"<<endl;

    }
};
class triangle :public shape{

public :
    triangle(){}
    triangle(float b , float h): shape(b,h)
    {}
     float area(){
    return 0.5 * d1*d1;
    }

   // friend float sumareas(circle *c,rectangle *r, triangle *t);
};

 float sumareas(circle *c,rectangle *r, triangle *t){
    return c->area()+r->area()+t->area();

 }

int main()
{
    /*circle c(40);
    triangle t(33,33.3);
    rectangle r(33,33);
    cout<<c.area()<<endl;
    cout<<t.area()<<endl;
    cout<<r.area()<<endl;*/
     //1- cannot make instance of abstruct class.
        //shape s;
        shape *st;
        //2- poniter of base ponit to its childrens.
            circle c(40);
            triangle t(33,33.3);
            rectangle r(33,33);
           st= &c;
           cout<<"for circle  : "<<st->area()<<endl;
           st= &t;
            cout<<"for triangle : "<<st->area()<<endl;
           //  make them all public as pure function need public

            // t2--> area sum
            cout<<sumareas(&c,&r,&t)<<endl;

           cout<<".........................\n";

            shape *st2;
            st2->base_function();
            cout<<".........................\n";
           st2= &c;
            //st2->base_function();
            // 'class shape' has no member named 'cicleonlyyy'|
            // st2->cicleonlyyy();




    return 0;
}

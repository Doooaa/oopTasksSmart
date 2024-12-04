#include <iostream>

using namespace std;

//........................................class..............................
class Ccomplex
{
    int real ,imag;
    //get set real
    public:


      Ccomplex() {
       // cout << "Hi from default constructor!!" << endl;
        real = 0;
        imag = 0;
    }
       Ccomplex(int r)
     {
        cout << "Hi from default constructor!!" << endl;

        real=r;
        imag=0;
     }
     Ccomplex(int r ,int i)
     {
         cout<<"hi from overloaded constructor!!"<<endl;
        real=r,imag=i;
     }
     ~Ccomplex()
     {
        // cout<<"hi destructor!"<<endl;
     }
    int get_real();
    void set_real(int);

        //get set image
    int get_imag();
    void set_imag(int);

    void display();
    //   sum forms
    Ccomplex sum(Ccomplex ,Ccomplex,Ccomplex);
    Ccomplex sum(Ccomplex ,Ccomplex);
    Ccomplex sum(Ccomplex ,int);
    Ccomplex sum(int ,Ccomplex);


    //sub forms
    Ccomplex sub(Ccomplex ,Ccomplex,Ccomplex);
    Ccomplex sub(Ccomplex ,Ccomplex);
    Ccomplex sub(Ccomplex ,int);
    Ccomplex sub(int ,Ccomplex);

};
//****************implementations********************************

int   Ccomplex::get_imag() { return imag;}
int   Ccomplex::get_real() { return real;}
//set
void Ccomplex::set_imag(int n){ imag=n;}
void Ccomplex::set_real(int n){ real=n;}

//sum
Ccomplex Ccomplex::sum(Ccomplex c1, Ccomplex c2) {
    Ccomplex result;
    result.set_real(c1.get_real() + c2.get_real());
    result.set_imag(c1.get_imag() + c2.get_imag());
    return result;
}

Ccomplex Ccomplex::sum(Ccomplex c1, Ccomplex c2 ,Ccomplex c3) {
    Ccomplex result;
    result.set_real(c1.get_real() + c2.get_real()+c3.get_real());
    result.set_imag(c1.get_imag() + c2.get_imag()+c3.get_imag());
    return result;
}

Ccomplex Ccomplex::sum(Ccomplex c1,int n) {
    Ccomplex result;
    result.set_real(c1.get_real() + n);
    result.set_imag(c1.get_imag());
    return result;
}

Ccomplex Ccomplex::sum(int n,Ccomplex c1) {
    Ccomplex result;
    result.set_real(c1.get_real() + n);
    result.set_imag(c1.get_imag());
    return result;
}


Ccomplex Ccomplex::sub(Ccomplex c1, Ccomplex c2) {
    Ccomplex result;
    result.set_real(c1.get_real() - c2.get_real());
    result.set_imag(c1.get_imag() - c2.get_imag());
    return result;
}
Ccomplex Ccomplex::sub(Ccomplex c1, Ccomplex c2 ,Ccomplex c3) {
    Ccomplex result;
    result.set_real(c1.get_real() - c2.get_real()-c3.get_real());
    result.set_imag(c1.get_imag() -c2.get_imag()-c3.get_imag());
    return result;
}

Ccomplex Ccomplex::sub(Ccomplex c1,int n) {
    Ccomplex result;
    result.set_real(c1.get_real() - n);
    result.set_imag(c1.get_imag());
    return result;
}

Ccomplex Ccomplex::sub(int n,Ccomplex c1) {
    Ccomplex result;
    result.set_real(c1.get_real() -n);
    result.set_imag(c1.get_imag());
    return result;
}

void Ccomplex::display(){
     if(real>0)
    cout<<real<<"+" <<imag<<endl;
    else if (real<0)cout<<real<<"."<<imag<<endl;
    else cout<<"0." <<imag<<endl;
    }

class Stack{

int top , st[10];
public:
Stack()
{
  top=0;
}


//push
void push(int n)
{
  if(top==10)
    cout<<"stack is full"<<endl;
  else st[top++]=n;
}

 int pop() {
        if (top == 0) {
            cout << "Stack is empty" << endl;
            return -1; // Return an invalid value
        } else {
            return st[--top];
        }
    }

};


//ds
class dyStack{

int top ,*st ;
public:
 dyStack(int s) {

        st = new int[s];
        top = 0;
    }


//push
void push(int n)
{
  if(top==10)
    cout<<"stack is full"<<endl;
  else st[top++]=n;
}

 int pop() {
        if (top == 0) {
            cout << "Stack is empty" << endl;
            return -1; // Return an invalid value
        } else {
            return st[--top];
        }
    }
~dyStack()
{
    delete(st);
}
};


int main()
{

     cout<<"************ class complex **************************"<<endl;
    Ccomplex c1 ,c2 ,sumcom ,s1,s2,s3,s4,sub1,sub2,sub3;
    //c1
    c1.set_real(3);
    c1.set_imag(55);
    c1.display();
    //c2
    c2.set_real(2);
    c2.set_imag(3);
     sumcom = c1.sum(c1, c2);
    cout<<"sum complex :"; sumcom.display();
    cout<<"************ sum class complex **************************"<<endl;
    s1=s1.sum(c1 ,c2);
    s2=s2.sum(c1,10);
    s3=s3.sum(10,c1);
    cout<<"   s1 --> ";
    s1.display();
    cout<<"   s2-->";
    s2.display();
    cout<<"   s3--->  ";
     s3.display(); cout<<endl;   //4++4  0+0 0+-1
      cout<<"************ class complex sub **************************"<<endl;
    s1=s1.sub(c1 ,c2);
    s2=s2.sub(c1,10);
    s3=s3.sub(10,c1);
    cout<<"   s1 --> ";
    s1.display();
    cout<<"   s2-->";
    s2.display();
    cout<<"   s3--->  ";
     s3.display(); cout<<endl;

     cout<<"************ constructors complex sub **************************"<<endl;
     Ccomplex c11(1),c12(1,2),c13;
     c11.display();
       c12.display();
         c13.display();
          cout<<"************ stack **************************"<<endl;
          Stack s;
         s.push(2);
        s.push(5);
        cout<<s.pop()<<endl;

           cout<<"************ dynamic stack **************************"<<endl;
          dyStack ss(3);
         ss.push(2);
        ss.push(5);
        cout<<ss.pop();
}







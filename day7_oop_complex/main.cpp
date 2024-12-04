#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Complex{
 int real ,imag;
    //get set real
    public:


      Complex() {
       // cout << "Hi from default constructor!!" << endl;
        real = 0;
        imag = 0;
    }
       Complex(int r)
     {
        cout << "Hi from default constructor!!" << endl;

        real=r;
        imag=0;
     }
     Complex(int r ,int i)
     {
         cout<<"hi from overloaded constructor!!"<<endl;
        real=r,imag=i;
     }
     ~Complex()
     {
        // cout<<"hi destructor!"<<endl;
     }

    int get_real() { return real; }
    void set_real(int r) { real = r; }

    int get_imag() { return imag; }
    void set_imag(int i) { imag = i; }


    friend ostream&  operator <<(ostream&,Complex &);
    friend istream&  operator >>(istream&,Complex&);


};



     ostream&  operator <<(ostream& out,Complex& c){
       return   out<<c.real<<"+i"<<c.imag;
     }
     istream&  operator >>(istream&in ,Complex& c){
            in>>c.real>>c.imag;
            return in;
     }



int main()
{
    printf("Hello world!\n");

    Complex  c(3,44),c2;
     cout<<c<<endl;
    cout << "Enter real and imaginary parts: ";


     cin>>c2;

      cout<<c2;
    return 0;
}



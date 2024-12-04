#include <iostream>

using namespace std;
//........................................struct
struct Complex
{

    int real ,imag;
    //get set real
    int get_real();
    void set_real(int);

        //get set image
    int get_imag();
    void set_imag(int);

    void display();
};
//get implementation
int   Complex::get_imag() { return imag;}
int   Complex::get_real() { return real;}
//set
void Complex::set_imag(int n){ imag=n;}
void Complex::set_real(int n){ real=n;}

void Complex::display(){ cout<<real<<"+" <<imag<<endl;}

//........................................class..............................
class Ccomplex
{
    int real ,imag;
    //get set real
    public:
    int get_real();
    void set_real(int);

        //get set image
    int get_imag();
    void set_imag(int);

    void display();
    Ccomplex sum(Ccomplex ,Ccomplex);
    Ccomplex sub(Ccomplex ,Ccomplex);

};
//get implementation classssssssssss
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

Ccomplex Ccomplex::sub(Ccomplex c1, Ccomplex c2) {
    Ccomplex result;
    result.set_real(c1.get_real() - c2.get_real());
    result.set_imag(c1.get_imag() - c2.get_imag());
    return result;
}


void Ccomplex::display(){ cout<<real<<"+" <<imag<<"i"<<endl;}



int main()
{
    cout<<"************ STRUCT **************************"<<endl;
    Complex structComplex;
    structComplex.set_real(3);
    structComplex.set_imag(55);
    structComplex.display();
     cout<<"************ class complex **************************"<<endl;
    Ccomplex c1 ,c2 ,sumcom;
    //c1
    c1.set_real(3);
    c1.set_imag(55);
    c1.display();
    //c2
    c2.set_real(2);
    c2.set_imag(3);
     sumcom = c1.sum(c1, c2);
    cout<<"sum complex :"; sumcom.display();

    cout<<"************ class complex **************************"<<endl;


}

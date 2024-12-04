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
        cout<<"hi destructor!"<<endl;
     }
    int get_real();
    void set_real(int);

        //get set image
    int get_imag();
    void set_imag(int);
    void display();
    Complex operator+(const Complex& c);
    Complex operator-(const Complex& c);
    Complex operator/(const Complex& c);
    friend Complex operator-(float n, const Complex& c);
    Complex operator*(const Complex& c);


    Complex operator--();//pre
      Complex operator++();//pre
    Complex operator--(int);//post
    Complex operator++(int);//post


    Complex operator=(const Complex& c);
    Complex operator+=(const Complex& c);
    Complex operator-=(const Complex& c);
    Complex operator-=(int n);

    bool operator==(const Complex& c) const;
    bool operator!=(const Complex& c) const;
    bool operator>(const Complex& c) const;
    bool operator<(const Complex& c) const;
    bool operator>=(const Complex& c) const;
    bool operator<=(const Complex& c) const;


    //casting
    operator float()
    {
        return (float)real;
    }
    operator int()
    {
        return real;
    }

};



//****************implementations********************************

int   Complex::get_imag() { return imag;}
int   Complex::get_real() { return real;}
//set
void Complex::set_imag(int n){ imag=n;}
void Complex::set_real(int n){ real=n;}

Complex Complex::operator+(const Complex& c) {
    Complex ret;
    ret.real = real + c.real;
    ret.imag = imag + c.imag;
    return ret;
}

Complex Complex::operator-(const Complex &c){
    Complex ret;
    ret.real=real-c.real;
    ret.imag=imag-c.imag;
    return ret;
}

 Complex operator-(float n ,const Complex &c)
{
  Complex ret;
    ret.real=c.real-n;
    ret.imag=c.imag;
    return ret;
}

Complex Complex::operator*(const Complex& c) {
    Complex ret;
    ret.real = real * c.real;
    ret.imag = imag * c.imag;
    return ret;
}
Complex Complex::operator/(const Complex& c) {
    Complex ret;
    ret.real = real / c.real;
    ret.imag = imag / c.imag;
    return ret;
}

//post &pre increment &decrement
Complex Complex::operator--() {
    real = real - 1;  // Or just: real = real - 1;
    return *this;  // Return the current object (modified)
}

Complex Complex::operator--(int ) {
     Complex r=*this;
       real=real-1;
       return r;
}
Complex Complex::operator++(){
       real=real+1;
       return *this;
}

Complex Complex::operator++(int){
       Complex r=*this;
       real=real+1;

       return r;
}

//assiagn...............................................

Complex Complex::operator=(const Complex& c) {

    real = c.real;
    imag = c.imag;
    return *this;
}

Complex Complex::operator+=(const Complex& c) {
    real += c.real;
    imag += c.imag;
    return *this;
}

Complex Complex::operator-=(const Complex& c) {
    real -= c.real;
    imag -= c.imag;
    return *this;
}

Complex Complex::operator-=(int n) {
    real -= n;
    return *this;
}

//comparsion...............................................
 bool Complex::operator==(const Complex& c) const{

     return (real==c.real && imag==c.imag);
 }

  bool Complex::operator!=(const Complex& c) const{

     return (real!=c.real || imag!=c.imag);
 }


 bool Complex::operator<(const Complex &c)const {
      return (real<c.real&&imag<c.imag);
 }

 bool Complex::operator>(const Complex &c)const {
      return (real>c.real&&imag>c.imag);
 }
 bool Complex::operator<=(const Complex &c)const {
      return (real==c.real && imag==c.imag)||(real<c.real&&imag<c.imag);
 }
 bool Complex::operator>=(const Complex &c)const {
      return (real==c.real && imag==c.imag)||(real>c.real&&imag>c.imag);
 }

void Complex::display() {
    if (real == 0 && imag == 0) {
        cout << "0"; // Case 1: 0 + 0i
    } else if (real == 0) {
        cout << imag << "i"; // Case 2: 0 + imag*i (or just imag*i)
    } else if (imag == 0) {
        cout << real; // Case 3: real + 0i (or just real)
    } else if (imag > 0) {
        cout << real << " + " << imag << "i"; // Case 4: real + positive imag*i
    } else { // imag < 0
        cout << real << " - " << -imag << "i"; // Case 5: real + negative imag*i
    }

    cout << endl;
}



int main()
{
    printf("Hello world!\n");
    Complex c1(2,2),c2(3,2),r,c3(1,1),c4(1,1),c5(1,1);
    r=c1+c2;
    cout<<"add  ==>real"<<r.get_real()<<" imag:"<<r.get_imag()<<endl;
    r.display();
    r=c1*c2;
    r.display();
    r=c1/c2;
    r.display();
    //............................... post pre increament
     ++c3;
     c3.display();
     c3++;
     c3.display();
     //...............................compare
    if(c5==c4)
    {
        cout<<"compare c5 ,c 4 and they are equal"<<endl;
    }
    if(c3<=c1)
    {
        cout<<"c3<=c1"<<endl;
    }
    int x=(int)c5;
    cout<<x<<endl;
    float y=(float)c5;
    cout<<"float y-->"<<y<<endl;

    return 0;
}


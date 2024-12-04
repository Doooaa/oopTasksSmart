#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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
    int get_real();
    void set_real(int);

        //get set image
    int get_imag();
    void set_imag(int);




};




int main()
{
    printf("Hello world!\n");
    return 0;
}

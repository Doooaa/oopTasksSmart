#include <iostream>

using namespace std;
/*class Stack{

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
  void display() {
        if (top == 0) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack elements are: ";
            for (int i = 0; i < top; i++) {
                cout << st[i] << " ";
            }
            cout << endl;
        }
    }

 int& operator[](int index) {
        if (index >= 0 && index < 10) {
            return st[index];
        } else {
            cout << "Index out of bounds!" << endl;
            static int outOfBounds = -1;
            return outOfBounds;
        }
    }
   // s[0]=sss     this
     int& operator=(int n) {

             *st=n;

    }
};
*/
template <class T>
class dyStack{

int top  ,S=10 ;
static int c;
T *st;
public:

 dyStack(int s=10) {

        st = new T[s];
        top = 0;
        S=s;
        c++;
    }


//push

void push(T n)
{
  if(top==S)
    cout<<"stack is full"<<endl;
  else st[top++]=n;
}

 T pop() {
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

 void display() {
        if (top == 0) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack elements are: ";
            for (int i = 0; i < top; i++) {
                cout << st[i] << " ";
            }
            cout << endl;
        }
    }

 T& operator[](int index) {
        if (index >= 0 && index < S) {
            return st[index];
        } else {
            cout << "Index out of bounds!" << endl;
            static int outOfBounds = -1;
            return outOfBounds;
        }
    }

  // Overloaded Assignment Operator (deep copy)
    dyStack& operator=(const dyStack& other) {
        if (this != &other) { // Avoid self-assignment
            // Release the existing memory
            delete[] st;

            // Allocate new memory and copy elements
            S = other.S;
            top = other.top;
            st = new T[S];
            for (int i = 0; i < top; i++) {
                st[i] = other.st[i];
            }
        }
        return *this;
    }
};

template <class T>
 int dyStack<T>::c=0;
int main()
{

 dyStack<int> s,s2;
    s.push(3);
     s.push(22);
      s.push(10);
       s.push(24);
         s.display();
       cout<< s[2]<<endl;
       s[2]=20;

       cout<< s[2];
    return 0;
}

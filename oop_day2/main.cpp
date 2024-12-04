#include <iostream>

using namespace std;
//pass by referrence:

swap_ref(int& x ,int& y)
{
    int temp=x;

     x=y;
     y=temp;
}
//pass by address
swap_ad(int* x ,int* y)
{
    int *temp=x;
     x=y;
     y=temp;
}


class Stack{

int top , st[10],size=10;
static int counter;
public:
Stack()
{
  top=0;
  counter++;
}

 Stack(const Stack &x) {
        this->top = x.top;
        for (int i = 0; i < this->top; i++) {
            this->st[i] = x.st[i];
        }
        counter++; // Increment counter for the copied object
    }




~Stack()
{

  counter--;
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

  //ref +friend functin
  friend void printStackContent(Stack &x);


};

void printStackContent(Stack &x)
{
    int size=x.top;
   for(int i=0;i<size;i++)
   {
       cout<<x.st[i]<<" -->"<<i+1<<endl;
   }
}

/*Stack::Stack(Stack x){
    this.top=x.top;
    this.counter=x.counter;
    this.st=new int [this.size];
    for(int i=0;i<this.top;i++)
   {
       this.st[i]=x.st[i];
   }
   counter++;
  // Stack
}*/

int Stack::counter = 0;

int main()
{
    cout << "Hello world!" << endl;

    int x=8,y=9 ;
    swap_ref(x,y);
    cout<<x<<" : "<<y<<endl;
    swap_ref(x,y);
    cout<<x<<" : "<<y<<endl;

    Stack  st ,news;
    st.push(3);
      st.push(55);
        st.push(70);
       printStackContent(st);x
     //Stack st(news);

       Stack stt(news);
    return 0;
}





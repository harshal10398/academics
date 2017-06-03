/*
 * Question 52:
 * Write a program to demonstrate concept of
 * expanding member function outside the class by
 * using ::
 */
#include "iostream"
using namespace std;
class foo{
public:
    static int i;
    foo()
    {i++;}
    
    static int disp(){return i;}
};
int foo::i=0;
int main()
{
    foo f[10];
    cout<<"foo::disp() = "<<foo::disp()<<endl;
    cout<<"foo::i= "<<foo::i<<endl;
}

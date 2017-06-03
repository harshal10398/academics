/*
 * Question 59
 * Write a program to illustrate concept of array
 * of objects
 */

#include "iostream"
using namespace std;
class foo{
    static int i;
    int norm;
public:
    foo()
    {
        i++;
        norm=rand()%1000;
    }
    int retValue()
    {
        return norm;
    }
    void dump()
    {
        cout<<"norm: "<<norm<<endl;
    }
};
int foo::i=0;
#define size 5
int main()
{
    foo array[size];
    cout<<"Size of each element: "<<sizeof(foo)<<endl;
    for(int i=0;i<size;i++)
        cout<<"addr: "<<&array[i]<<"\tvalue: "<<array[i].retValue()<<endl;
}

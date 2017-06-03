/*
 * Question 5:
 * Explain functin overloading with an example.
 */
#include "iostream"
using namespace std;
double add(double x,double y)
{
    return x+y;
}
int add(int x,int y)
{
    return x+y;
}
int main()
{
    cout<<"5+6="<<add(5,6)<<endl;
    cout<<"4.33+6.76="<<add(4.33,6.76)<<endl;
}

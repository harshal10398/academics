/*
 * Question 55:
 * Write a program to demonstrate concept of making
 * outside functions inline
 */
#include "iostream"
#include "cstdlib"
using namespace std;
class foo{
public:
    int random(int);
};
inline int foo::random(int x)
{
    srand(time(0));
    return rand()%x;
}
int main()
{
    foo f;
    cout<<f.random(100)<<endl;
}

/*
 * Question 54
 * Write a program to demonstrate 
 * concept of private member function.
 */
#include "iostream"
using namespace std;
class priv{
private:
    double factStore(double n,int p)
    {
        if(p==1)
            return n;
        return n * factStore(n-1,p-1);
    }
public:
    int factorial(int n)
    {   
        return factStore(n,(int)n);
    }
    int npr(int n,int r)
    {
        return factStore(n,r);
    }
    double factorial(double n)
    {
        return factStore(n,(int)n);
    }
    double npr(double n,int r)
    {
        return factStore(n,r);
    }
};
int main()
{
    priv p;
    cout<<p.factorial(5)<<endl;
    cout<<p.factorial(4.4)<<endl;
    cout<<p.npr(6,3)<<endl;
    cout<<p.npr(7.9,2)<<endl;
}

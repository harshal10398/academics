#include "iostream"
#include "cmath"
using namespace std;
#define cons 0.000006

inline double f(double x)
{
    return 2.0*sin(x)-x*x/10.0;
}
inline double f1(double x,double h=cons)
{
    return (f(x+h)-f(x))/h;
}
inline double f2(double x,double h=cons)
{
    return (f1(x+h,h)-f1(x,h))/h;
}
double nextX(double x0,double h=cons)
{
    return (x0-f1(x0,h)/f2(x0,h));
}
int main()
{
    double x0,y;
    double eps=0.0001;
    cout<<"Enter initial value for x0: ";
    cin>>x0;
    for(int i=0,double y=nextX(x0);1 && i<10;i++,y=nextX(x0))
    {
        cout<<i<<" "<<x0<<" "<<f(x0)<<" "<<f1(x0)<<" "<<f2(x0)<<"\t"<<(y-x0)/eps<<endl;
        x0=y;
    }
    cout<<y<<endl;
    return 0;
}

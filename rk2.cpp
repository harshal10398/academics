#include "iostream"
using namespace std;
float f(float x,float y)
{
    return 3*x+y;
}
int main()
{
    float h,x,x0,y0,y;
    cout<<"Enter h: ";cin>>h;
    cout<<"Enter x: ";cin>>x;
    cout<<"Enter x0 and y0: ";cin>>x0>>y0;
    float k1,k2,k;
    for(float xn=x0,yn=y0;xn!=x;xn=xn+h,yn=y)
    {
        k1=h*f(xn,yn);
        k2=h*f(xn+h,yn+k1);
        k=(k1+k2)/2.0;
        y=yn+k;
        cout<<"k1="<<k1<<endl
            <<"k2="<<k2<<endl
            <<"k="<<k<<endl
            <<"y("<<xn+h<<")="<<y<<endl<<endl;
    }
    cout<<"y("<<x<<")="<<y<<endl;
    
}

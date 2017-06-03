/*
 * Question 72:
 * Write a program to illustrate the concept of operator overloading[unary]
 * 
 * Question 73:
 *  || [unary using friend]
 * 
 * Question 74:
 *  || [binary]
 * 
 * Question 75:
 *  || [binary using friend]
 * 
 */
#include "iostream"
#include "cmath"
using namespace std;
//class complex;
class polar;
class complex{
    float r,c;
public:
    complex(float x,float y)
    {
        r=x,c=y;
    }
    void operator ++()
    {
        r++,c++;
    }
    complex operator +(complex a)
    {
        return complex(r+a.r,c+a.c);
    }
    void disp()
    {
        cout<<r<<" + i("<<c<<")"<<endl;
    }
    complex(float dist)
    {
        r=c=dist/sqrt(2.0);
    }
    operator float()
    {
        return sqrt(r*r+c*c);
    }
    //friend operator complex(polar);
    friend class polar;
    //To negative complex number
    friend void operator !(complex&);
    //To find distance b/w two complex numbers
    friend float operator %(complex&,complex&);
};

void operator !(complex &a)
{
    a.r=-a.r;
    a.c=-a.c;
}
float operator %(complex& a,complex& b)
{
    float ans=pow(a.r-b.r,2)+pow(a.c-b.c,2);
    return sqrt(ans);
}
class polar{
    float dist,radian;
public:
    polar(float x,float y)
    {
        dist=x;radian=y;
    }
    void disp()
    {
        cout<<dist<<","<<radian<<endl;
    }
    polar(complex& c)
    {
        dist=c;
        radian=acos(c.r/dist);
    }
    
};

int main()
{
    complex x(10,20),y(30,40);
    
    cout<<"Initially:\n";
    cout<<"x: ";x.disp();
    cout<<"y: ";y.disp();
    //Unary operator overload
    ++x;
    cout<<"++x: ";x.disp();
    
    //binary operator overload
    cout<<"x+y: ";(x+y).disp();
    
    //unary operator overload (friend)
    !x;
    cout<<"!x: ";x.disp();
    
    //binary operator overload (friend)
    cout<<"x%y: "<<x%y<<endl;
    
    //class to basic (object to float)
    float modX=x;
    cout<<"modX: "<<modX<<endl;
    
    //basic to class (float to object)
    complex z=100.0;
    cout<<"z.disp: ";z.disp();
    
    //class to class (rectangular to polar form)
    polar r=x;
    cout<<"r.disp: ";r.disp();
}

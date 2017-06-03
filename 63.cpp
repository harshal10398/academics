/*
 * Question 63:
 * Write a program to swap private data of two 
 * classes using friend function
 * 
 * Question 64:
 * Write a program to illustrate concept of
 * returning objects
 * 
 * Question 65:
 * Write a program to illustrate concept of
 * parameterized constructor
 */
#include "iostream"
#include "cmath"
using namespace std;
class circle;
class rectangle{
private:
    float a,b;
public:
    rectangle(float c,float d)
    {
        a=c;b=d;
    }
    void disp()
    {
        cout<<"Sides: "<<a<<"\t"<<b<<endl;
        cout<<"Area of rectangle: "<<a*b<<endl;
    }
    friend circle sameAreaCircle(rectangle&);
};
class circle{
private:
    float r;
public:
    circle(float rad)
    {
        r=rad;
    }
    void disp()
    {
        cout<<"Radius: "<<r<<endl;
        cout<<"Area of circle: "<<M_PI*r*r<<endl;
    }
    friend rectangle sameAreaSquare(circle&);
};
circle sameAreaCircle(rectangle &rect)
{
    return circle(sqrt(rect.a*rect.b/M_PI));
}
rectangle sameAreaSquare(circle &cir)
{
    float area=M_PI*cir.r*cir.r;
    return rectangle(sqrt(area),sqrt(area));
}
int main()
{
    circle c(10);
    rectangle r(30,20);
    c.disp();
    r.disp();
    cout<<"Creating a square of same area as circle\n";
    rectangle cRect=sameAreaSquare(c);
    cRect.disp();
    cout<<"Creating a circle of same area as rectangle\n";
    circle rCir=sameAreaCircle(r);
    rCir.disp();
}

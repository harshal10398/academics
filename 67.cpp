/*
 * Question 67:
 * Write a program to illustrate the concept of 
 * constructor in derived class
 */
#include "iostream"
using namespace std;
class base{
private: 
    int privIntBase;
protected:
    int protIntBase;
public:
    int publIntBase;
};
class derived:public base{
private:
    int privIntDeri;
protected:
    int protIntDeri;
public:
    int publIntDeri;
    derived()
    {
        cout<<"Enter value of protIntDeri: ";
        cin>>protIntDeri;
        cout<<"Enter value of privIntDeri: ";
        cin>>privIntDeri;
        cout<<"Enter value of protIntBase: ";
        cin>>protIntBase;
        cout<<"Cannot access privIntBase\n";
    }
    void display()
    {
        cout<<"privIntDeri: "<<privIntDeri<<endl;
        cout<<"protIntDeri: "<<protIntDeri<<endl;
        cout<<"Cannot access privIntBase\n";
        cout<<"protIntBase: "<<protIntBase<<endl;
    }
};
int main()
{
    derived d;
    d.publIntDeri=0; 
    d.publIntBase=1;
    //d.getData();
    cout<<endl<<endl;
    d.display();
    cout<<"Accessing from main\n";
    cout<<"publIntDeri: "<<d.publIntDeri<<endl;
    cout<<"publIntBase: "<<d.publIntBase<<endl;
}

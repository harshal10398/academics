#include "iostream"
using namespace std;
class base {
//protected:
    int baseInt;
public:
    int publInt;
    base()
    {
        cout<<"Called base class default constructor!\n";
    }
    base(int baseInt)
    {
        cout<<"Called base class parameterized constructor\n";
        this->baseInt=baseInt;
        publInt=baseInt;
    }
    void baseFun()
    {
        cout<<"Just a base class function\n";
    }
};

class derived1:virtual public base{
    int d1int;
public:
    derived1()
    {
        cout<<"Calling derived1 default constructor.\n";
    }
    derived1(int baseInt,int d1int):base(baseInt)
    {
        cout<<"Calling derived1 parameterized constructor.\n";
        this->d1int=d1int;
    }
};
class derived2:virtual public base{
    int d2int;
public:
    derived2()
    {
        cout<<"Calling derived2 default constructor.\n";
    }
    derived2(int baseInt,int d2int):base(baseInt)
    {
        cout<<"Calling derived2 parameterized constructor.\n";
        this->d2int=d2int;
    }
};
class derived3:public derived1,public derived2{
    int d3int;
public:
    derived3()
    {
        cout<<"Calling derived3 default constructor.\n";
    }
    derived3(int d1int,int d2int,int d3int):derived1(5,d1int),derived2(15,d2int)
    {
        cout<<"Calling derived3 parameterized constructor.\n";
        this->d3int=d3int;
    }
};

class virTest{
    int v;
public:
    virTest()
    {
        cout<<"virTest default constructor called!\n";
    }
    virTest(int v)
    {
        cout<<"virTest parameterized constructor called!\n";
        this->v=v;
    }
    virtual void show()=0;
};
class vi2:private virTest{
    int v2;
    
public:
    vi2()
    {
        cout<<"Calling default constructor of vi2\n";
    }
    vi2(int x,int y):virTest(y)
    {
        cout<<"Calling parameterized constructor of vi2\n";
        v2=x;
    }
    void show()
    {
        cout<<"show defined in virtest bcoz shizzz!\n";
    }
    
};

int main()
{
    cout<<"Creating objects without arguments\n";
    cout<<"creating base\n";
    base b1;
    
    cout<<"Creating derived1\n";
    derived1 d11;
    
    cout<<"Creating parameterized objects now\n";
    cout<<"creating base(5)\n";
    base b2(5);
    cout<<"Creating derived1(15,12)\n";
    derived1 d12(15,12);
    
    cout<<"Created hybrid inheritance over derived3\n";
    cout<<"Creating object of derived3 w/o args\n";
    derived3 d31;
    
    cout<<"Creating object of derived3 with args\n";
    derived3 d32(10,20,30);

    
    cout<<"==============================\n";
    base *bptr;
    bptr=&d32;
    cout<<bptr->publInt<<endl;
    cout<<"******************************\n";
    vi2 v1;
    vi2 v2(4,7);
    
    return 0;
    
}

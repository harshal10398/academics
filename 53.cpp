/*
 * Question 53:
 * Write a program to demonstrate the concept 
 * of nesting of member functions.
 */
#include "iostream"
using namespace std;
class nest{
public:
    
    void first()
    {
        cout<<"Inside first function, calling second now.\n";
        second();
    }
    void second()
    {
        cout<<"Inside second function, calling third now.\n";
        third();
    }
    void third()
    {
        cout<<"Inside third function, calling first now (to create infinity).\n";
        first();
    }
};
int main()
{
    nest n;
    n.first();
}

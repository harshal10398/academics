/*
 * Question 56
 * Write a program to demonstrate the concept of array with a class
 */
#include "iostream"
#include "cstdlib"
#define size 10
using namespace std;
class arrayDemo{
private:
    int array[size];
public:
    arrayDemo()
    {
        for(int i=0;i<size;i++)
            array[i]=0;
    }
    void fillArray()
    {
        srand(time(0));
        for(int i=0;i<size;i++)
            array[i]=rand()%(size*2);
    }
    void display()
    {
        for(int i=0;i<size;i++)
            cout<<"addr: "<<&array[i]<<"\tvalue: "<<array[i]<<endl;
    }
};
int main()
{
    arrayDemo one;
    one.fillArray();
    one.display();
}

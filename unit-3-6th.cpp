/*
 * Question 6:
 * Define class matrix with integer array of 3x3
 * as a data member.
 * Define a friend function hich adds two matrix objects and
 * returns resultant matrix object.
 */
#include "iostream"
using namespace std;
class matrix{
    int array[3][3];
public:
    void fillMatrix()
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                cin>>array[i][j];
    }
    void print()
    {
        for(int i=0;i<3;i++,cout<<endl)
            for(int j=0; j<3; j++)
                cout<< array[i][j]<<" ";
    }
    friend void add(matrix m1,matrix m2);
};
void add(matrix m1,matrix m2)
{
    for(int i=0;i<3;i++,cout<<endl)
        for(int j=0;j<3;j++)
            cout<< m1.array[i][j] + m2.array[i][j]<<" ";
}

int main()
{
    matrix x,y;
    cout<<"Enter x matrix:\n";
    x.fillMatrix();
    cout<<"Enter y matrix:\n";
    y.fillMatrix();
    
    cout<<"x matrix:\n";
    x.print();
    cout<<"y matrix:\n";
    y.print();
    
    cout<<"x+y:\n";
    add(x,y);
    
    
}

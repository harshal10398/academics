/*
 * Question 68:
 * Write a program to illustrate concept of copy constructor.
 * 
 * Question 69:
 * Write a program to illustrate concept of Dynamic constructor.
 * 
 * Question 70:
 * Write a program to illustrate concept of destructor
 * 
 * Question 71:
 * Write a program to illustrate concept of constructing
 * two dimensional array using constructor
 * 
 */
#include "iostream"
#include "unistd.h"
using namespace std;
class array{
    int **ddPointer;
    int row,column;
public:
    array()
    {
        row=1;
        column=1;
        ddPointer=new int*[1];
        *ddPointer=new int[1];
        cout<<"1x1 memory allocated: "<<ddPointer<<endl;
        ddPointer[0][0]=0;
    }
    //Dynamic constructor.
    array(int r,int c)
    {
        row=r,column=c;
        ddPointer=new int*[row];
        for(int i=0;i<row;i++)
            ddPointer[i]=new int[column];
        for(int i=0;i<row;i++)
            for(int j=0;j<column;j++)
                ddPointer[i][j]=0;
        cout<<row<<"x"<<column<<" memory allocated: "<<ddPointer<<endl;
    }
    //Copy constructor
    array(array &toBeCopied)
    {
        row=toBeCopied.row;
        column=toBeCopied.column;
        ddPointer=new int*[row];
        for(int i=0;i<row;i++)
            ddPointer[i]=new int[column];
        for(int i=0;i<row;i++)
            for(int j=0;j<column;j++)
                ddPointer[i][j]=toBeCopied.ddPointer[i][j];
        
        //ddPointer=toBeCopied.ddPointer;
        cout<<row<<"x"<<column<<" memory copied: "<<ddPointer<<endl;
        
    }
    //Destructor
    ~array()
    {
        cout<<"starting to delete "<<row<<"x"<<column<<":\n";
        for(int i=0;i<row;i++)
            delete[] ddPointer[i];
        delete[] ddPointer;
        cout<<"deleted "<<ddPointer<<endl;
        //delete ddPointer;
    }
    void display()
    {
        for(int i=0;i<row;i++,cout<<endl)
            for(int j=0;j<column;j++)
                cout<<ddPointer[i][j]<<" ";
    }
};
int main()
{
    cout<<"Creating objects now!\n";
    array a;
    array b(3,2);
    array c(b);
    cout<<"Displaying objects now!\n";
    cout<<"a\n";
    a.display();
    cout<<"b\n";
    b.display();
    cout<<"c\n";
    c.display();
    cout<<"Objects will destroy now!\n";
    
}

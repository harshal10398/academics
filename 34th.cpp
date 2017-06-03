/*
 * Question 34:
 * Write a program to read a matrix of size m*n from user and print it
 */

#include "iostream"
#include "cstdlib"
using namespace std;
int main()
{
    int rows,columns;
    cout<<"Enter number of rows: ";     cin>>rows;
    cout<<"Enter number of columns: ";  cin>>columns;
    
    int **matrix=new int *[columns];
    for(int i=0;i<rows;i++)
        matrix[i]=new int[rows];
    cout<<"Start entering matrix by row\n";
    for(int i=0;i<rows;i++)
        for(int j=0;j<columns;j++)
            cin>>matrix[i][j];
    cout<<endl;
    for(int i=0;i<rows;i++,cout<<endl)
        for(int j=0;j<columns;j++)
            cout<<matrix[i][j]<<" ";
}
/*
 * Output:
 * Enter number of rows: 3
 * Enter number of columns: 2
 * Start entering matrix by row.
 * 1 2
 * 5 6 
 * 7 8
 * 
 * 1 2 
 * 3 4 
 * 5 6 
 * 7 8 
 */

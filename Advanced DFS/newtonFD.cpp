#include "iostream"
#include "cstdlib"
#include "unistd.h"
using namespace std;
#define row 2
#define column 4

int fact(int x)
{
	if(x==1)
		return 1;
	else
		return x*fact(x-1);
}
int main(int argc,char **argv)
{
float quesTable[row][column],diffTable[column][column+1];
int i,j;
cout<<"Size of float: "<<sizeof(float)<<endl;
cout<<"2.0-2.0="<<(float)(2.0-2);
for(i=0,*argv++;i<row;i++,cout<<endl)
	for(j=0;j<column;j++)
		quesTable[i][j]=atof(*argv++);
		//cout<<*argv++<<"\t";
sleep(0.5);
cout<<"Entry success, printing now!"<<endl<<endl;
sleep(0.5);
for(i=0;i<row;i++,cout<<endl)
	for(j=0;j<column;j++)
		cout<<quesTable[i][j]<<"\t";
sleep(1);
cout<<"Entry seems ok!"<<endl;
sleep(0.5);
cout<<"Moving forward to diffTable init and insertion!"<<endl<<endl;

for(i=0;i<column;i++)
	for(j=0;j<column+1;j++)
		diffTable[i][j]=0;
sleep(0.5);
cout<<"diffTable initialized to zero!"<<endl<<"Going to insert default values..."<<endl;

for(i=0;i<column;i++)
	for(j=0;j<row;j++)
		diffTable[i][j]=quesTable[j][i];
cout<<"Insertion tried...";
sleep(0.5);
cout<<"Printing now!"<<endl;
for(i=0;i<column;i++,cout<<endl)
	for(j=0;j<column+1;j++)
		cout<<diffTable[i][j]<<"\t";
sleep(1);
cout<<"Insertion seems ok!";
sleep(0.5);
cout<<"Moving forward to calculation!"<<endl;

cout<<"testRun: "<<diffTable[1][3]-diffTable[0][3]<<endl<<diffTable[0][4]<<endl;
for(j=2;j<column+1;j++)
	for(i=0;i<column-j+1;i++)
		diffTable[i][j]=diffTable[i+1][j-1]-diffTable[i][j-1],cout<<i<<" "<<j<<" "<<diffTable[i][j]<<" -->> "<<diffTable[i+1][j-1]-diffTable[i][j-1]<<" "<<diffTable[i+1][j-1]<<" "<<diffTable[i][j-1]<<endl;
		
sleep(0.5);
cout<<"Calculation done!";sleep(0.5);cout<<"Printing diffTable!"<<endl;sleep(1);
for(i=0;i<column;i++,cout<<endl)
	for(j=0;j<column+1;j++)
		cout<<setw(3)<<diffTable[i][j]<<"\t";
		
cout<<diffTable[0][4]<<endl<<diffTable[1][3]-diffTable[0][3]<<endl;
cout<<endl<<endl;
float x;
cout<<"Enter value of x: ";
cin>>x;
float sum=diffTable[0][1],p=(x-diffTable[0][0])/(diffTable[1][0]-diffTable[0][0]);
cout<<"sum="<<sum<<" p="<<p<<endl;

for(i=2;i<column+1;i++,p=p*(--p))
	sum+=(p*diffTable[0][i])/fact(i-1),cout<<p<<" "<<sum<<endl;

cout<<"y("<<x<<")="<<sum<<endl;
return 0;
}

#include "iostream"
#include "cstdlib"
using namespace std;
int main(int argc,char *argv[])
{
	int n=(argc-1)/2;
	float x[n],y[n];
	for(int i=0;i<n;i++)
	{
		x[i]=atof(argv[i+1]);
		y[i]=atof(argv[i+n+1]);
	}
	float X;
	cout<<"Enter X: ";cin>>X;
	float sum=0;
	for(int i=0;i<n;i++)
	{
		float product=y[i];
		for(int j=0;j<n;j++)
			if(j!=i)
				product*=(X-x[j])/(x[i]-x[j]);
		sum+=product;
	}
	cout<<sum<<endl;

}
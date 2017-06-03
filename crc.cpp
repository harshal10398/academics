/*
Single damn algo which took me nearly 10 hours to convert to STUDENT UNDESTANDABLE code.
I know better programs exists but they're too complicated to understand so here is a basic g++/cpp implementation.
CRC=Cyclic Redundency Check is method of error detection based on concept of redundency bits.
Exectution:
./crc.cpp.o 10110011010 1001
-----------|-----------|----|
            Data to be  Code
               Sent     used
                        to
                        generate
                        crc
*/

#include "iostream"
using namespace std;
#include "cmath"
#include "cstring"
int toNumber(int bin[],int size)
{
    int ans=0;
    for(int i=0;i<size;i++)
        ans+=bin[size-1-i]*pow(2,i);
    
    return ans;
}
int radix(int x)
{
    int rad=0;
    for(;x!=0;x/=2)
        rad++;
    return rad;
}
int main(int argc,char *argv[])
{
    int sdw=strlen(argv[1]);
    int sc=strlen(argv[2]);
    int dataWord[sdw]={};
    int code[sc]={};
    for(int i=0;i<sdw;i++)
        dataWord[i]=argv[1][i]-'0';
    for(int i=0;i<sc;i++)
        code[i]=argv[2][i]-'0';
    int data=toNumber(dataWord,sdw);
    int c=toNumber(code,sc);
    int oldC=c,oldD,crc;
    data=data<<(radix(c)-1);
    crc=data;
    c=c<<(radix(data)-radix(c));
    
    while(radix(data)>=radix(oldC))
    {
        oldD=data;
        data=data^c;
        c=c>>(radix(oldD)-radix(data));
    }
    
    
    crc=crc|data;
    int final[radix(crc)]={};
    for(int tmp=crc,i=radix(crc)-1;i>=0;i--,tmp/=2)
        final[i]=tmp%2;
    
    cout<<"CRC: ";
    for(int i=0;i<radix(crc);i++)
        cout<<final[i]<<" ";
    cout<<endl;
    
}

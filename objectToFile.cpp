#include "iostream"
#include "fstream"
#include "cstdlib"
using namespace std;

class test
{
    int data;
    char *string;
protected:
    int money;
    float skills;
public:
    test()
    {
        data=rand()%100;
        string=new char[256];
        int len=rand()%256;
        for(int i=0;i<len;i++)
            string[i]='A'+rand()%26;
        money=rand()%5000;
        skills=(rand()%101)/100.0;
        
    }
    void change()
    {
        data=rand()%100;
        string=new char[256];
        int len=rand()%256;
        for(int i=0;i<len;i++)
            string[i]='A'+rand()%26;
        money=rand()%5000;
        skills=(rand()%101)/100.0;
        
    }
    void dump()
    {
        cout<<"Entering \n"
            <<"data: "<<data<<endl
            <<"string: "<<string<<endl
            <<"money: "<<money<<endl
            <<"skills: "<<skills<<endl;
    }
};
int main()
{
    test t1;
    fstream file;
    t1.dump();
    file.open("testFile.txt",ios::in | ios::out);
    file.write((char *)&t1,sizeof(t1));
    cout<<"\nObject wrote in file!\n";
    test t2;
    cout<<"\nCreated new object\n";
    t2.dump();
    //t1.change(10000);
    cout<<"\nCopying into t2 from file.\n";
    file.seekg(0);
    file.read((char *)&t2,sizeof(t2));
    t2.dump();
    file.close();
    return 0;
}

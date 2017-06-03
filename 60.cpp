/*
 *Question 60:
 *Write a program to illustrate concept of
 *object as function argument 
 */
#include "iostream"
using namespace std;
class Integer{
    int n;
public:
    Integer()
    {
        n=0;
    }
    Integer(int x)
    {
        n=x;
    }
    void add(Integer b)
    {
        n+=b.n;
    }
    int ret()
    {
        return n;
    }
};
int main()
{
    Integer me(1),you(1);
    cout<<"Me alone: "<<me.ret()<<endl;
    me.add(you); //     ;)
    cout<<"Me and you: "<<me.ret()<<endl;
}

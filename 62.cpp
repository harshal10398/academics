/*
 * Question 62:
 * Write a program to illustrate concept
 * of friend functin using two class.
 */
#include "iostream"
using namespace std;

class gabbar;

class sambha{
private:
    int loyality,fear;
public:
    sambha(int x,int y)
    {
        loyality=x;
        fear=y;
    }
    friend void checkFriendship(gabbar&,sambha&,int);
};

class gabbar{
private:
    int loyality,fear;
public:
    gabbar(int x,int y)
    {
        loyality=x;
        fear=y;
    }
    friend void checkFriendship(gabbar&,sambha&,int);
};
    

void checkFriendship(gabbar &g,sambha &s,int increaseRelation=0)
{
    cout<<"Gabbar is "<<g.loyality<<"% loyal and fears "<<g.fear<<"% from sambha.\n";
    cout<<"Sambha is "<<s.loyality<<"% loyal and fears "<<s.fear<<"% from gabbar.\n";
    if(increaseRelation!=0)
    {
        cout<<"Increasing loyality and decreasing fear by "<<increaseRelation<<endl;
        g.loyality+=increaseRelation;
        g.fear-=increaseRelation;
        s.loyality+=increaseRelation;
        s.fear-=increaseRelation;
        checkFriendship(g,s);
    }
}

int main()
{
    sambha s(70,90);
    gabbar g(60,10);
    checkFriendship(g,s,5);
}

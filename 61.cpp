/*
 * Question 61:
 * Write a program to illustrate concept of
 * friend functin using class
 */
#include "iostream"
using namespace std;
class lonelyPerson{
private:
    int privInfo;
public:
    lonelyPerson(int info) {privInfo=info;}
    friend void onlyOneFriend(lonelyPerson&,int);
};
void onlyOneFriend(lonelyPerson &bestFriend,int change=0)
{
    cout<<"I will only tell my best friend that my private info is "<<bestFriend.privInfo<<endl;
    if(change!=0)
    {
        cout<<"I can change his/her private info.\n";
        bestFriend.privInfo+=change;
        onlyOneFriend(bestFriend);
    }
}
int main()
{
    lonelyPerson nerd(157);
    onlyOneFriend(nerd,-10);
}

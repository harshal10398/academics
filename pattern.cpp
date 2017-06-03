 /*
  * 
  * 1
  * 12
  * 123
  * 1234
  * 12345
  * 1234
  * 123
  * 12
  * 1
  * 
  */
#include "iostream"
using namespace std;
int main()
{
    for(int i=1;i<=10;i++,cout<<endl)
    {
        if(i<=5)
        for(int j=1;j<=i;j++)
            cout<<j;
        else
            for(int j=1;j<=10-i;j++)
                cout<<j;
    }
    
    for(int i=1;i<=5;i++)
    {
        int ans=1;
        for(int j=1;j<=i;j++)
            ans*=i;
        cout<<ans<<endl;
    }
    
}

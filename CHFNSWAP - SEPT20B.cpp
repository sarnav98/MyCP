
#include<bits/stdc++.h>
using namespace std;
long long int square(long long int c)
{
        return (-1+sqrt(1+4*c))/2;
}
int main()
{
    ios_base::sync_with_stdio(false);
           cin.tie(NULL);
    long long int t;cin>>t;
    while(t--)
    {
       long long int n;cin>>n;
       long long int sum=(n*(n+1))/2;
        if(sum%2!=0)
       {cout<<0<<endl;
       continue;
       }
       long long int r=square(sum);
      
       if((r*(r+1))/2==sum/2)
       cout<<n-r+(r*(r-1))/2+(((n-r)*(n-r-1))/2)<<endl;
       else
       cout<<n-r<<endl;
       
    }

}
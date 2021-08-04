#include <iostream>
#define ll long long
using namespace std;

int main()
{
     ll N, T = 0;
     cin>>N;
     for(ll i = 1;i<=((ll)1<<60);i*=2)
     {
       //  cout<<i<<" acumula "<<T<<endl;
         ll j = i * 2;
         T += (N/j)*i;
         ll k = N%j;
         T += max(k-i+1,k-k);
     }
     cout<<T<<endl;
}
/*
i = 1, j = 2;
7/2 = 3
7%2 = 1
1-1 = 0

*/

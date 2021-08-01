#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int res = 1, mod = 1e9+7;
    while(n--) res =(res*2)%mod;
    cout<<res<<"\n";
}

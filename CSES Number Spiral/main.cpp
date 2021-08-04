#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
ll Caso()
{
    ll x,y;

    scanf("%lld %lld",&y,&x);
    if(y > x)
    {
        ll V = y*(y-1)+1;
        if(y%2 == 0)
            return V + y - x;
        else
            return V - y + x;
    }
    else
    {
        ll V = x*(x-1)+1;
        if(x%2 == 1)
            return V + x - y;
        else
            return V - x + y;
    }

}
int main()
{
    int t;
    cin>>t;
    while(t--)
        printf("%lld\n", Caso());
}

#include <iostream>
#include <cstdio>
using namespace std;
long long SUM = 0, LSUM = 0;
int main()
{
    long long n;
    cin>>n;
    SUM = (n*(n+1))/2;
    for(int i = 0;i<n-1;i++)
    {
        int a;
        scanf("%d",&a);
        LSUM += a;
    }
    cout<<(SUM-LSUM)<<endl;
}

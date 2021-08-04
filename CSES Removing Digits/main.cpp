#include <iostream>

using namespace std;
int Dist[1000001],N;
int DP(int n)
{
    if(n==0)
        return 0;
    if(n<10)
        return 1;
    if(Dist[n]!=-1)
        return Dist[n];
    Dist[n] = 2000000;
    int k = n;
    while(k)
    {
        int c = k%10;
        Dist[n] = min(Dist[n], DP(n-c)+1);
        k/=10;
    }
    return Dist[n];
}
int main()
{
    cin>>N;
    for(int i = 1;i<=N;i++)
        Dist[i] = -1;
    cout<<DP(N)<<endl;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
struct item{
    int next, prev, pos, orden;
};
bool Comparer(const item a, const item b)
{
    return a.pos < b.pos;
}
item in[300000];
int R[300000], Ord[300000];
int main()
{
    int X,N, maxR = 0;
    cin>>X>>N;
    in[0].pos = 0;
    in[0].next = 1;
    for(int i = 1;i<=N;i++)
    {
        //in[i].next = i+1;
        //in[i].prev = i-1;
        scanf("%d",&in[i].pos);
        in[i].orden = i;
        //maxR = max(maxR,in[i].pos - in[i-1].pos);
    }
    in[N+1].pos = X;
    in[N+1].prev = N;
    //maxR = max(maxR,X - in[N].pos);
    sort(in+1,in+N+2,Comparer);
    maxR = max(maxR,in[1].pos);
    for(int i = 1;i<=N;i++)
    {
        //cout<<i<<" = "<<in[i].pos<<" | "<<maxR<<endl;
        Ord[in[i].orden] = i;
        in[i].next = i+1;
        in[i].prev = i-1;
        maxR = max(maxR,in[i+1].pos - in[i].pos);
    }
    R[N+1] = maxR;
    for(int i = N;i>=1;i--)
    {
        int n = Ord[i];
        int prev = in[n].prev, next = in[n].next;
        maxR = max(maxR,in[next].pos - in[prev].pos);
        in[prev].next = next;
        in[next].prev = prev;
        R[i] = maxR;
    }
    for(int i = 2;i<=N+1;i++)
        printf("%d ",R[i]);
}

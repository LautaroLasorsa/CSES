#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
const int largo = 1<<19;
int ST[largo], in[largo];
//pair<int,int> R[largo];
int Query(int i, int val, int acum)
{
    if(i*2 >= largo)
        return (i-largo/2);
    if(acum + ST[i*2] >= val)
        return Query(i*2,val,acum);
    return Query(i*2+1,val,acum + ST[i*2]);
}
void Update(int pos, int sum)
{
    pos += largo/2;
    while(pos)
        ST[pos]+=sum, pos/=2;
}
map<int,int> valores, inversos;
int K,N;
int main()
{
    cin>>N>>K;
    for(int i = 0;i<N;i++)
    {
        scanf("%d",in+i);
        valores[in[i]] = 1;
    }
    int v = 1;
    for(auto & k : valores)
        k.second = v, v++, inversos[k.second] = k.first;
    for(int i = 0;i<N;i++)
        in[i] = valores[in[i]];
    for(int i = 0;i<K-1;i++)
        Update(in[i],1);
    for(int i = K-1;i<N;i++)
    {
        if(i>=K)
            Update(in[i-K],-1);
        Update(in[i],1);
        int l = Query(1,(K+1)/2,0);
        printf("%d ",inversos[l],l);
    }
}

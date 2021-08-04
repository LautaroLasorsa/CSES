#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;
const int largo=1<<21;
int ST[largo], ini, fin;
pair<int,int> R[largo], in[400002];
void Update(int p)
{
    p+=largo/2;
    while(p)
        ST[p]++, p/=2;
}
int Query(int i)
{
    //cout<<"Query en "<<i<<" : "<<ini<<" , "<<fin<<" , "<<R[i].first<<" , "<<R[i].second<<endl;
    if(R[i].first > fin || R[i].second < ini)
        return 0;
    else if(R[i].first >= ini && R[i].second <= fin)
        return ST[i];
    return Query(i*2) + Query(i*2+1);
}
map<int,int> mapa;
int main()
{
    int N,K = 1, k = 0;
    cin>>N;//>>K;
    for(int i = largo/2;i<largo;i++)
        R[i] = {i-largo/2,i-largo/2};
    for(int i = largo/2-1;i>0;i--)
        R[i] = {R[i*2].first,R[i*2+1].second};
    for(int i = 0;i<N;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        in[i] = {b,a};
        mapa[a] = mapa[b] = 1;
    }
    int v = 1;
    for(auto & j : mapa)
        j.second = v, v++;
    sort(in,in+N);
   // priority_queue<int,vector<int>,greater<int> > PQ;
    fin = largo/2-1;
    for(int i = 0;i<N;i++)
    {
        int b = mapa[in[i].first], a = mapa[in[i].second];
        ini = a+1;
        //cout<<i<<" : "<<a<<" , "<<b<<" | "<<k<<" = "<<Query(1)<<endl;
        if(Query(1) < K)
        {
            Update(b);
            k++;
        }
    }
    cout<<k<<endl;
}
/*
5 2
1 5
1 4
2 5
3 4
4 6


4 2
3 5
4 9
5 8
1 4

10 2
40 44
37 74
70 81
62 83
11 85
17 86
38 87
92 95
65 97
99 100
*/

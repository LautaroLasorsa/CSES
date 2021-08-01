#include <iostream>
#include <map>
#include <bitset>
#include <vector>
#include <unordered_map>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
/// 32678
const int LARGO = 1<<19, MAXN = 2e5+10;
struct query{
    int a,b,q;
};
query Qs[200001];
int ST[LARGO];
pair<int,int> LIMs[LARGO];
int Qr[200001],  in[MAXN], post[MAXN], fron[MAXN];
map<int,int> M;
//vector<int> vec[30001];
int ini,fin;
bool Comparador(const query & a, const query & b)
{
    return a.a < b.a;
}
int Query(int i)
{
    if(ini <= LIMs[i].first && LIMs[i].second <= fin)
    {
        return ST[i];
    }
    else if(LIMs[i].first<=fin && ini <= LIMs[i].second)
    {
        return Query(i*2) + Query(i*2+1);
    }
    return 0;
}
int main()
{
    //memset(M,0,sizeof(M));
    for(int i = 0;i<MAXN;i++)
        fron[i] = 0, post[i] = -1;
    int n,a,q;
    cin>>n>>q;
    for(int i = LARGO/2;i<LARGO;i++)
    {
        LIMs[i] = {i - LARGO/2,i-LARGO/2};
        ST[i] = 0;
    }
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&in[i]);
        if(!M[in[i]])
        {
            M[in[i]] = M.size();
            //ms++;
            //M[in[i]] = ms;
            ST[i+LARGO/2] = true;
            in[i] = M[in[i]];
            fron[in[i]] = i;
        }
        else
        {
            ///vec[M[in[i]]].push_back(i);
            ST[i+LARGO/2] = false;
            in[i] = M[in[i]];
            post[fron[in[i]]] = i;
            fron[in[i]] = i;
        }
    }
    //cout<<"---"<<endl;
    for(int i = LARGO/2 - 1;i>=1;i--)
    {
        ST[i] = ST[i*2]+ST[i*2+1];
        LIMs[i] = {LIMs[i*2].first, LIMs[i*2+1].second};
    }
    for(int i = 0;i<q;i++)
    {
        scanf("%d %d",&Qs[i].a,&Qs[i].b);
        Qs[i].q = i;
        Qs[i].a--,Qs[i].b--;
    }
    //cout<<"J"<<endl;
    sort(Qs,&Qs[q],Comparador);
    for(int i = 0, j = 0;i<q;i++)
    {
        //cout<<i<<endl;
        //cout<<Qs[i].a<<" - "<<Qs[i].b<<endl;
        while(j < Qs[i].a)
        {
     //       cout<<"  "<<j<<endl;
            if(post[j]>-1)
            {
                int k = post[j] + LARGO/2;
                ST[k] = true;
                k/=2;
                while(k)
                    ST[k] = ST[k*2] + ST[k*2+1],k/=2;
                // cout<<"kk"<<endl;
            }
            j++;
        }
        ini = Qs[i].a, fin = Qs[i].b;
        Qr[Qs[i].q] = Query(1);
    }
   // cout<<"z"<<endl;
    for(int i = 0;i<q;i++)
       printf("%d\n",Qr[i]);
}

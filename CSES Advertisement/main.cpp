#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int comp[200000];
pair<int,int> rango[200000];
ll Val[200000], CVAL[200000], MAX = 0;
ll Tamanio(int i)
{
    return rango[i].second - rango[i].first +1;
}
void Unir(int a, int b)
{
    int ta = comp[a], tb = comp[b];
    //cout<<"Se unen los intervalos"<<ta<< "  y  "<<tb<<endl;

    if(ta == tb)
        return;
    if(Tamanio(ta) > Tamanio(tb))
        swap(ta,tb);
    CVAL[tb] = min(CVAL[ta],CVAL[tb]);
    //int La = Tamanio(ta), Lb = Tamanio(tb);
    for(int i = rango[ta].first; i <= rango[ta].second;i++)
        comp[i] = tb;
    rango[tb].first = min(rango[tb].first,rango[ta].first);
    rango[tb].second = max(rango[tb].second,rango[ta].second);
    ll VAL = Tamanio(tb) * CVAL[tb];
    if(VAL > MAX)
        MAX = VAL;
}
int main()
{
    int N;
    cin>>N;
    priority_queue<pair<int,int> > PQ;
    for(int i = 0;i<N;i++)
    {
        int v;
        scanf("%d",&v);
        Val[i] = CVAL[i] = v;
        rango[i] = {i,i};
        comp[i] = i;
        PQ.push({v,i});
    }
    while(PQ.size())
    {
        int nod = PQ.top().second;
        PQ.pop();
        if(nod < N-1 && Val[nod+1] >= Val[nod])
            Unir(nod,nod+1);
        if(nod > 0 && Val[nod-1] >= Val[nod])
            Unir(nod,nod-1);
    }
    cout<<MAX<<endl;
}

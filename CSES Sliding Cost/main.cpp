#include <iostream>
#include <cstdio>
#include <map>
#define ll long long
using namespace std;
const int largo = 1<<19;
int ST[largo], in[largo], ini, fin;
pair<long long,int> ST2[largo];
pair<int,int> R[largo];
pair<long long,int> operator+(pair<long long, int> A, pair<long long, int> B)
{
    pair<long long, int> C;
    C.first = A.first + B.first;
    C.second = A.second + B.second;
    return C;
}
pair<ll,int> Query2(int i)
{
    if(R[i].first>=ini && R[i].second <= fin)
        return ST2[i];
    if(R[i].first> fin || R[i].second <ini)
        return {0,0};
    return Query2(i*2) + Query2(i*2+1);
}
int Query(int i, int val, int acum)
{
    if(i*2 >= largo)
        return (i-largo/2);
    if(acum + ST[i*2] >= val)
        return Query(i*2,val,acum);
    return Query(i*2+1,val,acum + ST[i*2]);
}
map<ll,ll> valores, inversos;
void Update2(int pos, ll sum)
{
    //sum *= inversos[pos];
    pair<ll,int> P = {sum * inversos[pos],sum};
    pos += largo/2;
    while(pos)
    {

        ST2[pos]= ST2[pos] + P;
         pos/=2;
    }
}

void Update(int pos, int sum)
{
    pos += largo/2;
    while(pos)
        ST[pos]+=sum, pos/=2;
}
int K,N;
int main()
{
    cin>>N>>K;
    for(int i = 0;i<largo/2;i++)
        R[i+largo/2] = {i,i};
    for(int i = largo/2-1;i;i--)
        R[i] = {R[i*2].first,R[i*2+1].second};
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
        Update(in[i],1), Update2(in[i],1);
    for(int i = K-1;i<N;i++)
    {
        if(i>=K)
            Update(in[i-K],-1), Update2(in[i-K],-1);
        Update(in[i],1);
        Update2(in[i],1);
        int l = Query(1,(K+1)/2,0);
        ini = 0, fin = l-1;
        pair<long long,int> izq = Query2(1);
        ini = l+1, fin = N;
        pair<long long,int> der = Query2(1);
        ll dizq = izq.second * inversos[l] - izq.first;
        ll dder = der.first - der.second * inversos[l];
        ll DIF = dizq + dder;
      //  cout<<"En la ventana "<<i<<" tenemos "<<dizq<<" y "<<dder<<endl;
        printf("%lld ",DIF);
    }
}

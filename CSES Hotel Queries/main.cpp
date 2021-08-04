#include <iostream>
#include <cstdio>
using namespace std;
const int largo = 1<<19;
pair<int,int> Rango[largo];
int ST[largo], N,M;
void Actualizar(int pos, int v)
{
    pos += largo/2;
    ST[pos] -= v;
    while((pos/=2)>0)
        ST[pos] = max(ST[pos*2],ST[pos*2+1]);
}
int Query(int i, int v)
{
    if(i >= largo/2)
        return i - largo/2;
    if(ST[i*2]>=v)
        return Query(i*2,v);
    return Query(i*2+1,v);
}
int main()
{
    for(int i = largo/2;i<largo;i++)
        Rango[i] = {i-largo/2,i-largo/2};
    cin>>N>>M;
    for(int i = 0;i<N;i++)
        scanf("%d",ST+largo/2+i);
    for(int i = largo/2-1;i>0;i--)
    {
        Rango[i] = {Rango[i*2].first,Rango[i*2+1].second};
        ST[i] = max(ST[i*2],ST[i*2+1]);
    }
    for(int i = 0;i<M;i++)
    {
        int r;
        scanf("%d",&r);
        if(r > ST[1])
            printf("0 ");
        else
        {
            int pos = Query(1,r);
            printf("%d ",pos+1);
            Actualizar(pos,r);
        }
    }
}

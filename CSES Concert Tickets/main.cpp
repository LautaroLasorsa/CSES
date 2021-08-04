#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
const int largo = 1<<19;
int ST[largo], ini,fin,t[largo/2],n,m;
pair<int,int> Rango[largo];

int Query(int i)
{
    if(ini<=Rango[i].first&&Rango[i].second<=fin)
    {
        //cout<<i<<" agrega "<<ST[i]<<" | "<<Rango[i].first<<" , "<<Rango[i].second<<endl;
        return ST[i];
    }
    if(ini > Rango[i].second || fin<Rango[i].first)
    {
     //   cout<<ini<<";"<<fin<<" no pertenece a "<<i<<" : "<<Rango[i].first<<" , "<<Rango[i].second<<endl;
        return 0;
    }
    return Query(i*2) + Query(i*2+1);
}
int Buscar(int i, int v, int acum)
{
    //cout<<(i-largo/2)<<" , "<<v<<" , "<<acum<<" y "<<ST[i]<<" | "<<Rango[i].first<<" , "<<Rango[i].second<<endl;
    if(i>=largo/2)
    {
        if(acum + ST[i] == v)
            return i - largo/2;
        return -1;
    }
    if(acum+ST[i*2]>=v)
        return Buscar(i*2,v,acum);
    return Buscar(i*2+1,v,acum+ST[i*2]);
}
void Update(int p, int v)
{
    p += largo/2;
    ST[p] = v;
    while((p/=2)>0)
        ST[p] = ST[p*2] + ST[p*2+1];
}
int main()
{
    for(int i = largo/2;i<largo;i++)
    {
        ST[i] = 1;
        Rango[i] = {i-largo/2,i-largo/2};
    }
    for(int i = largo/2-1;i>=0;i--)
    {
        ST[i] = ST[i*2] + ST[i*2+1];
        Rango[i] = {Rango[i*2].first,Rango[i*2+1].second};
    }
    cin>>n>>m;
    for(int i = 0;i<n;i++)
        scanf("%d",t+i);
    sort(t,t+n);
    for(int i = 0;i<m;i++)
    {
        int h;
        scanf("%d",&h);
        if(t[0]>h)
            printf("-1\n");
        else
        {
            int pos;
            if(t[n-1]<=h)
                pos = n-1;
            else
                pos = upper_bound(t,t+n-1,h) - t -1 ;
            if(ST[pos+largo/2] == 1)
            {
                printf("%d\n",t[pos]);
                Update(pos,0);
            }
            else
            {
                //cout<<"Pos vale : "<<pos<<endl;
                ini = 0, fin = pos;
                int V = Query(1);
                //cout<<ini<<" , "<<pos<<" = "<<V<<endl,
                pos = Buscar(1,V,0);
                if(V == 0 || pos==-1)
                    printf("-1\n");
                else
                {
                    printf("%d\n",t[pos]);
                    Update(pos,0);
                }
            }
        }
    }
}
/*
5 5
5 3 7 8 5
8
7
5
5
5
*/

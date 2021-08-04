#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct evento{
    int person, dia;
    bool entra;
};
bool Comparer(const evento & a, const evento &b)
{
    if(a.dia!= b.dia)
        return a.dia < b.dia;
    return a.entra > b.entra;
}
evento in[500000];
int maxR = 0, R[250000];
int main()
{
    int N;
    cin>>N;
    for(int i = 0;i<N;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        in[i*2].dia = a, in[i*2].entra = true, in[i*2].person = i;
        in[i*2+1].dia = b, in[i*2+1].entra = false, in[i*2+1].person = i;
    }
    sort(in,in+2*N, Comparer);
    queue<int> lugares;
    for(int i = 0;i<2*N;i++)
    {
        int person = in[i].person;
        if(in[i].entra)
        {
            if(lugares.size())
            {
                int l = lugares.front();
                lugares.pop();
                R[person] = l;
            }
            else
            {
                maxR++;
                R[person] = maxR;
            }
        }
        else
        {
            int k = R[person];
            lugares.push(k);
        }
    }
    cout<<maxR<<endl;
    for(int i = 0;i<N;i++)
        printf("%d ",R[i]);
}

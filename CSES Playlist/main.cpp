#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<int,int> pos;
int ini = 1, R = 0;
int main()
{
    int N;
    cin>>N;
    for(int i = 1;i<=N;i++)
    {
        int k;
        scanf("%d",&k);
        if(pos[k] >= ini)
        {
            R = max(R,i-ini);
            ini = pos[k]+1;
        }
        pos[k] = i;
    }
    R = max(R,N-ini+1);
    cout<<R<<endl;
}

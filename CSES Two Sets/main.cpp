#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
vector<int> sets[2];

int main()
{
    long long N, SUM;
    cin>>N;
    SUM = (N*(N+1))/2;
    if(SUM%2)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        int ini = 1, fin = N, pos = 0;
        if(N%2 == 1)
        {
            sets[0] = {1,2};
            sets[1] = {3};
            ini = 4;
        }
        while(ini < fin)
        {
            sets[pos].push_back(ini);
            sets[pos].push_back(fin);
            ini++,fin--, pos = !pos;
        }
        for(int i = 0;i<2;i++)
        {
            cout<<sets[i].size()<<endl;
            for(auto k : sets[i])
                printf("%d ",k);
            cout<<endl;
        }
    }
}

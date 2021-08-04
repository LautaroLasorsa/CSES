#include <iostream>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
pair<int,int> in[250000];
int main()
{
    int N,K,a;
    cin>>N>>K;
    for(int i = 0;i<N;i++)
        scanf("%d",&in[i].first),in[i].second = i+1;
    sort(in,in+N);
    int i = 0, j = N-1;
    while(i<j)
    {
        int c = in[i].first + in[j].first;
        if(c == K)
        {
            cout<<in[i].second<<" "<<in[j].second<<endl;
            return 0;
        }
        else if(c > K)
            j--;
        else
            i++;
    }
    cout<<"IMPOSSIBLE"<<endl;

}

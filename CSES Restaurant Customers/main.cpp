#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
pair<int,int> in[500000];
int N,a,b,T = 0, MT = 0;
int main()
{
    cin>>N;
    for(int i = 0;i<N;i++)
    {
        scanf("%d %d",&a,&b);
        in[i*2] = {a,1};
        in[i*2+1] = {b,-1};
    }
    sort(in,in+2*N);
    for(int i = 0;i<2*N;i++)
    {
        T+=in[i].second;
        if(T>MT)
            MT = T;
    }
    cout<<MT<<endl;
}

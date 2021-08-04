#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int N, X,P[200001],R = 0, ini = 0;
int main()
{
    cin>>N>>X;
    for(int i = 0;i<N;i++)
        scanf("%d",P+i);
    sort(P,P+N);
    while(N>ini)
    {
        while(N>ini && ((N-ini)%2 == 1 || (P[N-1] + P[ini])>X))
            N--,R++;
        if(N>ini && P[N-1] + P[ini] <= X)
            N--,ini++,R++;
    }
    cout<<R<<endl;
}

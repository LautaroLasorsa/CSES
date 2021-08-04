#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
ll K, A[200001],B[200001],N,M;
int main()
{
    cin>>N>>M>>K;
    for(int i = 0;i<N;i++)
        scanf("%lld",A+i);
    for(int i = 0;i<M;i++)
        scanf("%lld",B+i);
    sort(A,A+N),sort(B,B+M);
    int R = 0;
    for(int i = 0, j = 0;i<N && j<M;i++)
    {
        while(j<M && B[j]+K < A[i])
            j++;
        if(j<M && B[j]-K <= A[i])
            R++, j++;
    }
    cout<<R<<endl;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int SIZE = 0, LIST[300000], N, K;
void Update(int p)
{
    if(SIZE == 0)
        LIST[0] = p, SIZE++;
    else if(LIST[SIZE-1]<p)
        LIST[SIZE] = p, SIZE++;
    else
    {
        int pos = lower_bound(LIST,LIST + SIZE,p) - LIST;
        LIST[pos] = p;
    }
}
int main()
{
    cin>>N;
    for(int i = 0;i<N;i++)
    {
        scanf("%d",&K);
        Update(K);
    }
    cout<<SIZE<<endl;
}
/*
6
1 1 1 1 1 1

*/

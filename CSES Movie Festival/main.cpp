#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
set<pair<int,int> > s;
int main()
{
    int N = 0, T = 0, fin = -1;
    cin>>N;
    for(int i = 0;i<N;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        pair<int,int> p = {b,a};
        s.insert(p);
    }
    for(auto k : s)
    {
        int b = k.first, a = k.second;
        if(a>=fin)
            fin = b, T++;
    }
    cout<<T<<endl;
}

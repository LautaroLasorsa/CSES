#include <iostream>
#include <set>
#include <cstdio>
using namespace std;
set<int> s;
int main()
{
    int N;
    cin>>N;
    for(int i = 0;i<N;i++)
    {
        int a;
        scanf("%d",&a);
        s.insert(a);
    }
    cout<<s.size()<<endl;
}

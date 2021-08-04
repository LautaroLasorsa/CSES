#include <iostream>
#include <cstdio>
using namespace std;
int elem;
long long TOT = 0;
int main()
{
    int n;
    cin>>n;
    scanf("%d",&elem);
    for(int i = 1;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        if(a<elem)
            TOT += (elem)-a, a = elem;
        elem = a;
    }
    cout<<TOT<<endl;
}

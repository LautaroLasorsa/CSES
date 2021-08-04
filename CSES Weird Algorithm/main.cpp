#include <iostream>
#include <cstdio>
using namespace std;
void Funcion(long long n)
{
    printf("%lld ",n);
    if(n == 1)
        return ;
    if(n%2 == 0)
        Funcion(n/2);
    else
        Funcion(n*3+1);
}
int main()
{
    long long n;
    scanf("%lld",&n);
    Funcion(n);
}

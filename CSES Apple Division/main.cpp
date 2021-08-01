#include <iostream>
#include <bitset>
using namespace std;

#define forn(i,n) for(int i = 0;i<int(n);i++)
#define dforn(i,n) for(int i = int(n)-1;i>0;i--)
#define forsn(i,s,n) for(int i = int(s);i<int(n);i++)
#define dforsn(i,s,n) for(int i = int(n)-1;i>=int(s);i--)
#define DBG(x)do{cout<<#x<<" = "<<x<<endl;}while(false)
#define get(mask,i) ((mask)&(1<<(i)))
#define sett(mask,i) ((mask)|(1<<(i)))

/*template<class T> ostream  & operator<<(vector<T> v, ostream & out){
    out<<"[";
    for(auto k : v)out<<k<<" ";
    out<<"]";
    out<<endl;
    return out;
}*/

typedef long long intl;

int in[21],N;
intl res = 1e18;
void DP(int i, intl acum){
    if(i == N){
        res = min(res,abs(acum));
        return;
    }
    DP(i+1,acum+in[i]);
    DP(i+1,acum-in[i]);
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>N;
    forn(i,N)cin>>in[i];
    DP(0,0);
    cout<<res<<"\n";
}

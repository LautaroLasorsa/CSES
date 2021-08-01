#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i = 0;i<int(n);i++)
#define dforn(i,n) for(int i = int(n)-1;i>0;i--)
#define forsn(i,s,n) for(int i = int(s);i<int(n);i++)
#define dforsn(i,s,n) for(int i = int(n)-1;i>=int(s);i--)
#define DBG(x)do{cout<<#x<<" = "<<x<<endl;}while(false)
template<class T> ostream  & operator<<(vector<T> v, ostream & out){
    out<<"[";
    for(auto k : v)out<<k<<" ";
    out<<"]";
    out<<endl;
    return out;
}

typedef long long intl;
typedef long double ld;
const int largo = 3e5+10;
pair<intl,intl> in[largo];
intl N, tim = 0;
intl res = 0;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>N;
    forn(i,N)cin>>in[i].first>>in[i].second;
    sort(in,in+N);

    forn(i,N){
        tim+=in[i].first;
        res+=in[i].second-tim;
    }
    cout<<res<<endl;
    return 0;
}

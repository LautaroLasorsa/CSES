#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

#define forn(i,n) for(int i = 0;i<int(n);i++)
#define dforn(i,n) for(int i = int(n)-1;i>=0;i--)
#define forsn(i,s,n) for(int i = int(s);i<int(n);i++)
#define fore(i,s,n) for(int i = int(s);i<int(n);i++)
#define dforsn(i,s,n) for(int i = int(n)-1;i>=int(s);i--)

#define DBG(x) do{cout<<#x<<" = "<<x<<endl;}while(false)
#define get(mask,i) (mask&(1<<i))
#define set(mask,i) (mask|=(1<<i))
template<class T> ostream & operator<<(ostream & out, vector<T> & v){
	out<<"[";
	for(auto k : v) out<<k<<" ";
	out<<"]"<<"\n";
	return out;
}
typedef long long intl;
const int maxn = 1e5;
int a[maxn], b[maxn];
intl d[maxn], d2[maxn],x[maxn];
vector<int> rev[maxn];
bitset<maxn> visto;
bool Buscar(int n, int p){
    if(visto[n]) return false;
    visto[n] = true;
    if(d[n]<d2[n]) return true;
    for(auto k : rev[n])
        if(k!=p && Buscar(k,n)) return true;
    return false;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    visto.reset();
    int N,M; cin>>N>>M;
    intl inf = 1e18;
    forsn(i,1,N+1) d[i] = d2[i] =-inf;
    d[1] = d2[1] = 0;
    forn(i,M) {cin>>a[i]>>b[i]>>x[i];
        rev[b[i]].push_back(a[i]);
    }
    forn(i,M+N)
        forn(j,M)
            if(d[a[j]]!=-inf)d[b[j]] = max(d[b[j]],d[a[j]]+x[j]);
    forn(i,4*(N+M))
        forn(j,M)
            if(d[a[j]]!=-inf)d2[b[j]] = max(d2[b[j]],d2[a[j]]+x[j]);
    if(Buscar(N,-1)){
        cout<<-1<<endl;
    }
    else cout<<d[N]<<endl;
	return 0;
}
/*
4 4
1 4 1000000
2 3 1
3 2 1
2 4 1
*/

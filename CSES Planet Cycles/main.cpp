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
const int maxn = 3e5;
int nex[maxn];
int val[maxn];
bitset<maxn> visto;
void DFS1(int n, int ini, int & d){
    d++;
    if(nex[n]!=ini){
        DFS1(nex[n],ini,d);
    }
    val[n] = d;
}
void Buscar(int n){
    int a = n;
    int b = nex[a];
    while(a!=b){
        if(visto[a]) return;
        visto[a] = true;
        a = nex[a];
        b = nex[nex[b]];
    }
    int d = 0;
    DFS1(a,a,d);
}
int DP(int n){
    if(val[n]!=0) return val[n];
    else return val[n] = DP(nex[n])+1;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N;
    cin>>N;
    forn(i,N){
        cin>>nex[i];
        nex[i]--;
    }
    forn(i,N)Buscar(i);
    forn(i,N)DP(i);
    forn(i,N)cout<<val[i]<<((i==N-1)?"\n":" ");
	return 0;
}

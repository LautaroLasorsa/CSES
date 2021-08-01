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
int N,Q, res[maxn], val[maxn], cam[maxn];
vector<int> Adj[maxn], Query[maxn];
void DFS(int n, int & id){
    id++;
    for(auto k : Query[n]){
        int  v = val[k];
        if(v>id) res[k] = -1;
        else res[k] = cam[id-v];
    }
    cam[id] = n;
    for(auto k : Adj[n]) DFS(k,id);
    id--;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>N>>Q;
    forn(i,N-1){
        int n;
        cin>>n;
        Adj[n].push_back(i+2);
    }
    forn(i,Q){
        int x,k;
        cin>>k>>x;
        val[i] = x;
        Query[k].push_back(i);
    }
    int id = -1;
    DFS(1,id);
    forn(i,Q)cout<<res[i]<<((i==Q-1)?"\n":" ");
	return 0;
}

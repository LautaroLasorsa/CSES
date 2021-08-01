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
const int maxn = 1e6;
int N,M;
vector<int> Adj[maxn], Rev[maxn];
bitset<maxn> dir, rev;
void DFS(int nod, bitset<maxn> & vis, vector<int> g[maxn]){
    if(vis[nod]) return;
    vis[nod] = true;
    for(auto k : g[nod]) DFS(k,vis,g);
}
int main()
{
    rev.reset();
    dir.reset();
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>N>>M;
    forn(i,M){
        int a,b;
        cin>>a>>b;
        Adj[a].push_back(b);
        Rev[b].push_back(a);
    }
    DFS(1,dir,Adj);
    DFS(1,rev,Rev);
    if(dir.count() == N && rev.count()==N){
        cout<<"YES\n";
        return 0;
    }
    cout<<"NO\n";
    forsn(i,2,N+1){
        if(dir[i]==false){
            cout<<1<<" "<<i<<"\n";
            return 0;
        }
        if(rev[i]==false){
            cout<<i<<" "<<1<<"\n";
            return 0;
        }
    }
	return 0;
}

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
const int maxn = 1e5+10;
bitset<maxn> res, visto;
vector<int> adj[maxn];
int N,M;
void DFS(int n, int & t){
    if(visto[n]) return;
    visto[n] = true;
    t++;
    for(auto k : adj[n]) DFS(k,t);
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>N>>M;
    forn(i,M){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    res[0] = true;
    forn(i,N){
        if(visto[i]==0){
            int t = 0;
            DFS(i,t);
            res |= res<<t;
        }
    }
    forsn(i,1,N+1)cout<<res[i];
    cout<<"\n";
	return 0;
}

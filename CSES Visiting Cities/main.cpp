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
const int maxn = 4e5, lar = 19;
intl d[maxn];
vector<pair<int,int> > Adj[maxn];
vector<int> Adj2[maxn], pad[maxn];
int N, M, dom[maxn][lar], topo[maxn], prof[maxn], ori = 0;
bitset<maxn> visto;
void DFS(int n){
    if(visto[n]) return ;
    visto[n]=true;
    for(auto k : Adj[n]){
        int nn = k.first;
        intl lc = d[n] + k.second;
        if(d[nn] == lc){
            Adj2[n].push_back(nn);
            DFS(nn);
        }
    }
    topo[ori] = n;
    ori++;
}
int LCA(int a, int b){
    if(a == b) return a;
    if(prof[a]>prof[b]) swap(a,b);
    dforn(i,lar){
        if(prof[dom[b][i]]>=prof[a]) b = dom[b][i];
    }
    if(a==b) return a;
    dforn(i,lar){
        if(dom[a][i]!=dom[b][i]){
            a = dom[a][i];
            b = dom[b][i];
        }
    }
    if(a==b) return a;
    return dom[a][0];
}
int main()
{
    visto.reset();
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>N>>M;
    forn(i,M){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        Adj[a].push_back({b,c});
    //    Adj[b].push_back({a,c});
    }
    forn(i,N) d[i] = 1e18;
    d[0] = 0;
    priority_queue<pair<intl,int>,vector<pair<intl,int> >, greater<pair<intl,int> > > PQ;
    PQ.push({0,0});
    while(PQ.size()){
        auto p = PQ.top();
        PQ.pop();
        int n = p.second;
        intl c = p.first;
        for(auto k : Adj[n]){
            intl lc = c+k.second;
            int nn = k.first;
            if(d[nn]>lc){
                d[nn]=lc;
                PQ.push({lc,nn});
            }
        }
    }
    DFS(0);
    dforn(i,ori){
        int n = topo[i];
        if(n == 0){
            forn(j,lar) dom[n][i]=0;
            prof[n] = 0;
        }else{
            int p = pad[n][0];
            forsn(j,1,pad[n].size()){
                p = LCA(p,pad[n][j]);
            }
            dom[n][0]=p;
            prof[n] = prof[p]+1;
        }
       // cout<<(ori-i-1)<<" : "<<n+1<<" : "<<prof[n]<<" y "<<dom[n][0]<<" => "<<pad[n];
        forsn(j,1,lar) dom[n][j] = dom[dom[n][j-1]][j-1];
        for(auto k : Adj2[n]) pad[k].push_back(n);
    }
    vector<int> res;
    int p = N-1;
    while(p!=0){
        res.push_back(p+1);
        p=dom[p][0];
    }
    res.push_back(1);
    sort(res.begin(),res.end());
    cout<<res.size()<<"\n";
    forn(i,res.size())cout<<res[i]<<(((i==int(res.size()-1)))?"\n":" ");
	return 0;
}
/*
7 9
1 2 1
2 3 1
3 4 1
4 2 1
4 7 2
4 6 1
6 7 1
1 7 99
1 7 1
*/

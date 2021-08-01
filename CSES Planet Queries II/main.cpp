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
//#define set(mask,i) (mask|=(1<<i))
template<class T> ostream & operator<<(ostream & out, vector<T> & v){
	out<<"[";
	for(auto k : v) out<<k<<" ";
	out<<"]"<<"\n";
	return out;
}
typedef long long intl;
const int maxn = 5e5, lev = 22;
bitset<maxn> raiz, visto;
int cic[maxn], pos[maxn], lar[maxn], nex[maxn], skip[maxn][lev], nc = 0, res[maxn], llega[maxn], dist[maxn];
int N,Q;
void Buscar(int i){
    int a = i;
    int b = nex[i];
    while(a!=b){
        if(visto[a])return;
        visto[a] = true;
        a = nex[a];
        b = nex[nex[b]];
    }
    if(visto[a])return;
    visto[a] = true;
    nc++;
    cic[a] = nc;
    pos[a] = 0;
    b = nex[a];
    while(b!=a){
        visto[b] = true;
        lar[nc]++;
        cic[b] = nc;
        pos[b] = lar[nc];
        b = nex[b];
    }
    lar[nc]++;
}
int DFS(int n){
    if(cic[n]!=0){
        llega[n] = n;
        dist[n] = 0;
        return 0;
    }
    if(dist[n]!=0) return dist[n];
    dist[n] = DFS(nex[n])+1;
    llega[n] = llega[nex[n]];
    return dist[n];
}

int main()
{

    cin.tie(0);
    cin.sync_with_stdio(0);
    memset(res,-1,sizeof(res));
    raiz.set();
    visto.reset();
    cin>>N>>Q;
    forn(i,N){
        cin>>nex[i];
        nex[i]--;
        skip[i][0] = nex[i];
        raiz[nex[i]]=false;
    }
    forsn(k,1,lev){
        forn(i,N){
            skip[i][k] = skip[skip[i][k-1]][k-1];
        }
    }
    forn(i,N)Buscar(i);
    forn(i,N)if(raiz[i])DFS(i);
   forn(i,Q){
        int a,b;
        cin>>a>>b;
        a--,b--;
        if(cic[b]){
            if(cic[a]){
                if(cic[a]!=cic[b]) continue;
                res[i] = (pos[b]-pos[a]+lar[cic[a]])%lar[cic[a]];
            }
            else{
                int d = dist[a];
                a = llega[a];
                if(cic[a]!=cic[b]) continue;
                res[i] = (pos[b]-pos[a]+lar[cic[a]])%lar[cic[a]] + d;
            }
        }else{
            if(cic[a]) continue;
            if(llega[a] == llega[b]){
              if(dist[b]>dist[a]) continue;
                int d = dist[a] - dist[b];
                dforn(j,lev){
                    if(d&(1<<j)){
                        a = skip[a][j];
                    }
                }
                if(a==b) res[i] = d;

            }
        }
    }
     forn(i,Q)cout<<res[i]<<((i==Q-1)?"\n":" ");
   return 0;
}
/*
20 0
2 3 4 5 1
7 8 9 10 6
1 2 3 4 5
11 16 17 18 19

*/

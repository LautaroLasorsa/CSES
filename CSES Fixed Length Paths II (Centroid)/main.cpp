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
#define TAM_MASK 1
#define get(mask,i) ((mask>>(TAM_MASK*(i)) & ( (1<<TAM_MASK)-1)))
#define set(mask,i,v)  ( ((mask & ~( ( (1<<TAM_MASK)-1) << (TAM_MASK*(i)) )) | (v<<(TAM_MASK * (i))) ))
#define popcount(mask) (__builtin_popcount(mask))
#define endl '\n'
#define ALL(x) x.begin(),x.end()
template<class T> ostream & operator<<(ostream & out, vector<T> & v){
	out<<"[";
	for(auto k : v) out<<k<<" ";
	out<<"]"<<"\n";
	return out;
}
template<class T> ostream & operator<<(ostream & out, set<T>  s){
	out<<"{";
	for(auto k : s) out<<k<<" ";
	out<<"}"<<"\n";
	return out;
}

template<class T, class U> ostream & operator<<(ostream & out, pair<T,U>  p){
	out<<"[ "<<p.first<<" , "<<p.second<<" ] ";
	return out;
}
template<class T, class U> istream & operator>>(istream & in, pair<T,U> & p){
	in>>p.first>>p.second;
	return in;
}


typedef long long intl;
const int maxn = 3e5;
bitset<maxn> cen;
vector<int> adj[maxn];
intl RES2 = 0, RES1 = 0;
int K1, K2;
int cdis[maxn];
void FijarDis(int nod, int d, vector<int> & nods, vector<int> & dis, int pad = -1){
    if(cen[nod]) return;
    cdis[nod] = d;
    nods.push_back(nod);
    dis.push_back(d);
    for(auto x : adj[nod])
        if(x!=pad)
            FijarDis(x,d+1,nods,dis,nod);
}
int Tams(int nod, vector<pair<int,int> > & vals, vector<int> & nods, int pad = -1){
    if(cen[nod]) return 0;
    int tam = 1;
    int maxt = 0;
    for(auto x : adj[nod])
        if(x!=pad)
        {
            int lt =Tams(x,vals,nods,nod);
            tam+=lt;
            maxt = max(maxt,lt);
        }
    nods.push_back(nod);
    vals.push_back({tam,maxt});
    return tam;

}
void Procesar(int nod){
    //DBG(nod);
    vector<int> nods;
    vector<pair<int,int> > tams;
    vector<vector<int> >  lads, ldis;
    int tot = Tams(nod,tams,nods);
    int cent = -1;
    forn(i,nods.size()){
        int v = max(tot-tams[i].first,tams[i].second);
        if(v*2<=tot){
            cent = nods[i];
            cen[cent] = true;
            break;
        }
    }
    for(auto x : adj[cent])
        if(!cen[x]){
            lads.push_back({});
            ldis.push_back({});
            FijarDis(x,1,lads.back(),ldis.back());
            diss.insert(diss.end(),ALL(ldis.back()));
        }
    sort(diss.begin(),diss.end());
    //intl LOC = 0;
    forn(i,lads.size()){
        sort(ALL(ldis[i]));
        for(auto x : lads[i]){
            int k1 = K1-cdis[x];
            int k2 = K2-cdis[x];
            if(0>=k1 and 0<=k2) RES1++;
            int tot = upper_bound(ALL(diss),k2)-lower_bound(ALL(diss),k1);
            int loc = upper_bound(ALL(ldis[i]),k2)-lower_bound(ALL(ldis[i]),k1);
            RES2 += tot-loc;
        }
    }
    //cout<<cent<<" = "<< LOC<<" >> "<<lads<<endl;
    forn(i,lads.size()){
        Procesar(lads[i][0]);
    }
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n; cin>>n>>K1>>K2;
    forsn(i,1,n){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Procesar(1);
    cout<<RES2/2+RES1<<endl;
    return 0;
}

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
#define get(mask,i) (bool(mask&(1<<(i))))
#define set(mask,i) (mask|=(1<<(i)))
#define invert(mask,i) (mask^=(1<<(i)))
#define popcount(mask) (__builtin_popcount(mask))
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
const int inf = 2e9 + 10;
struct nodo{
    nodo * l, * r;
    int val;
    nodo(){
        l = r = nullptr;
        val = inf;
    }
};
const int largo = 1e7;
//nodo st[largo];
int tam = 2;
//int raiz1 = 0, raiz2 = 1;
nodo * raiz1 = nullptr, * raiz2 = nullptr;
nodo * Update(nodo * nod, int x, int v, int ini = 0, int fin = (1<<30)-1){
    if(x<ini || x>fin) return nod;
    if(nod==nullptr){
        nod = new nodo();
    }
    if(ini == fin) nod -> val = v;
    else{
        nod ->val = inf;
        int m = (ini+fin)/2;
        nod ->l = Update(nod ->l,x,v,ini,m);
        nod ->r = Update(nod ->r,x,v,m+1,fin);
        if(nod ->l != nullptr) nod ->val = min(nod -> val,nod -> l ->val);
        if(nod ->r != nullptr) nod ->val = min(nod -> val,nod -> r ->val);
    }
    return nod;
}
int Query(nodo * nod, int lq, int rq, int ini = 0, int fin = (1<<30)-1){
    if(nod==nullptr) return inf;
    if(lq<=ini && fin<= rq) return nod ->val;
    if(lq>fin || rq<ini) return inf;
    int m = (ini+fin)/2;
    return min(Query(nod ->l,lq,rq,ini,m),Query(nod -> r,lq,rq,m+1,fin));
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,q;
    cin>>n>>q;
    forsn(i,1,n+1){
        int p; cin>>p;
        raiz1 = Update(raiz1,i,p+i);
        raiz2 = Update(raiz2,i,p+(n-i));
    }
    forn(i,q){
        int t; cin>>t;
        if(t==1){
            int k,x; cin>>k>>x;
            raiz1 = Update(raiz1,k,k+x);
            raiz2 = Update(raiz2,k,x+(n-k));
        }else{
            int k; cin>>k;
            int r1 = Query(raiz1,k,n) - k;
            int r2 = Query(raiz2,1,k) - (n-k);
            cout<<min(r1,r2)<<"\n";
        }
    }
    return 0;
}

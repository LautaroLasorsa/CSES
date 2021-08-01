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
#define set(mask,i,v)  ( ((mask & ~( ( (1<<TAM_MASK)-1) << (TAM_MASK*(i)) )) | (v<<(TAM_MASK * (i))) )
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
struct nodo{
    nodo * l = nullptr, * r=nullptr;
    pair<intl,intl> fun = {0ll,(intl)1e18};
};
intl Eval(pair<intl,intl> fun, intl x){
    return fun.first*x+fun.second;
}
void Update(nodo * & nod, pair<intl,intl> fun, int l = 0, int r = 1<<20){
    //cout<<"Update en "<<l<<" a "<<r<<endl;
    int m = (l+r)/2;
    if(!nod) nod = new nodo();
    bool ini = (Eval(fun,l)<Eval(nod->fun,l));
    bool mid = (Eval(fun,m)<Eval(nod->fun,m));
    if(mid) swap(nod->fun,fun);
    if(l==r) return;
    if(ini==mid) Update(nod->r,fun,m+1,r);
    else Update(nod->l,fun,l,m);
}
intl Query(nodo * nod, int x, int l = 0, int r = 1<<20){
    if(l>x or r<x or !nod) return 1e18;
    if(l==r) return Eval(nod->fun,x);
    //cout<<l<<" a "<<r<<" tiene "<<nod->fun<<endl;
    int m = (l+r)/2;
    return min({Eval(nod->fun,x),Query(nod->l,x,l,m),Query(nod->r,x,m+1,r)});
}
intl s[300000],f[300000];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,x;
    cin>>n>>x;
    nodo * raiz = nullptr;
    Update(raiz,{intl(x),0ll});
    //cout<<"input ok"<<endl;
    forn(i,n) cin>>s[i];
    forn(i,n) cin>>f[i];
    //cout<<"input ok"<<endl;
    forn(i,n-1){
        intl mint = Query(raiz,s[i]);
        Update(raiz,{f[i],mint});
    }
    intl res = Query(raiz,s[n-1]);
    cout<<res<<endl;
    return 0;
}

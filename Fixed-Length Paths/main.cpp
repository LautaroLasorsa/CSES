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
    nodo *l = nullptr, * r = nullptr;
    int cant = 0;
    int Query(int lq, int rq, int lp = 0, int rp=1<<19){
        /*DBG(lq);
        DBG(rq);
        DBG(lp);
        DBG(rp);
        DBG(cant);*/
        if(lq<=lp and rp<=rq)
        {
            return cant;
        }
        if(lq>rp or rq<lp) return 0;
        int res = 0;
        int mp = (lp+rp)/2;
        if(l) res+=l->Query(lq,rq,lp,mp);
        if(r) res+=r->Query(lq,rq,mp+1,rp);
        return res;
    }
};
void Update(nodo * & nod, int x, int v, int lp = 0, int rp = 1<<19){
    if(x<lp or x>rp) return ;
    if(!nod) nod = new nodo();
    nod->cant+=v;
    if(lp==rp) return;
    //DBG(lp);
    //DBG(rp);
    //cout<<"x"<<endl;
    int mp = (lp+rp)/2;
    Update(nod->l,x,v,lp,mp);
    Update(nod->r,x,v,mp+1,rp);
}

struct stree{
    nodo * raiz = new nodo();
    int offset = -(1<<18);
    void Add(int x, int v = 1){
        Update(raiz,x-offset,v);
    }
    int Query(int lq, int rq){
        return raiz->Query(lq-offset,rq-offset);
    }
};

int k1, k2;
intl res = 0;
void QueryMix(nodo * nod, stree & st, int off, int l = 0, int r = (1<<19)){
    if(!nod) return;
    if(l==r){
        res += st.Query(k1-l-off,k2-l-off)*1ll*nod->cant;
        return;
    }
    int m = (l+r)/2;
    QueryMix(nod->l,st,off,l,m);
    QueryMix(nod->r,st,off,m+1,r);
}
void Traspaso(nodo * nod, stree & st, int off, int l = 0, int r = (1<<19)){
    if(!nod) return;
    if(l==r){
        st.Add(l+off,nod->cant);
        return;
    }
    int m = (l+r)/2;
    Traspaso(nod->l,st,off,l,m);
    Traspaso(nod->r,st,off,m+1,r);
}
bool Comp(const stree & sta, const stree & stb){
    return sta.raiz->cant > stb.raiz->cant;
}
const int maxn = 3e5;
vector<int> adj[maxn];
stree DFS(int nod, int pad=-1){
    vector<stree> hs;
    stree loc;
    loc.Add(0);
    hs.push_back(loc);
    //DBG(nod);
    for(auto x : adj[nod])
        if(x!=pad)
        {
            stree st = DFS(x,nod);
            st.offset++;
            hs.push_back(st);
        }
    //DBG(nod);
    sort(hs.begin(),hs.end(),Comp);
    //DBG(hs.size());
    forsn(i,1,hs.size()){
        //DBG(hs[i].raiz->cant);
        QueryMix(hs[i].raiz,hs[0],hs[i].offset);
        Traspaso(hs[i].raiz,hs[0],hs[i].offset);
    }
    return hs[0];
}
int main()
{
    //cin.tie(0);
    //cin.sync_with_stdio(0);
    int n; cin>>n;
    cin>>k1; k2 = k1;
    cin>>k2;
    /*DBG(k1);
    DBG(k2);*/
    forn(i,n-1){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //forsn(i,1,5){
    //    k1 = k2 = i;
    //    res = 0;
    DFS(1);
    cout<<res<<endl;
    //}*/
    return 0;
}
/*
7
1 2
1 3
2 4
2 5
3 6
3 7


*/

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
struct nodo{
    int r,l,v;
    nodo(){
        l = r = -1;
        v = 0;
    }
};
const int maxn = 3e5, largo = 2e7, maxv = int(1<<30)-1;
nodo st[largo];
int sal[maxn], N, Q,stsize=1, raiz = 0;
int Query(int i, int & ini, int & fin, int l, int r){
    if(i==-1) return 0;
    if(ini<=l && r <= fin) return st[i].v;
    if(ini>r || fin<l) return 0;
    int m = (l+r)/2;
    return Query(st[i].l,ini,fin,l,m)+ Query(st[i].r,ini,fin,m+1,r);
}
int Update(int n, int l, int r, int & x, int & v){
    if(n == -1) n = stsize, stsize++;
    if(l == r){
        st[n].v += v;
        return n;
    }
    int m = (l+r)/2;
    if(x<=m) st[n].l = Update(st[n].l,l,m,x,v);
    else st[n].r = Update(st[n].r,m+1,r,x,v);
    st[n].v = 0;
    if(st[n].l!=-1) st[n].v+=st[st[n].l].v;
    if(st[n].r!=-1) st[n].v+=st[st[n].r].v;
    return n;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>N>>Q;
    int add = 1, rev = -1;
    forn(i,N){
        cin>>sal[i+1];
        raiz = Update(raiz,0,maxv,sal[i+1],add);
    }
    forn(i,Q){
        char t;
        int a,b;
        cin>>t>>a>>b;
        if(t == '?'){
            cout<<Query(raiz,a,b,0,maxv)<<"\n";
        }else{
            Update(raiz,0,maxv,sal[a],rev);
            sal[a] = b;
            Update(raiz,0,maxv,sal[a],add);
        }

    }
	return 0;
}

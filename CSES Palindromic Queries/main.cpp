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
const int tam = 2;
int ps[tam] = {int(1e9) + 7, int(1e9) +9};
int b = 5500;
struct Hash{
    int h[tam];
    intl ac[tam];
    Hash(){
        forn(i,tam) h[i] = 0, ac[i] = 1;
    }
    Hash(char c){
        forn(i,tam) h[i] = c, ac[i] = b;
    }
};
Hash nulo;
Hash operator +(const Hash & a, const Hash & b){
    Hash c('a');
    forn(i,tam){
        c.h[i] = (b.h[i]*a.ac[i] + a.h[i])%ps[i];
        c.ac[i] = b.ac[i] * a.ac[i] % ps[i];
    }
    return c;
}
bool operator ==(const Hash & a, const Hash & b){
    forn(i,tam) if(a.h[i]!=b.h[i]) return false;
    return true;
}
const int largo = 1<<19;
pair<Hash,Hash> st[largo];
int L[largo], R[largo];
pair<Hash,Hash> op(const pair<Hash,Hash> a, const pair<Hash,Hash> b){
    return {a.first+b.first,b.second+a.second};
}
pair<Hash,Hash> Query(int nod, int & lq, int & rq){
    if(lq>R[nod] || rq<L[nod]) return {nulo,nulo};
    if(lq<=L[nod] && R[nod] <= rq) return st[nod];
    return op(Query(nod*2,lq,rq),Query(nod*2+1,lq,rq));
}
void Update(int p, char c){
    p+=largo/2;
    st[p] = {Hash(c),Hash(c)};
    while(p/=2) st[p] = op(st[p*2],st[p*2+1]);
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m; string s;
    cin>>n>>m>>s;
    forn(i,n) st[i+largo/2+1] = {Hash(s[i]),Hash(s[i])};
    forsn(i,largo/2,largo) L[i] = R[i] = i-largo/2;
    dforn(i,largo/2) L[i] = L[i*2], R[i] = R[i*2+1], st[i] = op(st[i*2],st[i*2+1]);
    forn(i,m){
        int t;
        cin>>t;
        if(t==1){
            int p;
            string in;
            cin>>p>>in;
            Update(p,in[0]);
        }else{
            int l,r;
            cin>>l>>r;
            auto p = Query(1,l,r);
            if(p.first == p.second) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}


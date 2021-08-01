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
const int largo = 1<<19;
map<int,int> id;
vector<int> ran[300000];
int st[largo],L[largo],R[largo], res[2][300000];
int Query(int nod, int lq, int rq){
    if(lq<=L[nod] && R[nod] <= rq) return st[nod];
    if(lq>R[nod] || rq<L[nod]) return 0;
    return Query(nod*2,lq,rq) + Query(nod*2+1,lq,rq);
}
void Update(int pos){
    pos+=largo/2;
    st[pos]++;
    while(pos/=2) st[pos]++;
}
bool Comp(vector<int>  a, vector<int> b){
    a[0]*=-1;
    b[0]*=-1;
    return a<b;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    forsn(i,largo/2,largo) L[i] = R[i] = i-largo/2;
    dforn(i,largo/2) L[i] = L[i*2], R[i] = R[i*2+1];
    int n; cin>>n;
    forn(i,n){
        int a,b;
        cin>>a>>b;
        id[b] = 0;
        ran[i] = {a,b,i};
    }
    int v = 0;
    for(auto &k : id) k.second = ++v;
    forn(i,n)  ran[i][1] = id[ran[i][1]];
    sort(ran,ran+n,Comp);
    forn(i,n){
        res[0][ran[i][2]] = Query(1,0,ran[i][1]);
        Update(ran[i][1]);
    }
    memset(st,0,sizeof(st));
    dforn(i,n){
        res[1][ran[i][2]] = Query(1,ran[i][1],largo/2-1);
        Update(ran[i][1]);
    }
    forn(i,n) cout<<(bool)res[0][i]<<" ";
    cout<<"\n";
    forn(i,n) cout<<(bool)res[1][i]<<" ";

    return 0;

}

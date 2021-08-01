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
int L[largo], R[largo];
intl st[largo], lz[largo];
intl Eval(int i){ return st[i] + lz[i];}
const intl inf = 1e18;
void Propagar(int i){
    lz[i*2]+= lz[i];
    lz[i*2+1]+= lz[i];
    st[i] = max(Eval(i*2),Eval(i*2+1));
    lz[i] = 0;
}
intl Query(int nod, int lq, int rq){
    if(lq<=L[nod] && R[nod] <= rq) return Eval(nod);
    if(lq>R[nod] || rq<L[nod]) return -inf;
    Propagar(nod);
    return max(Query(nod*2,lq,rq),Query(nod*2+1,lq,rq));
}
void Update(int nod, int lq, int rq, intl v){
    //cout<<nod<<" >> "<<lq<<" "<<rq<< " : "<<L[nod] << "  a " << R[nod]<<endl;
    if(rq<L[nod]) return;
    if(lq>R[nod]) return;
    if(lq <= L[nod] && R[nod] <= rq){
        lz[nod]+=v;
        //cout<<"Actualizo en "<<L[nod]<<" a "<<R[nod]<<endl;
        return;
    }
    Update(nod*2,lq,rq,v);
    Update(nod*2+1,lq,rq,v);
    Propagar(nod);
}
intl vec[largo/2];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m; cin>>n>>m;
    forsn(i,1,n+1){
        cin>>vec[i];
        st[i+largo/2] = st[i-1+largo/2] + vec[i];
    }
    forsn(i,largo/2,largo) L[i] = R[i] = i-largo/2;
    dforn(i,largo/2) L[i] = L[i*2], R[i] = R[i*2+1], Propagar(i);
    //forsn(i,1,n+1) cout<<Query(1,i,i)<<" ";
    //cout<<endl;
    forn(i,m){
        int t; cin>>t;
        if(t==1){
            int k,u; cin>>k>>u;
            Update(1,k,n,u-vec[k]);
            vec[k] = u;
            //forsn(i,1,n+1) cout<<Query(1,i,i)<<" ";
            //cout<<endl;
        }else{
            int lq,rq; cin>>lq>>rq;
            cout<<Query(1,lq-1,rq)-Query(1,lq-1,lq-1)<<"\n";
            //cout<<endl;
        }
    }
    return 0;
}

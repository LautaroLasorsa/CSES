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
const int largo = 1<<19;
struct nodo{
    intl pref, subf, val, tot;
    void Update(intl v){
        tot = v;
        pref = subf = val = max(v,intl(0));
    }
    nodo(){
        pref = subf = tot = val = 0;
    }
};
nodo Opp(nodo  a, nodo  b){
    nodo c;
    c.pref = max(a.pref,a.tot+b.pref);
    c.subf = max(b.subf,b.tot+a.subf);
    c.tot = a.tot+b.tot;
    c.val = max(max(a.val,max(a.subf+b.pref,b.val)),max(c.subf,c.pref));
    return c;
}
nodo st[largo];
int L[largo], R[largo], ini, fin, N, Q;
void Update(int n, int v){
    n+=largo/2;
    st[n].Update(v);
    while(n/=2) st[n] = Opp(st[n*2],st[n*2+1]);
}
nodo Query(int i){
    if(ini<=L[i] && R[i] <=fin) return st[i];
    if(R[i]<ini || L[i] <fin) return nodo();
    return Opp(Query(i*2),Query(i*2+1));
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    forsn(i,largo/2,largo) L[i] = R[i] = i-largo/2;
    cin>>N>>Q;
    forn(i,largo) st[i] = nodo();
    forn(i,N){
        int v;cin>>v;
        st[i+largo/2].Update(v);
    }
    dforn(i,largo/2){
        L[i] = L[i*2];
        R[i] = R[i*2+1];
        st[i] = Opp(st[i*2],st[i*2+1]);
    }
    forn(i,Q){
        int k,x;
        cin>>k>>x;
        k--;
        Update(k,x);
        cout<<st[1].val<<"\n";
    }
	return 0;
}

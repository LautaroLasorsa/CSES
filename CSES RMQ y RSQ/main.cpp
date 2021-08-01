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
intl N, Q, st[largo], L[largo], R[largo], ini, fin;
intl neutro =0;
intl Opp(intl i, intl j){
    return i+j;//i^j;//min(i,j);
}
intl Query(int i){
    if(ini<=L[i] && R[i]<=fin) return st[i];
    if(ini>R[i] || fin<L[i]) return neutro;
    return Opp(Query(i*2),Query(i*2+1));
}
void Update(int i, intl v){
    i+=largo/2;
    st[i]+=v;
    while(i/=2) st[i] = Opp(st[i*2],st[i*2+1]);
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    forsn(i,largo/2,largo) L[i] = R[i] = i-largo/2, st[i] = neutro;
    cin>>N>>Q;
    dforn(i,largo/2) L[i] = L[i*2], R[i] = R[i*2+1];//, st[i] = Opp(st[i*2],st[i*2+1]);
    forn(i,N){
        int v; cin>>v;
        Update(i+1,v);
        Update(i+2,-v);
    }
    ini = 0;
    forn(i,Q){
        int t; cin>>t;
        if(t == 1){
            int a,b,u;
            cin>>a>>b>>u;
            Update(a,u);
            Update(b+1,-u);
            continue;
            /*int p,v;cin>>p>>v;
            Update(p,v);
            continue;*/
        }
        cin>>fin;
        cout<<Query(1)<<"\n";
    }
	return 0;
}

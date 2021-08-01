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
int st[largo], N, in[largo];
int Query(int i, int acum){
    //cout<<i<<" : "<<acum<<" | "<<i-largo/2<<" || "<<st[i*2]<<" ||| "<<(st[i*2]>=acum)<<endl;
    if(i>largo/2)return i-largo/2;
    if(st[i*2]>=acum) return Query(i*2,acum);
    else return Query(i*2+1,acum-st[i*2]);
}
int Update(int p){
    p+=largo/2;
    st[p] = 0;
    while(p/=2) st[p]--;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>N;
    forsn(i,1,N+1){
        st[i+largo/2] = 1;
        cin>>in[i];
    }
    //cout<<"k"<<endl;
    dforn(i,largo/2)st[i] = st[i*2] + st[i*2+1];
    //cout<<"k2"<<endl;
    forn(i,N){
        int p; cin>>p;
        int r = Query(1,p);
        Update(r);
     //   DBG(r);
        cout<<in[r]<<" ";
    }
	return 0;
}

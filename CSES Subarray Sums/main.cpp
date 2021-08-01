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
map<intl,int> mapa;
int N; intl X, acum = 0, Res = 0;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>N;
    X = N;
    mapa[0]++;
    forn(i,N){
        int v;cin>>v;
        acum = ((acum+v)%X +2*X)%X;;
        Res+=mapa[acum];
        mapa[acum]++;
    }
    cout<<Res<<endl;
	return 0;
}

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
const int maxn = 5e5, lev = 31;
bitset<maxn> raiz, visto;
int cic[maxn], pos[maxn], lar[maxn], nex[maxn][lev], nc = 0, res[maxn], llega[maxn], dist[maxn];
int N,Q;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>N>>Q;
    forsn(i,1,N+1){
        cin>>nex[i][0];
    }
    forsn(k,1,lev){
        forsn(i,1,N+1){
            nex[i][k] = nex[nex[i][k-1]][k-1];
        }
    }
    forn(i,Q){
        int x,k;
        cin>>x>>k;
        dforn(j,lev){
            if(k&(1<<j))
                x = nex[x][j];
        }
        cout<<x<<"\n";
    }
	return 0;
}

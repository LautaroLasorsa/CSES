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
const int maxn = 1e5+10;
vector<int> Dir[maxn],Rev[maxn];
bitset<maxn> visto;
int topo[maxn], ori=0, N,M, comp[maxn];
void Order(int i){
    if(visto[i]) return;
    visto[i] = true;
    for(auto k : Dir[i]) Order(k);
    topo[ori] = i;
    ori++;
}
void Comp(int n, int c){
    if(comp[n]!=0) return;
    comp[n]=c;
    for(auto k : Rev[n]) Comp(k,c);
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
	cin>>N>>M;
	forn(i,M){
        int a,b;cin>>a>>b;
        Dir[a].push_back(b);
        Rev[b].push_back(a);
	}
    forsn(i,1,N+1)Order(i);
    int c = 1;
    for(int i = 0;i<N;i++){
        int n = topo[ori-i-1]; //cout<<i<<" : "<<n<<endl;
        if(comp[n]==0) Comp(n,c), c++;
    }
    cout<<c-1<<"\n";
    forsn(i,1,N+1)cout<<comp[i]<<((i==N)?"\n":" ");

}

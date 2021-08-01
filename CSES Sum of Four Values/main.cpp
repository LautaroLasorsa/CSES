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
map<intl,vector<pair<int,int> > > vals;
intl in[2000], X;
int N;
bool OK(pair<int,int> & a, pair<int,int> & b){
    if(a.first == b.first) return false;
    if(a.first == b.second) return false;
    if(a.second == b.first) return false;
    if(a.second == b.second) return false;
    return true;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
	cin>>N>>X;
	forn(i,N)cin>>in[i];
	forn(i,N)
        forsn(j,i+1,N)
            vals[in[i]+in[j]].push_back({i,j});
    forn(i,N)
        forsn(j,i+1,N)
        {
            intl s = X-in[i]-in[j];
            pair<int,int> p = {i,j};
            for(auto & k : vals[s]){
                if(OK(k,p)){
                    cout<<i+1<<" "<<j+1<<" "<<k.first+1<<" "<<k.second+1<<"\n";
                    return 0;
                }
            }
        }
    cout<<"IMPOSSIBLE\n";
	return 0;
}

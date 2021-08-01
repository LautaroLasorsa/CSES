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
int dp[2000][2000], add[2000][2000];
string in[2000];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N,M;cin>>N>>M;
    forn(i,N)cin>>in[i];
    dforn(i,N)
        dforn(j,M){
            if(in[i][j] == '.'){
                if(j == M-1) dp[i][j] = 1;
                else dp[i][j] = dp[i][j+1]+1;
            }
        }
    forn(i,N){

    }
}

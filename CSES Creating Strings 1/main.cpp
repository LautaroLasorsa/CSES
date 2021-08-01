#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i = 0;i<int(n);i++)
#define dforn(i,n) for(int i = int(n)-1;i>0;i--)
#define forsn(i,s,n) for(int i = int(s);i<int(n);i++)
#define dforsn(i,s,n) for(int i = int(n)-1;i>=int(s);i--)
#define DBG(x)do{cout<<#x<<" = "<<x<<endl;}while(false)
#define get(mask,i) ((mask)&(1<<(i)))
#define sett(mask,i) ((mask)|(1<<(i)))

/*template<class T> ostream  & operator<<(vector<T> v, ostream & out){
    out<<"[";
    for(auto k : v)out<<k<<" ";
    out<<"]";
    out<<endl;
    return out;
}*/

typedef long long intl;
int adj[21][21];
int dp[1<<21][20], N, M, mod = 1e9+7;
//bitset<1<<21> visto[21];
/*int TSP(int mask, int i){
    if(mask == (1<<(N))-1) return i == N-1;
    if(visto[i][mask]) return dp[mask][i];
    visto[i][mask] = true;
    dp[mask][i] = 0;
    forsn(j,1,N){
        if(!(get(mask,j)) && adj[i][j]){
            dp[mask][i] = (dp[mask][i]+intl(TSP(sett(mask,j),j))*adj[i][j])% mod;
        }
    }
    return dp[mask][i];
}*/
vector<string> res;
set<char> S;
int siz;
void Generator(string & s){
    if(s.size() == siz){
        res.push_back(s);
        return;
    }
    int l = s.size();
    s+=' ';
    for(auto k : S){
        s[l] = k;
        Generator(s);
    }
    s.pop_back();
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    string in;
    cin>>in;
    sort(in.begin(),in.end());
    do{
        res.push_back(in);
    }while(next_permutation(in.begin(),in.end()));
    cout<<res.size()<<"\n";
    for(auto k : res)cout<<k<<"\n";
}

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
pair<intl,int> in[6000];
int N;
intl X;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>N>>X;
    forn(i,N){
        cin>>in[i].first;
        in[i].second = i;
    }
    sort(in,in+N);
    forn(i,N)
        forsn(j,i+1,N){
            intl s = X-in[i].first - in[j].first;
           // cout<<i<<" , "<<j<<" , "<<s<<endl;
            pair<intl,int> p ={s,0};
            int pos = lower_bound(in,in+N,p)-in;
            if(pos!=i && pos!=j && in[pos].first == s){
                cout<<in[i].second+1<<" "<<in[j].second+1<<" "<<in[pos].second+1<<"\n";
                return 0;
            }
        }
    cout<<"IMPOSSIBLE\n";
	return 0;
}

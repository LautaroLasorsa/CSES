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
bitset<maxn> ok;
int N,X;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    ok[0] = 1;
    cin>>N;
    forn(i,N){
        cin>>X;
        ok |= ok<<X;
    }
    cout<<ok.count()-1<<"\n";
    bool emp = false;
    forsn(i,1,maxn){
        if(ok[i]){
            if(emp) cout<<" ";
            else emp = true;
            cout<<i;
        }
    }
    cout<<"\n";
	return 0;
}

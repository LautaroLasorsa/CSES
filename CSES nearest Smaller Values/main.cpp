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
int st[largo], val,N;
int Query(int i){
    if(i>=largo/2) return i-largo/2;
    if(st[i]>=val) return 0;
    if(st[i*2+1]<val) return Query(i*2+1);
    else return Query(i*2);
}
void Update(int p, int v){
    p+=largo/2;
    st[p]=v;
    while(p/=2) st[p] = min(st[p*2],st[p*2+1]);
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    forn(i,largo) st[i] = 2e9;
    cin>>N;
    forn(i,N){
        cin>>val;
        cout<<Query(1)<<" ";
        Update(i+1,val);
    }
	return 0;
}

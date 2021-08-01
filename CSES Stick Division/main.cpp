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
template<class T, class U> ostream & operator<<(ostream & out, pair<T,U> & p){
	out<<"[ "<<p.first<<" , "<<p.second<<" ] ";
	return out;
}
typedef long long intl;
priority_queue<intl,vector<intl>,greater<intl> > PQ;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;intl x, c = 0;cin>>x>>n;
    forn(i,n){
        int v;cin>>v;
        PQ.push(v);
    }
    while(PQ.size()>1){
        int p = PQ.top();
        PQ.pop();
        int q = PQ.top();
        PQ.pop();
        int pq = p+q;
        c+=pq;
        PQ.push(pq);
    }
    cout<<c<<"\n";
	return 0;
}

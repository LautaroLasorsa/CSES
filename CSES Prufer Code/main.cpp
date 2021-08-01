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
priority_queue<int,vector<int>,greater<int> > PQ;
const int maxn = 3e5;
int in[maxn], grad[maxn], N;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>N;
    forn(i,N-2){
        cin>>in[i];
        grad[in[i]]++;
    }
    forsn(i,1,N+1)if(grad[i]==0)PQ.push(i);
    forn(i,N-2){
        int u = PQ.top(), v = in[i];
        PQ.pop();
        cout<<u<<" "<<v<<"\n";
        grad[v]--;
        if(grad[v]==0) PQ.push(v);
    }
    cout<<PQ.top()<<" ";
    PQ.pop();
    cout<<PQ.top()<<"\n";
	return 0;
}

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
#define get(mask,i) (bool(mask&(1<<(i))))
#define set(mask,i) (mask|=(1<<(i)))
#define invert(mask,i) (mask^=(1<<(i)))
#define popcount(mask) (__builtin_popcount(mask))
template<class T> ostream & operator<<(ostream & out, vector<T> & v){
	out<<"[";
	for(auto k : v) out<<k<<" ";
	out<<"]"<<"\n";
	return out;
}
template<class T> ostream & operator<<(ostream & out, set<T>  s){
	out<<"{";
	for(auto k : s) out<<k<<" ";
	out<<"}"<<"\n";
	return out;
}

template<class T, class U> ostream & operator<<(ostream & out, pair<T,U>  p){
	out<<"[ "<<p.first<<" , "<<p.second<<" ] ";
	return out;
}
template<class T, class U> istream & operator>>(istream & in, pair<T,U> & p){
	in>>p.first>>p.second;
	return in;
}


typedef long long intl;
intl a[22],k,n, res = 0, mask;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>k;
    forn(i,k) cin>>a[i];
    mask = (1<<k);
    forsn(i,1,mask){
        intl lv = n;
        forn(j,k) if(get(i,j)) lv /= a[j];
        if(popcount(i)&1) res+= lv;
        else res-= lv;
    }
    cout<<res<<endl;
    return 0;
}

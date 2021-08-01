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

template<class T, class U> pair<T,U> operator +(const pair<T,U> & a, const pair<T,U> & b){
	return {a.first+b.first,a.second+b.second};
}
template<class T, class U> pair<T,U> operator -(const pair<T,U> & a, const pair<T,U> & b){
	return {a.first-b.first,a.second-b.second};
}



typedef long long intl;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, r[200];
    cin>>n;
    forn(i,n)cin>>r[i];
    long double res = 0;
    forn(i,n) forsn(j,i+1,n){
        long double tot = r[i] * r[j];
        long double fav = 0;
        forsn(k,1,r[i]+1) fav += min(k-1,r[j]);
        res += fav/tot;
    }
    cout<<setprecision(6)<<fixed<<res<<"\n";
	return 0;
}

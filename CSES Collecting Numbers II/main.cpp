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
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m, r = 1;
    cin>>n>>m;
    vector<int> v(n+1), p(n+1);
    forn(i,n){
        cin>>v[i+1];
        p[v[i+1]] = i+1;
    }
    forsn(i,2,n+1) if(p[i]<p[i-1]) r++;
    //DBG(r);
    forn(i,m){
        int a,b;
        cin>>a>>b;
        int & va = v[a], & vb = v[b];
        //DBG(va);
        //DBG(vb);
        //DBG(p);
        if(va>1 && p[va]<p[va-1]) r--;
        if(va<n && p[va]>p[va+1]) r--;

        if(vb>1 && vb!= va+1 && p[vb]<p[vb-1]) r--;
        if(vb<n && vb!= va-1 && p[vb]>p[vb+1]) r--;

        swap(p[va],p[vb]);
        swap(va,vb);
        //DBG(va);
        //DBG(vb);
        //DBG(p);
        if(va>1 && p[va]<p[va-1]) r++;
        if(va<n && p[va]>p[va+1]) r++;

        if(vb>1 && vb!= va+1&& p[vb]<p[vb-1]) r++;
        if(vb<n && vb!= va-1 && p[vb]>p[vb+1]) r++;

        cout<<r<<"\n";
        //DBG(v);
    }
    return 0;
}

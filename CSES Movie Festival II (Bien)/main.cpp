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
#define TAM_MASK 1
#define get(mask,i) ((mask>>(TAM_MASK*(i)) & ( (1<<TAM_MASK)-1)))
#define set(mask,i,v)  ( ((mask & ~( ( (1<<TAM_MASK)-1) << (TAM_MASK*(i)) )) | (v<<(TAM_MASK * (i))) ))
#define popcount(mask) (__builtin_popcount(mask))
#define endl '\n'
#define ALL(x) x.begin(),x.end()
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
    int n,k, res;
    cin>>n>>k; res = n;
    multiset<int> s;
    vector<pair<int,int> > in;
    forn(i,n){
        int a,b;
        cin>>a>>b;
        in.push_back({a,b-1});
    //    in.push_back({b,-1});
    }
    sort(in.begin(),in.end());

    //DBG(in);
    for(auto x : in){
        while(s.size() and *s.begin()<x.first){
            s.erase(s.begin());
        }
        //DBG(s);
        if(s.size()==k){
            if(x.second<*s.rbegin()){
                s.erase(--s.end());
                s.insert(x.second);
            }
            res--;
        }
        else s.insert(x.second);
    }
    cout<<res<<endl;
    return 0;
}

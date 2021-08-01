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
#define set(mask,i,v)  ( ((mask & ~( ( (1<<TAM_MASK)-1) << (TAM_MASK*(i)) )) | (v<<(TAM_MASK * (i))) )
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
const int maxn = 3e5;
vector<int> comp[maxn];
int id[maxn];
vector<pair<int,int> > ups[maxn];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m,q;
    cin>>n>>m>>q;
    forsn(i,1,n+1) comp[i] = {i}, id[i] = i, ups[i] = {{0,i}};
    forn(i,m){
        int a,b;
        cin>>a>>b;
        a = id[a], b = id[b];
        if(a==b) continue;
        if(comp[a].size()<comp[b].size()) swap(a,b);
        for(auto x : comp[b]){
            id[x] = a;
            comp[a].push_back(x);
            ups[x].push_back({i+1,a});
        }
    }
    forn(i,q){
        int a,b;
        cin>>a>>b;
        if(id[a]!=id[b]) cout<<-1<<endl;
        else if(a==b) cout<<0<<endl;
        else{
            int l = 0, r = m;
            //DBG(ups[a]);
            //DBG(ups[b]);
            while(r-l>1){
                int mid = (l+r)/2;
                pair<int,int> p = {mid,1e9};
                auto ida = upper_bound(ups[a].begin(),ups[a].end(),p);
                auto idb = upper_bound(ups[b].begin(),ups[b].end(),p);
                ida--, idb--;
                if(ida->second == idb->second)
                    r = mid;
                else l = mid;
            }
            cout<<r<<endl;
        }

    }
    return 0;
}
/**
3 2 2
1 2
1 3
1 2
1 3

*/

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
typedef vector<vector<intl> > mat;
intl neutro = 4e18, mod = 1e9+7;
int N,M,K;
mat operator *(mat a, mat b){
    mat c(N,vector<intl>(N,neutro));
    forn(i,N)
        forn(j,N)
            forn(k,N)
                c[i][j] = min(c[i][j],a[i][k]+b[k][j]);
    return c;
}
mat BinPow(mat base, int e){
    if(e==1) return base;
    if(e&1) return base * BinPow(base,e-1);
    mat base2 = BinPow(base,e/2);
    return base2*base2;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>N>>M>>K;
    mat adj(N,vector<intl>(N,neutro));
    forn(i,M){
        intl a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        adj[a][b] = min(adj[a][b],c);
    }
    intl res = BinPow(adj,K)[0][N-1];
    if(res == neutro) res = -1;
    cout<<res<<"\n";
	return 0;
}
/**
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
typedef vector<vector<intl> > mat;
intl neutro = -1, mod = 1e9+7;
int N,M,K;
intl Op(intl a, intl b){
    if(a==-1) return b;
    if(b==-1) return a;
    return min(a,b);
}
intl Op2(intl a, intl b){
    if(a==-1 || b==-1) return -1;
    return a+b;
}
mat operator *(mat a, mat b){
    mat c(N,vector<intl>(N,neutro));
    forn(i,N)
        forn(j,N)
            forn(k,N)
                c[i][j] = Op(c[i][j],Op2(a[i][k],b[k][j]));
    return c;
}
mat BinPow(mat base, int e){
    if(e==1) return base;
    if(e&1) return base * BinPow(base,e-1);
    mat base2 = BinPow(base,e/2);
    return base2*base2;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>N>>M>>K;
    mat adj(N,vector<intl>(N,neutro));
    forn(i,M){
        intl a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        adj[a][b] = Op(adj[a][b],c);
    }
    intl res = BinPow(adj,K)[0][N-1];
    cout<<res<<"\n";
	return 0;
}
**/

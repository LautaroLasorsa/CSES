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
typedef vector<vector<intl> > mat;
const intl mod = 1e9+7;
mat recu(6,vector<intl>(6,0));
mat operator * (mat a, mat b){
    int la = a.size();
    int lc = a[0].size();
    int lb = b[0].size();

    mat c(la,vector<intl>(lb,0));
    forn(i,la)
        forn(j,lb)
            forn(k,lc)
                c[i][j] = ( c[i][j] + a[i][k] * b[k][j] ) % mod;
    return c;
}
mat BinPow(mat b, intl e){
    if(e==1) return b;
    if(e&1) return BinPow(b,e-1) * b;
    mat bb = BinPow(b,e/2);
    return bb*bb;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    intl n; cin>>n;
    forn(i,6){
        if(i<5) recu[i][i+1] = 1;
        recu[5][i] = 1;
    }
    mat fin = BinPow(recu,n);
    mat vec = {{0,0,0,0,0,1}};
    mat res = vec*fin;
    cout<<res[0][5]<<endl;
    //DBG(res[0]);
    return 0;
}

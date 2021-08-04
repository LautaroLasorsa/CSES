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
/**
Importante, el problema seguramente sale con las 3 aproximaciones posibles
Alien trick
Knuth
D&C


Haremos todas :D
*/
/// Algo Común a los 3 enfoques
const int maxn = 3005;
intl cost[maxn][maxn];
int in[maxn];
/// Parte de Alien Trick
struct pos{
    intl val = 0, segs = 1;
    pos(intl v = 0){
        val = v;
    }
};
bool operator<(const pos & a, const pos & b){
    if(a.val!=b.val) return a.val<b.val;
    return a.segs<b.segs;
}
pos operator +(const pos & a, const pos & b){
    pos c;
    c.val  = a.val + b.val;
    c.segs = a.segs+b.segs;
    return c;
}
pos dp[maxn];
pos Intento(intl m, int n){
    dp[0].val = 0;
    dp[0].segs = 0;
    forsn(i,1,n+1) dp[i] = pos(1e18);
    forsn(i,0,n)
        forsn(j,i+1,n+1)
        {
            dp[j] = min(dp[j],dp[i]+pos(cost[i][j-1]+m));
        }
    //cout<<"Con m = "<<m<<endl;
    //for(auto v : dp)
    //    cout<<v.val<<" "<<v.segs<<endl;
    return dp[n];
}
intl AlienTrick(int n, int k){
    intl l = -1, r = 1e16;
    while(r-l>1){
        intl m = (l+r)/2;
        pos ret = Intento(m,n);
        //cout<<ret.val<<" - "<<ret.segs<<endl;
        if(ret.segs>k) l = m;
        else r = m;
    }
    //DBG(r);
    pos ret = Intento(r,n);
    return ret.val - r*k;
}

///Parte de D&C
intl dp2[maxn][maxn];
intl g(int n, int k, int i){
    if(i>n) return 1e18;
    //cout<<n<<" , "<<k<<" , "<<i<<" = "<<dp2[i][k-1]<<" + "<<cost[i][n-1]<<endl;
    return dp2[i][k-1]+cost[i][n-1];
}
void Recur(int nini, int nfin, int k, int ini, int fin){
    if(nini>nfin) return;
    int n = (nini+nfin)/2;
    int ires = ini;
    dp2[n][k] = 1e18;
    forsn(i,ini,fin+1){
        intl v = g(n,k,i);
        if(v<dp2[n][k]){
            dp2[n][k] = v;
            ires = i;
        }
    }
    Recur(nini,n-1,k,ini,ires);
    Recur(n+1,nfin,k,ires,fin);
}
intl DandC(int n, int k){
    forsn(i,1,n+1)
        dp2[i][1] = cost[0][i-1];
    forsn(i,2,k+1)
        Recur(0,n+1,i,0,n+1);
    /*forn(i,n+1){
        forn(j,k+1) cout<<dp2[i][j]<<" ";
        cout<<endl;
    }*/
    return dp2[n][k];
}

/// Parte de Knuth
/// Reuso la función g y la matriz dp2 de D&C
int I[maxn][maxn];
intl Knuth(int n, int k){
    forsn(i,1,n+1){
        dp2[i][1] = cost[0][i-1];
        I[i][1] = 0;
    }
    forsn(a,2,k+1){
        I[n+1][a] = n;
        dforn(b,n+1){
            dp2[b][a] = 1e18;
            forsn(i,I[b][a-1],I[b+1][a]+1){
                intl v = g(b,a,i);
                if(v<dp2[b][a]){
                    dp2[b][a] = v;
                    I[b][a] = i;
                }
            }
        }
    }
    return dp2[n][k];
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    forn(i,n) cin>>in[i];
    /**
    Precalculo el costo de cada rango
    (que podría ser caro en si)
    */
    forsn(ini,0,n){
        intl sum = 0, psum = 0, c = 0;
        int piv = ini;
        forsn(fin,ini,n){
            sum+=in[fin];
            c+=1ll*in[fin]*(fin-piv);
            if(fin==ini) psum+=in[fin];
            else{
                while(piv<fin and sum>=2*psum){
                    c+=psum;
                    c-=(sum-psum);
                    piv++;
                    psum+=in[piv];
                }
            }
            cost[ini][fin] = c;
        }
    }
    /*forn(i,n+1){
        forn(j,n+1)
            cout<<cost[i][j]<<" ";
        cout<<endl;
    }*/
    /// Enfoque con Alien Trick
    ///cout<<AlienTrick(n,k)<<endl;

    /// Enfoque con D&C
    ///cout<<DandC(n,k)<<endl;


    /// Enfoque con Knuth
    cout<<Knuth(n,k)<<endl;
    return 0;
}

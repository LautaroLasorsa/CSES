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
intl in[40];
const int largo = 1<<20;
intl a[largo], b[largo];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    intl N,X;
    cin>>N>>X;
    forn(i,N)cin>>in[i];
    memset(a,-1,sizeof(a));
    memset(b,-1,sizeof(b));
    forn(i,largo){
        intl A = 0, B = 0;
        forn(j,20) if(get(i,j)){
            if(j>=N || A==-1) A = -1;else A+=in[j];
            if(j+20>=N || B==-1) B=-1;else B+=in[j+20];
        }
        //cout<<i<<" : "<<A<<" y "<<B<<endl;
        a[i]=A;
        b[i]=B;
    }
    sort(a,a+largo);
    sort(b,b+largo);
    intl res = 0;
    forn(i,largo){
        if(a[i]>=0 && a[i]<=X){
            intl k = X-a[i];
            res += upper_bound(b,b+largo,k)-lower_bound(b,b+largo,k);
            //cout<<i<<" : "<<a[i]<<endl;
        //    cout<<(upper_bound(b,b+largo,k)-b)<<endl;
        //    cout<<(lower_bound(b,b+largo,k)-b)<<endl;
        }
    }
    cout<<res<<"\n";
	return 0;
}

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
const int largo = 1<<21;
int L[largo], R[largo];
struct nodo{
    intl base,largo, cant, acum;
    intl Eval(){
        return base*largo + ((largo*(largo+1)/2))*cant + acum;
    }
};
nodo st[largo];
void Update(int i, intl base, intl cant, int l = -1, int r = -1){
    if(l == -1)l=L[i];
    if(r == -1)r=R[i];
   // cout<<"Update en "<<i<<" , "<<L[i]<<" a "<<R[i]<<" , "<<base<<" + "<<cant<<" ( "<<l<<" , "<<r<<" )"<<endl;
    if(l<=L[i] && R[i]<=r){
        st[i].base += base;
        st[i].cant += cant;
        return;
    }else if(l>R[i] || r<L[i])return;
    if(st[i].base!=0 || st[i].cant!=0){
        Update(i*2,st[i].base,st[i].cant);
        Update(i*2+1,st[i].base+st[i].cant*(st[i].largo/2),st[i].cant);
        st[i].cant = 0;
        st[i].base = 0;
    }
    int m = (L[i]+R[i])/2+1;
    int d = max(0,m-max(L[i],l));

    //cout<<L[i]<<" , "<<R[i]<<" prom : "<<m<<" y con "<<l<<" da "<<d<<endl;
    Update(i*2,base,cant,l,r);
    Update(i*2+1,base+d*cant,cant,l,r);
    st[i].acum = st[i*2].Eval() + st[i*2+1].Eval();
}
intl Query(int i, int ini, int fin){
    if(ini<=L[i] && R[i] <= fin){
    //    cout<<i<<" que va de "<<L[i]<<" a "<<R[i]<<" da "<<st[i].Eval()<<endl;
    //    DBG(st[i].base);
    //    DBG(st[i].largo);
    //    DBG(st[i].cant);
        return st[i].Eval();
    }
    if(ini>R[i] || fin<L[i]) return 0;
    if(st[i].base!=0 || st[i].cant!=0){
        Update(i*2,st[i].base,st[i].cant);
        Update(i*2+1,st[i].base+st[i].cant*(st[i].largo/2),st[i].cant);
        st[i].cant = 0;
        st[i].base = 0;
        st[i].acum = st[i*2].Eval() + st[i*2+1].Eval();
    }
    return Query(i*2,ini,fin) + Query(i*2+1,ini,fin);
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N, Q;cin>>N>>Q;
    forsn(i,1,N+1){
        cin>>st[i+largo/2].acum;
    }
    forsn(i,largo/2,largo){
        L[i] = R[i] = i-largo/2;
        st[i].largo = 1;
    }
    dforn(i,largo/2){
        L[i] = L[i*2];
        R[i] = R[i*2+1];
        st[i].acum = st[i*2].acum + st[i*2+1].acum;
        st[i].largo = R[i]-L[i]+1;
    }
    forn(i,Q){
        int t, a,b;
        cin>>t>>a>>b;
        if(t==1){
            Update(1,0,1,a,b);
        }else{
            cout<<Query(1,a,b)<<"\n";
        }
    }
    /*forsn(i,1,N+1){
        cout<<i<<" : "<<Query(1,i,i)<<endl;
    }*/
	return 0;
}
/*
5 6
4 2 3 1 7
2 1 5
1 1 5
2 1 5
1 3 5
2 1 5
2 3 5
*/

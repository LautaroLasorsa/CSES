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
typedef unsignlong long intl;
const int largo = 1<<19;
struct nodo{
    intl sum, add, pisa;
    int L,R;
    intl Calc(){
        if(pisa!=0){
            return (add+pisa)*(R-L+1);
        }
        return sum+add*(R-L+1);
    }
    void ini(int i){
        L = R = i;
        sum = add = pisa = 0;
    }
};
nodo st[largo];
void Agregar(int i, int ini, int fin, int x);
void Pisar(int i, int ini, int fin, int x){
    if(ini<=st[i].L && st[i].R<=fin){
        st[i].add = 0;
        st[i].pisa = x;
        return;
    }
    if(st[i].L>fin || st[i].R<ini){
        return;
    }
    if(st[i].pisa!=0){
        Pisar(i*2,0,largo,st[i].pisa);
        Pisar(i*2+1,0,largo,st[i].pisa);
    }
    if(st[i].add!=0){
        Agregar(i*2,0,largo,st[i].add);
        Agregar(i*2+1,0,largo,st[i].add);
    }
    Pisar(i*2,ini,fin,x);
    Pisar(i*2+1,ini,fin,x);
    st[i].pisa = st[i].add = 0;
    st[i].sum = st[i*2].Calc() + st[i*2+1].Calc();
}

void Agregar(int i, int ini, int fin, int x){
    if(ini<=st[i].L && st[i].R<=fin){
        st[i].add +=x;
        return;
    }
    if(st[i].L>fin || st[i].R<ini){
        return;
    }
    if(st[i].pisa!=0){
        Pisar(i*2,0,largo,st[i].pisa);
        Pisar(i*2+1,0,largo,st[i].pisa);
    }
    if(st[i].add!=0){
        Agregar(i*2,0,largo,st[i].add);
        Agregar(i*2+1,0,largo,st[i].add);
    }
    Agregar(i*2,ini,fin,x);
    Agregar(i*2+1,ini,fin,x);
    st[i].pisa = st[i].add = 0;
    st[i].sum = st[i*2].Calc() + st[i*2+1].Calc();
}

intl Query(int i, int & ini, int & fin){
    if(ini<=st[i].L && st[i].R<=fin){
       return st[i].Calc();
    }
    if(st[i].L>fin || st[i].R<ini){
        return 0;
    }
    if(st[i].pisa!=0){
        Pisar(i*2,0,largo,st[i].pisa);
        Pisar(i*2+1,0,largo,st[i].pisa);
    }
    if(st[i].add!=0){
        Agregar(i*2,0,largo,st[i].add);
        Agregar(i*2+1,0,largo,st[i].add);
    }
    st[i].pisa = st[i].add = 0;
    st[i].sum = st[i*2].Calc() + st[i*2+1].Calc();
    return Query(i*2,ini,fin) + Query(i*2+1,ini,fin);
}
int N,Q;
int main()
{
    cout<<"z"<<endl;
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout<<"k"<<endl;
    forsn(i,largo/2,largo) st[i].ini(i);
    cout<<"l"<<endl;
    cin>>N>>Q;

    forn(i,N){
        cin>>st[i+largo/2+1].sum;
    }
    dforn(i,largo/2){
        st[i].L = st[i*2].L;
        st[i].R = st[i*2+1].R;
        st[i].sum = st[i*2].sum + st[i*2+1].sum;
    }
    forn(i,Q){
        int t; cin>>t;
        if(t == 1){
            int a,b,x;
            cin>>a>>b>>x;
            Agregar(1,a,b,x);
        }else if(t == 2){
            int a, b, x;
            cin>>a>>b>>x;
            Pisar(1,a,b,x);
        }else{
            int a,b;
            cin>>a>>b;
            cout<<Query(1,a,b)<<"\n";
        }
    }
	return 0;
}

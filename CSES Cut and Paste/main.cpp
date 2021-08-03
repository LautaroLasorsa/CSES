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
template<class T> ostream & operator<<(ostream & out, vector<T> & v)
{
    out<<"[";
    for(auto k : v)
        out<<k<<" ";
    out<<"]"<<"\n";
    return out;
}
template<class T> ostream & operator<<(ostream & out, set<T>  s)
{
    out<<"{";
    for(auto k : s)
        out<<k<<" ";
    out<<"}"<<"\n";
    return out;
}

template<class T, class U> ostream & operator<<(ostream & out, pair<T,U>  p)
{
    out<<"[ "<<p.first<<" , "<<p.second<<" ] ";
    return out;
}
template<class T, class U> istream & operator>>(istream & in, pair<T,U> & p)
{
    in>>p.first>>p.second;
    return in;
}


typedef long long intl;
struct bloque
{
    int ini, fin;
    bool ignor = false;
    int pre = 0, pos = 0;
};

int nex = 0;
bloque mat[10000];
int tam = 0;
void PonerPre(int i, int ini,int fin)
{
    /*DBG(i);
    DBG(ini);
    DBG(fin);*/
    mat[tam].ini = ini;
    mat[tam].fin = fin;
    mat[tam].ignor = false;
    mat[tam].pos = i;
    mat[tam].pre = mat[i].pre;
    mat[mat[i].pre].pos = tam;
    mat[i].pre = tam;
    tam++;
}
string s;
void mostrar(){
    return;
    int i = 0;
    do{
        cout<<i<<": [ "<<mat[i].ini<<" , "<<mat[i].fin<<" ] "<<mat[i].pre<<" || "<<mat[i].pos<<endl;;
        i = mat[i].pos;
    }while(i!=0);
    cout<<endl;
}
void Regenerar()
{
    string s2(s.size(),'-');
    int p = 0;
    int i = 0;
    mostrar();
    while(i!=-1)
    {
        //DBG(i);
        //DBG(mat[i].ini);
        //DBG(mat[i].fin);
        if(!mat[i].ignor)
        {
            //cout<<"X"<<endl;

            forsn(z,mat[i].ini,mat[i].fin+1)
            {
                //DBG(s.size());
                //DBG(s[z]);
                s2[p] = s[z-1];
                p++;
            }
        }
        i = mat[i].pos;
        if(p==s.size())break;
    }
    s = s2;
}
int main()
{
    //cin.tie(0);
    //cin.sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    cin>>s;
    mat[1] = {1,n};
    mat[0].pos = mat[0].pre = 1;
    mat[0].ignor = true;
    tam = 2;
    forn(_,m)
    {
        //cout<<"Normal"<<endl;
        mostrar();
        if(tam * tam > n)
        {
            Regenerar();
            mat[1] = {1,n};
            mat[0].pos = mat[0].pre = 1;
            tam = 2;
        }
        int l,r;
        cin>>l>>r;
        int l2 = l, r2 = r, i =0;
        while(true)
        {
            while(mat[i].ignor){
                i = mat[i].pos;
            }
            int sz = mat[i].fin-mat[i].ini+1;
            //DBG(l2);
            if(sz>=l2 and l2>1)
            {
                //DBG(sz); DBG(l2); DBG(i);
                int ini = mat[i].ini, fin = mat[i].ini+l2-2;
                mat[i].ini+=l2-1;
                r2-=l2-1;
                l2 = 0;
                //cout<<" Agrego izq : "<<ini<<" a "<<fin<<endl;
                //mat.insert(mat.begin()+i,(bloque){ini,fin});

                PonerPre(i,ini,fin);
                mostrar();
                /*for(auto b : mat){
                    cout<<"[ "<<b.ini<<" a "<<b.fin<<" | "<<b.ignor<<" ]";
                } cout<<endl;*/
                //break;
            }
            else l2-=sz;
            sz = mat[i].fin-mat[i].ini+1;
            if(sz>r2 and r2>=1)
            {
                //cout<<"Agrego der"<<endl;
                int ini = mat[i].ini, fin = mat[i].ini+r2-1;
                mat[i].ini+=r2;
                //i = mat[i].pos;
                PonerPre(i,ini,fin);
                mostrar();
                /*mat.insert(mat.begin()+i,(bloque)
                {
                    ini,fin
                });*/
                /*for(auto b : mat){
                    cout<<"[ "<<b.ini<<" a "<<b.fin<<" | "<<b.ignor<<" ]";
                } cout<<endl;*/

            }
            r2-=sz;
            if(r2<1) break;
            i = mat[i].pos;
        }
        l2 = l, r2 = r, i =0;
        while(true)
        {
            while(mat[i].ignor) i = mat[i].pos;
            int sz = mat[i].fin-mat[i].ini+1;
            if(l2<=1 and r2>=sz)
            {
                int x = mat[i].pre;
                int y = mat[i].pos;
                mat[x].pos = y;
                mat[y].pre = x;
                int z = mat[0].pre;
                mat[z].pos = i;
                mat[0].pre = i;
                mat[i].pre = z;
                mat[i].pos = 0;
                i = x;
                //mat.push_back(mat[i]);
                //mat[i].ignor = true;
            }
            l2-=sz;
            r2-=sz;
            i = mat[i].pos;
            if(r2<1)
                break;
        }


    }
    //cout<<"Paso final"<<endl;
    Regenerar();
    cout<<s<<endl;
    return 0;
}
/*
5 5
ABCDE
1 1
1 1
1 1
1 1
1 1


*/

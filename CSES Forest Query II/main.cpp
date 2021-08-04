#include <iostream>

using namespace std;
struct Nodo{
    int izq, der, abajo;
    int val;
    Nodo(){
        izq = der = abajo = -1;
        val = 0;
    }
};
bool check = false;
const int LargoX = 1<<10, LargoY = 1<<10; /// La memoria es Updates * log2(LargoX) * log2(LargoY) Nodos
Nodo ST[10000000]; /// GRAN CAJA DE NODOS
int STS = 0; /// Cantidad de nodos en el ST | Indice del proximo nodo a agarrar
bool Persistente = false; /// Si ponen false solo tiene lazy creation (consume menos memoria)
int QueryY(int pos, int &ay, int &by, int iniy, int finy)
{
    if(pos == -1) return 0;
    if(by < iniy || finy < ay) return 0;
    if(ay <= iniy && finy <= by) return ST[pos].val;
    int midy = (iniy+finy)/2;
    return QueryY(ST[pos].izq,ay,by,iniy,midy) + QueryY(ST[pos].der,ay,by,midy+1,finy);
}
int QueryX(int pos, int &ax, int& bx, int &ay, int& by, int inix = 0, int finx = LargoX-1, int iniy = 0, int finy = LargoY-1)
{
    if(pos == -1) return 0;
    if(bx < inix || finx < ax) return 0;
    if(ax <= inix && finx <= bx) return QueryY(ST[pos].abajo,ay,by,iniy,finy);
    int midx = (inix+finx)/2;
    return QueryX(ST[pos].izq,ax,bx,ay,by,inix,midx,iniy,finy)+
           QueryX(ST[pos].der,ax,bx,ay,by,midx+1,finx,iniy,finy);
}
int UpdateY(int pos, int& y, int iniy, int finy, int val)
{
    if(y<iniy || finy<y) return pos;
    int nextp = pos;
    if(nextp == -1 || Persistente) nextp = STS, STS++;
    Nodo & nex = ST[nextp];
    if(pos!=-1)nex = ST[pos];
    if(iniy == finy)
    {
        nex.val = val;
    }
    else
    {
        int midy = (iniy+finy)/2;
        nex.izq = UpdateY(nex.izq,y,iniy,midy,val);
        nex.der = UpdateY(nex.der,y,midy+1,finy,val);
        nex.val = 0;
        if(nex.izq!=-1) nex.val+=ST[nex.izq].val;
        if(nex.der!=-1) nex.val+=ST[nex.der].val;
    }
    return nextp;
}
int UpdateX(int pos, int &x, int &y,int& val, int inix = 0,int finx = LargoX-1, int iniy = 0, int finy = LargoY-1)
{
    if(x<inix || finx<x) return pos;
    int nextp = pos;
    if(nextp == -1 || Persistente) nextp = STS, STS++;
    Nodo & nex = ST[nextp];
    if(pos!=-1)nex = ST[pos];
    int midx = (inix+finx)/2;
    if(inix!=finx)
    {
        nex.izq = UpdateX(nex.izq,x,y, val,inix,midx,iniy,finy);
        nex.der = UpdateX(nex.der,x,y, val,midx+1,finx,iniy,finy);
    }
    int vali = 0, vald = 0;
    if(nex.izq!=-1) vali = QueryY(ST[nex.izq].abajo,y,y,iniy,finy);
    if(nex.der!=-1) vald = QueryY(ST[nex.der].abajo,y,y,iniy,finy);
    nex.abajo = UpdateY(nex.abajo,y,iniy,finy, ((inix==finx)?val:vali+vald));
    return nextp;
}
int main()
{
    int n,q;
    cin>>n>>q;
    int raiz = -1;
    for(int i = 1;i<=n;i++)
    {
        char c;
        scanf("%c",&c);
        int v = 1;
        for(int j = 1;j<=n;j++)
        {
            scanf("%c",&c);
            if(c == '*')
                raiz = UpdateX(raiz,j,i,v);
        }
    }
    for(int i = 0;i<q;i++)
    {
        int t;
        scanf("%d",&t);
        if(t == 1)
        {
            int x,y;
            scanf("%d %d",&y,&x);
            int v = 1-QueryX(raiz,x,x,y,y);
            raiz = UpdateX(raiz,x,y,v);
        }
        else
        {
            int x1,x2,y1,y2;
            scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
            printf("%d\n",QueryX(raiz,x1,x2,y1,y2));
        }
    }
}
/*
4 20
.*..
*.**
**..
****

2 1 1 4 4
2 2 2 3 4
1 3 3
2 2 2 3 4
*/

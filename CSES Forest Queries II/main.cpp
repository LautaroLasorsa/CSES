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
template<class T> ostream & operator<<(ostream & out, vector<T> & v)
{
    out<<"[";
    for(auto k : v)
        out<<k<<" ";
    out<<"]"<<"\n";
    return out;
}
typedef long long intl;
const int largo = 1<<12;
int st[largo][largo], L[largo], R[largo], N, Q;
void Query(int i, int & ini, int & fin, vector<int> & ind)
{
    if(ini<=L[i] && R[i]<=fin)
    {
        //   cout<<i<<" con "<<L[i]<<" a "<<R[i]<<endl;
        ind.push_back(i);
        return;
    }
    if(ini>R[i] || fin<L[i])
        return;
    Query(i*2,ini,fin,ind);
    Query(i*2+1,ini,fin,ind);
}
void Update(int y, int x)
{
    int i = y+largo/2, j = x+largo/2;
    st[i][j] = 1-st[i][j];
    while(j/=2)     st[i][j] = st[i][j*2] + st[i][j*2+1];

    while(i/=2)
    {
        j = x+largo/2;
        st[i][j] = st[i*2][j] + st[i*2+1][j];
        while(j/=2)
        {
            st[i][j] = st[i][j*2] + st[i][j*2+1];
        }
    }
}
string in[largo];
int main()
{
    // cin.tie(0);
    // cin.sync_with_stdio(0);
    forsn(i,largo/2,largo) L[i] = R[i] = i-largo/2;
    cin>>N>>Q;
    forn(i,N)
    {
        string s;
        cin>>s;
        in[i+1] = " "+s;
        forn(j,N) if(s[j] == '*')
            st[i+largo/2+1][j+largo/2+1] = 1;
    }
    forsn(i,largo/2,largo)
    {
        dforn(j,largo/2)
        {
            st[i][j] = st[i][j*2]+st[i][j*2+1];
            st[j][i] = st[j*2][i]+st[j*2+1][i];
        }
    }
    dforn(i,largo/2)
    {
        L[i] = L[i*2];
        R[i] = R[i*2+1];
        dforn(j,largo/2)
        {
            st[i][j] = st[i][j*2] + st[i][j*2+1];
        }
    }
    /*forsn(i,1,largo){
        forsn(j,1,largo){
            printf("%.2d ",st[i][j]);//cout<<fixed<<st[i][j]<<" ";
            if(j==largo/2-1)cout<<"| ";
        }
        cout<<endl;
        if(i==largo/2-1)cout<<string(largo*3+1,'-')<<endl;

    }
    cout<<endl;*/
    /*forsn(x1,1,N+1)
    forsn(x2,x1,N+1)
    forsn(y1,1,N+1)
    forsn(y2,y1,N+1)
    {
        int rc = 0;
        if(rand()%2)
        {
            int x = (x1+x2)/2;
            int y = (y1+y2)/2;
            if(in[y][x]=='.')
                in[y][x] = '*';
            else
                in[y][x] = '.';
            Update(y,x);
        }
        forsn(i,y1,y2+1)
        forsn(j,x1,x2+1)
        {
            //         cout<<"miro "<<in[i][j]<<endl;
            rc+=(in[i][j]=='*');
        }
        vector<int> X,Y;
        Query(1,y1,y2,Y);
        Query(1,x1,x2,X);
        int r = 0;
        // DBG(X);
        // DBG(Y);
        for(auto a : Y)
            for(auto b : X)
            {
                //            cout<<"Agrego "<<a<<" , "<<b<<" : "<<st[a][b]<<endl;
                r+=st[a][b];
            }
        if(r!=rc)
        {
            cout<<y1<<" , "<<x1<<" || "<<y2<<" , "<<x2<<endl;
            cout<<r<<" vs "<<rc<<endl;
            forsn(i,1,N+1)
            cout<<in[i]<<endl;
            DBG(X);
            DBG(Y);
            forsn(i,1,largo)
            {
                forsn(j,1,largo)
                {
                    printf("%.2d ",st[i][j]);//cout<<fixed<<st[i][j]<<" ";
                    if(j==largo/2-1)
                        cout<<"| ";
                }
                cout<<endl;
                if(i==largo/2-1)
                    cout<<string(largo*3+1,'-')<<endl;

            }
            cout<<endl;
        }
    }*/
    forn(i,Q){
        int t = 2; //cin>>t;
        if(t==1){
            int x,y;cin>>y>>x;
            Update(y,x);
        }else{
            int x1,x2,y1,y2;
            cin>>y1>>x1>>y2>>x2;
            vector<int> X,Y;
            Query(1,y1,y2,Y);
            Query(1,x1,x2,X);
            int r = 0;
           // DBG(X);
           // DBG(Y);
            for(auto a : Y)
                for(auto b : X)
                {
           //         cout<<"Agrego "<<a<<" , "<<b<<" : "<<st[a][b]<<endl;
                    r+=st[a][b];
                }
            cout<<r<<"\n";
        }
    }
    return 0;
}
/*


*/

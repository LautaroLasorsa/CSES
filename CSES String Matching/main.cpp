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
int borde[int(1e7)], N, M, L, R = 0;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    string a,b;
    cin>>a>>b;
    string t = b+"#"+a;
    int i = 1,j = 0;
    N = a.size(), M = b.size(), L = t.size();
	while(i<L){
        while(j>0 && t[j]!=t[i]){
            j = borde[j-1];
        }
        if(t[j]==t[i])j++;
        if(j == M)R++;
        borde[i]=j;
        i++;
    }
    cout<<R<<endl;
	return 0;
}

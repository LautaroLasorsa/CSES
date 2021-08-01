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
const int MAXN = 2e6 +10;
int res = -1, L ;
void duval(char* s)
{
    int i = 0, n = strlen(s), j, k;
    while (i < n)
    {
        j = i + 1, k = i;
        while (j < n and s[k] <= s[j])
        {
            if(s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k)
        {
            if(i<L) res = i;
            i += j - k;
        }
    }
}
char ss[MAXN];
int main()
{
    // cin.tie(0);
    // cin.sync_with_stdio(0);
    scanf("%s",ss);
    L = strlen(ss);
    forn(i,L) ss[i+L]=ss[i];
    duval(ss);
    ss[res+L] = 0;
    printf("%s",ss+res);
    return 0;
}

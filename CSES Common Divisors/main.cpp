#include <iostream>

using namespace std;
const int maxn = 2e5 + 10, maxx = 1e6 + 10;
int input[maxn];
int dp[maxx];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n; cin>>n;
    for(int i = 0;i<n;i++){
        cin>>input[i];
        dp[input[i]] ++;
    }
    int res = 1;
    for(int i = 2;i<maxx;i++){
        int apariciones = 0;
        for(int j = i;j<maxx;j+=i)
            apariciones += dp[j];
        if(apariciones>=2)
            res = i;
    }
    cout<<res<<endl;
    return 0;
}

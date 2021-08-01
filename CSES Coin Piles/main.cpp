#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if((a+b)%3 == 0 && a*2>=b && b*2>=a)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
}
/*
2x1 + x2 = a
x1 + 2x2 = b

3/2x2 = b-a/2
3x2 = 3b-2a
x2 = b-2/3 a

2x1 + (b-2/3a) = a
2x1 + b = 5/3+a
x1 = 5/6a-b/2


x1 - x2 = a-b
3x1 + 3x2 = a+b
*/

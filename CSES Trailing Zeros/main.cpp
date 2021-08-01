#include <iostream>

using namespace std;

int main()
{
    int n; cin>>n;
    int R2 = 0, R5 = 0, p2 = 2, p5 = 5;
    while(p2<=n) R2+=n/p2, p2*=2;
    while(p5<=n) R5+=n/p5, p5*=5;
    cout<<min(R2,R5)<<endl;
}

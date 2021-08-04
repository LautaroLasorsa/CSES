#include <iostream>

using namespace std;
int cont = 0, mcont = 0;
char c = 'e';
int main()
{
    string S;
    cin>>S;
    for(auto k : S)
    {
        if(k == c)
            cont++;
        else
            c = k, mcont = max(cont,mcont), cont = 1;
    }
    mcont = max(cont,mcont);
    cout<<mcont<<endl;
}

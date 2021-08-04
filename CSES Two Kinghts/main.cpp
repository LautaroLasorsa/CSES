#include <iostream>
#include <fstream>
#define ll long long
using namespace std;
ll mx[] = {2,2,1,1,-1,-1,-2,-2};
ll my[] = {1,-1,2,-2,2,-2,1,-1};
ll ContarF(ll k)
{
    ll T = 0, Tam = k*k, CERO = 0;
    if(k == 1)
        return 0;
    if(k == 2)
        return 6;
    if(k>3)
        T = 8;
    if(k>4)
        T += max(CERO,(k-4)*(k-4)*(Tam-9));
    T += max(CERO,4*(k-4)*(Tam-7));
    T += max(CERO,4*(k-2)*(Tam-5));
    T += max(CERO,4*(Tam-5));
    T += max(CERO,4*(Tam-3));
   // cout<<k<<endl;
   // cout<<max(CERO,(k-2)*(k-2)*(Tam-9))<<" + "<<endl;
   // cout<<max(CERO,4*(k-2)*(Tam-7))<<" + "<<endl;
   // cout<<max(CERO,4*(k-1)*(Tam-5))<<" + "<<endl;
   // cout<<max(CERO,4*(Tam-5))<<" + "<<endl;
   // cout<<max(CERO,4*(Tam-3))<<" + "<<endl;
   // cout<<T<<" => "<<T/2<<endl;
    return T/2;


    /*for(ll i = 0;i<k;i++)
        for(ll j = 0;j<k;j++)
        {
            ll cont = 1;
            for(int l = 0;l<8;l++)
            {
                ll x = i + mx[l], y = j + my[l];
                if(0<=x && x<k && 0<=y && y<k)
                    cont++;
            }

            T += max(CERO,Tam-cont);
        }*/
    return T/2;
}
int main()
{
    //ofstream FE("resultado.out");
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        cout<<ContarF(i)<<endl;
      //  FE<<ContarF(i)<<",";
      //  if(i%100 == 0)
      //  {
      //      cout<<i<<endl;
      //      FE<<endl;
      //  }
    }
}

#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int Dist[1001][1001], Padre[1001][1001], N, M;
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int Ax, Ay, Bx, By;
char C,in[1001][1001], Mov[4] = {'R','D','L','U'};
int main()
{
    cin>>N>>M;
    scanf("%c",&in[0][0]);
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<M;j++)
        {
            Dist[i][j] = 1e7;
            scanf("%c",&in[i][j]);
            if(in[i][j]=='A')
                Ax = j, Ay = i;
            else if(in[i][j] == 'B')
                Bx = j, By = i;
        }
        scanf("%c",&C);
    }
    queue<pair<int,int> > Q;
    Q.push({Ay,Ax});
    Dist[Ay][Ax] = 0;
    while(Q.size())
    {
        pair<int,int> p = Q.front();
        Q.pop();
        int i = p.first, j = p.second, c = Dist[i][j]+1;
        //cout<<i<<" , "<<j<<" : "<<c<<endl;
        for(int k = 0;k<4;k++)
        {
            int y = i + dy[k], x = j + dx[k];
            if(y >= 0 && y < N && x >= 0 && x < M)
                if(c<Dist[y][x] && in[y][x]!='#')
                    Padre[y][x] = k, Dist[y][x] = c, Q.push({y,x});
        }
    }
    if(Dist[By][Bx] == 1e7)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl<<Dist[By][Bx]<<endl;
    string S ="";
    while(Bx!=Ax || By!=Ay)
    {
        int p = Padre[By][Bx];
        S+=Mov[p];
        Bx -= dx[p];
        By -= dy[p];
    }
    reverse(S.begin(),S.end());
    cout<<S<<endl;
}

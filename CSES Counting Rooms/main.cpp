#include <iostream>

using namespace std;
string in[1000];
int mx[] = {1,0,-1,0}, my[] = {0,1,0,-1}, N, M;
void DFS(int x, int y)
{
    if(x<0 || x==M || y<0 || y==N)
        return;
    if(in[y][x] == '#')
        return;
    in[y][x] = '#';
    for(int l = 0;l<4;l++)
        DFS(x+mx[l],y+my[l]);
}
int main()
{
    int Cant = 0;
    cin>>N>>M;
    for(int i = 0;i<N;i++)
        cin>>in[i];
    for(int i = 0;i<N;i++)
        for(int j = 0;j<M;j++)
            if(in[i][j]=='.')
                DFS(j,i),Cant++;
    cout<<Cant<<endl;
}

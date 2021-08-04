#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;
char C[4] = {'A','C','G','T'};
priority_queue<int,vector<int>,greater<int> > PQ[256];
int main()
{
    string S;
    cin>>S;
    int L = S.size(), Lp = L + 4;
    S = S + "ACGT";
    for(int i = 0;i<Lp;i++)
        PQ[S[i]].push(i);
    string R = "";
    int ini = -1;
    while(ini<L)
    {
        for(int i = 0;i<4;i++)
            while(PQ[C[i]].size() && PQ[C[i]].top() <= ini)
                PQ[C[i]].pop();
        char Plus = '#';
        int maxind = 0;
        for(int i = 0;i<4;i++)
            if(PQ[C[i]].top() > maxind)
                maxind = PQ[C[i]].top(), Plus = C[i];
        ini = maxind;
        R += Plus;
    }
    cout<<R<<endl;
}

/*set<string> SET;
void Avanzar(string & s)
{
    int L = s.size(), i = 0;
    while(i<L && s[i] == 'T')
        s[i] = 'A', i++;
    if(i == L)
        s+= 'A';
    else if(s[i] == 'A')
        s[i] = 'C';
    else if(s[i] == 'C')
        s[i] = 'G';
    else
        s[i] = 'T';
}
int main()
{
    string in;
    cin>>in;
    int L = in.size();
    for(int i = 0;i<L;i++)
    {
        string subs = "";
        for(int j = 0;j<10 && i+j<L;j++)
            subs += in[i+j], SET.insert(subs);
    }
    string ini = "A";
    while(SET.count(ini))
        Avanzar(ini);
    cout<<ini<<endl;
}*/

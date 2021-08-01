#include <bits/stdc++.h>

using namespace std;

#define forsn(i, s, n) for(tint i=s;i<tint(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(), v.end()
#define dbg cerr << "HU" << endl;
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);

typedef long long tint;

const int INF = 11000;
const tint MOD = 1000000007;
const int MAXN = 60003;

string best = "{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{";
int cnt = 0;
bool ok = 0;

void get(string s){
	cnt++;
	string a = "";
	int n = s.size();
	int i = 0;
	int pa = 0;
	for(;i<n-1;i++){
		if(s[i] == 'x'){
			if(s[i+1] == 'p'){ a+='$'; i++;pa++;}
			else if(s[i+1] == 'x'){ a+='x'; i++;pa++;}
			else ok = 1;
		}else{
			a+=s[i];
		}
	}
	if(i <= n-1){
		a+=s[n-1];
	}
	best = min(best, a);
	if(pa == 0) return;
	get(a);
}

int main(){
	string s; cin >> s;
	forn(i, s.size()){
		if(s[i] == '$') ok = 1;
	}
	if(ok){
		cout << 0 << "\n";
		cout << "NOSTRING" << "\n";
		return 0;
	}
	get(s);
	if(int((s.size()) == 1 && s[0] == 'x') || ok){
		cout << 0 << "\n";
		cout << "NOSTRING" << "\n";
	}else{
		cout << cnt-1 << "\n";
		cout << best << "\n";
	}
}

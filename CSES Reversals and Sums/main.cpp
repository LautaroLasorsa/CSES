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
#define TAM_MASK 1
#define get(mask,i) ((mask>>(TAM_MASK*(i)) & ( (1<<TAM_MASK)-1)))
#define set(mask,i,v)  ( ((mask & ~( ( (1<<TAM_MASK)-1) << (TAM_MASK*(i)) )) | (v<<(TAM_MASK * (i))) ))
#define popcount(mask) (__builtin_popcount(mask))
#define endl '\n'
#define ALL(x) x.begin(),x.end()
template<class T> ostream & operator<<(ostream & out, vector<T> & v){
	out<<"[";
	for(auto k : v) out<<k<<" ";
	out<<"]"<<"\n";
	return out;
}
template<class T> ostream & operator<<(ostream & out, set<T>  s){
	out<<"{";
	for(auto k : s) out<<k<<" ";
	out<<"}"<<"\n";
	return out;
}

template<class T, class U> ostream & operator<<(ostream & out, pair<T,U>  p){
	out<<"[ "<<p.first<<" , "<<p.second<<" ] ";
	return out;
}
template<class T, class U> istream & operator>>(istream & in, pair<T,U> & p){
	in>>p.first>>p.second;
	return in;
}
// example that supports range reverse and addition updates, and range sum query
// (commented parts are specific to this  problem)
typedef long long intl;
typedef struct item *pitem;
struct item {
	int pr,cnt;
	int val;
	intl sum; // (paramters for range query)
	bool rev; // (parameters for lazy prop)
	pitem l,r;
	item(int val): pr(rand()),cnt(1),val(val),l(0),r(0),rev(0){}
};
void push(pitem it){
	if(it){
		if(it->rev){
			swap(it->l,it->r);
			if(it->l)it->l->rev^=true;
			if(it->r)it->r->rev^=true;
			it->rev=false;
		}
		//it->val+=it->add;
		//it->sum+=it->cnt*it->add;
		//if(it->l)it->l->add+=it->add;
		//if(it->r)it->r->add+=it->add;
		//it->add=0;
	}
}
int cnt(pitem t){return t?t->cnt:0;}
 intl sum(pitem t){return t?push(t),t->sum:0;}
void upd_cnt(pitem t){
	if(t){
		t->cnt=cnt(t->l)+cnt(t->r)+1;
        t->sum=t->val+sum(t->l)+sum(t->r);
	}
}
void merge(pitem& t, pitem l, pitem r){
	push(l);push(r);
	if(!l||!r)t=l?l:r;
	else if(l->pr>r->pr)merge(l->r,l->r,r),t=l;
	else merge(r->l,l,r->l),t=r;
	upd_cnt(t);
}
void split(pitem t, pitem& l, pitem& r, int sz){ // sz:desired size of l
	if(!t){l=r=0;return;}
	push(t);
	if(sz<=cnt(t->l))split(t->l,l,t->l,sz),r=t;
	else split(t->r,t->r,r,sz-1-cnt(t->l)),l=t;
	upd_cnt(t);
}
string res = "";
void output(pitem t){ // useful for debugging
	if(!t)return;
	push(t);
	output(t->l);res+=t->val;output(t->r);
}
// use merge and split for range updates and queries


int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m; cin>>n>>m;
    int v; cin>>v;
    pitem raiz = new item(v);
    forsn(i,1,n){
        cin>>v;
        pitem x = new item(v);
        merge(raiz,raiz,x);
    }
    forn(_,m){
        int t, l,r;
        cin>>t>>l>>r;
        pitem a,b,c;
        split(raiz,a,b,l-1);
        split(b,b,c,r-l+1);
        if(t==1)b->rev^=1;
        else cout<<sum(b)<<endl;
        merge(raiz,a,b);
        merge(raiz,raiz,c);

    }
    //output(raiz);
    //cout<<res<<endl;
    return 0;
}

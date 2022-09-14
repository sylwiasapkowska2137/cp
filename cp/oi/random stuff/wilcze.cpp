#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

vector<LL>x;

/*struct elem{
	LL x;
	int cnt;
};
struct maxqueue{
	deque<elem> K;
	void push(int x){
		int cnt = 0;
		while (K.size() > 0 && K.back().x >= x) {
			cnt+=K.back().cnt+1;
			K.pop_back();
		}
		K.push_back({x, cnt});
	}
	void pop(){
		if (K.front().cnt == 0) K.pop_front();
		else K.front().cnt--;
	}
	LL min(){return K.front().x;}
};*/

struct segtree{
	vector<LL> tab;
	int size = 1;
	
	void init(){
		while(size < x.size()) size*=2;
		tab.resize(2*size);
		build();
	}
	
	void build(){
		for (int i = 1; i<x.size(); i++) {
			tab[i+size-1] = x[i];
		}
		for (int i = size-1; i>=0; i--) tab[i] = max(tab[2*i], tab[2*i+1]);
	}
	
	LL maxi(int l, int r){
		l = l+size-1;
		r = r+size+1;
		LL res = 0LL;
		while (r-l>1){
			if (!(l&1)) res = max(res, tab[l+1]);
			if (r&1) res = max(res, tab[r-1]);
			l/=2;r/=2;
		}
		return res;
	}
	
};


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, d;
	LL p;
	cin >> n >> p >> d;
	int ans = d, j = d;
	vector<int>a(n+1);
	vector<LL>pref(n+1);
	x.resize(n-d+1);
	for (int i = 1; i<=n; i++){
		cin >> a[i];
		pref[i] = pref[i-1]+(LL)a[i];
	}
	for (int i = 1; i<=n-d+1; i++){
		x[i] = pref[i+d-1] - pref[i-1];
		//debug(x[i]);
	}
	segtree seg;
	seg.init();
	//debug(seg.size);
	//for (auto x: seg.tab)debug(x);
	//cerr << "\n";
	for (int i = 1; i<=n-d+1; i++){
		j = max(j, i+d-1);
		//debug(i);
		while (j+1<=n && (pref[j+1]-pref[i-1])-seg.maxi(i, j-d+2)<=p) {
			//debug(seg.maxi(i, j-d+2));
			j++;
		}
		//debug(j-i+1);
		//cerr << "\n";
		ans = max(ans, j-i+1);
	}
	cout << ans << "\n";
	return 0;
}

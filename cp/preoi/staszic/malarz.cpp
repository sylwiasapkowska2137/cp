#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

struct segtree{
	vector<int>tab;
	vector<bool> lazy;
	int size = 1;
	
	void init(int n){
		
	}
	
	
	
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, a, b;
	cin >> n >> m;
	char type;
	segtree seg;
	seg.init(n+1);
	for (auto x: seg.tab) debug(x);
	cerr << "\n";
	for (int i = 0; i<m; i++){
		cin >> type >> a >> b;
		if (type == '?') cout << seg.query(1, 1, seg.size, a, b) << "\n";
		else seg.update(1, 1, seg.size, a, b);
		
	}
	return 0;
}

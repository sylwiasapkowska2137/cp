#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second

const int MAX = 1e5+7;
vector <int> graf[MAX];
vector <bool> vis;


struct query{
	mutable int x, y, l, i; 
};

inline bool operator <(const query& a, const query& b){
	return a.x < b.x;
}

bool cmp(query a, query b){return (a.y < b.y);}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, q, h;
	cin >> n >> q >> h;
	vector <query> a(n);
	set<query> s;
	for (int i = 0; i<n; i++){
		cin >> a[i].x >> a[i].y >> a[i].l;
		a[i].l+=a[i].x;
		a[i].x++;
		a[i].l--;
		a[i].i = i;
	}
	sort(a.begin(), a.end(), cmp);
	for (auto x: a){
		debug(x.x);
		debug(x.l);
		cerr << "\n";
		
		auto it = s.lower_bound({x.x, 0, 0, 0});
		auto curr = it;
		if (it != s.begin()) {
			it--;
			it->l = min(it->l, x.x);
			if (x.y - it->y <= h){
				graf[x.i].pb(it->i);
				graf[it->i].pb(x.i);
			}
			it++;
		}
		while (it != s.end()) {
			curr = it++;
			if (curr->l < x.l) {
				if (x.y - curr->y <= h){
					graf[x.i].pb(curr->i);
					graf[curr->i].pb(x.i);
				}
				s.erase(curr);
			}
			else break;
		}
		if (curr != s.end()) {
			curr->x = max(curr->x, x.l);
			if (x.y - curr->y <= h){
				graf[x.i].pb(curr->i);
				graf[curr->i].pb(x.i);
			}
		}
		s.insert(x);
		//debug("set:\n");
		//for (auto it = s.begin(); it != s.end(); it++) {
		//	debug(it->x);
		//	debug(it->l);
		//	cerr << "\n";
		//}
	}
	for (int i = 0; i<n; i++){
		for(auto x: graf[i])debug(x);
		cerr << "\n";
	}
	return 0;
}

/*
4 0 0
1 1 2
3 1 3
6 1 3
2 2 6
*/

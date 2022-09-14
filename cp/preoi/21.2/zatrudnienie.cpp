#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << x << " "
#define LL long long
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second

const int MAX = 2e5+7;
vector <int> graf[MAX], ans, side;
vector <bool> vis; 
int n;

bool bipartite(){
	bool is_bipartite = true;
	queue<int> q;
	for (int st = 0; st < n; st++) {
		if (side[st] == -1) {
			q.push(st);
			side[st] = 0;
			while (!q.empty()) {
				int v = q.front();
				q.pop();
				for (int u : graf[v]) {
					if (side[u] == -1) {
						side[u] = side[v] ^ 1;
						q.push(u);
					} else is_bipartite &= side[u] != side[v];
				}
			}
		}
	}
	return is_bipartite;
}

int binsracz(int start, int koniec, int i, int val){
    int ans = -1;
    while (start <= koniec) {
        int m = (start+koniec) / 2;
        if (graf[i][m] < val) {
            ans = m;
            start = m + 1;
        } else koniec = m - 1;
    } return ans;
}

void generate(int a, int b){
	if (a == b) return;
	int indeks = binsracz(a, graf[a].size()-1, a, b);
	//debug(indeks);
	
	if (ans[a] == 0) {
		if (ans[b] == 3) ans[a] = 1;
		else ans[a] = ans[b]+1; 
	}
	if (ans[b] == 0) ans[b] = 2;
	if (indeks == -1) return;
	if (ans[graf[a][indeks]] == 0){
		if (make_pair(min(ans[a], ans[b]), max(ans[a], ans[b])) == make_pair(1, 2)) ans[graf[a][indeks]] = 3;
		if (make_pair(min(ans[a], ans[b]), max(ans[a], ans[b])) == make_pair(2, 3)) ans[graf[a][indeks]] = 1;
		if (make_pair(min(ans[a], ans[b]), max(ans[a], ans[b])) == make_pair(1, 3)) ans[graf[a][indeks]] = 2;
	}
	generate(a, graf[a][indeks]);
	generate(graf[a][indeks], b);
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int out, in, edges = 0;
	cin >> n;
	stack<pii> s;
	for (int i = 0; i<n; i++){ //zwolnieni ---> zatrudnieni
		cin >> out >> in;
		while (out > 0 && !s.empty()){
			out-=s.top().st;
			graf[i].pb(s.top().nd);
			graf[s.top().nd].pb(i);
			edges++;
			if (out < 0) s.top().st = -out;
			else s.pop();
		}
		if (in > 0)	s.push({in, i});
	}
	if (edges == 0){
		cout << "1\n";
		for (int i = 0; i<n; i++) cout << "1 ";
		cout << "\n";
		return 0;
	}
	vis.assign(n, 0);
	side.assign(n, -1);
	if (bipartite()) {
		cout << "2\n";
		for (int i = 0; i<n; i++){
			cout << side[i]+1 << " ";
		}
		cout << "\n";
		return 0;
	}//3 kolorowanie
	cout << "3\n";
	for (int i = 0; i<n; i++) sort(graf[i].begin(), graf[i].end());
	ans.assign(n+1, 0);
	for (int i = 0; i<n; i++){
		if (ans[i] == 0) generate(i, n);
	}
	for (int i = 0; i<n; i++) cout << ans[i] << " ";
	cout << "\n";
	return 0;
}

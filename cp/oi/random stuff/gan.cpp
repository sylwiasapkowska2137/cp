#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX = 1e5+7;
int depth[MAX], parents[MAX];
vector <int> graf[MAX];
struct A{
	int a,b,c;
} input[MAX];
set <int> k;
int koszt[MAX];
int res[MAX];

void dfs(int v, int u, int _depth = 0){
	parents[v] = u;
	depth[v] = _depth;
	for (auto x: graf[v]){
		if (x!=u) 
			dfs(x, v, _depth+1);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	char type;
	int n, m, t, a, b, c, tmp;
	cin >> n >> m >> t;
	for (int i = 1; i<n; i++){
		cin >> a >> b >> c;
		graf[a].push_back(b);
		graf[b].push_back(a);
		input[i].a = a;
		input[i].b = b;
		input[i].c = c;
	}
	// cout << "b";
	dfs(1, -1);
	// cout << "a";
	for (int i = 0; i<=n; i++) res[i] = -1;
	for (int i = 1; i<n; i++){
		if (depth[input[i].a]>depth[input[i].b]){
			koszt[input[i].a] = input[i].c;
		} else {
			koszt[input[i].b] = input[i].c;
		}
	}
	res[1] = 0;
	// for (int i = 1; i<=n; i++) cout << koszt[i] << " ";
	while (t--){
		cin >> type;
		if (type=='Z'){ //zapytanie
			cin >> a;
			tmp = a;
			if (res[a]!= -1) {
				cout << res[a] << "\n";
				continue;
			}
			k.clear();
			while (a!=1){
				// cout << a << " ";
				k.insert(koszt[a]);
				a = parents[a];
			}
			res[tmp] = k.size();
			cout << res[tmp] << "\n";
		} else { //zmiana
			cin >> a >> c;
			if (depth[input[a].a]>depth[input[a].b]){
				koszt[input[a].a] = c;
			} else {
				koszt[input[a].b] = c;
			}
			for (int i = 0; i<=n; i++) res[i] = -1;
		}
	}
	return 0;
}
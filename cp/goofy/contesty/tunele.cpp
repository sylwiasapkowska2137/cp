#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int MAX = 1e5+7;
int rep[MAX];
int parts;

int Find(int a){
	if (a == rep[a]) return a;
	rep[a] = Find(rep[a]);
	return rep[a];
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
        rep[b] = a;
        parts--;
    }
}


int main(){
	fastio;
	int n, m, a, b, k;
	cin >> n >> m >> k;
	parts = n;
	vector <pii> edges;
	for (int i = 0; i<=n; i++) {
		rep[i] = i;
	}
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		edges.pb({a, b});
	}
	int it = m-1;
	while (parts>=k){
		Union(edges[it].st, edges[it].nd);
		it--;
	}
	cout << it+3;
	return 0;
}


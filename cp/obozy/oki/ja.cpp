#include <bits/stdc++.h>
using namespace std;
vector <int> rep, maxi, mini, masa;

int Find(int v){
	if (v == rep[v]) return v;
	rep[v] = Find(rep[v]);
	return rep[v];
}

void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if (a != b){
		rep[b] = rep[a];
		maxi[a] = max(maxi[a], maxi[b]);
		mini[a] = min(mini[a], mini[b]);
		masa[a] += masa[b];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m, iq, a, b;
	string s;
	cin >> n;
	rep.resize(n+1);
	for (int i = 1; i<=n; i++) rep[i] = i;
	maxi.assign(n+1, 0);
	mini.assign(n+1, 1e9+7);
	masa.assign(n+1, 0);
	for (int i = 1; i<=n; i++){
		cin >> masa[i] >> mini[i];
		maxi[i] = mini[i];
	}
	while (cin >> s){
		if (s[0]=='M') {
			cin >> a;
			cout << masa[Find(a)] << "\n";
		} else if (s[0]=='J'){
			cin >> a >> b;
			Union(a,b);
		} else {
			cin >> a;
			if (s[4] == 'A') cout << maxi[Find(a)] << "\n";
			else cout << mini[Find(a)] << "\n";
		}
	}
	return 0;
}
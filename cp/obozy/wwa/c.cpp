#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int>poprzeczki(n), pale(n), lewo(n), prawo(n), dist(n);
	for (int i = 0; i<n; i++){
		cin >> poprzeczki[i];
	}
	
	for (int i = 0; i<n; i++){
		cin >> pale[i];
	}
	stack<int>S;
	for (int i = 0; i<n; i++){
		while (!S.empty() && pale[S.top()] <= pale[i]) S.pop();
		if (S.empty()) lewo[i] = -1;
		else lewo[i] = S.top();
		S.push(i);
	}
	while (!S.empty()) S.pop();
	for (int i = n-1; i>=0; i--){
		while (!S.empty() && pale[S.top()] <= pale[i]) S.pop();
		if (S.empty()) prawo[i] = -1;
		else prawo[i] = S.top();
		S.push(i);
	}
	for (int i = 0; i<n; i++){
		if (i == 0 || i == n-1) dist[i] = INT_MAX;
		else dist[i] = prawo[i]-lewo[i];
	}
	sort(dist.begin(), dist.end());
	sort(poprzeczki.begin(), poprzeczki.end());
	for (auto x: dist) debug(x);
	cerr << "\n";
	for (auto x: poprzeczki) debug(x);
	int ptr = 0; //ptr wskazuje na poprzeczki
	for (int i = 0; i<n; i++){
		int x = lower_bound(dist.begin(), .end(), dist[i])
	}
	return 0;
}



#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define pb push_back
#define st first
#define nd second
#define debug(x) cerr << x << " "

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, suma = 0, ans = 0, koniec = 1, curr = 0;
	cin >> n;
	vector<int>dist(n+1);
	for (int i = 1; i<=n; i++) {
		cin >> dist[i];
		suma += dist[i];
	}
	for (int start = 1; start<=n; start++){
		while (2*curr+dist[koniec] < suma){
			curr += dist[koniec];
			koniec = (koniec == n)? 1 : koniec+1; 
		}
		/*
		debug(start);
		debug(koniec);
		debug(curr);
		debug(suma-curr);
		debug(curr+dist[koniec]);
		debug(suma-curr-dist[koniec]);
		cerr << "\n";*/
		curr-=dist[start];
		ans = max(ans, min(curr, suma-curr));
		ans = max(ans, min(curr+dist[koniec], suma-curr-dist[koniec]));
	}
	cout << ans << "\n";
	
}

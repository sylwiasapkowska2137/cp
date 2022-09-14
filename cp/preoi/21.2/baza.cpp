#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << x << " "
#define pb push_back
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
const int S = 450;
map<pii, bool>mapa;
map<int, int> ile;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	LL ans = 0;
	int n, x, y;
	cin >> n;
	vector <pii> points(n);
	for (int i = 0; i<n; i++){
		cin >> points[i].st >> points[i].nd;
		mapa[points[i]] = 1;
		ile[points[i].st]++;
	}
	for (auto x: ile){
		debug(x.st);
		debug(x.nd);
		cerr << "\n";
		if (x.st <= S){
			//obsluz
		} else {
			
		}
	}
	return 0;
}

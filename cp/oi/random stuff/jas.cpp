#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define fastio ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0)

const int MAX = 5e5+7;
vector<int> graf[MAX];

int main(){
	fastio;
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i<n; i++){
		cin >> a[i];
	}
	do {
		for (auto x: a) debug(x);
		cerr << "\n";
	} while (next_permutation(a.begin(), a.end()));
	return 0;
}





#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

const int MAX = 5e5+7, K = 26;
vector<int>tab[MAX];

int p(int a, int b){
	return a+rand()%(b-a+1);
}

int main(){
	srand((unsigned)time(NULL));
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q, x, a, b, num;
	bool ok;
	cin >> n >> q;
	vector<int>z(n+1);
	for (int i = 1; i<=n; i++){
		cin >> z[i];
		tab[z[i]].pb(i);
	}
	while (q--){
		cin >> a >> b;
		ok = 0;
		for (int i = 0; i<K; i++){
			x = z[p(a, b)];
			auto low = lower_bound(tab[x].begin(), tab[x].end(), a);
			auto high = upper_bound(tab[x].begin(), tab[x].end(), b);
			num = high-low;
			if (2*num > (b-a+1)){
				cout << x << "\n";
				ok = 1;
				break;
			}
		}
		if (!ok) cout << "0\n";
	}
	return 0;
}

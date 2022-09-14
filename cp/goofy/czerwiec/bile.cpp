#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

const int MAX = 1e6+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		if (a[i]>=n){
			cout << "NIE\n";
			return 0;
		}
	}
	sort(a.begin(), a.end());
	vector<bool>vis(n, 0);
	for (auto x: a){
		if (!vis[x]){
			vis[x] = 1;
		} else {
			x = n-x-1;
			if (!vis[x]) vis[x] = 1;
			else {
				cout << "NIE\n";
				return 0;
			}
		}
	}
	cout << "TAK\n";
	return 0;
}


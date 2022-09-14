#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<pii>a(n);
	for (int i = 0; i<n; i++) {
		cin >> a[i].st;
		a[i].nd = i;
	}
	sort(a.begin(), a.end());
	cout << a[a.size()-2].nd+1 << "\n";
	return 0;
}



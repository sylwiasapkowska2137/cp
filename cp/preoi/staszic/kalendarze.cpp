#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector <int> a(n+1), b(m+1);
	for (int i = 1; i<=n; i++){
		cin >> a[i];
		a[i]+=a[i-1];
	} 
	for (int i = 1; i<=m; i++){
		cin >> b[i];
		b[i]+=b[i-1];
	}
	int t, x, y;
	string s;
	cin >> t;
	while (t--){
		cin >> x >> y >> s;
		
	}
	return 0;
}

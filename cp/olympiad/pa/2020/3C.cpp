#include <bits/stdc++.h>
using namespace std;
map <int, int> freq1, freq2;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, type, a, t, res = 0;
	cin >> n;
	for (int i = 0; i<n; i++){
		cin >> type >> a >> t;
		if (type == 1){
			freq1[a-t]++;
		} else freq2[a-t]++;
	}	
	for (auto x: freq1){
		auto it = freq2.find(x.first);
		if (it != freq2.end()){
			res += min(it->second, x.second);
		}
	}
	cout << res << "\n";
	return 0;
}

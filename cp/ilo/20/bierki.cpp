#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
	int n; cin >> n;
	vector<int>a(n+1), s;
	for (int i = 1; i<=n; i++) cin >> a[i];
	s = a;
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	for (int i = 1; i<=n; i++) a[i] = lower_bound(s.begin(), s.end(), a[i])-s.begin();
	vector<vector<int>>cnt(n+1);
	vector<int>prev(n+1);
	for (int i = 1; i<=n; i++){
		if (a[i] == a[i-1]){
			cnt[a[i]].back()++;
		} else {
			if (prev[a[i]] - i + 1 != 0) cnt[a[i]].emplace_back(prev[a[i]]-i+1);
			cnt[a[i]].emplace_back(1);
		}
		prev[a[i]] = i;
	}
	for (int i = 1; i<=n; i++) if (prev[i] != n) cnt[i].emplace_back(prev[i]-n);
	int ans = 1;
	for (int i = 1; i<=n; i++){
		for (int rep = 0; rep < 2; rep++){
			vector<int>pref = {0}, mn = {0};
			int sum = 0, abssum = 0;
			for (int j = 0; j<(int)cnt[i].size(); j++){
				int curr = cnt[i][j];
				sum += curr;
				abssum += abs(curr);
				pref.emplace_back(abssum);
				mn.emplace_back(min(mn.back(), sum));
				// debug(pref, mn, sum);
				int L = 0, R = (int)pref.size()-1;
				int pos = -1;
				while (R >= L){
					int mid = (L+R)/2;
					if (mn[mid] < sum){
						pos = mid;
						R = mid-1;
					} else L = mid+1;
				}
				if (pos == -1){
					if (j+1 < (int)cnt[i].size()) ans = max(ans, curr + min(-cnt[i][j+1], curr-1));
					continue;
				}
				int kand = abssum-pref[pos];
				if (j+1 < (int)cnt[i].size()) kand += min(-cnt[i][j+1], sum-mn[pos]-1);
				ans = max(ans, kand);
			}
			reverse(cnt[i].begin(), cnt[i].end());
		}
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}

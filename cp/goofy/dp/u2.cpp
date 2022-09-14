#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int,int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

struct elem{
	int w, s, val;
};
const int MAX = 2e4+7;
LL dp[MAX];
bool cmp(elem a, elem b){return a.w+a.s < b.w+b.s;}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<elem>a(n);
	for (int i = 0; i<n; i++) cin >> a[i].w >> a[i].s >> a[i].val;
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i<n; i++){
		for (int j = a[i].s; j>=0; j--){
			dp[j+a[i].w] = max(dp[a[i].w+j], dp[j]+a[i].val);
		}
	}
	LL ans = 0;
	for (int i = 0; i<MAX; i++) ans = max(ans, dp[i]);
	cout << ans << "\n";
	return 0;
}

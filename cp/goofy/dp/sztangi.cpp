#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

const int INF = 1e9+7;
struct elem{
	pii val; //{dp[j], c[j]};
	int index;
};
deque<elem>q, q2;

void pop(int index){
	while (!q.empty() && q.front().index < index) q.pop_front();
}

void push(pii val, int index){
	while (!q.empty() && q.back().val >= val) q.pop_back();
	q.push_back({val, index});
}

void pop2(int index){
	while (!q2.empty() && q2.front().index < index) q2.pop_front();
}

void push2(pii val, int index){
	while (!q2.empty() && q2.back().val >= val) q2.pop_back();
	q2.push_back({val, index});
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, t, k;
	cin >> n;
	vector<int>a(n), dp(n);
	for (int i = 0; i<n; i++) cin >> a[i]; 
	cin >> t;
	while (t--){
		cin >> k;
		q.clear();
		q2.clear();
		push({0, a[0]}, 0);
		push2({0, -a[0]}, 0);
		dp[0] = 0;
		for (int i = 1; i<n; i++){
			if (i > k) {
				pop(i-k);
				pop2(i-k);
			}
			dp[i] = q.front().val.st;
			if (q.front().val.nd <= a[i]) dp[i]++;
			if (q2.front().val.nd > a[i]) dp[i] = min(dp[i], -q2.front().val.st);
			else dp[i] = min(dp[i], -q2.front().val.st+1);
			push({dp[i], a[i]}, i);
			push2({dp[i], -a[i]}, i);
		}
		cout << dp[n-1] << "\n";
	}
	
	
	return 0;
}

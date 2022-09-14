//Sylwia Sapkowska
#include <bits/stdc++.h>
#include "ckuclib.h"
using namespace std;
typedef long long LL;
const int e = 20;

struct alaska{
	int t;
	vector<int>prev, now;
	alaska() {
		t = 1;
		prev.resize(e+1);
		now.resize(e+1);
	}
};
vector<alaska>dp;

void i_hate_dp(int i){
	dp[i].t++;
	int t = dp[i].t;
	if (dp[i-1].t != t-t/2) i_hate_dp(i-1);
	vector<int>dp2(e+1);
	for (int j = 0; j<=e; j++){
		dp2[j] = min(dp[i].now[min(j+1, e)]+jedno(t), dp[i].prev[j]+dwa(t));
		if (j) dp2[j] = min(dp2[j], dp[i-1].now[j-1]+polowa(t));
	}
	swap(dp[i].prev, dp[i].now);
	dp[i].now = dp2;
}

void solve(){
	int n = dajn();
	dp.resize(e+1);
	for (int i = 0; i<=e; i++) for (int j = 0; j<=e; j++) dp[i].now[j] = jedno(1);
	while (dp[e].t != n) i_hate_dp(e);
	odpowiedz(dp[e].now[min(e, daje())]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}

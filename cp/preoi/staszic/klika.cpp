#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int,int>
#define pb push_back
#define st first
#define nd second
#define debug(x) cerr << x << " "

const int MAX = 1e6+7;
int d[MAX], tab[MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, x;
	cin >> n;
	for (int i = 0; i<n; i++){
		cin >> x;
		
	}
	for (int i = 1; i<MAX; i++){
		if (tab[i]) for (int j = 2*i; j<MAX; j+=i) d[j] = max(d[j], d[i]+1);
	}
	int ans = 1;
	for (int i = 1; i<MAX; i++) {
		if (d[i]>ans) debug(i);
		ans = max(ans, d[i]);
		
	}
	cout << ans << "\n";
	return 0;
}

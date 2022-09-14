#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, cnt;
	cin >> n;
	vector<int>a(n);
	vector<pii>tab;
	for (int i = 0; i<n; i++) cin >> a[i];
	stack<int>s;
	for (int i = n-1; i>=0;i--){
		if (a[i]>0){
			cnt = 0;
			while (!s.empty() && cnt < a[i]) {
				tab.pb({i, s.top()});
				a[s.top()] = -1;
				s.pop(); 
				cnt++;
			}
			a[i]-=cnt;
			if (!a[i]) {
				s.push(i);
				a[i] = -1;
			}
		} else s.push(i);
	}
	//for (auto x: a) debug(x);
	//cerr << "\n";
	for (int i = n-1; i>=0; i--){
		if (a[i]>0){
			cnt = 0;
			while (!s.empty() && cnt < a[i]) {
				tab.pb({i, s.top()});
				s.pop(); 
				cnt++;
			}
			a[i]-=cnt;
			if (!a[i]) s.push(i);
		} else if (a[i]==-1) continue;
		else s.push(i);
	}
	sort(tab.begin(), tab.end());
	for (auto x: tab){
		cout << x.st+1 << " " << x.nd+1 << "\n";
	}
	return 0;
}


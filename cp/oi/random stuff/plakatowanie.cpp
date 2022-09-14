#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	stack<int>s;
	int n, p = 0, trash;
	cin >> n;
	vector <int> w(n);
	for (int i = 0; i<n; i++){
		cin >> trash >> w[i];
	}
	for (int i = 0; i<n; i++){
		while (!s.empty() && s.top() > w[i]) s.pop();
		if (s.empty() or s.top() < w[i]){
			s.push(w[i]);
			p++;
		}
	}
	cout << p << "\n";
	return 0;
}


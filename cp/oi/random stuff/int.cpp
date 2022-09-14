#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define pb push_back
#define st first
#define nd second
#define debug(x) cerr << x << " "

const int MAX = 1e6+7;
int pref[MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	
	//uwzglednic a = b
	int n, a, b;
	cin >> n;
	vector<int>tab;
	for (int i = 0; i<n; i++){
		cin >> a >> b;
		pref[a]++;
		pref[b]--;
	}
	for (int i = 1; i<=1000000; i++){
		pref[i]+=pref[i-1];
	}
	int k = 0;
	while (k<MAX){
		//pomin zera
		while (!pref[k] && k<MAX) k++;
		if (k == MAX) break;
		cout << k << " ";
		while (pref[k]>0 && k<MAX) k++;
		cout << k << "\n";
		//policz przedzial
	}
	return 0;
}


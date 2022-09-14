#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

const int MAX = 1e6+7, S = 1000;
int pref[MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int q, a, b;
	for (int i = 0; i<=S; i++){
		for (int j = 0; j<=S; j++){
			int x = i*i+j*j;
			if (x < MAX)pref[x] = 1;
		}
	}
	for (int i = 1; i<=1000000; i++) pref[i]+=pref[i-1];
	cin >> q;
	while (q--){
		cin >> a >> b;
		cout << pref[b]-pref[a-1] << "\n";
	}
	return 0;
}


#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

const int MAX = 1e5+7;
struct e{
	int a[5];
};
e tab[MAX];


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q, curr, prev, ans = 0;
	cin >> n >> q;
	vector<int>query(q+1);
	for (int i = 1; i<=n; i++){
		for (int j = 0; j<5; j++){
			cin >> tab[i].a[j];
		}
	}
	for (int i = 1; i<=q; i++){
		cin >> query[i];
		if (i == 1){
			for (auto x: tab[query[i]].a) ans++;
		} else {
			int ptr = 0;
			while (ptr < 5 && tab[query[i]].a[ptr]==tab[query[i-1]].a[ptr])	ptr++;
			for (int j = 4; j>=ptr; j--)ans++;
			for (int j = ptr; j<5; j++)	ans++;
		}
	}
	cout << ans+5 << "\n";
	for (int i = 1; i<=q; i++){
		if (i == 1){
			for (auto x: tab[query[i]].a) cout << "1 " << x << "\n";
		} else {
			int ptr = 0;
			while (ptr < 5 && tab[query[i]].a[ptr]==tab[query[i-1]].a[ptr])	ptr++;
			for (int j = 4; j>=ptr; j--)cout << "0\n";
			for (int j = ptr; j<5; j++)	cout << "1 " << tab[query[i]].a[j] << "\n";
		}
	}
	for (int i = 0; i<5; i++) cout << "0\n";
	return 0;
}



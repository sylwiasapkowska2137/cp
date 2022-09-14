#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
const int MAX = 1e6+7;
int prime[MAX];

void sito(){
	for (int i = 2; i<MAX; i++){
		if (!prime[i] && (LL)i*i<(LL)MAX){
			for (int j = i*i; j<MAX; j+=i){
				prime[j] = i;
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q, a, b;
	cin >> n >> q;
	while (q--){
		cin >> a >> b;
		int d = __gcd(a, b);
		if (a == b) cout << "0\n";
		else if (d == a || d == b){
			if (d == a) cout << b/a << "\n";
			else cout << a/b  << "\n";
		} else {
			if (d > 1){
				cout << (a+b)/d << "\n";
			} else {
				if (a == 1 || b == 1){
					
				} else {
					cout << a+b << "\n";
				}
				
			}
		}
	}
	
	
	return 0;
}



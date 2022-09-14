#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back

void div(vector<int>&divisors, int x){
	for (int i = 1; i<=sqrt(x)+1; i++){
		if (x%i==0){
			divisors.pb(i);
			divisors.pb(x/i);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int>a(n), b(n), divisors, div;
	for (int i = 0; i<n; i++){
		cin >> a[i];
	}
	int x = a[0];
	for (int i = 1; i<=sqrt(x); i++){
		if (x%i==0){
			divisors.pb(i);
			if (i!=x/i) divisors.pb(x/i);
		}
	}
	
	for (auto x: divisors){
		debug(x);
		
	}
	divisors.clear();
	for (int i = 0; i<n; i++){
		cin >> b[i];
	}
	x = b[0];
	for (int i = 1; i<=sqrt(x); i++){
		if (x%i==0){
			div.pb(i);
			if (i!=x/i) div.pb(x/i);
		}
	}
	for (auto x: divisors){
		for (auto y: div){
			
		}
	}
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
	int d,a,b;
	cin>>d>>a>>b;
	int sum = a / d + b / d;
	if(sum % 2 == 1){
		cout << "Nlodlotroklo";
	}
	else{
		cout << "Bloglohro";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}

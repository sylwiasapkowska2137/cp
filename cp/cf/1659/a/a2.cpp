#include <bits/stdc++.h>

using namespace std;

void solve(int r, int b, int x){
	if(r-b == 1) {
		cout << "R";
		while(b--) cout << "BR";
		cout << "\n";
		return;
	} 
	
	for(int i = 0; i < x; i++) cout << "R";
	r -= x;
	while(b < (x-1)*r && b > 0 && r > 0){
		cout << "B";
		for(int i = 0; i < x; i++){
			if(r == 0) break;
			r--;
			cout << "R";
		}
		//r-=x;
		b--;
	}
	while(r > 0 && b > 0){
		cout << "B";
		for(int i = 1; i < x; i++) {
			if(r == 0) break;
			r--;
			cout << "R";
		}
		b--;
	}
	//cout << " " << r << " " << b << " ";
	cout << "\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, r, b;
		cin >> n >> r >> b;
		int x = r/(b+1);
		if(r%(b+1)) x++;
		solve(r, b, x);
	}
	
	return 0;
}

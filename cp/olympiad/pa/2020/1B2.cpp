#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6+7;
int yellow[MAX], blue[MAX], red[MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, t, a, b, c, res = 0;
	cin >> n >> t;
	while (t--){
		cin >> a >> b >> c;
		if (c == 1){ // zolty
			yellow[a]++;
			yellow[b+1]--;
		} else if (c == 2){ //niebieski
			blue[a]++;
			blue[b+1]--;
		} else { //czerwony
			red[a]++;
			red[b+1]--;
		}
	}
	for (int i = 1; i<=n; i++){
		blue[i]+=blue[i-1];
		yellow[i]+=yellow[i-1];
		red[i]+=red[i-1];
		//cerr << i << " " << blue[i] << " " << yellow[i] << " " << red[i] << "\n";
		if (blue[i]>0 && yellow[i]>0 && red[i]<1) res++;
	}
	cout << res << "\n";
	return 0;
}

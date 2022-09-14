#include <bits/stdc++.h>
using namespace std;

struct A{
	int val, kolor;
	bool start;
};
vector <A> tab;

bool cmp(A a, A b){
	return (a.val < b.val);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, t, a, b, c, res = 0, niebieskie = 0, czerwone = 0, zolte = 0;
	cin >> n >> t;
	while (t--){
		cin >> a >> b >> c;
		A elem;
		elem.kolor = c;
		elem.val = a;
		elem.start = true;
		tab.push_back(elem);
		elem.val = b;
		elem.start = false;
		tab.push_back(elem);
	}
	sort(tab.begin(), tab.end(), cmp);
	for (auto x: tab){
		//cerr << x.val << " " << x.start << " " << x.kolor << "\n";
		if (x.kolor == 1) zolte = (x.start) ? zolte+1 : zolte-1; 
		else if (x.kolor == 2)	niebieskie = (x.start) ? niebieskie+1 : niebieskie-1;
		else czerwone = (x.start) ? czerwone+1 : czerwone-1;
		//cerr << zolte << " " << niebieskie << " " << czerwone << "\n";
		if (zolte > 0 && niebieskie > 0 && czerwone == 0) res++;
	}
	cout << res << "\n";
	return 0;
}

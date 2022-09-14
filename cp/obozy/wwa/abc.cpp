#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << x << " "

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string a, b;
	cin >> a >> b;
	int A = 0, B = 0, C = 0, aa = 0, bb = 0, cc = 0;
	for (int i = 0; i<(int)a.size(); i++){
		if (a[i] == 'A') A++;
		else if(a[i] == 'B') B++;
		else C++;
	}
	for (int i = 0; i<(int)b.size(); i++){
		if (b[i] == 'A') aa++;
		else if(b[i] == 'B') bb++;
		else cc++;
	}
	A = min(A, aa);
	B = min(B, bb);
	C = min(C, cc);
	if (A>=B && A>=C){
		for (int i = 0; i<A; i++) cout << "A";
	} else if (B >= A && B >= C){
		for (int i = 0; i<B; i++) cout << "B";
	} else for (int i = 0; i<C; i++) cout << "C";
	cout << "\n";
	return 0;
}

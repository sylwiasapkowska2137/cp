//https://goofy.ilo.pl/team/problem.php?id=1337
#include <bits/stdc++.h>

using namespace std;

#define LL long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	LL n, a, b, x, y;
	cin >> n >> a >> b;
	LL mini = abs(a-b);
	while (n--){
		cin >> x >> y;
		a+=x;
		b+=y;
		mini = min(mini, abs(a-b));
	}
	cout << mini << "\n";
	return 0;
}

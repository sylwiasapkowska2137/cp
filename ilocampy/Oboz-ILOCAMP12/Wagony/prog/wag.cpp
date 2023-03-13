#include<iostream>
#include<algorithm>
using namespace std;

int n, a, b, wyn;
int t[300001];

int main() {
    cin >> n;
    for (int k = 1; k <= n; k++)
        cin >> t[k];
    cin >> a >> b;
    wyn = -100001;
    for (int k = a; k <= b; k++)
        if (t[k]%2) wyn = max(t[k], wyn);
    cout << wyn;
    return 0;   
}

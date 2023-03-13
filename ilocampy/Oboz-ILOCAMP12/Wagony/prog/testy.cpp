#include<iostream>
using namespace std;
int main() {
    int n, a, b;
    srand(time(NULL));
    cin >> n;
    cout << n << endl;
    for (int k = 1; k <= n; k++) {
        int x = rand()%2;
        if (x) cout << rand()%10000 << " ";
        else cout << (rand()%10000) * -1 << " ";
    }
    cout << endl;
    cin >> a >> b;
    cout << a << " " << b << endl;

    return 0;   
}

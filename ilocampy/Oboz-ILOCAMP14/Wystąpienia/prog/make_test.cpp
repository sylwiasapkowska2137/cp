#include <bits/stdc++.h>

using namespace std;

int n, m;
int tab[1000005];

int main() {

//     cin >> n >> m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }
//     for (int i = 1; i <= n; i++) {
//         cin >> tab[i];
//     }
    cout << "Test nazwaTestu() {\n";
    cout << "\tTest test;\n";
    cout << "\ttest.addLine(" << n << ", " << m << ");\n";
    cout << "\ttest.addLine(";
    for (int i = 1; i <= n; i++) {
        cout << tab[i] << (i < n ? ", " : "");
    }
    cout << ");\n";
    cout << "\treturn test;\n";
    cout << "}\n";

    return 0;
}
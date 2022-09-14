#include<cstdlib>
#include<bitset>
using namespace std;

const int M = 6e6;
bitset<M>b;


int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i<n; i++){
        int x; scanf("%d", &x);
        x %= M;
        b.set(x, 1);
    }
    printf("%d", 2*(int)b.count());
}
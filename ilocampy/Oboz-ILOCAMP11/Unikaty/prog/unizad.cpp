#include <iostream>
#include <cassert>

const int MAX_N = 1e6;
const int MIN_N = 1;

const int MAX_K = 26;
const int MIN_K = 1;

char input[MAX_N + 6];
int count[128];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    assert(MIN_N <= n && n <= MAX_N);
    assert(MIN_K <= k && k <= MAX_K);
    
    scanf("%s", input);
    assert(n == strlen(input));
    
    int lettersCount = 0;
    int start = 0;
    int res = -1;
    for (int i = 0; i < n; i++) {
        if (count[(int)input[i]]++ == 0) {
            lettersCount++;
        }
        
        while (lettersCount > k) {
            if (--count[(int)input[start]] == 0) {
                lettersCount--;
            }
            start++;
        }
        
        if (lettersCount == k) {
            res = std::max(res, i - start + 1);
        }
    }
    
    assert(res != -1);
    printf("%d\n", res);
}
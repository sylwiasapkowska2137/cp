#include <cstdio>
#include <iostream>
#include <assert.h>

#define DEBUG

#ifdef DEBUG
const bool debug = true;
#else
const bool debug = false;
#endif

const int MAX_X = 2 * 1000 * 1000 * 1000;


int main()
{
	int a, b;
    int result = 0;
	scanf("%d%d", &a, &b);
	
	if (debug)
    {
		assert(0 < a && a < MAX_X);
        assert(0 < b && b < MAX_X);
	}
    
    while (a != b)
    {
        if (a < b)
        {
            std::swap(a,b);
        }
        a >>= 1;
        ++result;
    }
    
    printf("%d\n", result);
	
	return 0;
}
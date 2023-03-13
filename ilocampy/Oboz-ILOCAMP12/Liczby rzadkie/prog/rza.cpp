#include <cstdio>
#include <iostream>

typedef long long int lld;

lld calc(lld curNum, char first11, char curStep = 0)
{
	if ((curNum & 3) == 0 && curStep > first11)
		return curNum + 1;
	else
		return calc(curNum >> 1, first11, curStep + 1) << 1;
}

lld rzadka(lld x)
{
	char first11 = -1;
	int lastNum = 0;
	lld cur = x;
	
	for (int i = 0; cur; i++) {
		if ((cur & 1) == lastNum && lastNum)
			first11 = i;
		lastNum = cur & 1;
		cur >>= 1;
	}
	
	if (first11 == -1)
		return x;
	
	return calc(x, first11);
}

int main()
{
	lld n;
	scanf("%lld", &n);
	printf("%lld\n", rzadka(n+1));
}
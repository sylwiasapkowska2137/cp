#include <cstdio>
#include <iostream>

struct pair
{
	int a, b, s;
};

const int N = 500006;
int t[N];
pair res[N];
pair stack[N];
int stack_end = 1;

void addToStack(int a)
{
	int start = 0, end = stack_end-1, mid = -1;
	while((start + end) / 2 != mid)
	{
		mid = (start + end) / 2;
		if (stack[mid].a < a)
			start = mid;
		else if (stack[mid].a > a)
			end = mid;
		else
			return;
	}
	while(stack[mid].a > a && mid)
		mid--;
	while(stack[mid+1].a <= a && mid+1 < stack_end)
		mid++;
	
	if (stack[mid].a == a)
		return;
	
	if (stack[mid+1].a > a || mid+1 >= stack_end)
	{
		stack[mid+1].b = stack[mid+1].a;
		stack[mid+1].a = a;
		stack_end = std::max(stack_end, mid+2);
	}
	if (stack[mid+1].b == -2000000000)
		stack[mid+1].b = stack[mid+1].a;
		
}

int main()
{
	int n;
	scanf("%d", &n);
	
	stack_end = 1;
	for (int i = 0; i <= n; i++)
		stack[i].a = stack[i].b = -2000000000;
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t[i]);
		addToStack(t[i]);
		res[i] = stack[stack_end-1];
		res[i].s = stack_end-1;
	}
	
	int result = res[n-1].s;
	
	stack_end = 1;
	for (int i = 0; i <= n; i++)
		stack[i].a = stack[i].b = -2000000000;
	
	int tmp;
	for (int i = n-1; i >= 0; i--)
	{
		addToStack(t[i]);
		if (res[i-1].a != stack[stack_end-1].a || res[i-1].a != stack[stack_end-1].b || res[i-1].b != stack[stack_end-1].a || res[i-1].b != stack[stack_end-1].b)
			tmp = stack_end-1 + res[i-1].s;
		else
			tmp = stack_end-2 + res[i-1].s;
		result = std::max(result, tmp);
	}
	printf("%d\n", n-result);
}

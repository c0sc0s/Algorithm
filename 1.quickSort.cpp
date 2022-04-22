#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n;
int q[N];

void quick_sort(int l, int r)
{	
	
	//只有一个待处理的数就已经有序
	if (l >= r) return;
	
	
	//基数X 选择数组中间的那个数
	//快排常见误区:
	//q[left + q] == x ×
	
	//快排正确逻辑:
	//left ~ j 这个区间内的数全部小于或等于x, 另一个区间 i ~ right 一定大于或等于x, 没有！其他逻辑了！
	int x = q[(l + r)>>1];
	
	int i = l - 1;
	int j = r + 1;
	
	//基于X 调整数组顺序
	while (i < j)
	{
		while(q[ ++ i ] < x);
		while(q[ -- j ] > x);
		if(i < j){
			swap(q[i],q[j]);
		}
	}
	
	//递归处理 j 的左右两边
	quick_sort(l, j);
	quick_sort(j + 1, r);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &q[i]);
	quick_sort(0, n-1);
	
	for (int i = 0; i < n; i++){
		if(i != n-1)
			printf("%d ", q[i]);
		else
			printf("%d", q[i]);
	}
	return 0;
}



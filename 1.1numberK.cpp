#include <iostream>

using namespace std;

const int N = 1e6+1;

int n,k;
int q[N];

//找到比k小的k-1个数就行
int quick_find(int l, int r, int k){
	
	//直到带查找数组只有一个元素，就是所求元素
	if(l >= r) return q[l];
	
	//以x为基准，将数组划分两块
	int x = q[(l + r) >> 1];
	
	int i = l - 1;
	int j = r + 1;
	
	while(i < j){
		while(q[ ++ i ] < x);
		while(q[ -- j ] > x );
		if(i < j) swap(q[i], q[j]);
	}
	
	//确定x在哪一块，缩短查找x的范围
	//确定left ~ j 区间的长度，看看k是不是其中的一个数，如果不是，这段已经不重要了
	int sl = j - l + 1;
	
	//如果k在这段里，对这段使用quick_find就行
	if(k < sl) return quick_find(l, j, k);
	
	//如果第
	if(k == sl) return q[l + sl - 1];
	//如果不在，说明已经找到了第 sl 位的位置，则可以将参考点变为sl而不是0，k的相对位置变为k - sl;
	return quick_find(j + 1, r, k - sl);
}


int main(){
	cin >> n >> k;
	
	for(int i = 0; i < n; i ++ ) cin >> q[i];
	
	cout << quick_find(0, n - 1, k) << endl;
	
	return 0;
}

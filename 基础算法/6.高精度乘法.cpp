#include <iostream>
#include <vector>

using namespace std;

vector<int> mul(vector<int> &A, int b){
	vector<int> ans;
	int t = 0;
	for(int i = 0; i < A.size() || t; i++){
		if( i < A.size()) t += A[i] * b;
		ans.push_back( t % 10 );
		t /= 10;
	}
	return ans;			
}


int main(){
	string a;
	int b;
	cin >> a >> b;
	vector<int> A;
	for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
	auto ans = mul(A, b);
	for(int i = ans.size() - 1; i >= 0; i --) printf("%d" , ans[i]);
	return 0;
}


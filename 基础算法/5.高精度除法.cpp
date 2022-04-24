#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> div(vector<int> &A, int b, int &r){
	vector<int> ans;
	r = 0;
	for(int i = A.size() - 1; i >= 0; i -- ){
		r = r * 10 + A[i];
		ans.push_back(r / b);
		r %= b;
	}
	reverse(ans.begin(), ans.end());
	
	
	while(ans.size() > 1 && ans.back() == 0) ans.pop_back();
	
	
	return ans;	
}



int main(){
	string a;
	int b;
	cin >> a >> b;
	vector<int> A;
	for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
	int r;
	auto ans = div(A, b,r);
	for(int i = ans.size() - 1; i >= 0; i --) printf("%d" , ans[i]);
	return 0;
}


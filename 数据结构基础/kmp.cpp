#include <iostream>

using namespace std;

const int N = 1e6 + 10, M= 1e4 + 10;

int n, m;
int Next[M];
char s[N], p[M];//S是模式串，p是匹配串
void GetNexr(char s[], int length, int next[])
{
	next[1] = 0;
	int i = 1,j = 0;
	while(i <= length)
	{
		if(j == 0  || s[i] == s[j]) next[ ++ i] = ++ j;
		else j = next[j];	
	}
}
int main()
{

	cin >> n >> s + 1 >> m >> p + 1;
	
	for(int i = 2, j = 0; i <= m; i ++ )
	{
		while(j && s[i] != p[j + 1])j = Next[j];	
		if(p[i] == p[j + 1])j ++;
		Next[i] = j;
	}
	
	for(int i = 1, j = 0; i <= n; i++)
	{
		while(j && s[i] != p[j+1]) j = ne[j];
		if(s[i] == p[j+1]) j++;
		if(j == m)  //满足匹配条件，打印开头下标, 从0开始
		{
			//匹配完成后的具体操作
			//如：输出以0开始的匹配子串的首字母下标
			//printf("%d ", i - m); (若从1开始，加1)
			j = Next[j];            //再次继续匹配
		}
	}
	
	
	
	
	return 0;	

	
}

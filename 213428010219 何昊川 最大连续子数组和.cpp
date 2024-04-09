#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
const int INF = -1e9;
int a[N];
int n;
int main()
{
	while (cin >> n,n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		int res = INF;  //用于记录最大的连续的子数组的和
		int s = 0;    //s记录的是前i-个数中连续子数组的最大值
		int t = 0;    //用于判断给定的数组是否为全负
		for (int i = 1; i <= n; i++)
		{
			if (a[i] < 0)t++;
			if (s < 0)s = 0;
			s += a[i];
			res = max(res, s);   
		}
		if (t == n)
		{
			res = 0;
		}
	    cout << "最大连续子数组的和为："<<res << endl;
	}
	return 0;
}
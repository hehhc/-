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
		int res = INF;  //���ڼ�¼����������������ĺ�
		int s = 0;    //s��¼����ǰi-��������������������ֵ
		int t = 0;    //�����жϸ����������Ƿ�Ϊȫ��
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
	    cout << "�������������ĺ�Ϊ��"<<res << endl;
	}
	return 0;
}
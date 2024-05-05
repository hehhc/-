#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include<ctime>
using namespace std;
class Solve
{
private:
	char* cst;
	float* fst;
	int cp, fp;
	static int table[7][7];  //�������ȷ��ű�
protected:
	int compare(char a, char b);
	/* ������Ƚ�����������ȴ�����a Ϊ������������� b Ϊ�����������, ��� a > b
	 ���� 1�� ��� a = b ����0; ��� a < b, ���� 1 */
	void computer(char c);
	/* �Ӳ�����ջ��ȡ���������� c ���㣬���ѽ����ջ*/
	int getodr(char c);  //��ȡ��������table���е��±�;
public:
	Solve();
	void isolve();
	~Solve();
	void getNum(float c);     //��ȡ��Ӧ����
	void getCh(char c);		//��ȡ��Ӧ�ַ�ѹ��ջ
	float getRes();
};
int Solve::table[7][7] = {// +�� -�� *�� /�� ���� ���� #��
	{ -1, -1, -1, -1, 1, 0, 1 },
	{ -1, -1, -1, -1, 1, 0, 1 },
	{ 1,  1, -1, -1, 1, 0, 1 },
	{ 1,  1, -1, -1, 1, 0, 1 },
	{ 1,  1, 1,  1, 1, 0, 1 },
	{ -1, -1, -1, -1, 0, 0 ,0 },
	{-1, -1, -1, -1, 0, 0, 0}
};
Solve::Solve()              // ��ɳ�ʼ����������������ջ��0
{
	cst = new char[30];
	fst = new float[30];
}
Solve::~Solve() {}
void Solve::isolve()
{
	cp = 0;
	fp = 0;
}
void Solve::getNum(float c)
{
	fst[fp++] = c;
}
float Solve::getRes()
{
	return  fst[--fp];
}
void Solve::getCh(char c)			// c Ϊ�µõ����ַ�;
{
	if (cp == 0 && c == '#')		//���ܵ�һ���ַ� '#'
	{
		cst[cp++] = c;
	}
	else							//��������ǼӼ��˳�'#'��
	{
		char u = cst[cp - 1];		// u ջ���ַ�
		if (compare(c, u) == 1)		//����������ȼ�����ջ��
		{
			cst[cp++] = c;
		}
		else if (compare(c, u) == 0) // ���������ȼ�С��ջ��
		{
			if (u == '(' && c == ')' || u == '#' && c == '#')
			{
				cp--; //���������Ƴ�ȥ;
			}
			else
			{
				printf("priority 0 error");
			}
		}
		else if (compare(c, u) == -1) //���������ȼ�����С��ջ��
		{
			do
			{
				cp--;
				computer(u);			//�ó�ջ������ȥ����
				u = cst[cp - 1];	//�µ�ջ������
			} while (compare(c, u) == -1);
			//ֱ��ջ���������ȼ������� ��������Ĳ��������ȼ�������ѭ��
			if (u == '(' && c == ')' || u == '#' && c == '#') //������ȼ���ȣ����ó�ȥ;
			{
				cp--; //���������Ƴ�ȥ;
			}
			else					 //�����������������ȼ��ߣ������;
			{
				cst[cp++] = c;
			}
		}
		else
		{
			printf("error\n");
		}
	}
}
int Solve::compare(char a, char b)
{
	return table[getodr(a)][getodr(b)];
}
void Solve::computer(char c)
{
	float a, b;
	float res;
	b = fst[--fp];
	a = fst[--fp];
	if (c == '*')
	{
		res = a * b;
	}
	else if (c == '/') //����Ϊ0�ǲ��������,���ﵱ����Ϊʱ��1������ֹ�������;
	{
		if (b == 0)
		{
			res = a;
		}
		else
		{
			res = 1.0 * a / b;
		}
	}
	else if (c == '+')
	{
		res = a + b;
	}
	else if (c == '-')
	{
		res = a - b;
	}
	else
	{
		printf("computer error having excepted opr");
	}
	fst[fp++] = res; //������ɹ��Ľ�����ض�ջ��
}
int Solve::getodr(char c)
{
	if (c == '+') return 0;
	if (c == '-') return 1;
	if (c == '*') return 2;
	if (c == '/') return 3;
	if (c == '(') return 4;
	if (c == ')') return 5;
	if (c == '#') return 6;
}
int main()
{
	srand((unsigned)time(NULL));
	int num, max = 0;
	char op[20] = { '\0' };
	bool cld1, cld2; // cld1Ϊ1 ��ʾ���ܺ������ţ� Ϊ0��ʾ�������ţ� cld2 Ϊ1��ʾ����С��Ϊ2��ʾ������С��;
	float  resArray[100] = { 0 };
	int respos = 0;
	// �������

	printf("������������Ŀ������:\n");
	while (true)
	{
		cin >> num;
		if (num > 0) break;
		cout << "�������� ������������Ŀ����:\n";
	}
	printf("========================================================\n");
	printf("��ѡ��������� ���磺�Ӽ��˳�  +  -  *  /  :\n ");
	cin >> op;
	printf("========================================================\n");
	printf("��������ֵ�����ֵ:\n");
	while (true)
	{
		cin >> max;
		if (max > 0) break;
		cout << "�������� �������������ֵ:\n";
	}
	printf("========================================================\n");
	printf("��ѡ���Ƿ������� 1or0��1�����У�0�����ޣ�:\n");
	cin >> cld1;
	printf("========================================================\n");
	printf("��ѡ���Ƿ���С�� 1or0��1�����У�0�����ޣ�:\n");
	cin >> cld2;

	// **********************************************--------***********//
	 //���ɲ���
	int opnum = 0;    //ͳ��op ������
	while (true)
	{
		if (op[opnum] != '\0')
		{
			opnum++;
		}
		else
		{
			break;
		}
	}  // ��ʱ  opnum ��¼�� op��������������
	/*****************************************************************/

	// ���ǵ�ʵ���в�̫���� ���ڳ��Ķ���ʽ�� ���� ����һ��������Ѻ��еķ��������Ƶ�7�����ڣ�
	// opmax Ϊ + - * / ���������� �����˶���ʽ�ĳ���;
	int pos = 0;
	int opmax = 0;
	int kuohao = 0;
	int order = 1; //��Ŀ���
	int flag = 0; // �ų�һ�������������������ŵ����:  (a) + b 
	Solve s1;  //������������ ����ʵʱ�����ַ�����ֵ��
	while (num--)
	{
		s1.isolve(); //��ռ�����; 
		s1.getCh('#'); // ����'#' ׼��������ʽ��ʼ����;
		float factor = 0;
		cout << order++ << ".     ";
		pos = 0;
		opmax = rand() % 6 + 1;
		kuohao = 0;
		while (opmax--)			//��ʼ���ɶ���ʽ
		{
			char vv = '\0';
			bool lf = false;	// ���ڱ�ʾ�˴��Ƿ�������������
			if (cld1 == 1 && rand() % 8 > 5) // 1/8 �ĸ��ʳ�������;
			{
				flag = 0;
				cout << '(';
				kuohao++;
				lf = true;
			}
			if (lf)
			{
				s1.getCh('(');
			}
			factor = rand() % (max - 1) + 1 + ((rand() % 100) * 1.0 / 100) * cld2;
			cout << factor;
			//���ɲ����� factor;
			s1.getNum(factor); //���������������
			bool rf = false;  //���ڱ�ʾ�Ƿ�������������;
			if (cld1 == 1 && kuohao > 0 && flag != 0)
			{
				if (rand() % 4 > 2)
				{
					cout << ')';
					kuohao--;
					rf = true;
				}
			}
			if (rf)
			{
				s1.getCh(')');
			}
			//���ɲ����� 
			pos = rand() % opnum;
			cout << op[pos];

			//�����������������;
			s1.getCh(op[pos]);

			flag++;
		}
		factor = rand() % (max - 1) + 1 + ((rand() % 100) * 1.0 / 100) * cld2;
		cout << factor;
		//�����һ�����������������
		s1.getNum(factor);
		while (kuohao--)
		{
			cout << ')';
			s1.getCh(')');
		}
		//����β����'#'���������;
		s1.getCh('#');
		printf("=\n");
		//�����յĽ������������
		resArray[respos++] = s1.getRes();
	}

	return 0;
}
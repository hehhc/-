#include <iostream>
using namespace std;

typedef struct snode {
	char data;
	struct snode* next;
}snode,*linkstack;  
      //定义结点结构
typedef struct stack {
	linkstack top;  
}stack; 

void push(linkstack &top,char x)//插入元素
{
	linkstack p = new snode;
	p->data = x;
	p->next = top;
	top = p;
	return;
}

void pop(linkstack &top)   //弹出栈顶元素
{
	if (top == NULL)return;
	linkstack p = new snode;
	p = top;
	top = top->next;
	free(p);
	return;
}

char gettop(linkstack top)  //得到栈顶元素
{
	if (top == NULL)
		return 0;
	else
		return top->data;
}

bool emptystack(linkstack top)//判断栈是否为空
{
	if (top==NULL)
		return 1;
	else
		return 0;
}

int main()
{
	
    int b = 1; 
    
    while (b == 1)
	{ 
		linkstack top = new snode;  //创建top指针
		top = NULL;//初始化
		char a[1000]; int i = 0; 
		int flag = 1;//用flag去优化，如果出现[(])这种情况，可以在第三个括号出现时就结束循环，达到一个优化的目的
		cout << "请输入一个字符串" << endl;
		
		cin >> a;
		while (a[i] != '\0' && flag == 1)
		{
			switch (a[i])
			{
			case'(':push(top, a[i]); break;
			case'[':push(top, a[i]); break;    //判断如果为左括号，则进栈
			case')':
				if (gettop(top) == '(' && !emptystack(top))  
				{
				   pop(top);
				}//如果为右括号，判断是否是与之相匹配的左括号，如果是则弹出，否则直接令flag=0,以提前结束循环
				//else push(top, a[i]);
				else 
				{
				flag = 0;
				}
				break;
			case']':
				if (gettop(top) == '[' && !emptystack(top)) 
				{
					pop(top);
			    }
				//else push(top, a[i]);
				else flag = 0;
				break;
			}
			i++;
		}
		if (emptystack(top) && flag == 1) 
		{
		   cout << "匹配成功" << endl;
		}//如果栈为空则说明匹配成功
		else 
		{
		cout << "匹配失败" << endl;
	    }
		cout << "请选择1：继续或0：结束,请输入您的选择："  ;
		cin >> b;
	}
	return 0;
}
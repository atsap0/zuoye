#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
char zero[] = "零",
one[] = "一",
two[] = "二",
three[] = "三",
four[] = "四",
five[] = "五",
six[] = "六",
seven[] = "七",
eight[] = "八",
nine[] = "九",
ten[] = "十";
int Cn_To_Int(char* s); // 把一个汉字转化成数字
void Int_To_Cn(char* m, int a); // 把数字转换成一个汉字
int f(char* s); // 分类处理不同汉字数组成的数字
int f1(char* s); // 把两个汉字转换成数字
int f2(char* s); // 把三个汉字转换成数字
void output(int i); // 处理数字并输出
int main()
{
	char file[1000];
	scanf("%s", file);
	freopen(file, "r", stdin);
	int money = 0;
	char zs[] = "整数",
		op1[] = "等于",
		op2[] = "增加",
		op3[] = "减少",
		kk[] = "看看";
	char word[1000] , name[1000];
	scanf("%s", word);
	if (strcmp(word, zs) != 0)
	{
		printf("程序只能处理整数数据\n");
	}
	scanf("%s", name);
	scanf("%s", word);
	if (strcmp(word, op1) == 0)
	{
		scanf("%s", word);
		money = f(word);
	}
	else
		printf("请按照格式输入\n");

		for (;;)
		{
			scanf("%s", word);
			if (strcmp(word, name) != 0 && strcmp(word, kk) != 0)
			{
				printf("无法进行运算\n");
				break;
			}
			else if (strcmp(word, kk) == 0)
				break;
			scanf("%s", word);
			if (strcmp(word, op2) == 0)
			{
				scanf("%s", word);
				money += f(word);
			}
			else if (strcmp(word, op3) == 0)
			{
				scanf("%s", word);
				money -= f(word);
			}
		}
	scanf("%s", word);
	
	if (strcmp(word, name) != 0)
	{
		printf("无法进行运算\n");
	}
	output(money);
	return 0;
}
int f(char* s)
{
	int i;
	if (strlen(s) == 2)
	{
		i = Cn_To_Int(s);
		if (i == -1)
			printf("无法处理输入的数字\n");
		else
			return i;
	}
	else if (strlen(s) == 4)
		return f1(s);
	else if (strlen(s) == 6)
		return f2(s);
	else printf("无法处理输入的数字\n");
}
int Cn_To_Int(char* s)
{
	if (strcmp(s, zero) == 0) return 0;
	else if (strcmp(s, one) == 0) return 1;
	else if (strcmp(s, two) == 0) return 2;
	else if (strcmp(s, three) == 0) return 3;
	else if (strcmp(s, four) == 0) return 4;
	else if (strcmp(s, five) == 0) return 5;
	else if (strcmp(s, six) == 0) return 6;
	else if (strcmp(s, seven) == 0) return 7;
	else if (strcmp(s, eight) == 0) return 8;
	else if (strcmp(s, nine) == 0) return 9;
	else if (strcmp(s, ten) == 0) return 10;
	else return -1;
}
void Int_To_Cn(char* m, int a)
{
	if (a == 1) strcat(m, one);
	if (a == 2) strcat(m, two);
	if (a == 3) strcat(m, three);
	if (a == 4) strcat(m, four);
	if (a == 5) strcat(m, five);
	if (a == 6) strcat(m, six);
	if (a == 7) strcat(m, seven);
	if (a == 8) strcat(m, eight);
	if (a == 9) strcat(m, nine);
}
int f1(char* s)
{
	int m = 0, n;
	char k[3];
	k[0] = s[0];
	k[1] = s[1];
	k[2] = '\0';
	n = Cn_To_Int(k);
	if (n > 1)
	{
		if (n < 10)
			m += n * 10;
		else if (n == 10)
			m += 10;
		k[0] = s[2];
		k[1] = s[3];
		m += (Cn_To_Int(k));
	}
	else
		printf("无法处理输入的数字\n");


		return (m);
}
int f2(char* s)
{
	int m = 0 ,n;
	char k[3];
	k[0] = s[0];
	k[1] = s[1];
	k[2] = '\0';
	n = Cn_To_Int(k);
	if (n > 1 && n < 10)
	{
		m += n * 10;
		k[0] = s[2];
		k[1] = s[3];
		if (Cn_To_Int(k) != 10)
		{
			printf("无法处理输入的数字\n");
		}
		k[0] = s[4];
		k[1] = s[5];
		n = Cn_To_Int(k);
		m += n;
	}
	else
		printf("无法处理输入的数字\n");
		return (m);

}
void output(int i)
{
	int a, b;
	char money[7] = { 0 };
	a = i % 10;
	b = i / 10;
	if (b != 0)
	{
		if (b != 1) Int_To_Cn(money, b);
		strcat(money, ten);
	}
	if (a != 0) Int_To_Cn(money, a);
	if (a == 0 && b == 0)
		strcat(money, zero);
	printf("%s", money);
}


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


//
////дһ�������ж�һ�����ǲ�������
//
//#include <math.h>
//
//int is_prime(int n)
//{
//	int i = 2;
//
//	for (i = 2; i <= sqrt(n); i++)//sqrt����Ϊ��������ƽ����
//	{
//		if (n%i == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int main()
//{
//	int i = 1;
//	scanf("%d",&i);
//
//	if (is_prime(i) == 1)
//	{
//		printf("%d������", i);
//	}
//	else
//		printf("%d��������",i);
//	return 0;
//}
//
//
//
////дһ�������ж�һ���ǲ�������
//
//int is_leap_year(int year)
//{
//	return((year%4==0&&year%100!=0)||(year%400==0));
//}
//
//
//int main()
//{
//	int i = 0;
//	scanf("%d", &i);
//	if (is_leap_year(i) == 1)
//	{
//		printf("%d������", i);
//	}
//	else
//		printf("%d��������", i);
//
//	return 0;
//}
//
//
////дһ������ʵ��������������Ķ��ֲ���
//
//int binary_search(int key, int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else if(arr[mid]>key)
//		{
//			right = mid-1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//
//
//int main()
//{
//	int arr[] = {1,3,5,6,7,8,9,11,23};
//	int key = 0;
//	int sz = (sizeof arr) / (sizeof arr[0]);
//	scanf("%d", &key);
//	int ret = binary_search(key, arr, sz);
//
//	//���ҵ�key������ʾλ��
//	/*if (binary_search(key, arr, sz) == -1)
//	{
//		printf("�Ҳ���\n");
//	}
//	else
//		printf("�ҵ���%d\n", key);*/
//
//	if (ret == -1)
//	{
//		printf("�Ҳ���\n");
//	}
//	else
//		printf("�ҵ���%d,�±�Ϊ%d\n",key, ret);
//	return 0;
//}
//
//
////дһ��������ÿ����һ�κ������ͻὫnum����1��
//
//void add(int *p)
//{
//	*p =*p+1;//����(*p)++;
//}
//
//int main()
//{
//	int i = 0;
//	int num = 0;
//	//ָ��ѭ��11�Σ���������11��
//	for (i = 0; i < 11; i++)
//	{
//		add(&num);
//		printf("%d\n", num);
//	}
//	/*add(&num);
//	printf("%d\n", num);
//	add(&num);
//	printf("%d\n", num);*/
//
//	return 0;
//}
//
//
////�ݹ���ϰ
////����һ������ֵ���޷��ţ�������˳���ӡ����ÿһλ�����磺����1234�����1 2 3 4
////˼·��ÿ�ηֱ��ӡ1234%10=4,123%10=3,12%10=2,1%10=1;��������˼·����һ����ӡ�������еݹ�����ʹ�ô�ӡΪ1 2 3 4
////printf�����ķ���ֵΪ�ַ��ĸ���
//
//void print(unsigned int num)
//{
//	if (num > 9)
//	{
//		print(num / 10);//�ı�ÿ��print����
//	}
//	printf("%d ",num%10 );//��ӡ����
//}
//
//int main()
//{
//	unsigned int num = 0;
//	scanf("%d", &num);//12345
//	print(num);
//	//����
//	//print(12345)
//	//print(1234) + 5
//	//print(123) + 4 + 5
//	//printf(12) + 3 + 4 + 5
//	//print(1) + 2 + 3 + 4 + 5
//	//1 2 3 4 5 
//
//	return 0;
//}
//
//
////��д��������������ʱ���������ַ����ĳ���
////˼·���ַ���������־��־Ϊ\0������ֻ������ַ�����λֱ������\0Ϊֹ
//
////����ѭ��
//int my_strlen1(char *p)
//{
//	int count = 0;
//	while (*p != '\0')
//	{
//		count++;
//		p++;
//	}
//	return count;
//}
//
////���ú����ݹ�
//int my_strlen2(char *p)
//{
//	if (*p != '\0')
//	{
//		return 1 + my_strlen2(p + 1);//���ú����ݹ����ѭ�� 
//	}
//	
//	return 0;
//}
//
//int main()
//{
//	char arr[7];//�����ַ�����С<=7,Ҳ����˵�������ֻ����<7���ַ�����С
//	scanf("%s", &arr);
//	int len1 = my_strlen1(arr);//�������lenΪ�ַ���arr�ĳ���
//	int len2 = my_strlen2(arr);
//	printf("�ַ�������Ϊ%d\n",len1 );
//	printf("�ַ�������Ϊ%d\n", len2);
//
//	return 0;
//}
//
////��n!���������
//
//int fac(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n*fac(n - 1);//���ú����ݹ�
//	}
//}
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//
//	int ret = fac(n);
//	printf("%d�Ľ׳�Ϊ%d", n, ret);
//
//	return 0;
//}
//
//
////���n��쳲�������
////쳲���������
////1 1 2 3 5 8 13 21 34 55 ...
//
//int fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fib(n);
//	printf("%d\n", ret);
//
//	return 0;
//}
//


#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//��ӡ�˷��ھ���
void print(int i)
{
	//ѭ��ÿ��(j��ʾ��)
	int j = 0;
	for (j = 1; j <= i; j++)
	{
		//ѭ��ÿ�У�n��ʾ�У�
		int n = 0;
		for (n = 1; n <= j; n++)
		{
			printf("%d*%d=%-2d  ",j,n,j*n);
		}
		printf("\n");
	}
}

int main()
{
	int i = 0;
	scanf("%d",&i);
	print(i);

	return 0;
}


//�ú����ݹ齫�����ַ����е��ַ���������
//
#include <string.h>

//���ÿ⺯��
//˼�룺�����ַ�����������'\0'ʱ��ʾ�ַ�������������ָ������Ϊʵ�β��ܱ��ı���Ҫ���ݵ�ַ
int my_strlen(char *arr)
{
	int count = 0;
	while (*arr != '\0')
	{
		count++;
		*arr++;
	}
	return count;
}
//˼·��
//��1����'\0'ǰһԪ�����ַ�����һԪ�ؽ�����������'hello\0'��Ϊ'oell \0'
//��2����'\0'������һ��'\0'ǰһԪ�أ��ı��ַ�������ʹ�ý���ѭ�����С���ʱ'oell \0'���'oell\0\0'��ʱ�����ڶ���'\0'ռ����h��λ
//��3���ж��ַ��������Ƿ�>=2����ǣ����ú����ݹ����reversion_print������������Ϊarr+1;
//��4���ݹ����Ϊ��'oell\0\0'���'oll\0\0\0'����ʱ����������'\0'ռ��e��λ�������ڶ���'\0'ռ����h��λ���ַ�������<2,�����ݹ���ý�����
//��5������'\0'��'oll\0\0\0'���'olle\0\0','olle\0\0'���'olleh\0';��ʱ�ַ�����ȫ����������ʱ'hello\0'��Ϊ'olleh\0'

void reversion_print(char *arr)
{
	int left = 0;
	int right = my_strlen(arr) - 1;
	char tmp = arr[left];//(1)
	arr[left] = arr[right];
	arr[right] = '\0';//(2)
	if (my_strlen(arr + 1) >= 2)//(3)
		reversion_print(arr + 1); //(4)
	arr[right] = tmp;//(5)
}
//���ÿ⺯��


int main()
{
	char arr[20] = " ";
	scanf("%s",&arr);
	reversion_print(arr);
	printf("%s", arr);
}


//����һ������ÿλ֮��

//ѭ��
int add1(int i)
{
	int j = 0;
	int sum = 0;
	while(i>9)
	{
		j = i % 10;
		i = i / 10;
		sum = sum + j;
	}
	sum = sum + i;
	return sum;
}

//�ݹ�
int add2(int i)
{
	if (i > 9)
	{
		return (add2(i / 10) + i % 10);
	}
	else
		return i;
}

int main()
{
	int i = 0;
	scanf("%d",&i);
	int tmp1 = add1(i);
	int tmp2 = add2(i);
	printf("%dÿλ��Ӻ�Ϊ%d\n",i,tmp1);
	printf("%dÿλ��Ӻ�Ϊ%d\n",i,tmp2);

	return 0;
}

//�ݹ�ʵ��n��k�η�
//ʹ�ÿ⺯��
//pow��������math������Ϊ��n��k�η�
#include <math.h>
//�����ݹ麯��

double Pow(int n, int k)
{
	if (k > 0)
	{
		return n*Pow(n, k - 1);
	}
	else if (k == 0)
	{
		return 1;
	}
	else
	{
		return 1.0 / Pow(n, -k);
	}
}
int main()
{
	int n = 0;
	int k = 0;
	scanf("%d,%d",&n,&k);//ע�⸽���ֵʱһ��ע���﷨%d%d�����������޷�ʶ��%d %d����%d,%d����ʶ��
	//ע�⣺scanf��������ո���ַ���ʱ��Ĭ�Ͽո�Ϊ���������������ַ���һ����gets(),�����ַ���getchar().
	double d = Pow(n, k);
	printf("d =%lf\n",d);
	return 0;
}


//���н��Ϊ6385
int  main()
{
	char c[2][5] = { "6938", "8254" }, *p[2];
	int i, j, s = 0;
	for (i = 0; i < 2; i++)
		p[i] = c[i];
	for (i = 0; i < 2; i++)
	for (j = 0; p[i][j] > 0; j+=2)
		s = 10 * s + p[i][j] - '0';
	printf(" %d \n ", s);
}

//��������������г�ʼ������ӡ����ÿ��Ԫ�أ�ʵ������Ԫ������
//�����������
//
//��ʼ������
void Init(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = i;
	}
}
//��ӡ����
void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//
//���ú���
void reserve(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left<right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}
//
int main()
{
	int arr[20] = { 1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Init(arr, sz);
	print(arr,sz);
	reserve(arr, sz);
	print(arr, sz);
	return 0;
}

//������A���е����ݺ�����B��������������һ����

int main()
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 6, 7, 8, 9, 10 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	int tmp = 0;
	int i = 0;
	
	for (i = 0; i < sz; i++)
	{
		tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
	print(arr1,sz);
	print(arr2, sz);
	return 0;
}

//�������������в�ͬλ�ĸ���
//˼·����λ��������ͬΪ0������Ϊ1��ȷ����ͬλ����iλ�͵�i-1�룬ͬ��Ϊ�棬����Ϊ�١�

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d,%d",&a,&b);
	int tmp = a^b;
	int count = 0;
	int i = 1;
	while(tmp)
	{
		tmp = tmp&(tmp - 1);
		count++;
	}
	printf("%d",count);
	return 0;
}


//��ӡ���������Ƶ�����λ��ż��λ
//˼·�����Ƶ����λ��λ��1�Ϳ��Եõ���һλ
int main()
{
	int a = 0;
	scanf("%d", &a);
	int i = 0;
	//��ӡ����
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d", (a >> i) & 1);
	}
	printf("\n");
	//��ӡż��
	for (i = 31; i >= 0; i -= 2)
	{
		printf("%d", (a >> i) & 1);
	}
	printf("\n");
	return 0;
}

#include <string.h>

//�ַ������ú���
void reserve1(char* arr)//ע��ָ���д��
{
	int len = strlen(arr);
	char* left=arr;//�ַ�����ַΪ��Ԫ�ص�ַ
	char* right=arr+len-1;
	int tmp = 0;
	while (left<right)
	{
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

int main()
{
	char arr[20] = { 0 };
	gets(arr);
	reserve1(arr);
	printf("%s\n",arr);
	return 0;
}

//�������sn=a+aa+aaa+aaaa+aaaaa��ǰ����֮��aΪһ������

int main()
{
	int a = 0;
	int n = 0;
	scanf("%d,%d",&a,&n);
	int i = 0;
	int sum = 0;
	int sn = 0;
	for (i = 0; i < n; i++)
	{

		sum = 10*sum+a;
		sn = sn + sum;/*sn += sum;*/
	}
	printf("tmp=%d\n",sn);
	return 0;
}


//��ӡ1-10000��ˮ�ɻ���
#include <math.h>
int main()
{
	int i = 0;
	for (i = 0; i < 10000; i++)
	{
		int sum = 0;
		int count = 1;//�κ�������1λ
		//�ж�i�Ƿ�Ϊˮ�ɻ���
		//1.����i��λ��
		int tmp = i;
		while (tmp /= 10)
		{
			count++;
		}
		//2.�õ�i��ÿһλ������ÿһλ��λ���η���
		tmp = i;
		while (tmp)
		{
			sum = sum + pow(tmp % 10, count);//sum +=pow(tmp % 10, count);
			tmp = tmp / 10;//tmp /=10;
		}
		//3.�ж�
		if (sum == i)
		{
			printf("%d\n",i);
		}
	}
	return 0;
}

//��ӡ����
int main()
{
	int n = 0;
	scanf("%d",&n);
	//��ӡ�ϰ벿��
	int i = 0;
	for (i = 0; i < n; i++)
	{
		//��ӡһ��
		//�ȴ�ӡ�ո�
		int j = 0;
		for (j = 0; j < n - 1 - i; j++)
		{
			printf(" ");
		}
		//��ӡ*
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//��ӡ�°벿��
	for (i = 0; i < n-1; i++)
	{
		//��ӡһ��
		//�ȴ�ӡ�ո�
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		//��ӡ*
		for (j = 0; j < 2 * (n-1-i)-1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

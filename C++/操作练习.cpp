#include<iostream>
using namespace std;

//引用
void TestRef()
{
	int a = 10;
	int& ra = a;
	printf("%p\n", &a);
	printf("%p\n", &ra);
}
//做参数引用
void Swap(int& left, int& right)
{
	int tmp = left;
	left = right;
	right = tmp;
}
//做返回值
int& Count()
{
	static int n = 0;
	n++;
	return n;
}
int& Add(int a, int b)
{
	int c = a + b;
	return c;
}

int main()
{
	int& ret = Add(1, 2);
	Add(3, 4);
	cout << "Add(1,2)is:" << ret << endl;
	return 0;
	//输出为7，因为Add(3,4)改变了原来的返回对象
}

/*
//重载
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}
long Add(long left, long right)
{
	return left + right;
}
int main()
{
	Add(10, 20);
	Add(10.0, 20.0);
	Add(10L, 20L);

	return 0;
}
/*
//半缺省参数
void TestFunc1(int a, int b, int c =20)
{
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}
int main()
{
	TestFunc1(1,4);
	TestFunc1(8,1);
}

/*
//缺省参数
void TestFunc(int a = 0)
{
	cout << a << endl;
}

int main()
{
	TestFunc();    //没有传参时，使用参数的默认值
	TestFunc(10);  //传参时，使用指定的实参
}

/*
int main()
{
	int a;
	double b;
	char c;
	cin >> a;
	cin >> b >> c;
	cout << a << endl;
	cout << b << " " << c << endl;
	return 0;
}

/*
int main()
{
	cout << "hello world" <<endl;
	return 0;
}
/*
namespace N1
{
	int a=1;
	int Add(int left, int right)
	{
		return left + right;
	}
}

namespace N2
{
	int a;
	int b;
	int Add(int left, int right)
	{
		return left + right;
	}
	namespace N3
	{
		int c;
		int d;
		int Sub(int left, int right)
		{
			return left + right;
		}
	}
}

namespace N1
{
	int Mul(int left, int right)
	{
		return left + right;
	}
}
#include<stdio.h>
using namespace N1;

int main()
{
	printf("%d\n",a);
	return 0;
}
*/
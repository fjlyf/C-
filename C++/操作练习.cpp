#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//this指针
class A
{
	friend class Date;
public:
	void PrintA()
	{
		cout << _a << endl;
	}
	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};

int main()
{
	A* p = NULL;
	p->PrintA();
	p->Show();
}

class Date
{
	
public:
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
/*
int main()
{
	Date d1, d2;
	d1.SetDate(2020, 8, 11);
	d2.SetDate(2020, 8, 10);
	d1.Display();
	d2.Display();
	return 0;
}
/*
//类与对象
class Person
{
public:
	void PrintPersonInfo()
	{
		cout << _name << "" << _gender << "" << _age << endl;
	}
private:
	char _name[20];
	char _gender[3];
	int _age;
};

class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}
private:
	char _a;
};

//类中既有成员变量，又有成员函数
class A1
{
public:
	void f1(){}
private:
	int _a;
};

//类中仅有成员函数
class A2
{
public:
	void f2(){}
};

//类中什么也没有（空类）
class A3
{};

/*

struct Student
{
	void SetStudentInfo(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}

	char _name[20];
	char _gender[3];
	int _age;
};

int main()
{
	Student s;
	s.SetStudentInfo("Peter", "男", 18);
	s.PrintStudentInfo();
	return 0;
}


/*
//指针空值
void TestPtr()
{
	int* p1 = NULL;
	int* p2 = 0;
}
void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}

int main()
{
	f(0);
	f(NULL);
	f((int*)NULL);
	return 0;
}

/*
//for循环
void TestFor()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto& e:array)
		e *= 2;
	for (auto e:array)
		cout << e << " ";
}
int main()
{
	TestFor();
	return 0;
}
/*
void TestFor()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		array[i] *= 2;
	for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
		cout << *p << endl;
}

/*
//auto关键字
int main()
{
	int x = 10;
	auto a = &x;
	auto* b = &x;
	auto& c = x;
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;

	*a = 20;
	*b = 30;
	c = 40;
	return 0;
}

/*
int TestAuto()
{
	return 10;
}

int main()
{
	int a = 10;
	auto b = a;
	auto c = 'a';
	auto d = TestAuto();
	//typeid().name()用于输出变量类型
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;

	return 0;
}

/*
//传值引用
#include<time.h>
struct A
{
	int a[10000];
};
void TestFunc1(A a)
{
}
void TestFunc2(A& a)
{
}
void TestRefandvalue()
{
	A a;
	//以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc1(a);
	size_t end1 = clock();

	//以引用作为函数参数
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc2(a);
	size_t end2 = clock();

	//分别计算两个函数运行结束后的时间
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}

int main()
{
	int a = 10;
	int& ra = a;
	ra = 20;
	int* pa = &a;
	*pa = 20;
	return 0;
	//cout << "&a=" << &a << endl;
	//cout << "&ra=" << &ra << endl;
	return 0;
}
/*
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

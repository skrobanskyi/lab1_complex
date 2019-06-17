// Complex.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//#include "stdafx.h";
//using namespace std;
#include "pch.h"
#include <iostream>

class MyComplex
{

private:
	double Re, Im;
public:
	MyComplex(double InitRe = 0, double InitIm = 0)
	{
		Re = InitRe;
		Im = InitIm;
	};
	~MyComplex()
	{
		cout << "In Dectructor\n";
	}
	// +, - , *
	friend istream& operator>> (istream& o, MyComplex& b)
	{
		double a, d;
		o>>a>>d;
		b.SetRe(a);
		b.SetIm(d);
		return o;
	}

	friend ostream& operator<< (ostream& o, MyComplex& b)
	{
		o << "Re=" << b.GetRe() << ", Im=" << b.GetIm();
		return o;
	}

	friend MyComplex& operator+ (MyComplex a, MyComplex b)
	{
		MyComplex c;
		c.SetRe(a.GetRe() + b.GetRe()); // c.Re = a.Re + b.Re;
		c.SetIm(a.GetIm() + b.GetIm());
		//cout << c;
		return c;
	}
	friend MyComplex operator+ (MyComplex a, double b)
	{
		MyComplex c;
		c.SetRe(a.GetRe() + b);
		c.SetIm(a.GetIm());
		return c;
	}
	MyComplex& operator= (MyComplex b)
	{
		Re = b.GetRe();
		Im = b.GetIm();
		return(*this);
	}
	friend MyComplex operator+ (double a, MyComplex b)
	{
		return(b + a);
	}

	friend MyComplex operator- (MyComplex a, MyComplex b)
	{
		MyComplex c;
		c.SetRe(a.GetRe() - b.GetRe());
		c.SetIm(a.GetIm() - b.GetIm());
		return c;
	}

	friend MyComplex operator- (MyComplex a, double b)
	{
		MyComplex c;
		c.SetRe(a.GetRe() - b);
		c.SetIm(a.GetIm());
		return c;
	}

	friend MyComplex operator- (double a, MyComplex b)
	{
		MyComplex c;
		c.SetRe(a - b.GetRe());
		c.SetIm(0 - b.GetIm());
		return c;
	}

	friend MyComplex operator* (MyComplex a, MyComplex b)
	{
		MyComplex c;
		double x1 = a.GetRe();
		double x2 = b.GetRe();
		double y1 = a.GetIm();
		double y2 = b.GetIm();
		c.SetRe(x1 * x2 - y1 * y2);
		c.SetIm(x1 * y2 + y1 * x2);
		return c;
	}

	friend MyComplex operator* (MyComplex a, double b)
	{
		MyComplex c;
		c.SetRe(a.GetRe() * b);
		c.SetIm(a.GetIm() * b);
		return c;
	}

	friend MyComplex operator* (double a, MyComplex b)
	{

		return (b * a);
	}

	double GetRe()
	{
		return Re;
	};
	double GetIm()
	{
		return Im;
	};
	int SetRe(double newVal)
	{
		Re = newVal;
		return 1;
	};
	int SetIm(double newVal)
	{
		Im = newVal;
		return 1;
	};
};
using namespace std;
int main()
{
	MyComplex A(1,1), B(1), C(1), D(1, -5), E(5, 2);
	//C = 2 * E;
	C = A + B;	
	cout << C;
	C = A + 10.5;
	cout << C;
	C = 10.5 + A;
	cout << C;
	cin >> B;
	//C = B + A;
	//cout << C;
	C = A + B + C + D;
	C = A = B = C;
	cin >> A >> B >> C;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

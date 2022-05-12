#include <iostream>
#include<Windows.h>
#include "Money.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool res;
	Money a(0, 0), b(0, 0);
	double x;

	do
	{
		try
		{
			res = true;

			cout << "Enter a value of \"a\":"; cin >> a;
			cout << "Enter a value of \"b\":"; cin >> b;

			Money c(a - b);
			cout << "�i��i����� ����: " << c;
			cout << endl << endl;

			cout << "��i� = "; cin >> x;
			cout << endl;

			Money d(a * x);
			cout << "���������� ��������: " << d;
			cout << endl << endl;

			cout << "���i������ ���: " << endl;

			if (a == b)
			{
				cout << a.GetHrn() << "," << a.GetKop() << " == "
					<< b.GetHrn() << "," << b.GetKop() << endl << endl;
			}

			if (a != b)
			{
				cout << a.GetHrn() << "," << a.GetKop() << " != "
					<< b.GetHrn() << "," << b.GetKop() << endl << endl;
			}

			if (a > b)
			{
				cout << a.GetHrn() << "," << a.GetKop() << " > "
					<< b.GetHrn() << "," << b.GetKop() << endl << endl;
			}

			if (a < b)
			{
				cout << a.GetHrn() << "," << a.GetKop() << " < "
					<< b.GetHrn() << "," << b.GetKop() << endl << endl;
			}

			if (a >= b)
			{
				cout << a.GetHrn() << "," << a.GetKop() << " >= "
					<< b.GetHrn() << "," << b.GetKop() << endl << endl;
			}

			if (a <= b)
			{
				cout << a.GetHrn() << "," << a.GetKop() << " <= "
					<< b.GetHrn() << "," << b.GetKop() << endl << endl;
			}

			cout << "I��������/��������� � ���� ������: " << endl;

			cout << "a++: " << a++ << endl;
			cout << "res: " << a << endl;
			cout << "++a: " << ++a << endl;

			cout << "a--: " << a-- << endl;
			cout << "res: " << a << endl;
			cout << "--a: " << --a << endl;
		}
		catch (invalid_argument ex)
		{
			res = false;
			cerr << ex.what() << endl;
		}
		catch (MyException& ex)
		{
			res = false;
			cerr << ex.What() << endl;
		}
		catch (Exception* ex)
		{
			res = false;
			cerr << ex->What() << endl;
		}
	} while (!res);

	system("pause");
	return 0;
}
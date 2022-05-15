#include "Fraction.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Fraction count: " << Object::Count() << endl;

	bool result;
	Fraction f1, f4;
	cout << "Enter first number" << endl;
	cin >> f1;
	cout << "Chuslo 1:" << f1 << endl;
	do
	{
		try
		{
			result = true;
			cout << "Enter second number" << endl;
			cin >> f4;
			cout << "Chuslo 2:" << f4 << endl;
		}
		catch (Error_ex& e)
		{
			result = false;
			cerr << e.What() << endl;
		}
		catch (bad_exception e)
		{
			result = false;
			cerr << e.what() << endl;
		}
		catch (MyError& e)
		{
			result = false;
			cerr << e.What() << endl;
		}
		catch (const char* e)
		{
			result = false;
			cerr << e << endl;
		}
	} while (!result);

	cout << "Sub = " << f1 - f4 << endl;
	int f;
	f = f1 < f4;
	cout << "f1 < f4 - " << f << endl;
	f = f1 == f4;
	cout << "f1 == f4 - " << f << endl;
	f = f1 > f4;
	cout << "f1 > f4 - " << f << endl;
	f = f1 <= f4;
	cout << "f1 <= f4 - " << f << endl;
	f = f1 != f4;
	cout << "f1 != f4 - " << f << endl;
	f = f1 >= f4;
	cout << "f1 >= f4 - " << f << endl;

	cout << "Chuslo 1 = " << f1 << endl;
	cout << ++f1 << endl;
	cout << --f1 << endl;
	cout << f1++ << endl;
	cout << f1-- << endl;

	cout << "Fraction count: " << Object::Count();

	return 0;
}

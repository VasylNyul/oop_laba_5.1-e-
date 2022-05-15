#include "Fraction.h"
#include "Error_ex.h"
#include "MyError.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <sstream>

using namespace std;

Fraction::Fraction()
	: first(0), second(0)
{}

Fraction::Fraction(long f,short s)
{
	set_a(f); set_b(s);
}

Fraction::Fraction(const Fraction& f)
{
	*this = f;
}
Fraction::operator string() const
{
	stringstream ss;

	ss << "Zufra = " << first << "," << second << endl;

	return ss.str();
}

Fraction& Fraction::operator ++()
{
	first++;
	return *this;
}

Fraction& Fraction::operator --()
{
	first--;
	return *this;
}

Fraction Fraction::operator ++(int)
{
	Fraction t(*this);
	second++;
	return t;
}

Fraction Fraction::operator --(int)
{
	Fraction t(*this);
	second--;
	return t;
}

ostream& operator <<(ostream& out, const Fraction& f)
{
	out << string(f);
	return out;
}
istream& operator >>(istream& in, Fraction& a) throw(Error_ex,  bad_exception, MyError, char)
{
	cout << "Zila chastuna = "; in >> a.first;
	cout << "Drobova chastuna = "; in >> a.second;

	if (a.first == 0 && a.second < 0)
		throw Error_ex("Invalid_argument");
	else if (a.first < 0 && a.second < 0)
		throw bad_exception();
	else if (a.first > 0 && a.second < 0)
		throw MyError("My exception");
	else if (a.first == 0 && a.second == 0)
		throw "Exception";

	return in;
}

Fraction operator - (const Fraction& x, const Fraction& y)
{
	return Fraction(x.first - y.first, x.second - y.second);
}

bool operator < (Fraction& f, Fraction& s)
{
	return f.first < s.first || f.first == s.first && f.second < s.second;
}

bool operator == (Fraction& f, Fraction& s)
{
	return f.first == s.first && f.second == s.second;
}

bool operator > (Fraction& f, Fraction& s)
{
	return f.first > s.first || f.first == s.first && f.second > s.second;
}
bool operator <= (Fraction& f, Fraction& s)
{
	return !(f.first < s.first || f.first == s.first && f.second < s.second);
}

bool operator != (Fraction& f, Fraction& s)
{
	return !(f.first == s.first && f.second == s.second);
}

bool operator >= (Fraction& f, Fraction& s)
{
	return !(f.first > s.first || f.first == s.first && f.second > s.second);
}


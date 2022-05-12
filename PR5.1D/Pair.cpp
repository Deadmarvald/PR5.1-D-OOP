#include "Pair.h"

using namespace std;

void Pair::SetHrn(long value)
{
	if (value < 0)
	{
		throw Exception("Numbers must be bigger than 0!");
	}
	else
	{
		hrn = value;
	}
}

void Pair::SetKop(unsigned long value)
{
	if (value < 0)
	{
		throw Exception("Numbers must be bigger than 0!");
	}
	else
	{
		kop = value;
	}
}

Pair::Pair(const long x, const unsigned long y) : hrn(x), kop(y)
{ }

Pair::Pair(const Pair& r)
{
	hrn = r.hrn;
	kop = r.kop;
}

Pair::~Pair(void)
{ }

Pair::operator string() const
{
	stringstream ss;
	ss << "( " << GetHrn() << ", " << GetKop() << " )";

	return ss.str();
}

ostream& operator << (ostream& out, const Pair& r)
{
	return out << (string)r;
}

istream& operator >> (istream& in, Pair& r)
{
	long hrn;
	unsigned long kop;

	cout << "a = "; in >> hrn;
	cout << "b = "; in >> kop;

	if (hrn < 0 || kop < 0)
	{
		throw MyException("Numbers must be bigger than 0!!!");
	}
	else
	{
		r.SetHrn(hrn);
		r.SetKop(kop);
	}

	return in;
}
#include "Money.h"
#include <string>
#include <sstream>

using namespace std;

Money::Money(const long x, const unsigned long y)
{
	if (x < 0 || y < 0)
	{
		throw invalid_argument("Numbers must be bigger than 0!");
	}
	else
	{
		long a = x;
		unsigned long b = y;

		while (b > 99)
		{
			b -= 100;
			a++;
		}

		SetHrn(a);
		SetKop(b);
	}
}

Money::Money(double z)
{
	if (z < 0)
	{
		throw invalid_argument("Numbers must be bigger than 0!");
	}
	else
	{
		long a = (long)z;
		z -= a;
		z *= 100;
		unsigned long b = (unsigned long)z;

		while (b > 99)
		{
			b -= 100;
			a++;
		}

		SetHrn(a);
		SetKop(b);
	}
}

Money::Money(const Money& r)
{
	int a = r.GetHrn();
	int b = r.GetKop();

	while (b > 99)
	{
		b -= 100;
		a++;
	}
	while (b < -99)
	{
		b += 100;
		a--;
	}

	SetHrn(a);
	SetKop(b);
}

Money::~Money(void)
{ }

Money operator -(const Money& l, const Money& r)
{
	Money t;

	long a = l.GetHrn() - r.GetHrn();
	unsigned long b = l.GetKop() - r.GetKop();

	t.SetHrn(a);
	t.SetKop(b);

	return t;
}

Money operator *(const Money& l, const double k)
{
	Money t;

	long a = (l.GetHrn() * k);
	unsigned long b = (l.GetKop() * k);

	while (b > 99)
	{
		b -= 100;
		a++;
	}

	t.SetHrn(a);
	t.SetKop(b);

	return t;
}

Money operator *(const double k, const Money& r)
{
	Money t;

	long a = r.GetHrn() * k;
	unsigned long b = r.GetKop() * k;

	while (b > 99)
	{
		b -= 100;
		a++;
	}

	t.SetHrn(a);
	t.SetKop(b);

	return t;
}

bool Money::operator ==(const Money& x)
{
	return this->GetHrn() == x.GetHrn() && this->GetKop() == x.GetKop();
}

bool Money::operator !=(const Money& x)
{
	return !(this->GetHrn() == x.GetHrn() && this->GetKop() == x.GetKop());
}

bool Money::operator >(const Money& x)
{
	if (this->GetHrn() > x.GetHrn())
	{
		return true;
	}

	if (this->GetHrn() == x.GetHrn())
	{
		if (this->GetKop() > x.GetKop())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	if (this->GetHrn() < x.GetHrn())
	{
		return false;
	}
}

bool Money::operator <(const Money& x)
{
	if (this->GetHrn() < x.GetHrn())
	{
		return true;
	}

	if (this->GetHrn() == x.GetHrn())
	{
		if (this->GetKop() < x.GetKop())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	if (this->GetHrn() > x.GetHrn())
	{
		return false;
	}
}

bool Money::operator >=(const Money& x)
{
	if (this->GetHrn() > x.GetHrn())
	{
		return true;
	}

	if (this->GetHrn() == x.GetHrn())
	{
		if (this->GetKop() > x.GetKop())
		{
			return true;
		}

		if (this->GetKop() == x.GetKop())
		{
			return true;
		}

		if (this->GetKop() < x.GetKop())
		{
			return false;
		}
	}

	if (this->GetHrn() < x.GetHrn())
	{
		return false;
	}
}

bool Money::operator <=(const Money& x)
{
	if (this->GetHrn() < x.GetHrn())
	{
		return true;
	}

	if (this->GetHrn() == x.GetHrn())
	{
		if (this->GetKop() < x.GetKop())
		{
			return true;
		}

		if (this->GetKop() == x.GetKop())
		{
			return true;
		}

		if (this->GetKop() > x.GetKop())
		{
			return false;
		}
	}

	if (this->GetHrn() > x.GetHrn())
	{
		return false;
	}
}

Money& Money::operator ++()
{
	int a = this->GetHrn();
	int b = this->GetKop();
	a++;
	b++;

	this->SetHrn(a);
	this->SetKop(b);

	return *this;
}

Money& Money::operator --()
{
	int a = this->GetHrn();
	int b = this->GetKop();
	a--;
	b--;

	this->SetHrn(a);
	this->SetKop(b);

	return *this;
}

Money Money::operator ++(int)
{
	Money t(*this);

	int a = this->GetHrn();
	int b = this->GetKop();
	a++;
	b++;

	this->SetHrn(a);
	this->SetKop(b);

	return t;
}

Money Money::operator --(int)
{
	Money t(*this);

	int a = this->GetHrn();
	int b = this->GetKop();
	a--;
	b--;

	this->SetHrn(a);
	this->SetKop(b);

	return t;
}
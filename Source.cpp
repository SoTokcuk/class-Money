#include "Header.h"
#include<iostream>
using namespace std;
Money::Money(double pound, double shilling, double penny)
{
	if (shilling > 20 || penny > 12 || pound > 1000000000)
	{
		throw "wrong amount of money";
	}
	Pound = pound;
	Shillings = shilling;
	Penny = penny;
}
bool Money::operator == (const Money& m)
{
	return (Pound * 480 + Shillings * 24 + Penny * 2 == m.Pound * 480 + m.Shillings * 24 + m.Penny * 2);
}
Money Money::operator + (const Money& m) const
{
	return Money(Pound + m.Pound, Shillings + m.Shillings, Penny + m.Penny);
}
bool Money::operator != (const Money& m)
{
	return (!(*this == m));
}
Money Money::operator - (const Money& m) const
{
	return Money(Pound - m.Pound, Shillings - m.Shillings, Penny - m.Penny);
}
bool Money::operator > (const Money& m)
{
	return (Pound * 480 + Shillings * 24 + Penny * 2 > m.Pound * 480 + m.Shillings * 24 + m.Penny * 2);
}
bool Money::operator<=(const Money& m)
{
	return (!(*this >= m) || (*this == m));
}
Money Money::operator-()
{
	return Money(-Pound, -Shillings, -Penny);
}
bool Money::operator >= (const Money& m)
{
	return ((*this > m) || (*this == m));
}
bool Money::operator < (const Money& m)
{
	return (!(*this > m) && (*this != m));
}
void Money::setPound(double pound)
{
	Pound = pound;
}
Money::Money()
{
	Shillings = 0;
	Pound = 0;
	Penny = 0;
}
void Money::setShilling(double shillings)
{
	if (shillings > 20)
	{
		throw "wrong amount of money";
	}
	Shillings = shillings;

}
void Money::setPenny(double penny)
{
	if (penny > 12)
	{
		throw "wrong amount of money";
	}
	Penny = penny;
}
double Money::getPound() const
{
	return Pound;
}

double Money::getShilling() const
{
	return Shillings;
}

double Money::getPenny() const
{
	return Penny;
}
std::ostream& operator << (std::ostream& out, const Money& m)
{
	if (m.Pound == 0 && m.Shillings == 0 && m.Penny == 0)
	{
		out << "the balance of money is 0";
		return out;
	}
	else
	{
		if (m.Pound == 0 && m.Penny != 0 && m.Shillings != 0)
		{
			out << m.Shillings << "sh." << m.Penny << "p.";
			return out;
		}
		if (m.Shillings == 0 && m.Pound != 0 && m.Penny != 0)
		{
			out << m.Pound << "pd." << m.Penny << "p.";
			return out;
		}
		if (m.Penny == 0 && m.Pound != 0 && m.Shillings != 0)
		{
			out << m.Pound << "pd." << m.Shillings << "sh.";
			return out;
		}
		if (m.Pound != 0 && m.Shillings != 0 && m.Penny != 0)
		{
			out << m.Pound << "pd." << m.Shillings << "sh." << m.Penny << "p.";
			return out;
		}
		if (m.Pound == 0 && m.Shillings == 0 && m.Penny != 0)
		{
			out << m.Penny << "p.";
			return out;
		}
		if (m.Pound != 0 && m.Shillings == 0 && m.Penny == 0)
		{
			out << m.Pound << "pd.";
			return out;
		}
		if (m.Pound == 0 && m.Shillings != 0 && m.Penny == 0)
		{
			out << m.Shillings << "sh.";
			return out;
		}
	}
}

Money operator += (Money& m, const Money& m1)
{
	return Money(m.Pound += m1.Pound, m.Shillings += m1.Shillings, m.Penny += m1.Penny);
}

Money operator -= (Money& m, const Money& m1)
{
	return Money(m.Pound -= m1.Pound, m.Shillings -= m1.Shillings, m.Penny -= m1.Penny);
}



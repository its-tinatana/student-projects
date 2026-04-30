#include <iostream>
using namespace std;

struct fraction
{
	int numerator;
	int denominator;

	fraction(int n, int d)
	{
		numerator = n;
		denominator = d;
	}
};

fraction add(fraction f1, fraction f2)
{

int num = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
int den = f1.denominator * f2.denominator;

return fraction(num, den);
}

int gcd(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

fraction reduce(fraction f)
{
	int g = gcd(f.numerator, f.denominator);
	return fraction(f.numerator / g, f.denominator / g);
}


int main()
{
	fraction f1(1,3);
fraction f2(4,7);
 
fraction result = reduce(add(f1, f2));
cout  << f1.numerator << "/" << f1.denominator << " + " << f2.numerator << "/" << f2.denominator <<endl;
cout << "= " << result.numerator << "/" << result.denominator << endl;
return 0;
}


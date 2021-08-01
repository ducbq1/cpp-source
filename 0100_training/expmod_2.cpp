#include <iostream>
#include <cmath>
using namespace std;

main()
{
	//456456456456456456
	//123123123123
	unsigned long long a, b, result = 1;
	cin >> a >> b;
	unsigned long long cont[65];
	int c = 1000000007;
	unsigned long long exponent = 1;
	cont[0] = a % c;
	int lim = floor(log2(b));
	int count = 1;
	while (count <= lim)
	{
		exponent *= 2;
		cont[count] = (cont[count - 1] * cont[count - 1]) % c;
		//cout << "element at " << count << " = " << cont[count] << endl;
		count += 1;
	}

	count -= 1;
	result *= cont[count];
	b -= exponent;
	while (b != 0)
	{
		//cout << "b value = " << b << endl;
		count = floor(log2(b));
		result *= cont[count];
		result = result % c;
		//cout << "element at " << count << " = " << result << endl;
		b -= pow(2, count);
	}

	cout << result << endl;
}
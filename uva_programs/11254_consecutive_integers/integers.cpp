#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

const double I = -5;

int main()
{

	double sum;
	double k, n1, n2;

	cin >> sum;
	while (sum != -1)
	{

		if (sum == I)
		{
			cout << "\nIMPORTANT CASE\n\n";
		}

		int limit = floor(sqrt(sum * 2));

		for (int i = 1; i <= limit; i++)
		{

			double temp_k = i;
			double temp_n1 = ceil(((sum / temp_k) - (temp_k / 2) + 0.5));
			double temp_n2 = temp_n1 + temp_k - 1;

			if (sum == I)
			{
				cout << "\nTEMP K\t" << temp_k << endl;
				cout << "TEMP N1\t" << temp_n1 << endl;
				cout << "TEMP N2\t" << temp_n2 << endl;
			}

			if ((temp_k * (temp_n1 + temp_n2)) / 2 == sum)
			{

				k = temp_k;
				n1 = temp_n1;
				n2 = temp_n2;
			}
		}

		cout << fixed << setprecision(0) << sum << " = " << n1 << " + ... + " << n2 << '\n';

		if (sum == I)
		{
			cout << "\nEND OF IMPORTANT CASE\n\n";
		}

		cin >> sum;
	}
}
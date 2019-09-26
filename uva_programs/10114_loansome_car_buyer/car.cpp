#include<iostream>
using namespace std;

int main() {

	int months, records;
	double down, loan;

	cin >> months >> down >> loan >> records;
	while (months >= 0) {
		double depreciation[101];
		for (int i = 0; i < 101; i++) {
			depreciation[i] = -1;
		}
		//Get the depreciation records
		for (int i = 0; i < records; i++) {
			int m; //month
			double d; //depreciation
			cin >> m >> d;
			depreciation[m] = d;
		}
		//Fill in the missing gaps in the depreciation records
		for (int i = 0; i <= months; i++) {
			if (depreciation[i] == -1) {
				depreciation[i] = depreciation[i - 1];
			}
		}

		//Initialize values to post-month-zero
		double value = (loan + down) * (1 - depreciation[0]);
		double debt = loan;
		double monthly = loan / (double)months;
		if (debt >= value) {
			//Loop through every month. Yes, every month. Efficiency be damned.
			for (int i = 1; i <= months; i++) {
				value *= (1 - depreciation[i]);
				debt -= monthly;
				if (debt < value) {
					cout << i;
					i == 1 ? cout << " month\n" : cout << " months\n";
					break;
				}
			}
		}
		else {
			cout << "0 months\n";
		}

		cin >> months >> down >> loan >> records;
	}

}
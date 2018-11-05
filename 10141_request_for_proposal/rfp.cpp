#include <iostream>
#include<string>
using namespace std;
int main() {
	int counter = 1;
	int numReqs, numProps;
	cin >> numReqs >> numProps;
	while (!(numReqs == 0 && numProps == 0)) {
		int best_numReqs = 0, p_numReqs;
		float best_price = -100.00, p_price;
		string best_name, p_name;
		for (int i = 0; i <= numReqs; i++) {
			cin.ignore(10000, '\n');
		}
		for (int i = 0; i < numProps; i++) {
			getline(cin, p_name);
			cin >> p_price >> p_numReqs;
			for (int j = 0; j <= p_numReqs; j++) {
				cin.ignore(10000, '\n');
			}
			if (best_numReqs < p_numReqs || best_price < 0
				|| (best_numReqs == p_numReqs && best_price > p_price)) {
				best_name = p_name;
				best_price = p_price;
				best_numReqs = p_numReqs;
			}
		}
		if (counter != 1) {
			cout << "\n";
		}
		cout << "RFP #" << counter << '\n';
		cout << best_name << '\n';
		counter++;
		cin >> numReqs >> numProps;
	}
	return 0;
}
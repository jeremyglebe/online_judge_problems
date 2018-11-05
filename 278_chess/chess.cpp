#include<iostream>
#include<math.h>
using namespace std;

int main() {

	int loops;
	char rank;
	int rows, cols;
	int max;

	cin >> loops;
	for (int i = 0; i < loops; i++) {

		cin >> rank >> rows >> cols;

		/* Rooks and queens are actually handled in the same way
		 * Rooks basically amount to the length of the diagonal, because each
		 * rook cannot share a row or column. In essence, it is the value of
		 * the smaller of the two measurements (rows or columns).
		 * Queens use the same value because they cannot share a row or column
		 * either. They also cannot share a diagonal but this only affects the
		 * problem of PLACEMENT, not our problem here of total amount.
		*/
		if (rank == 'Q' || rank == 'r') {
			max = rows > cols ? cols : rows;
		}
		/* Kings are a little more interesting. Basically they skip a space
		 * each placement, going in either direction. So we can measure by rows
		 * or by columns. We'll arbitrarily pick rows first. That means we skip
		 * every second row. Within each row, place a king every second column.
		 * To achieve this mathematically, we can multiply the values of half
		 * the rows (rounded up) and half the columns (rounded up).
		*/
		else if (rank == 'K') {
			max = ceil((double)rows / 2) * ceil((double)cols / 2);
		}
		/* The formula for the knight is similar to the formula for the king,
		 * except we now multiply the two values before dividing them by 2. We
		 * still round up.
		*/
		else if (rank == 'k') {
			max = ceil(((double)rows * (double)cols) / 2);
		}
		else {
			max = -1;
		}

		cout << max << '\n';
	}

	return 0;

}
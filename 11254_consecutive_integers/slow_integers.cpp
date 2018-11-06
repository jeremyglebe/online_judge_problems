#include<iostream>
#include<math.h>
using namespace std;

int main(){

	long sum;
	int k, n1, n2;
	
	cin >> sum;
	while( sum != -1 ){
		
		k = 0;
		for(long long i = 1; i <= sum; i++){
			
			int temp_k = ceil( ( ( ( ( -2 ) * i ) + 1 ) + sqrt( pow( ( 2 * i ) - 1, 2 ) - ( 4 * (-2) * sum ) ) ) / 2 );
			int temp_n1 = i;
			int temp_n2 = temp_n1 + temp_k - 1;
			
			if (temp_k > k && (temp_k * (temp_n1 + temp_n2)) / 2 == sum){
				
				k = temp_k;
				n1 = temp_n1;
				n2 = temp_n2;
				
			}
			
		}
		
		cout << "Sum: " << sum << " K: " << k << endl;
		cout << sum << " = " << n1 << " + ... + " << n2 << '\n';
		
		cin >> sum;
		
	}

}
#include<iostream>
#include<math.h>
using namespace std;

const long long I = 152;

int main(){

	long long sum, k, n1, n2;
	
	cin >> sum;
	while( sum != -1 ){
		
		if (sum == I){
			cout << "\nIMPORTANT CASE\n\n";
		}
		
		int limit = ceil(sqrt(sum * 2));
		
		for (long long i = 1; i <= limit; i++){
			
			long long temp_k = i;
			long long temp_n1 = ((sum / temp_k) - (temp_k / 2) + 0.5);
			long long temp_n2 = temp_n1 + temp_k - 1;
			
			if (sum == I){
				cout << "\nTEMP K\t" << temp_k << endl;
				cout << "TEMP N1\t" << temp_n1 << endl;
				cout << "TEMP N2\t" << temp_n2 << endl;
			}
			
			if ((long long)(temp_k * (temp_n1 + temp_n2)) / 2 == sum){
				
				k = temp_k;
				n1 = temp_n1;
				n2 = temp_n2;
				
			}
			
		}
		
		cout << sum << " = " << n1 << " + ... + " << n2 << '\n';
		
		if (sum == I){
			cout << "\nEND OF IMPORTANT CASE\n\n";
		}
		
		cin >> sum;
		
	}

}
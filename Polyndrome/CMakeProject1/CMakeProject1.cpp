// CMakeProject1.cpp: определяет точку входа для приложения.
//

#include "CMakeProject1.h"
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		bool flag = false;
		if (x >= 0) {

			vector<int> digits;
			vector<int> inverse_digits;
			int64_t tmp = 10;
			int size = 0;

			while (x / tmp > 0) {
				size++;
				tmp *= 10;
			}

			size++;

			cout << "Size:" << size << endl;

			int ost = x;
			tmp = 10;

			for (int i = 0; i <= size - 1; i++) {

				inverse_digits.push_back(ost % 10);
				cout << "Inv digits:" << ost % 10 << endl;
				ost = ost / tmp;


			}
			cout << endl;
			int* ptr = inverse_digits.data();

			for (int i = size - 1; i >= 0; i--) {
				cout << "Dir digits:" << *(ptr + i) << endl;
				digits.push_back(*(ptr + i));
			}

			int64_t inverse = 0;
			int64_t direct = 0;

			int* ptr2 = digits.data();

			int64_t tmp2 = 1;


			for (int i = 0; i < size; i++) {
				inverse += *(ptr + i) * tmp2;
				tmp2 *= 10;
			}
			cout << endl;
			for (int i = size -1 ; i >= 0; i--) {
				cout << "DIRECT COUNT:" << *(ptr2 + i) << " " << tmp2 << endl;
				direct += *(ptr2 + i) * tmp2;
				tmp2 /= 10;
			}
			direct /= 10;
			cout << inverse << "  " << direct << endl;

			if (inverse == direct) {
				flag = true;
			}
		}

		return flag;
	}
};
int main()
{
	Solution a;
	bool tmp = a.isPalindrome(1000000001);
	cout << tmp << endl;
	return 0;
}

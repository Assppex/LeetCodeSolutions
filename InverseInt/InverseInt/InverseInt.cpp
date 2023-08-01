// InverseInt.cpp: определяет точку входа для приложения.
//

#include "InverseInt.h"
#include "math.h"
using namespace std;

class Solution {
public:
	int reverse(int x) {
		//stack<int> digits;
		int tmp = x;
		int size = 1;
		while (tmp / 10 != 0) {
			size++;
			tmp = tmp / 10;
		}
		int ans = 0;
		tmp = 0;
		for (int i = size - 1; i > 0; i--) {
			ans += (x % 10);
			x = x / 10;
			tmp = ans;
			if (ans != 0 && (INT_MAX / ans < 10 || INT_MAX / ans < -10 ||  (INT_MIN + 1) / ans < 10 || (INT_MIN + 1) / ans < -10)) {
				cout << INT_MAX / ans << " " << (INT_MIN+1) / ans << endl;
				return false;
			}
			ans *= 10;
			if (ans / 10 != tmp) {
				return false;
			}
		}
		ans += x;
		if (ans > INT_MAX || ans < INT_MIN) {
			return 0;
		}
		return ans;
    }
};

int main()
{
	Solution a;
	cout << a.reverse(120)<< endl;
	return 0;
}

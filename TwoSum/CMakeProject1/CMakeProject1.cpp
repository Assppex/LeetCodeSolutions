// CMakeProject1.cpp: определяет точку входа для приложения.
//
#include "CMakeProject1.h"
#include <vector>

using namespace std;

class Solution {
public:
	vector <int> twoSum(vector<int>& nums, int target) {
		vector<int>need_nums;
		int* ptr = nums.data();
		for (int i = 0; i < nums.size(); i++) {
			
			for (int j = i + 1; j < nums.size(); j++) {
				cout << *(ptr + i) + *(ptr + j)  << endl;
				if (*(ptr + i) + *(ptr + j) == target) {
					need_nums.push_back(i);
					need_nums.push_back(j);
					cout << i << endl;
					cout << j << endl;

				}
			}
		}
		return need_nums;
	}
};

int main(int argc, char** argv)
{
	Solution a;
	vector<int> nums;
	vector<int> nums_1;

	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(4);
	//nums.push_back(15);

	a.twoSum(nums, 6);


}

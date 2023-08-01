// MedianOfTwoSortedArrays.cpp: определяет точку входа для приложения.
//

#include "MedianOfTwoSortedArrays.h"
#include <vector>
#include <algorithm>
using namespace std;
void heapify(int arr[], int n, int i)
{
	int largest = i;
	// Инициализируем наибольший элемент как корень
	int l = 2 * i + 1; // левый = 2*i + 1
	int r = 2 * i + 2; // правый = 2*i + 2

	// Если левый дочерний элемент больше корня
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// Если правый дочерний элемент больше, чем самый большой элемент на данный момент
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// Если самый большой элемент не корень
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
		heapify(arr, n, largest);
	}
}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(int arr[], int n)
{
	// Построение кучи (перегруппируем массив)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Один за другим извлекаем элементы из кучи
	for (int i = n - 1; i >= 0; i--)
	{
		// Перемещаем текущий корень в конец
		swap(arr[0], arr[i]);

		// вызываем процедуру heapify на уменьшенной куче
		heapify(arr, i, 0);
	}
}
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}
class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result;
		int* num1ptr = nums1.data();
		int* num2ptr = nums2.data();
		
		for (int i = 0; i < nums1.size(); i++) {
			result.push_back(*(num1ptr + i));
		}

		for (int i = 0; i < nums2.size(); i++) {
			result.push_back(*(num2ptr + i));
		}
		int* ptr = result.data();
		for (int i = 0; i < result.size(); i++) {
			cout << *(ptr + i) << " ";
		}
		cout << endl;
		//heapSort(ptr, result.size());
		sort(ptr,ptr+ result.size());
		printArray(ptr, result.size());
		if (result.size() % 2 == 0) {
			double a = ptr[result.size() / 2 - 1] + ptr[result.size() / 2];
			//cout << ptr[result.size() / 2 - 1] << " "<< ptr[result.size() / 2 ] << endl;
			return a / 2;
		}
		else {
			return ptr[result.size() / 2];
		}
    }
	
};
int main()
{
	Solution a;
	vector<int> one;
	vector<int> two;
	one.push_back(10);
	one.push_back(3);
	one.push_back(11);

	two.push_back(1);
	two.push_back(4);
	two.push_back(9);

	cout << a.findMedianSortedArrays(one,two) << endl;;
	cout << "Hello CMake." << endl;
	return 0;
}

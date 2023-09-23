#include"template.h"

using namespace std;

// Issue of memory leak because can't delete the Heap (don't use new to declare *arr)
template<typename type>
class DynamicArray {
private:
	int size;
	type* arr;
public:
	DynamicArray() {
		cout << "Not set size yet !!" << endl;
		size = 0;
		arr = nullptr;
	}
	void setSize(int size_para) {
		size = size_para;
		arr = new type[size];
		for (int i = 0; i < size; i++) {
			*(arr + i) = NULL;
		}
	}
	int getLength() {
		return size;
	}
	type* getArr() {
		return arr;
	}
	void replaceOrAssign(int position, type value) {
		*(arr + position) = value; //*(a+i) ~~ a[i]
	}
	void insertPosition(int position, type value) {
		if (isFull()) {
			cout << "Already full now. Can't insert" << endl;
			return;
		}
		if (arr[position] == NULL) {
			replaceOrAssign(position, value);
			return;
		}
		for (int i = size; i > position; i--) {
			arr[i] = arr[i - 1];
		}
		*(arr + position) = value;
	}
	void deletePosition(int position, type value) {
		if (arr[position] == NULL) return;
		for (int i = position; i < size; i++) {
			arr[i] = arr[i + 1];
		}
	}
	void checkSpace() { // check what if have space == NULL (avalble space to insert of assign value) 
		for (int i = 0; i < size; i++) {
			if (*(arr + i) == NULL) cout << "Position " << i << " is NULL" << endl;
		}
	}
	void swapElement(int position1, int position2) {
		type temp = arr[position1];
		arr[position1] = arr[position2];
		arr[position2] = temp;
	}
	void selectionSort() {
		for (int i = 0; i < size; i++) {
			for (int j = i + 1; j < size; j++) {
				if (arr[j] < arr[i]) swapElement(i, j);
			}
		}
	}
	void insertSort() {
		for (int i = 1; i < size; i++) {
			type current = arr[i];
			int j = i;
			while (j > 0 && arr[j - 1] > current) {
				arr[j] = arr[j - 1];
				j--;
			}
			arr[j] = current;
		}
	}
	void bubbleSort() {
		int last = size - 1;
		int last_swap = 0;
		while (last > 0) {
			for (int i = 0; i < last; i++) {
				if (arr[i] > arr[i + 1]) {
					swapElement(i, i + 1);
					last_swap = i;
				}
			}
			last = last_swap;
		}
	}
	void merge(int left, int mid, int right) {
		int size_local = right - left + 1;
		type* sortArr = new type[size_local];
		int i = left;
		int j = mid + 1;
		int k = 0;
		while (i <= mid && j <= right) {
			if (arr[i] <= arr[j]) {
				sortArr[k] = arr[i];
				++i;
			}
			else {
				sortArr[k] = arr[j];
				++j;
			}
			k++;
		}
		while (i <= mid) {
			sortArr[k] = arr[i];
			++k;
			++i;
		}
		while (j <= right) {
			sortArr[k] = arr[j];
			++k;
			++j;
		}
		for (k = 0; k < size_local; ++k) {
			arr[left + k] = sortArr[k];
		}
		delete[] sortArr;
	}
	void merge_sort(int left, int right) { //the best
		if (left < right) {
			int mid = (left + right) / 2;
			merge_sort(left, mid);
			merge_sort(mid + 1, right);
			merge(left, mid, right);
		}

	}
	bool isAllEmpty() {
		for (int i = 0; i < size; i++) {
			if (arr[i] != NULL) return false;
		}
		return true;
	}
	bool isFull() {
		for (int i = 0; i < size; i++) {
			if (arr[i] == NULL) return false;
		}
		return true;
	}
	void print() {
		if (size == 0) {
			cout << "Not initialize size yet!!" << endl;
			return;
		}
		for (int i = 0; i < size; i++) {
			if (arr[i] == NULL) cout << "NULL" << " ";
			else cout << *(arr + i) << " ";
		}
		cout << endl;
	}
};

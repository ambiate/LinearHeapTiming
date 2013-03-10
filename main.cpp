//Jonathan Drouillard

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void linearHeap(int*, int&, int);
void buildHeap(int*, int);
void perlocateDown(int*, int, int);

int main() {
	int buffSize = 0, arrSize = 0, *arr;
	clock_t start, end;
	cin >> buffSize;
	arr = new int[buffSize];

        cout << "Sorted" << endl;

	start= clock();
	for(int i = 0; i < buffSize-1; i++) {
		linearHeap(arr, arrSize, i);
	}
	end = clock();
	cout << "Insert: " << (end-start) << "microseconds" << "  --  " << (end-start)/CLOCKS_PER_SEC << "secs" << endl;
	delete arr;arr = new int[buffSize];arrSize = 0;

	start = clock();
	for(int i = 0; i < buffSize-1; i++) {
		arr[i] = i;
		arrSize++;
	}
	buildHeap(arr, arrSize);
	end = clock();
	cout << "Build: " << (end-start) << "microseconds" << "  --  " << (end-start)/CLOCKS_PER_SEC << "secs" << endl;
	delete arr;arr = new int[buffSize]; arrSize = 0;

        cout << "Reversed" << endl;

	start=clock();
	for(int i = buffSize-1; i > 0; i--) {
		linearHeap(arr, arrSize, i);
	}
	end = clock();
	cout << "Insert: " << (end-start) << "microseconds" << "  --  " << (end-start)/CLOCKS_PER_SEC << "secs" << endl;
	delete arr;arr = new int[buffSize];arrSize = 0;

	start = clock();
	for(int i = buffSize-1; i > 0; i--) {
		arr[i] = i;
		arrSize++;
	}
	buildHeap(arr, arrSize);
	end = clock();
	cout << "Build: " << (end-start) << "microseconds" << "  --  " << (end-start)/CLOCKS_PER_SEC << "secs" << endl;
	delete arr;arr = new int[buffSize]; arrSize = 0;

        cout << "Random" << endl;

	start=clock();
	for(int i = 0; i < buffSize-1; i++) {
		srand(i); //use same seed for both for loops.
		linearHeap(arr, arrSize, rand());
	}
	end = clock();
	cout << "Insert: " << (end-start) << "microseconds" << "  --  " << (end-start)/CLOCKS_PER_SEC << "secs" << endl;
	delete arr;arr = new int[buffSize];arrSize = 0;

	start = clock();
	for(int i = buffSize-1; i > 0; i--) {
		srand(i); //use the same seed for both for loops.
		arr[i] = rand();
		arrSize++;
	}
	buildHeap(arr, arrSize);
	end = clock();
	cout << "Build: " << (end-start) << "microseconds" << "  --  " << (end-start)/CLOCKS_PER_SEC << "secs" << endl;
	delete arr;arr = new int[buffSize]; arrSize = 0;

	cin.get();cin.get();cin.get();

	return 0;
}


void linearHeap(int *a, int &arrSize, int x) {
	int hole = ++arrSize;
	for(; hole > 1 && x < a[hole/2]; hole /= 2)
		a[hole] = a[hole/2];
	a[hole] = x;
}
void buildHeap(int *a, int arrSize) {
	for(int i = arrSize/2; i > 0; i--)
		perlocateDown(a, arrSize, i);
}

void perlocateDown(int *a, int arrSize, int hole) {
	int child;
	int tmp = a[hole];

	for(; hole*2 <= arrSize; hole = child) {
		child = hole*2;
		if(child != arrSize && a[child+1] < a[child])
			child++;
		if(a[child] < tmp)
			a[hole] = a[child];
		else
			break;
	}
	a[hole] = tmp;
}
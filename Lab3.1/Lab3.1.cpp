#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <ctime>
#include <map>

using namespace std;

class Lab1{
private: 
	//DEFAULT CONFIG
	int SIZE_ARR,
		MAX_ARR,
		MIN_ARR,
		AFTER_DOT;
	bool DOUBLE_TYPE_ARR;
public:

	// Func for setting config
	bool setConfig(int newSize, int newMax, int newMin, int newAfterDot, bool newType) {
		SIZE_ARR = newSize;
		MAX_ARR = newMax;
		MIN_ARR = newMin;
		AFTER_DOT = newAfterDot;
		DOUBLE_TYPE_ARR = newType;

		return true;
	}


	

	// Func for generate arr
	auto generateArray() {
		double* arr;
		if (DOUBLE_TYPE_ARR) {
			arr = new double[SIZE_ARR];
			float countRound = 1;
			srand(time(0));
			for (int i = 0; i < AFTER_DOT; i++) {
				countRound *= 10;
			}
			for (int i = 0; i < SIZE_ARR; i++) {
				arr[i] = (int)(((double)rand()/(double)RAND_MAX * (MAX_ARR - MIN_ARR) + MIN_ARR) * countRound)/(countRound +0.0);
			}
		} else {
			arr = new double[SIZE_ARR];
			srand(time(0));
			for (int i = 0; i < SIZE_ARR; i++) {
				arr[i] = rand() % MAX_ARR + MIN_ARR;
			}
		}
		return arr;
	}


	// Func for print arr
	bool printArray(double data[], float size) {
		cout << "Array: [";
		for (int i = 0; i < size; i++) {
			if (i != size - 1) {
				cout << data[i] << ",";
			}
			else {
				cout << data[i];
			}
		}
		cout << "]" << endl;
		return true;
	}
	
	//Func for get sum array's elements
	auto sumArray(double data[], float size) {
		auto sum = 0.0;
		for (int i = 0; i < size; i++) {
			sum += data[i];
		}
		return sum;
	}

	//Func for get max element in array
	auto maxArray(double data[], float size) {
		auto max = 0.0;
		for (int i = 0; i < size; i++) {
			if (data[i] > max) {
				max = data[i];
			}
		}
		return max;
	}

	//Func for get many max elements in array
	auto manyMaxArray(double data[], float size, float numberElem) {
		double* arrMax = new double[numberElem];
		auto max = 0.0;
		for (int i = 0; i < size; i++) {
			if (data[i] > max) {
				max = data[i];
			}
		}
		arrMax[0] = max;
		max = 0.0;
		for (int j = 1; j < numberElem; j++) {
			for (int i = 0; i < size; i++) {
				if (data[i] > max and data[i] < arrMax[j-1]) {
					max = data[i];
					arrMax[j] = data[i];
				}
			}
			max = 0.0;
		}
		return arrMax;
	}

	//Func for get index max element
	auto indexMaxArray(double data[], float size) {
		auto max = 0.0;
		auto id = 0;
		for (int i = 0; i < size; i++) {
			if (data[i] > max) {
				max = data[i];
				id = i;
			}
		}
		return id;
	}


	//Func for get min element in array
	auto minArray(double data[], float size) {
		auto min = data[0];
		for (int i = 0; i < size; i++) {
			if (data[i] < min) {
				min = data[i];
			}
		}
		return min;
	}

	//Func for get many min elements in array
	auto manyMinArray(double data[], float size, float numberElem) {
		double* arrMin = new double[numberElem];
		auto min = data[0];
		for (int i = 0; i < size; i++) {
			if (data[i] < min) {
				min = data[i];
			}
		}
		arrMin[0] = min;
		min = data[0];
		for (int j = 1; j < numberElem; j++) {
			for (int i = 0; i < size; i++) {
				if (data[i] < min and data[i] > arrMin[j - 1]) {
					min = data[i];
					arrMin[j] = data[i];
				}
			}
			min = data[0];
		}
		return arrMin;
	}

	//Func for get index min element
	auto indexMinArray(double data[], float size) {
		auto min = data[0];
		auto id = 0;
		for (int i = 0; i < size; i++) {
			if (data[i] < min) {
				min = data[i];
				id = i;
			}
		}
		return id;
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int sizeArray = rand() % 20 + 10;
	int maxArray = rand() % 1000 + 10;
	int minArray = rand() % 1 - 200;

	Lab1 arr;
	bool respConf = arr.setConfig(sizeArray, maxArray, minArray, 4, false);
	if (respConf) {
		double *data = arr.generateArray();
		arr.printArray(data, sizeArray);
		double sum = arr.sumArray(data, sizeArray);
		cout << "Sum: " << sum << endl;
		double max = arr.maxArray(data, sizeArray);
		cout << "Max: " << max << endl;
		double min = arr.minArray(data, sizeArray);
		cout << "Min: " << min << endl;

		double* manyMax = arr.manyMaxArray(data, sizeArray, 4);
		arr.printArray(manyMax, 4);
		double* manyMin = arr.manyMinArray(data, sizeArray, 4);
		arr.printArray(manyMin, 4);

	}
	else {
		cout << "ERROR IN SETTING CONFIG!!";
	}
}

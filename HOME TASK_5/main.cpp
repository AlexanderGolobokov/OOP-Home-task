#include <iostream>
#include <ctime>

#define RAND_RANGE(from, to) (rand() % (to + 1 - from) + from)

void fillMatrixRand(int*** arr, int a, int b) {
	srand(time(nullptr));
	for (int h_ = 0; h_ < a; ++h_) {
		for (int w_ = 0; w_ < b; ++w_) {
			(*arr)[h_][w_] = RAND_RANGE(10, 50);
		}
	}
}

void printMatrix(int**& arr, int a, int b) {
	for (int a_ = 0; a_ < a; ++a_) {
		for (int b_ = 0; b_ < b; ++b_) {
			std::cout << arr[a_][b_] << ((b_ + 1 < b) ? ' ' : '\n');
		}
	}
}

int main() {
	std::setlocale(LC_ALL, ".UTF8");

	int** arr = nullptr;

	std::cout << "Введите размеры двумерного массива (a b): ";
	int arrW = 0, arrH = 0;
	std::cin >> arrH >> arrW;

	arr = new int* [arrH];
	if (!arr) { std::cerr << "Не удалось выделить память.\n"; exit(-1); }
	for (int i = 0; i < arrH; ++i) {
		arr[i] = new int[arrW];
	}

	fillMatrixRand(&arr, arrH, arrW);
	printMatrix(arr, arrH, arrW);

	for (int i = 0; i < arrH; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
}

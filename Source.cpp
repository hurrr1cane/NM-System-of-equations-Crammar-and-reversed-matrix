#include <iostream>
#include "Header.h"

int main(void) {
	double Matrix[N][N] = { {3.01,-0.14,-0.15},{1.11,0.13,-0.75},{0.17,-2.11,0.71} };
	double Solutions[N], FreeMembers[N] = { 1, 0.13,0.17 };

	std::cout << "Matrix:" << std::endl;
	printMatrix34(Matrix, FreeMembers);

	//Cramar method
	std::cout << "\nCrammar Method:" << std::endl;
	CramarMethod(Matrix, FreeMembers, Solutions);
	for (int i = 0; i < N; i++) {
		std::cout << "x" << i + 1 << " = " << Solutions[i] << "\n";
	}

	//Matrix method
	std::cout << "\nMatrix Method:" << std::endl;
	MatrixMethod(Matrix, FreeMembers, Solutions);
	std::cout << "\n";
	for (int i = 0; i < N; i++) {
		std::cout << "x" << i + 1 << " = " << Solutions[i] << "\n";
	}
}
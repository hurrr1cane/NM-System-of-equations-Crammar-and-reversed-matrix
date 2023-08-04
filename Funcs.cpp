#include <iostream>
#include "Header.h"

int printMatrix34(double Matrix[N][N], double row[N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << Matrix[i][j] << " ";
		}
		std::cout << row[i] << std::endl;
	}
	return 1;
}
double Vyznachnyk(double Matrix[N][N]) {
	return (Matrix[0][0] * Matrix[1][1] * Matrix[2][2]\
		+ Matrix[0][1] * Matrix[1][2] * Matrix[2][0]\
		+ Matrix[0][2] * Matrix[1][0] * Matrix[2][1]\
		- (Matrix[0][2] * Matrix[1][1] * Matrix[2][0]\
			+ Matrix[0][1] * Matrix[1][0] * Matrix[2][2]\
			+ Matrix[0][0] * Matrix[1][2] * Matrix[2][1]));
}
int cpyMatrix(double Matrix1[N][N], double Matrix2[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Matrix1[i][j] = Matrix2[i][j];
		}
	}
	return 1;
}
int cpyOneColumn(double Matrix[N][N], double Column[N], int Col) {
	for (int i = 0; i < N; i++) {
		Matrix[i][Col] = Column[i];
	}
	return 1;
}
void CramarMethod(double Matrix[N][N], double FreeMembers[N], double Solutions[N]) {
	double Temp[N][N];

	for (int i = 0; i < N; i++) {
		cpyMatrix(Temp, Matrix);
		cpyOneColumn(Temp, FreeMembers, i);
		Solutions[i] = Vyznachnyk(Temp) / Vyznachnyk(Matrix);
		std::cout << "Determinant " << i + 1 << " = " << Vyznachnyk(Temp) << std::endl;
	}
	std::cout << "Determinant = " << Vyznachnyk(Matrix) << std::endl;
}

int multiplyMatrix(double Matrix[N][N], double Row[N], double Result[N]) {
	for (int i = 0; i < N; i++) {
		Result[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Result[i] += Matrix[i][j] * Row[j];
		}
	}
	return 1;
}
double Minor(double Matrix[N][N], int row, int col) {
	double dob1 = 1, dob2 = 1;
	int count1 = 0, count2 = 0;
	for (int i = 0; i < N; i++) {
		if (i == row) continue;

		for (int j = 0; j < N; j++) {
			if (j == col) continue;
			count1++;
			if (count1 == 1 || count1 == 4) {
				dob1 *= Matrix[i][j];
			}
			if (count1 == 2 || count1 == 3) {
				dob2 *= Matrix[i][j];
			}
		}
	}
	return dob1 - dob2;
}
void transponateMatrix(double Matrix[N][N]) {
	double TempMatr[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			TempMatr[i][j] = Matrix[j][i];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Matrix[i][j] = TempMatr[i][j];
		}
	}
}
void printMatrix(double Matrix[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << Matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
int MatrixMethod(double Matrix[N][N], double FreeMembers[N], double Solutions[N]) {
	double Minors[N][N], determinant;
	determinant = Vyznachnyk(Matrix);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Minors[i][j] = ((i + 1 + j + 1) % 2 == 0) ? Minor(Matrix, i, j) : -Minor(Matrix, i, j);
		}
	}
	std::cout << "Minors matrix: \n";
	printMatrix(Minors);
	transponateMatrix(Minors);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Minors[i][j] /= determinant;
		}
	}
	std::cout << "\nReversed matrix: \n";
	printMatrix(Minors);
	multiplyMatrix(Minors, FreeMembers, Solutions);
	return 1;
}
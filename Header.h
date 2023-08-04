#pragma once

#ifndef HEADER_H
#define HEADER_H
#define N 3
int printMatrix34(double Matrix[N][N], double row[N]);
double Vyznachnyk(double Matrix[N][N]);
int cpyMatrix(double Matrix1[N][N], double Matrix2[N][N]);
int cpyOneColumn(double Matrix[N][N], double Column[N], int Col);
void CramarMethod(double Matrix[N][N], double FreeMembers[N], double Solutions[N]);
int multiplyMatrix(double Matrix[N][N], double Row[N], double Result[N]);
double Minor(double Matrix[N][N], int row, int col);
void transponateMatrix(double Matrix[N][N]);
void printMatrix(double Matrix[N][N]);
int MatrixMethod(double Matrix[N][N], double FreeMembers[N], double Solutions[N]);
#endif
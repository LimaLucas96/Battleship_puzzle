#ifndef FUNCOES_H
#define FUNCOES_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <random>
#include <string.h>
#include <stdio.h>

#define MAX 150

namespace lp{
	int OpenGenerator(std::string *Puzzles);

	void CreateBoard(int Board[MAX][MAX], const int n_row, const int n_col);

	int PrintBoard(int Board[MAX][MAX], const int n_row, const int n_col, int *first,int *last);

	int CheckBoard(int BoardGab[MAX][MAX],int board[MAX][MAX], const int n_row, const int n_col);

	//void PrintGab(int BoardGab[MAX][MAX], const int n_row, const int n_col);

	void WaterRow(int Board[MAX][MAX],  int n_row,  int n_col);

	void WaterCol(int Board[MAX][MAX], const int n_row, const int n_col);
	
	void print_on_gab(int BoardGab[MAX][MAX],int Board[MAX][MAX], const int n_row, const int n_col);
}

#endif
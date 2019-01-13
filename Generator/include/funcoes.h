#ifndef FUNCOES_H
#define FUNCOES_H

#define tam_max 15

#include <iostream>
#include <fstream>

namespace BS{

	void Clear_board(int board[tam_max][tam_max], int n_line, int n_col);

	void ReflectBoardVertical(int board[tam_max][tam_max], int n_line, int n_col);

	void ReflectBoardHorizontal(int board[tam_max][tam_max], int n_line, int n_col);

	void print(std::ofstream &file, int board[tam_max][tam_max], int n_line,int n_col);

	void printTela(int board[tam_max][tam_max], int n_row,int n_col);
}

#endif
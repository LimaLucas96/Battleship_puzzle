#ifndef EMBARCACOES_H
#define EMBARCACOES_H

#define tam_max 15

#include <iostream>
#include <random>

namespace Ship{

	void create_Battleship(int board[tam_max][tam_max], int n_line, int n_col);

	void create_Crouiser(int board[tam_max][tam_max], int n_line, int n_col);

	void create_Destroyer(int board[tam_max][tam_max], int n_line, int n_col);

	void create_Submarine(int board[tam_max][tam_max], int n_line, int n_col);

	void create_water(int board[tam_max][tam_max], int n_line, int n_col);
}

#endif
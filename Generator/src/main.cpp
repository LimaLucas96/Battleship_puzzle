/*
*Linguagem de Progamacao I - DIM0120
*Project Battleship puzzle
*Produced by Lucas Lima Marques de Oliveria.
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "../include/funcoes.h"
#include "../include/Embarcacoes.h"

#define MAX 15 //maximum board size

/*Function responsible for create the battleship board.
*The function receives as input the matrix of the board,
*the number of rows, the number of columns and the destination file.
*/
void create(int board[MAX][MAX], int n_line,int n_col, std::ofstream &file){
		
		BS::Clear_board(board,n_line,n_col);//Clear the board

		Ship::create_Battleship(board,n_line-1,n_col-1);//add the Battleship on the board

		Ship::create_Crouiser(board,n_line-1,n_col-1);//add the Cruisers on the board

		Ship::create_Destroyer(board,n_line-1,n_col-1);//add the Destroyers on the board

		Ship::create_Submarine(board,n_line-1,n_col-1);//add the Submatines on the board

		Ship::create_water(board,n_line,n_col);//add the Water on the board

		BS::print(file,board,n_line,n_col);//add the board on the Generator file

		BS::printTela(board,n_line,n_col);
}

/*Function responsible for Reflect the battleship board.
*The function receives as input the matrix of the board,
*the number of rows, the number of columns and the destination file.
*/
void ReflectBoard(int board[MAX][MAX], int n_line,int n_col, std::ofstream &file){
	
	BS::ReflectBoardHorizontal(board,n_line,n_col);//Reflects the board horizontally

	BS::print(file,board,n_line,n_col);//add the board on the Generator file

	BS::printTela(board,n_line,n_col);

	BS::ReflectBoardVertical(board,n_line,n_col);//Reflects the board vertically

	BS::print(file,board,n_line,n_col);//add the board on the Generator file

	BS::printTela(board,n_line,n_col);

	BS::ReflectBoardHorizontal(board, n_line, n_col);//Reflects the board horizontally

	BS::print(file,board,n_line,n_col);//add the board on the Generator file

	BS::printTela(board,n_line,n_col);
}

int main(int argc, char const *argv[])
{
	int board[MAX][MAX];//Declares the array board

	int num_boards(1);//Variable num_board with pattern equal to one
	int n_row(10);//Variable n_row with pattern equal to ten
	int n_col(10);//Variable num_board with pattern equal to ten
	int aux(0);

	std::ofstream myFile;//Variable for Generator file access

	myFile.open("Generator.txt");//Open Generator file

	//Check if the argc is larger than one
	if(argc > 1){
		for(int i(0);i<=argc;i++){
			if(i==1){
				num_boards=atoi(argv[i]);
			}
			if(i==2){
				n_row=atoi(argv[i]);
			}

			if(i==3){
				n_col=atoi(argv[i]);
			}
		}
	}

	if((n_col<10 || n_col>15) || (n_row<10 || n_row>15) || (num_boards > 120)){
		std::cout<<"number of rows, columns or number of tables out of standard\n";
		std::cout<<"[0>num boards<120] [10>= numLines <= 15] [10>= numColumns <= 15]\n";
		return -1;
	}
	//Record in the Generator file the number of boards, of rows and columns
	myFile<<std::to_string(num_boards)<<"\n";
	myFile<<std::to_string(n_row)<<"\n";
	myFile<<std::to_string(n_col)<<"\n";	

	if(num_boards==1){
		create(board,n_row,n_col,myFile);
	}else{
		int Dif_num = num_boards/4;//Divide the number of boards by four, as they need to generate only one-quarter of the boards ordered
		while(aux<Dif_num){
			create(board,n_row,n_col,myFile);
			ReflectBoard(board,n_row,n_col,myFile);
			aux++;
		}

		//if the number requested by the user is not divisible by 4, the program creates more boards to complete
		if((Dif_num%4) != 0){


			int tam=num_boards-(Dif_num*4);

			while(tam>0){

				create(board,n_row,n_col,myFile);

				tam --;
			}
		}
	}
	

	myFile.close();//Close the generator file

	return 0;
}

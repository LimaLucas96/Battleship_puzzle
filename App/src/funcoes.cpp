#include "../include/funcoes.h"

namespace lp{
	/*Function Responsible for opening the Generator File with the puzzles.It receives as input a string vector and
	return 0 if the file exists or -1 if it doesn't exists.*/
	int OpenGenerator(std::string *Puzzles){

		std::ifstream myFile;
		int aux(0);
		myFile.open("../Generator/Generator.txt");

		//Check if file exists
		if(myFile.is_open()){

			while(!myFile.eof()){
				std::getline(myFile,Puzzles[aux]);//add the file line in vector
				aux++;
			}
		//if it doesn't exist
		}else{
			return -1;
		}
		return 0;
	}

	/*Function responsible for zeroing the array.It receives as input an array of board, the number of rows and the number of columns
	*/
	void CreateBoard(int Board[MAX][MAX], const int n_row, const int n_col){
		for(int i(0);i<n_row;i++){
			for (int j = 0; j < n_col; ++j){
				Board[i][j]=0;
			}
		}
	}

	/*Function Responsible for print the board puzzles in screen.It receives as input an array of board, the number of rows, the number of columns,
	a pointer pointing to the beginning of the vector and another pointing to the end.
	return the number of blank squares.*/
	int PrintBoard(int Board[MAX][MAX], const int n_row, const int n_col, int *first,int *last){
		std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		std::cout<<"  | ";
		int cont (0);

		// print the coordinates of the columns
		for (int i = 0; i < n_col; ++i){
			std::cout<<i+1<<" ";
		}
		std::cout<<"|\n";
		for (int i = 0; i < n_col; ++i){
			std::cout<<"---";
		}

		std::cout<<"\n";
		//prints the board with the representative characters
		for(int i(0);i<n_row;i++){
			if(i<9){std::cout<<i+1<<" | ";}
			else{std::cout<<i+1<<"| ";}
			for (int j = 0; j < n_col; ++j){
				if(Board[i][j] == 0){
					std::cout<<". ";
					cont++;
				}

				if(Board[i][j] == 2){
					std::cout<<"▲ ";
				}else if(Board[i][j] == 1){
					std::cout<<"◼ ";
				}

				else if(Board[i][j] == 3){
					std::cout<<"◀︎ ";
				}
				else if(Board[i][j] == 4){
					std::cout<<"● ";
				}
				else if(Board[i][j] == 5){
					std::cout<<"⌘ ";
				}
				else if(Board[i][j] == 6){
					std::cout<<"▼ ";
				}
				else if(Board[i][j] == 7){
					std::cout<<"▶︎ ";
				}
			}
			std::cout<<" |"<<first[i]<<std::endl;
		}

		for (int i = 0; i < n_col; ++i){
			std::cout<<"---";
		}

		std::cout<<"\n";

		std::cout<<"  | ";
		for (int i = n_row; i < (n_row + n_col); ++i){
			std::cout<< first[i] <<" ";
		}
		std::cout<<" |\n";
		//legend with the symbols
		std::cout<<"------SUBTITLE--------\n";
		std::cout<<"| 1-> ◼︎ (Ship body) | 2-> ▲ (Bow Vert.) | 3 -> ◀︎ (Bow Hori.) | 5 -> ⌘ (Water) |\n";
		std::cout<<"| 4 -> ● (submarine) | 6-> ▼ (Stern Vert.) | 7 -> ▶︎ (Stern Hori.) | 0-> . |\n\n";
		std::cout<<"water in the entire row -> [line] 0 0 \n";
		std::cout<<"water in the entire column -> 0 [column] 0 \n";
		std::cout<<"water in all squares white -> 0 0 0 \n\n";
		std::cout<<">> [line] [column] [code]\n\a";

		return cont;
	}

	/*Function Responsible for checking whether the puzzle equals the Generator puzzle.It receives as input an array of board, the number of rows and the number of columns.
	the function returns the number of errors.*/
	int CheckBoard(int BoardGab[MAX][MAX],int board[MAX][MAX], const int n_row, const int n_col){
		int cont(0);

		for(int i(0);i<n_row;i++){
			for(int j(0);j<n_col;j++){
				//verifies that the water in the model is equal to the user's puzzle.
				if(BoardGab[i][j] == 5 && board[i][j] != 5){
					cont++;
					
				}else if(BoardGab[i][j] != 5 && board[i][j] == 5){
					cont++;
				}
			}
		}


		return cont;
	}

	void print_on_gab(int BoardGab[MAX][MAX],int Board[MAX][MAX], const int n_row, const int n_col){
		for (int i(0);i<n_row;i++){
			for(int j(0);j<n_col;j++){
				if(BoardGab[i][j]==1 && BoardGab[i+1][j]==1 && BoardGab[i-1][j] != 1){
					Board[i][j]=2;
				}else if(BoardGab[i][j]==1 && BoardGab[i-1][j]==1 && BoardGab[i+1][j] != 1){
					Board[i][j]=6;
				}else if((BoardGab[i][j]==1 && BoardGab[i+1][j]==1 && BoardGab[i-1][j]==1) || (BoardGab[i][j]==1 && BoardGab[i][j+1]==1 && BoardGab[i][j-1]==1)){
					Board[i][j]=1;
				}else if(BoardGab[i][j]==1 && BoardGab[i][j+1]==1 && BoardGab[i-1][j] != 1){
					Board[i][j]=3;
				}else if(BoardGab[i][j]==1 && BoardGab[i][j-1]==1 && BoardGab[i+1][j] != 1){
					Board[i][j]=7;
				}else if (BoardGab[i][j]==4){
					Board[i][j]=4;
				}
			}
		}
	}

	void WaterRow(int Board[MAX][MAX], int n_row, int n_col){
		for(int i(0);i<n_col;i++){
			if(Board[n_row][i]==0){
				Board[n_row][i]=5;
			}
		}
	}
	void WaterCol(int Board[MAX][MAX], const int n_row, const int n_col){
		for(int i(0);i<n_row;i++){
			if(Board[i][n_col]==0){
				Board[i][n_col]=5;
			}
		}
	}
}





/*AVISO!!!!!
Prencher as linhas e colunas.*/







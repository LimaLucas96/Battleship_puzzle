#include "../include/funcoes.h"

namespace BS{
	//Function responsible for clear the board
	void Clear_board(int board[tam_max][tam_max], int n_line, int n_col){
		//The function adds zero in all board
		for(int i(0);i<n_line;i++){
			for(int j(0);j<n_col;j++){
				board[i][j]=0;
			}
		}
	}
	//Function Responsible for reflect vertically the board 
	void ReflectBoardVertical(int board[tam_max][tam_max], int n_line, int n_col){
		
		for(int i(0);i<n_line;i++){
			for(int j(0);j<n_col/2;j++){
				int temp=board[i][j];
				board[i][j]=board[i][n_line-1-j];
				board[i][n_line-1-j]=temp;
			}
		}
	}
	//Function Responsible for reflect Horizontally the board 
	void ReflectBoardHorizontal(int board[tam_max][tam_max], int n_line, int n_col){
		for(int i(0);i<n_line/2;i++){
			for(int j(0);j<n_col;j++){
				int temp=board[i][j];
				board[i][j]=board[n_line-1-i][j];
				board[n_line-1-i][j]=temp;
			}
		}
	}
	//Function Responsible for add the board on the Generator file
	void print(std::ofstream &file, int board[tam_max][tam_max], int n_line,int n_col){
		for(int i(0);i<n_line;i++){
			for(int j(0);j<n_col;j++){
				file<<board[i][j]<<" ";
			}
		}

		file<<"\n";
	}

	void printTela(int board[tam_max][tam_max], int n_row,int n_col){
	
		std::cout<<"\n\n\n";

		for (int i(0);i<n_row;i++){
			for(int j(0);j<n_col;j++){
				if(board[i][j]==1 && board[i+1][j]==1 && board[i-1][j] != 1){
					std::cout<<"▲ ";
				}else if(board[i][j]==1 && board[i-1][j]==1 && board[i+1][j] != 1){
					std::cout<<"▼ ";
				}else if((board[i][j]==1 && board[i+1][j]==1 && board[i-1][j]==1) || (board[i][j]==1 && board[i][j+1]==1 && board[i][j-1]==1)){
					std::cout<<"◼ ";
				}else if(board[i][j]==1 && board[i][j+1]==1 && board[i-1][j] != 1){
					std::cout<<"◀︎ ";
				}else if(board[i][j]==1 && board[i][j-1]==1 && board[i+1][j] != 1){
					std::cout<<"▶︎ ";
				}else if (board[i][j]==4){
					std::cout<<"● ";
				}else if(board[i][j]==5){
					std::cout<<". ";
				}
			}
			std::cout<<"\n";
		}
	}
}
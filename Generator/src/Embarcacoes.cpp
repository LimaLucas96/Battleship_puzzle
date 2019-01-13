#include "../include/Embarcacoes.h"

using namespace std;

namespace Ship{

	/*The function Create_Battleship receives as input the matrix of the board, the number of rows and number of columns.
	*The function is responsible for adding the Battleship in the board.
	*/
	void create_Battleship(int board[tam_max][tam_max], int n_line, int n_col){
		random_device rd;
		mt19937 gen(rd());
		//Create a variable dis that chooses a number from zero to the number of columns.
		uniform_int_distribution <> dis(0,n_col);
		//Create a variable dis2 that chooses a number from zero to the number of row less three,
		//because the ship will be placed vertically.
		uniform_int_distribution <> dis2(0,(n_line-3));
		//Create two variables that receive the random coordinates of the board.
		auto posX=dis2(gen);
		auto posY=dis(gen);

		//Inserts the Battleship on the board.
		for(int i(0);i<4;i++){
			board[posX+i][posY]=1;
		}

	}

	/*The function create_Crouiser receives as input the matrix of the board, the number of rows and number of columns.
	*The function is responsible for adding the cruisers on the board.
	*/
	void create_Crouiser(int board[tam_max][tam_max], int n_line, int n_col){
		random_device rd;
		mt19937 gen(rd());
		//Create a variable dis that chooses a number from zero to the number of columns.
		uniform_int_distribution <> dis(0,n_col);
		//Create a variable dis2 that chooses a number from zero to the number of row less two,
		//because the Cruiser will be placed vertically.
		uniform_int_distribution <> dis2(0,(n_line-2));
		//Create a variable dis2 that chooses a number from zero to the number of columns less two,
		//because the Cruiser will be placed Horisontally.
		uniform_int_distribution <> dis3(0,n_col-2);
		//Auxiliary variable Responsible for checking whether a boat exist around the selected coordinates 
		int p1(0);
		
		//Variables for the coordinates
		int posX(0);
		int posY(0);

		//Checking whether a boat exist around the selected coordinates.
		//If exist, the program choose another coordinates.
		do{

			posX=dis2(gen);
			posY=dis(gen);
			p1=0;
			
			for(int i(posX-1);i<=posX+3;i++){
				for (int j ( posY-1); j <= posY+1; j++)
				{
					if(board[i][j]==1){
						p1=1;
						break;
					}
				}
			}
		}while(p1!=0);

		//Add the cruiser in the vertical position on the board.
		for(int i(0);i<3;i++){
			board[posX+i][posY]=1;
		}

		//Checking whether a boat exist around the selected coordinates, but now in the horizontal position.
		//If exist, the program choose another coordinates.
		do{

			posX=dis(gen);
			posY=dis3(gen);

			p1=0;

			for(int i(posX-1);i<=posX+1;i++){
				for (int j ( posY-1); j <= posY+3; j++)
				{
					if(board[i][j]!=0){
						p1=1;
						break;
					}
				}
			}
		}while(p1!=0);

		//Add the cruiser in the horizontal position on the board.
		for(int i(0);i<3;i++){
			board[posX][posY+i]=1;
		}
	}

	/*The function Create_Destroyer receives as input the matrix of the board, the number of rows and number of columns.
	*The function is responsible for adding the Destroyers in the board.
	*/
	void create_Destroyer(int board[tam_max][tam_max], int n_line, int n_col){
		random_device rd;
		mt19937 gen(rd());
		//Create a variable dis that chooses a number from zero to the number of columns.
		uniform_int_distribution <> dis(0,n_col);
		//Create a variable dis2 that chooses a number from zero to the number of row less one,
		//because the Destroyer will be placed vertically.
		uniform_int_distribution <> dis2(0,(n_line-1));
		//Create a variable dis2 that chooses a number from zero to the number of columns less one,
		//because the Destroyer will be placed horizontally.
		uniform_int_distribution <> dis3(0,n_col-1);

		//Auxiliary variable Responsible for checking whether a boat exist around the selected coordinates 
		int p1(0);
		
		int posX(0);
		int posY(0);
		int vezes(2);//Variable Responsible for adding for Destroyer N times.

		//Choose the position and places the ship N times.
		for(int cont(0);cont<vezes;cont++){
		
			//Checking whether a boat exist around the selected coordinates.
			//If exist, the program choose another coordinates.
			do{

				posX=dis2(gen);
				posY=dis(gen);
				p1=0;
			
				for(int i(posX-1);i<=posX+2;i++){
					for (int j ( posY-1); j <= posY+1; j++)
					{
						if(board[i][j] != 0){
							p1=1;
							break;
						}
					}
				}

			}while(p1!=0);

			//Add the Destroyer in the vertical position on the board.
			for(int i(0);i<2;i++){
				board[posX+i][posY]=1;
			}
		}
		
		//Checking whether a boat exist around the selected coordinates.
		//If exist, the program choose another coordinates.
		do{

			posX=dis(gen);
			posY=dis3(gen);
			p1=0;
			
				for(int i(posX-1);i<=posX+1;i++){
					for (int j ( posY-1); j <= posY+2; j++)
					{
						if(board[i][j] != 0){
							p1=1;
							break;
						}
					}
				}

			}while(p1!=0);

		//Add the Destroyer in the horizontal position on the board.
		for(int i(0);i<2;i++){
			board[posX][posY+i]=1;
		}
	}

	/*The function Create_Submarine receives as input the matrix of the board, the number of rows and number of columns.
	*The function is responsible for adding the submarines in the board.
	*/
	void create_Submarine(int board[tam_max][tam_max], int n_line, int n_col){
		random_device rd;
		mt19937 gen(rd());
		//Create a variable dis that chooses a number from zero to the number of columns.
		uniform_int_distribution <> dis(0,n_col);
		//Create a variable dis that chooses a number from zero to the number of row.
		uniform_int_distribution <> dis2(0,n_line);
		//Auxiliary variable Responsible for checking whether a boat exist around the selected coordinates 
		int p1(0);
		
		int posX(0);
		int posY(0);
		int vezes(4);//Variable Responsible for adding for Submarine N times.

		//Choose the position and places the ship N times.
		for(int cont(0);cont<vezes;cont++){
			do{

				posX=dis2(gen);
				posY=dis(gen);
				p1=0;
			
				for(int i(posX-1);i<=posX+1;i++){
					for (int j ( posY-1); j <= posY+1; j++)
					{
						if(board[i][j] != 0){
							p1=1;
							break;
						}
					}
				}

			}while(p1!=0);

			//Add the Submarine in the position on the board.
			board[posX][posY]=4;
		}
	}

	/*The function Create_Water receives as input the matrix of the board, the number of rows and number of columns.
	*The function is responsible for adding the Water in the board.
	*/
	void create_water(int board[tam_max][tam_max], int n_line, int n_col){
		
		//The function walks the board and where it is empty adds water
		for(int i(0);i<n_line;i++){
			for (int j = 0; j < n_col; j++){

				if(board[i][j]==0){

					board[i][j] = 5;

				}
			}
		}
	}
}
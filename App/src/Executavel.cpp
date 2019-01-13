/*
*Linguagem de Progamacao I - DIM0120
*Project Battleship puzzle
*Produced by Lucas Lima Marques de Oliveria.
*/

#include "../include/funcoes.h"

#define MAX 150//number maximum of puzzles in the Generator file

using namespace lp;

int main(int argc, char const *argv[])
{
	
	std::random_device rd;
	std::mt19937 gen(rd());

	std::string Puzzles[MAX];//
	int Board_Print[MAX][MAX];
	int Gab[MAX][MAX];
	int vet[30];
	int aux(0);
	int n_puzzles(0);
	int n_row(0);
	int n_col(0);
	int line(0),col;
	int control(10);
	int Ob;

	//open the Gerador file
	int Result=OpenGenerator(Puzzles);

	if(Result == -1){// if the Gerador file not found, the function return -1 and the program closes
		
		std::cout<<">> Generator file not found <<"<<std::endl;
		return -1;
	}

	//if the function OpenGenerator return 0
	n_puzzles=std::stoi(Puzzles[0]);//variable n_puzzles receives the number of puzzles in the file
	n_row=std::stoi(Puzzles[1]);//variable n_row receives the number of rows of the board
	n_col=std::stoi(Puzzles[2]);//variable n_col receives the number of columns of the board

	//random interval
	std::uniform_int_distribution <>dis(3,n_puzzles+2);

	//choose a random puzzle
	std::stringstream iss(Puzzles[dis(gen)]);

	//transforms the string puzzle into an array of integers
	for(int i(0);i<n_row;i++){

		for (int j = 0; j < n_col; ++j)
		{
			iss>>Gab[i][j];

		}
	}

	//check the number of boats on each line and put in the first part of a vector
	for(int i(0);i<10;i++){
		aux=0;
		for (int j = 0; j < 10; ++j){
			if(Gab[i][j]!=5){
				aux++;
			}
			vet[i]=aux;
		}
	}
	//check the number of boats in each column and put in the second part of a vector
	for(int i(0);i<10;i++){
		aux=0;
		for (int j = 0; j < 10; ++j){
			if(Gab[j][i]!=5){
				aux++;
			}
			vet[n_row + i]=aux;
		}
	}


	CreateBoard(Board_Print,n_row,n_col);//create a zeroed array
	
	//while still having blank frames, the user is still playing
	while(control != 0){
		//print the board and return the number of blank frames
		control=PrintBoard(Board_Print,n_row,n_col,std::begin(vet),std::begin(vet)+n_col);
		
		std::cout<<"\n(Press Control+C to Exit)\n";
		//If there is no blank square, exit while
		if(control==0){
			break;
		}

		//PrintGab(Gab,n_row,n_col);
		std::cout<<">> ";
		std::cin>>line>>col>>Ob;
		// if the code exists, add in the desired coordinate
		if(line>0 && col>0 && Ob>=0 && Ob<8){
			Board_Print[line-1][col-1] = Ob;

		}else if(line == 30 && col ==30 && Ob == 30){
			print_on_gab(Gab,Board_Print,n_row,n_col);
		}
		else if(line != 0 && col == 0){
			WaterRow(Board_Print,line-1,n_col);
		}else if(line ==0 && col != 0){
			WaterCol(Board_Print,n_row,col-1);
		}else if (line==0 && col==0){//if you enter 0 0 0, put water in all the blank squares

			for(int i(0);i<n_row;i++){
				for(int j(0);j<n_col;j++){
					if(Board_Print[i][j]==0){
						Board_Print[i][j]=5;
					}
				}
			}
		}else if(line != 0 && col ==0){
			WaterRow(Board_Print,line,col);
		}
		//if the code or the rows are wrong, return invalid command
		else{std::cout<<"\nCommand invalid\n";}

	}//while(control > 1);

	// check if the user's matrix is the same as the puzzle template
	auto result=CheckBoard(Gab,Board_Print,n_row,n_col);
 	
 	//if the checkBoard function returns 0, the user has won, if not, the user has lost.
	if(result==0){
		std::cout<<"\n\a\a>>>>>>>>>>> YOU WIN!!!!!!! <<<<<<<<<<<\n";	
	}else{
		std::cout<<"\n>>>>>>>>>> YOU LOST!!!!!! <<<<<<<<<<<<\n";
	}
	return 0;
}












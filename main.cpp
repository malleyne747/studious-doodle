#include <iostream>

using namespace std;

/*
 mikes very minamalistic tic tac to game ..... (:<

*/
char Board[3][3] = { '1','2','3','4','5','6','7','8','9' };
int turns = 0;
bool gameOver = false; 
void printBoard() {
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			 cout << Board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl; 
}
bool validate(int c , int min, int max ) // ensures character c is within a certain asciii range  
{
	return (c -'0' >= min && c -'0' <= max);
}
void Input() {
	char choice;
	turns++; // increment turns counter with every chice made
	char symbol = '~';
	bool hFin = false; // three in a row horizonTALLY 
	bool vFin = false; // three in a row vertically 
	int  d1hits = 0; // forward diagonal hits 
	int d2hits = 0; // inverse diagonal hits 

	if ( turns % 2 == 0) // choose symbol used on this turn 
	{	symbol = 'X';}
	else { symbol = 'O'; }


	cout << "Press the number of the tile you choose";
	cin >> choice;
	if (validate( (int)choice , 1, 9) == false)
		return;
	else
	{
		for (int i = 0; i < 3; i++) {

			for (int j = 0; j < 3; j++) {
				if (Board[i][j] == (int)choice)
				{
					Board[i][j] = symbol;
					
				}
			}
		}

		for (int z = 0; z < 3; z++) // less than size of array 
		{
			int hHits = 0;
			int vHits = 0;

			// check horizontal line
			for (int i = 0; i < 3; ++i)
			{
				if (Board[i][z] == Board[0][z])
				{
					hHits++;
				}
			}
			hFin = hFin || hHits == 3;  // array size = 3 

			// check  vertical line
			for (int i = 0; i < 3; ++i)
			{ 
				if( Board[z][i] == Board[z][0])
				{
					vHits++;
				}
			}

			vFin = vFin || vHits == 3; // m array size = 3 

			if (Board[z][z] == Board[0][0])
			{
				d1hits++; 
			}
			if( Board[ 3 - z - 1][z] == Board[3-1][0])
			{
				d2hits++; 
			}


		}
		bool dFin = d1hits == 3 || d2hits == 3;
		if( dFin || vFin || hFin )
		{
			cout << " game over " << symbol << " wins!" << endl;

			printBoard(); 

			gameOver = true; 
			cin.ignore().get();
		}

		
	}
	
}

int main()
{
	
	cout << "tic tac toe clone v.01" << endl;
	while (gameOver == false)
	{
		printBoard();
		Input();


	}


	return 0;
}
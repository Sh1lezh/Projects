#include <iostream>
#include <ctime>
#include <random>
using namespace std;

void boardprint(char Board[][3]);
void playermove(int *rowP, int *colP);
void computermove(int *rowC, int *colC, int rowP, int colP, char Board[][3]);
int checkwinner(char Board[][3]);

const char X = 'X';
const char O = 'O';

int main() {
	
	char Board[3][3];
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			Board[i][j] = ' ';
		}
	}
	int rowP, colP;
	int rowC, colC;

	for (int i = 0; i < 5; i++) {
        boardprint(Board);
        playermove(&rowP, &colP);
        Board[rowP - 1][colP - 1] = X;
        if (checkwinner(Board) == 1) {
            boardprint(Board);
            cout << "Player Won" << endl;
            return 0;
        }
        
        computermove(&rowC, &colC, rowP, colP, Board);
        Board[rowC - 1][colC - 1] = O;
        if (checkwinner(Board) == 2) {
            boardprint(Board);
            cout << "Computer Won" << endl;
            return 0;
        }
    }

    boardprint(Board);
    cout << "It's a draw." << endl;
    return 0;

}

void boardprint(char Board[][3]) {
	for(int i=0; i<3; i++) {
		cout<<" "<<Board[i][0]<<" | "<<Board[i][1]<<" | "<<Board[i][2]<<" "<<endl;
		if(i<2) {
			cout<<"---|---|---"<<endl;
		}
	}
}

void playermove(int *rowP, int *colP) {
	cout<<"Enter row & column : ";
	cin>>*rowP>>*colP;
	if((*rowP < 1 || *rowP > 3) || (*colP < 1 || *colP > 3)) {
		cout<<"invalid input, renter value : ";
			while((*rowP < 1 || *rowP > 3) || (*colP < 1 || *colP > 3)) {
			cin>>*rowP>>*colP;
			}
	}
}

void computermove(int *rowC, int *colC, int rowP, int colP, char Board[][3]) {
	int min=1, max=3;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> distribution(min, max);
	do {
        *rowC = distribution(gen);
        *colC = distribution(gen);
    } while (Board[*rowC - 1][*colC - 1] != ' ');
}

int checkwinner(char Board[][3]) {
    
    for (int i = 0; i < 3; i++) {
        if ((Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2])) {
            if (Board[i][0] == X) return 1;
            if (Board[i][0] == O) return 2;
        }
        if ((Board[0][i] == Board[1][i] && Board[1][i] == Board[2][i])) {
            if (Board[0][i] == X) return 1;
            if (Board[0][i] == O) return 2;
        }
    }

    
    if ((Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2])) {
        if (Board[0][0] == X) return 1;
        if (Board[0][0] == O) return 2;
    }
    
    if ((Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0])) {
        if (Board[0][2] == X) return 1;
        if (Board[0][2] == O) return 2;
    }

    return 0; 
}
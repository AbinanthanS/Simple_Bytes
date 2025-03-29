#include<iostream>
using namespace std;

void Board(char board[3][3]){
	cout << "-------------\n"; 
	for (int i = 0; i < 3; i++) { 
		cout << "| "; 
		for (int j = 0; j < 3; j++) { 
			cout << board[i][j] << " | "; 
		} 
		cout << "\n-------------\n"; 
	} 
}
	
bool winner(char player,char board[3][3]){
	
	for (int i= 0;i<3;i++)
	{
		if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
		if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
	if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
		
	return false;	
	
}



int main(){
	
	char board[3][3] = {{ ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' }};
	char player = 'X';
	int row,col,turn;
	
	for (turn = 0;turn<9;turn++){
		
		Board(board);
		
		while(true){
			
			cout<<"Enter "<<player<< " position (0/1/2) : ";
			cin>>row>>col;
			if (board[row][col] != ' '||row>2||row<0||col>2||col<0) cout<<"Enter valid input";
			else break;
		}
		
		board[row][col] = player;
		
		if (winner(player,board)){
			Board(board);
			cout<<player<<" WINS"<<endl;
			break;
		}
		
		player = (player == 'X')?'O':'X';
		
    }
      
	
	Board(board);
	 
	if (turn==9 && !winner('X',board) && !winner('O',board))  cout<<"DRAW"; 
	           
    return 0;
}

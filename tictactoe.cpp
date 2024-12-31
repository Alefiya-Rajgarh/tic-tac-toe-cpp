#include <iostream>
using namespace std;

void drawboard( char board[3][3])
{ cout<<"This is your board:\n";
  std::cout<<"______________\n";
 for (int i=0; i<3; i++)
  { std::cout<<" | ";
   for(int j =0; j<3; j++)
   { std::cout<< board[i][j]<<" | ";
    }
  std::cout<<"\n______________\n";
 }
}

bool checkwin(char board[3][3], char player)
{ 
    for(int i=0; i<3; i++)
    { if (board[i][0]== player && board[i][1]==player && board[i][2]==player)
        return true;
      if (board[0][i]== player && board[1][i]==player && board[2][i]==player)
         return true;
    }
     if (board[0][0]==player && board[1][1]==player && board[2][2]==player)
         return true;
     if (board[0][2]==player && board[1][1]==player && board[2][0]==player)
         return true;
     else return false;
}

int main ()
{ char board[3][3]={ { ' ', ' ', ' '},
                     { ' ', ' ', ' '},
                     { ' ', ' ', ' '} };
  char player ='X';
  int row , colm;
  int turn;
  
  std::cout<<"\n Welcome to TIC-TAC-TOE game !\n ";
   for (turn = 0; turn < 9; turn++)
   { 
    drawboard(board);
    while(1)
    {  cout<<"\n\nThis board shows you where to enter:\n";
       cout<<"_ 0 0 _|_ 0 1 _|_ 0 2 _\n\n";
       cout<<"_ 1 0 _|_ 1 1 _|_ 1 2 _\n\n";
       cout<<"_ 2 0 _|_ 2 1 _|_ 2 2 _\n";
       cout<<"player "<<player<< " enter the row and column number where you want to enter  It must be from 0-2 in row and 0-2 in column as shown above: \n";
       std::cin>>row>>colm;
     if (board[row][colm]!= ' ' || row<0 || row>2 ||colm<0 || colm>2)
     { std::cout<<"invalid move. TRY again ,\n";}
     else 
      break;
                                  
    }
    board[row][colm]= player;
    cout<<"The player's move is valid and hence inserted\n";
// after each move check the wining 
 if (checkwin(board, player))
 {  drawboard(board);
    cout<<"Hurray!!  player " <<player<<" WINS!!\n";
     break;
  }
 
 // switch players 
  player= (player=='X') ? 'O' : 'X';
}

// for draw 
if ( turn==9 && !checkwin(board,'X') && !checkwin(board,'O'))
{ drawboard(board);
  cout<< " Its a Draw!!      Play again to win.......\n";
}
return 0;
}
#include <iostream>
using namespace std;

int main(){
    int playerOption=0;
    cout << "\t\tWelcome to Connect 4!\n\n";
    cout << "Please Select a Player Option" << endl;
    cout << "1. Person vs. Person" << endl;
    cout << "2. Person vs. Computer" << endl;
    cout << "Enter the number for the corresponding option above: " << endl;
    cin >> playerOption;

    if (playerOption==1){
        //board size: input and store rows/cols
        int nRows;
        cout<<"Enter number of rows: ";
        cin>>nRows;

        int nCols;
        cout<<"Enter number of columns: ";
        cin>>nCols;

        //create empty board with input dimensions
        char board[nRows][nCols];

        for (int row=0; row<nRows; row++){
            for (int col=0; col<nCols; col++){
                board[row][col]=' ';
            }
        }

        //display empty board
        for (int row=0; row<nRows+2; row++){
            for (int col=0; col<nCols; col++){
                if(row<=nRows-1 && col!=nCols-1){
                    cout<<'|'<<board[row][col];
                } else if (row<=nRows-1 && col==nCols-1){
                    cout<<'|'<<board[row][col]<<'|';
                } else if(row==nRows && col!=nCols-1){
                    cout<<'='<<'=';
                } else if (row==nRows && col==nCols-1){
                    cout<<'='<<'='<<'=';
                } else if (row==nRows+1 && col!=nCols-1){
                    cout<<'|'<<col+1;
                } else if (row==nRows+1 && col==nCols-1){
                    cout<<'|'<<col+1<<'|';
                }
            }
            cout<<endl;
        }

        //win and draw flags
        bool player1Won=false;
        bool player2Won=false;
        bool gameDraw=false;


        int colCounter[8];
        for(int i=0; i<nCols; i++){
        colCounter[i]=nRows-1;
        }

        //while no one has won yet or game isn't a draw
        while(player1Won==false || player2Won==false || gameDraw==false){

            //Player 1 move
                //prompt user for first move
                bool isColumnFull(int nCols){
                    return board[0][nCols] != ' ';
                }

                int playerInput;
                cout<<"player 1 move: "; 
                cin>>playerInput;
                
                //update board: assign token X to the bottom of the chosen column and if there's already a token stack them            
                switch (playerInput){
                    case 1:
                        board[colCounter[0]][playerInput-1]='X';
                        colCounter[0]=colCounter[0]-1;
                        break;    
                    case 2:
                        board[colCounter[1]][playerInput-1]='X'; 
                        colCounter[1]=colCounter[1]-1;
                        break;
                    case 3:
                        board[colCounter[2]][playerInput-1]='X';
                        colCounter[2]=colCounter[2]-1;
                        break;
                    case 4:
                        board[colCounter[3]][playerInput-1]='X';
                        colCounter[3]=colCounter[3]-1;
                        break;
                    case 5:
                        board[colCounter[4]][playerInput-1]='X';
                        colCounter[4]=colCounter[4]-1;
                        break;
                    case 6:
                        board[colCounter[5]][playerInput-1]='X';
                        colCounter[5]=colCounter[5]-1;
                        break;
                    case 7:
                        board[colCounter[6]][playerInput-1]='X';
                        colCounter[6]=colCounter[6]-1;
                        break;
                    case 8:
                        board[colCounter[7]][playerInput-1]='X';
                        colCounter[7]=colCounter[7]-1;
                        break;
                } 

                //display the update board
                for (int row=0; row<nRows+2; row++){
                    for (int col=0; col<nCols; col++){
                        if(row<=nRows-1 && col!=nCols-1){
                            cout<<'|'<<board[row][col];
                        } else if (row<=nRows-1 && col==nCols-1){
                            cout<<'|'<<board[row][col]<<'|';
                        } else if(row==nRows && col!=nCols-1){
                            cout<<'='<<'=';
                        } else if (row==nRows && col==nCols-1){
                            cout<<'='<<'='<<'=';
                        } else if (row==nRows+1 && col!=nCols-1){
                            cout<<'|'<<col+1;
                        } else if (row==nRows+1 && col==nCols-1){
                            cout<<'|'<<col+1<<'|';
                        }
                    }
                    cout<<endl;
                }
            
                //if player 1 gets 4 in a row horizontally
                for (int row=0; row<nRows; row++){
                    for (int col=0; col<nCols; col++){
                        if(board[row][col]=='X' && board[row][col+1]=='X' && board[row][col+2]=='X' && board[row][col+3]=='X'){
                            cout<<"Player 1 Wins (4 horiztonally)"<<endl;
                            return player1Won=true;
                        }
                    }
                }

                //if player 1 gets 4 in a row vertically
                for (int row=0; row<nRows; row++){
                    for (int col=0; col<nCols; col++){
                        if(board[row][col]=='X' && board[row+1][col]=='X' && board[row+2][col]=='X' && board[row+3][col]=='X'){
                            cout<<"Player 1 Wins (4 vertically)"<<endl;
                            return player1Won=true;
                        }
                    }
                }

                //if player 1 gets 4 in a row diagonally
                for (int row=0; row<nRows; row++){
                    for (int col=0; col<nCols; col++){
                        if(board[row][col]=='X' && board[row+1][col+1]=='X' && board[row+2][col+2]=='X' && board[row+3][col+3]=='X'){
                            cout<<"Player 1 Wins (4 diagonally (-)slope)"<<endl;
                            return player1Won=true;
                        } else if (board[row][col]=='X' && board[row-1][col+1]=='X' && board[row-2][col+2]=='X' && board[row-3][col+3]=='X'){
                            cout<<"Player 1 Wins (4 diagonally (+)slope)"<<endl;
                            return player1Won=true;
                        }
                    }
                }
            
            //Player 2 Move
                //prompt user for first move
                cout<<"player 2 move: "; 
                cin>>playerInput;
                
                //update board: assign token O to the bottom of the chosen column and if there's already a token stack them            
                switch (playerInput){
                    case 1:
                        board[colCounter[0]][playerInput-1]='O';
                        colCounter[0]=colCounter[0]-1;
                        break;    
                    case 2:
                        board[colCounter[1]][playerInput-1]='O'; 
                        colCounter[1]=colCounter[1]-1;
                        break;
                    case 3:
                        board[colCounter[2]][playerInput-1]='O';
                        colCounter[2]=colCounter[2]-1;
                            break;
                    case 4:
                        board[colCounter[3]][playerInput-1]='O';
                        colCounter[3]=colCounter[3]-1;
                        break;
                    case 5:
                        board[colCounter[4]][playerInput-1]='O';
                        colCounter[4]=colCounter[4]-1;
                        break;
                    case 6:
                        board[colCounter[5]][playerInput-1]='O';
                        colCounter[5]=colCounter[5]-1;
                        break;
                    case 7:
                        board[colCounter[6]][playerInput-1]='O';
                        colCounter[6]=colCounter[6]-1;
                        break;
                    case 8:
                        board[colCounter[7]][playerInput-1]='O';
                        colCounter[7]=colCounter[7]-1;
                        break;
                } 

                //display the update board
                for (int row=0; row<nRows+2; row++){
                    for (int col=0; col<nCols; col++){
                        if(row<=nRows-1 && col!=nCols-1){
                            cout<<'|'<<board[row][col];
                        } else if (row<=nRows-1 && col==nCols-1){
                            cout<<'|'<<board[row][col]<<'|';
                        } else if(row==nRows && col!=nCols-1){
                            cout<<'='<<'=';
                        } else if (row==nRows && col==nCols-1){
                            cout<<'='<<'='<<'=';
                        } else if (row==nRows+1 && col!=nCols-1){
                            cout<<'|'<<col+1;
                        } else if (row==nRows+1 && col==nCols-1){
                            cout<<'|'<<col+1<<'|';
                        }
                    }
                    cout<<endl;
                }
            
                //if player 2 gets 4 in a row horizontally
                for (int row=0; row<nRows; row++){
                    for (int col=0; col<nCols; col++){
                        if(board[row][col]=='O' && board[row][col+1]=='O' && board[row][col+2]=='O' && board[row][col+3]=='O'){
                            cout<<"Player 2 Wins (4 horizontally)"<<endl;
                            return player2Won=true;
                        }
                    }
                }

                //if player 2 gets 4 in a row vertically
                for (int row=0; row<nRows; row++){
                    for (int col=0; col<nCols; col++){
                        if(board[row][col]=='O' && board[row+1][col]=='O' && board[row+2][col]=='O' && board[row+3][col]=='O'){
                            cout<<"Player 2 Wins (4 vertically)"<<endl;
                            return player2Won=true;
                        }
                    }
                }

                //if player 2 gets 4 in a row diagonally
                for (int row=0; row<nRows; row++){
                    for (int col=0; col<nCols; col++){
                        if(board[row][col]=='O' && board[row+1][col+1]=='O' && board[row+2][col+2]=='O' && board[row+3][col+3]=='O'){
                            cout<<"Player 2 Wins (4 diagonally (-)slope)"<<endl;
                            return player2Won=true;
                        } else if (board[row][col]=='O' && board[row-1][col+1]=='O' && board[row-2][col+2]=='O' && board[row-3][col+3]=='O'){
                            cout<<"Player 2 Wins (4 diagonally (+)slope)"<<endl;
                            return player2Won=true;
                        }
                    }
                }
        
        }

    
    }

    return 0;
}
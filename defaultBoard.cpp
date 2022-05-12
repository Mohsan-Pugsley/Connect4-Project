#include <iostream>
using namespace std;

int main(){

    int playerOption=0;
    cout<<"Enter 1 for person vs person\n" <<
          "Enter 2 for person vs computer"<< endl;

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
            board[row][col]='*';
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

    //column counter: used to stack the tokens 
    int col1Counter=nRows-1;
    int col2Counter=nRows-1;
    int col3Counter=nRows-1;
    int col4Counter=nRows-1;
    int col5Counter=nRows-1;
    int col6Counter=nRows-1;
    int col7Counter=nRows-1;
    int col8Counter=nRows-1;

    //while no one has won yet or game isn't a draw
    while(player1Won==false || player2Won==false || gameDraw==false){

        //Player 1 move
            //prompt user for first move
            int playerInput;
            cout<<"player 1 move: "; 
            cin>>playerInput;
            
            //update board: assign token X to the bottom of the chosen column and if there's already a token stack them            
            if(playerInput==1){
                board[col1Counter][playerInput-1]='X';
                col1Counter--;
            } else if (playerInput==2){
                board[col2Counter][playerInput-1]='X';
                col2Counter--;
            }else if(playerInput==3){
                board[col3Counter][playerInput-1]='X';
                col3Counter--;
            }else if (playerInput==4){
                board[col4Counter][playerInput-1]='X';
                col4Counter--;
            }else if(playerInput==5){
                board[col5Counter][playerInput-1]='X';
                col5Counter--;
            }else if(playerInput==6){
                board[col6Counter][playerInput-1]='X';
                col6Counter--;
            }else if(playerInput==7){
                board[col7Counter][playerInput-1]='X';
                col7Counter--;
            }else if(playerInput==8){
                board[col8Counter][playerInput-1]='X';
                col8Counter--;
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
            if(playerInput==1){
                board[col1Counter][playerInput-1]='O';
                col1Counter--;
            } else if (playerInput==2){
                board[col2Counter][playerInput-1]='O';
                col2Counter--;
            }else if(playerInput==3){
                board[col3Counter][playerInput-1]='O';
                col3Counter--;
            }else if (playerInput==4){
                board[col4Counter][playerInput-1]='O';
                col4Counter--;
            }else if(playerInput==5){
                board[col5Counter][playerInput-1]='O';
                col5Counter--;
            }else if(playerInput==6){
                board[col6Counter][playerInput-1]='O';
                col6Counter--;
            }else if(playerInput==7){
                board[col7Counter][playerInput-1]='O';
                col7Counter--;
            }else if(playerInput==8){
                board[col8Counter][playerInput-1]='O';
                col8Counter--;
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

    return 0;
}
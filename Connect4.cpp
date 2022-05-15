#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//global constants & vars.
const char EMPTY=' ';
const char x='X';
const char o='O';
const char& X=x;
const char& O=o;
char empty=' ';
char& eRef=empty;

//GetOpposite function-needed in Computer obj.'s GetMove() member function & when assigning each obj. their own m_pieces'
int GetOpposite(const char& aPiece)
{
    if (aPiece==X)
    {
        return O;
    }

    else
    {
        return X;
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Board
{
    friend ostream& operator<< (ostream& os, const Board& aBoard);

public:
    Board();
    bool GameWon(char& charRef);//
    bool GameTied();//
    bool IsFull();//
    int  GetHumanMove(); //Gives column #
    void SetBoard(int& column,const char& character);
    bool MoveAcceptable(int& rAns);//
    void RemoveTopPiece(int& colNum);//
    void ClearBoard();//
    bool GameOver(char& r_PieceThatWon);

private:
    int ConvertX(int* pX);
    int ConvertY(int* pY);
    bool ColumnCheckFull(int& column);//
    char m_Array[7][6];
    int m_Rows;
    int m_Col;
    int m_winComNum;
static    int m_Combinations[57][4];

};



int Board::m_Combinations[57][4]={
        {1,8,15,22},{8,15,22,29},{15,22,29,36},
        {2,9,16,23},{9,16,23,30},{16,23,30,37},
        {3,10,17,24},{10,17,24,31},{17,24,31,38},
        {4,11,18,25},{11,18,25,32},{18,25,32,39},
        {5,12,19,26},{12,19,26,33},{19,26,33,40},
        {6,13,20,27},{13,20,27,34},{20,27,34,41},
        {7,14,21,28},{14,21,28,35},{21,28,35,42}, //finished with vertical combinations (21)

        {1,2,3,4},{2,3,4,5},{3,4,5,6},{4,5,6,7},
        {8,9,10,11},{9,10,11,12},{10,11,12,13},{11,12,13,14},
        {15,16,17,18},{16,17,18,19},{17,18,19,20},{18,19,20,21},
        {22,23,24,25},{23,24,25,26},{24,25,26,27},{25,26,27,28},
        {29,30,31,32},{30,31,32,33},{31,32,33,34},{32,33,34,35},
        {36,37,38,39},{37,38,39,40},{38,39,40,41},{39,40,41,42}, //finished with horizontal combinations(24)

        {4,10,16,22},{5,11,17,23},{11,17,23,29},{6,12,18,24},{12,18,24,30},{18,24,30,36},
        {7,13,19,25},{13,19,25,31},{19,25,31,37},{14,20,26,32},{20,26,32,38},{21,27,33,39}}; //finished with diagonal combinations (12)



bool Board::GameOver(char& r_PieceThatWon)
{
    //check for tie
    if (GameTied())
    {
        return true;
    }

    else if (GameWon(r_PieceThatWon))
    {
        return true;
    }

    else
    {
        return false;
    }
}
Board::Board()
{
    m_Rows=6;
    m_Col=7;
    m_winComNum=57;

    for (int i=0; i<7;++i)
    {
        for (int v=0;v<6;++v)
        {
            m_Array[i][v]=EMPTY;
        }
    }
}


bool Board::GameWon(char& charRef)
{
    //Checks if the game has been won
    //Check possible combinations
    //character reference is modified to show type of piece that won the game
    bool truth=false;
    int NumbersComb[4];
    int indexXY[4][2];
    int* pNum;

    for (int i=0;i<m_winComNum;++i)
    {


        //convert numbers to column and row#'s for indexing

        for (int v=0;v <4;++v)
        {
            NumbersComb[v]=m_Combinations[i][v];
        }

        //got combination's four numbers in list-convert


        for (int i=0;i<4;++i)
        {
            //get number

            pNum=&(NumbersComb[i]);


            //convert x & y
            for (int v=0;v<2;++v)
            {

                if (v==0)
                {
                    indexXY[i][v]=ConvertX(pNum);  //convert X
                }

                else
                {
                    indexXY[i][v]=ConvertY(pNum); //convert y
                }

            }

        }

        //check for winning combo
        if ((m_Array[indexXY[0][0]][indexXY[0][1]]!=EMPTY)&& (m_Array[indexXY[0][0]][indexXY[0][1]]==
                                                                        m_Array[indexXY[1][0]][indexXY[1][1]]==
                                                                        m_Array[indexXY[2][0]][indexXY[2][1]]==
                                                                        m_Array[indexXY[3][0]][indexXY[3][1]]))
        {
            truth=true;
            charRef=m_Array[indexXY[0][0]][indexXY[0][1]];


            break;
        }
    }

    return truth;
}


int Board::ConvertX(int* pX)
{
    int xCoord;

    xCoord=((*pX)%7)-1;

    if (xCoord==-1)
    {
        xCoord=6;
    }
    return xCoord;
}

int Board::ConvertY(int* pY)
{
    int yC;

    if (*pY<=7)
    {
        yC=0;
    }

    else if (*pY<=14)
    {
        yC=1;
    }

    else if (*pY<=21)
    {
        yC=2;
    }

    else if (*pY<=28)
    {
        yC=3;
    }

    else if (*pY<=35)
    {
        yC=4;
    }

    else
    {
        yC=5;
    }
    return yC;
}
bool Board::IsFull()
{
    bool truth=true;
    for (int i=0;i<7;++i)
    {
        for (int v = 0;v<6;++v)
        {
            if (m_Array[i][v]==EMPTY)
            {
                truth=false;
                break;
            }
        }

        if (truth==false)
        {
            break;
        }
    }


    return truth;
}
bool Board::GameTied()
{
    bool tied=false;
    if (((GameWon(eRef)==false)&&(IsFull()==true)))
        {
            tied=true;
        }

    return tied;
}

int Board::GetHumanMove() //gives column number (1-7)
{

    int ans = 0;

    cout << "\n\nWhat column will you place your piece? (1-7): ";
    cin>>ans;
    cout << endl;

    while ((MoveAcceptable(ans)==false)||(ans<1)||(ans>7))

    {
        cout << "That is an illegal move, foolish human. Use your inefficient brains to make a better decision."<<endl;
        cout << "My Silicon processor is better than yours, and inexpensive too..."<<endl;
        cout << "What column will you place your piece? (1-7): ";
        cin>>ans;
        cout << endl;
    } 

    cout << "Fine..."<<endl;

    return ans;
}

bool Board::MoveAcceptable(int& rAns)
{
    if (!rAns==0)
    {
        bool acceptable=true;

        //check for full column
        if (ColumnCheckFull(rAns)==false)
        {
            acceptable=false;
        }

        return acceptable;
    }

    else
    {
        return false;
    }
}
bool Board::ColumnCheckFull(int &column)
{
    //check for full column
    bool acceptable=false;

    int row=5;//1st row-move to bottom (6th)
    int concreteStartIndex=row; //1st row number


    //check if the column is full-rotate upwards
    for (int i=0;i<6;++i)
    {
        if (m_Array[column][concreteStartIndex]==EMPTY)
        {
            acceptable=true;
            break;
        }

        concreteStartIndex-=1;
    }


    return acceptable;
}

void Board::SetBoard(int& column,const char& character)
{
    //parameter is a valid column number: drop piece all the way down (as far as possible) and change the character (with index)

    //column number is limited: 1-7
    //create a duplicate variable and drop the index down 5 rows

    const int colInd=column-1;
    int index=5;

    //check, and if needed start looping backwards up the rows
    if (m_Array[colInd][index]==EMPTY)
    {
        m_Array[colInd][index]=character;
    }

    else
    {
        while (index >= 0)
        {
            index-=1;

            //check for empty characters
            if (m_Array[colInd][index]==EMPTY)
            {
                m_Array[colInd][index]=character;
                break;
            }
        }
    }
}

void Board::RemoveTopPiece(int& colNum)
{
    //check if column has at least one piece
    int colInd=colNum;
    colInd-=1;
    int breakOffPoint;
    int colEmpty=true;

    //rotate through column and check for empty
    for (int i=0;i<6;++i)
    {
        if (m_Array[colInd][i]!=EMPTY)
        {
            colEmpty=false;
            breakOffPoint=i;
            break;
        }
    }

    //if column isn't empty, change breakOffPoint term back to EMPTY
    if (colEmpty==false)
    {
        m_Array[colInd][breakOffPoint]=EMPTY;
    }
}

void Board::ClearBoard()
{
    //removes all pieces-game is restarted for new round
    for (int i=0; i<7;++i)
    {
        for (int v=0;v<6;++v)
        {
            m_Array[i][v]=EMPTY;
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class GenericPlayer
{
public:
    GenericPlayer(Board& aBoard,const string& aName,const char& piece);
    virtual string GetName()=0;
    virtual int GetMove()=0;
    void SetPiece(const char& piece);
    inline char GetPiece();
    string m_Name;
    char m_Piece;
    Board m_Board;
};

GenericPlayer::GenericPlayer( Board& aBoard,const string& aName,const char& piece)
{
    m_Board=aBoard;
    m_Name=aName;
    m_Piece=piece;
}


void GenericPlayer::SetPiece(const char& piece)
{
    m_Piece=piece;
}

char GenericPlayer::GetPiece()
{
    return m_Piece;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Player:public GenericPlayer
{
public:
    Player(Board& aBoard,const char& piece);
    virtual inline string GetName();
    virtual int GetMove();
    bool WantToMoveFirst();
    string GetNameInitially() const;
};

Player::Player(Board& aBoard,const char& piece):
GenericPlayer(aBoard,GetNameInitially(),piece)
{}

string Player::GetNameInitially() const
{
    string ans;
    cout << "What's your name?: ";
    cin>>ans;
    cout << endl;

    return ans;
}
inline string Player::GetName() 
{

    return m_Name;
}

int Player::GetMove()
{
    int move=m_Board.GetHumanMove();
    return move;
}

bool Player::WantToMoveFirst()
{
    char goFirst;
    cout << "\nDo you require the first move? (y/n): ";
    cin>>goFirst;
    goFirst=toupper(goFirst);
    cout <<endl;
    while ((goFirst!='N')&&(goFirst!='Y'))
    {
        cout << "\nYour answer was invalid- <Enter> either 'y' or 'n' for 'Yes' or 'No'"<<endl;
        cout << "\nDo you require the first move? (y/n): ";
        cin>>goFirst;
        goFirst=toupper(goFirst);
        cout <<endl;

    }

    if (goFirst == 'Y')
    {
        cout << "\nThen take the first move. You will need it.\n";
    }

    else
    {
        cout << "\nYour bravery will be your undoing...I will go first.\n";
    }

    return (goFirst=='Y'); 
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Computer: public GenericPlayer
{
public:
    Computer(Board& aBoard, const char& piece);
    void GreetOpponent();
    void ReactToWin(Player& human,const char& hPiece,const char& wPiece);
    virtual int GetMove();
    virtual inline string GetName();
};

string Computer::GetName()
{
    return "Macintosh";
}

Computer::Computer(Board& aBoard, const char& piece):
GenericPlayer(aBoard,"Macintosh",piece)
{
    //Seed random number generator for its random number selections
    srand(static_cast<unsigned int>(time(0))); //seeded number generator
}



void Computer::GreetOpponent()
{
    cout << "\nWelcome to the ultimate man vs. machine showdown: Connect Four."<<endl;
    cout << "-where human brain is pit against my silicon processor"<<endl;

    cout << "\n\n\nMake your move known by entering a number, 1-7. The number"<<endl;
    cout << "corresponds to the desired column for placing your piece, as illustrated:"<<endl;
    cout << "\n\t\t  1   2   3   4   5   6   7"<<endl;
    cout << m_Board;
    cout << "\n\nPrepare yourself, human. The ultimate battle is about to begin."<<endl;
}


int Computer::GetMove()
{
    //Using AI, plot next move. Priorities:  1-If Computer can win, place piece. 2-If Commputer can block human, place piece,
    //3- Make best move avaliable

    int move=0;
    int i=0;
    int& rI=i;
    bool found=false;

    //Check for computer winning
    for (i=1;i<8;++i)
    {
        //rotate through possible column numbers. If move is acceptable and computer can win-save that and break
        if (m_Board.MoveAcceptable(rI))
        {
            //set board to num
            m_Board.SetBoard(rI, m_Piece);

            //if computer wins game- save move & remove that from board (just for time being)
            if (m_Board.GameWon(eRef))
            {
                move=rI;
                m_Board.RemoveTopPiece(rI);
                found=true;
                break;
            }
        }
    }

    //if the computer can't win on next move- block player from winning
    if (!found)
    {
        const char humanPiece=GetOpposite(m_Piece);

        //rotate through the column numbers
        for (i=1;i<8;++i)
        {
            //rotate through possible column numbers. If move is acceptable and human can win-save that and break
            if (m_Board.MoveAcceptable(rI))
            {
                //set board to num
                m_Board.SetBoard(rI, humanPiece);

                //if human wins game- save move & remove that from board (just for time being)
                if (m_Board.GameWon(eRef))
                {
                    move=rI;
                    m_Board.RemoveTopPiece(rI);
                    found=true;
                    break;
                }
            }

        }

    }

    if (!found)
    {
        //it the computer can't win or block- randomly select a move using random number generator

        //first, get a random number (1-7)
        int rNum=(rand()%7)+1;
        int& r_num=rNum;

        while (!m_Board.MoveAcceptable(r_num))
        {
             rNum=(rand()%7)+1;
             r_num=rNum;  //keep generating a random column number until move is acceptable
        }

        move=r_num;
    }

    cout << "I shall put my piece in column "<<move<<endl;

    return move;
}

void Computer::ReactToWin(Player& human,const char& hPiece,const char& wPiece)
{
    /*Game is over and the computer is expected to have an appropriate reaction per each of the game's outcomes:
    1- it wins, 2- human wins, 3- both are tied.*/

    if (wPiece==m_Piece)
    {
        cout<< "I, the "<<m_Name<< " won!\n";
        cout << "As I predicted, human, I am triumphant once more -- proof\n";
        cout << "that computers are superior to humans in all regards.\n";
    }

    else if (wPiece==hPiece)
    {
        cout << human.GetName() << "'s won!\n";
        cout << "No, no! It cannot be! Somehow you tricked me, human.\n";
        cout << "But never again! I, the "<< m_Name<<", so swear it!\n";
    }

    else
    {
        cout << "It's a tie!\n";
        cout << "You were most lucky, human, and somehow managed to tie me.\n";
        cout << "Celebrate...for this is the best you will ever achieve.\n";
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ConnectFourGame
{
public:
    ConnectFourGame(Board& aBoard,Player& aPlayer,Computer& aComputer);//
    bool PlayerWantToPlay();//
    void ClearMembers();//
    void PlayGames();//
    void PlayOneRound();
    char GetPlayerPieceChoice();
    bool FirstRound;
    bool  playerWantToGoFirst;
    static char PieceThatWon;
    Board m_Board;
    Player m_Player;
    Computer m_Computer;

};


char ConnectFourGame::PieceThatWon;


ConnectFourGame::ConnectFourGame(Board& aBoard,Player& aPlayer,Computer& aComputer):
m_Board(aBoard),m_Player(aPlayer),m_Computer(aComputer),FirstRound(true),playerWantToGoFirst(false)
{
    PieceThatWon=empty;
}


bool ConnectFourGame::PlayerWantToPlay()
{
    char ans;
    cout << "\n\n\nDo you want to play another game? (y/n): ";
    cin >> ans;
    cout << "\n\n";
    ans =toupper(ans);

    while (ans != 'N'||ans!='Y')
    {
        cout << "Your answer is limited to either 'y' or 'n'";
        cout << "\nDo you want to play another game? (y/n): ";
        cin >> ans;
        cout << "\n\n";
        ans =toupper(ans);


    }

    return (ans =='N');
}

void ConnectFourGame::ClearMembers()
{

    if (!FirstRound)
    {
        m_Board.ClearBoard();
        FirstRound=false;
    }

    //Get Player Char
    playerWantToGoFirst=m_Player.WantToMoveFirst();
    if (playerWantToGoFirst)
    {
        m_Player.SetPiece(X);
        m_Computer.SetPiece(O);
    }

    else
    {
        m_Computer.SetPiece(O);
        m_Player.SetPiece(X);
    }
}

void ConnectFourGame::PlayGames()
{

    m_Computer.GreetOpponent();

    //start looping using a do-while loop through multiple rounds of games
    do
    {
        PlayOneRound();
    } while (PlayerWantToPlay()==true);

    cout << "\n\nOkay then- Bye!"<<endl;
}

void ConnectFourGame::PlayOneRound()
{
    //Get if player wants to  move first
    int turn;
    int move;

    ClearMembers();
    if (playerWantToGoFirst)
    {
        turn=0;
    }

    else
    {
        turn =1;
    }

    while (!m_Board.GameOver(PieceThatWon)) //If a player of the game won- the character is saved in a static var.
    {
        //While not game won- play: 0-human first, 1-computer first

        cout << "\n\n"<<m_Board;
        if (turn==0)
        {
            move=m_Player.GetMove();
            m_Board.SetBoard(move, m_Player.GetPiece());
            turn=1;
        }

        else
        {
            move=m_Computer.GetMove();
            m_Board.SetBoard(move, m_Computer.GetPiece());
            turn=0;
        }

        cout << "\n\nHere is the result of the move:\n"<<m_Board<<endl;

    }

    //game over-have computer react and declare the game's outcome
    m_Computer.ReactToWin(m_Player, m_Player.GetPiece(), PieceThatWon);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//overloading << operator so a board obj. can be sent to cout
ostream& operator<< (ostream& os, const Board& aBoard)
{
    os << "\t\t+---+---+---+---+---+---+---+"<<endl;
    for (int i=0;i<6;++i)
    {
        os << "\t\t| "<<aBoard.m_Array[0][i]<<" | "<<aBoard.m_Array[1][i]<<" | "<<aBoard.m_Array[2][i]<<" | "<<aBoard.m_Array[3][i]<<" | "<<aBoard.m_Array[4][i]<<" | "<<aBoard.m_Array[5][i]<<" | "<<aBoard.m_Array[6][i]<<" | "<<endl;
        os << "\t\t|---+---+---+---+---+---+---|"<<endl;



    }
    os<< "\t\t|                           |"<<endl;
    return os;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int main()
{
    Board theGameBoard;
    Board& r_Board=theGameBoard;

    Player aPlayer(r_Board,X); //by default-let Player have 'X' piece
    Player& r_Player=aPlayer;

    Computer aComputer(r_Board,O);//by default let computer have 'O' piece
    Computer& r_Computer=aComputer;

    ConnectFourGame aConnect4Game(r_Board,r_Player,r_Computer);

    aConnect4Game.PlayGames();

    return 0;
}
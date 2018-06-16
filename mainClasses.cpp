
class TicTacToe
{
    private:
        string xUserName; //name that identify x's user
        string oUserName; //name that identify o's user
        char board[FIRST_DIMENSION_SIZE][SECOND_DIMENSION_SIZE];
        char xUserPlay; //char that identify x's user sign on the board
        char oUserPlay; //char that identify o's user sign on the board
        char emptyPlay; //char that identify empty sign on the board
        int playCount; //counter var to verify status of the game
    public:
        TicTacToe();
        void setXUserName(string xUserNameIn);
        string getXUserName();
        void setOUserName(string oUserNameIn);
        string getOUserName();
        void setXUserPlay(char xUserPlayIn);
        char getXUserPlay();
        void setOUserPlay(char oUserPlayIn);
        char getOUserPlay();
        void setEmptyPlay(char emptyPlayIn);
        char getEmptyPlay();
        void setPlayAtPosition(int row, int column, char play);
        char getPlayAtPosition(int row, int column);
        char checkGameEndByColumnOrRow(int checkBy);
        char checkGameEndByDiagonal();
        int checkGameEnd(string user);
        void run();
        void printBoard();
};

TicTacToe::TicTacToe()
{
    xUserPlay = 'x';
    oUserPlay = 'o';
    emptyPlay = '-';
    xUserName = "user_x";
    oUserName = "user_o";
    playCount = 0;
    //Initialize board to empty play on all positions
    for(int i=0; i<FIRST_DIMENSION_SIZE; i++)  
    {
        for(int j=0; j<SECOND_DIMENSION_SIZE; j++)
        {
            board[i][j] = emptyPlay;
        }
    }
}
void TicTacToe::setXUserName(string xUserNameIn)
{
    xUserName = xUserNameIn;
}
string TicTacToe::getXUserName()
{
    return xUserName;
}
void TicTacToe::setOUserName(string oUserNameIn)
{
    oUserName = oUserNameIn;
}
string TicTacToe::getOUserName()
{
    return oUserName;
}
void TicTacToe::setXUserPlay(char xUserPlayIn)
{
    xUserPlay = xUserPlayIn;   
}
char TicTacToe::getXUserPlay()
{
    return xUserPlay;
}
void TicTacToe::setOUserPlay(char oUserPlayIn)
{
    oUserPlay = oUserPlayIn;
}
char TicTacToe::getOUserPlay()
{
    return oUserPlay;
}
void TicTacToe::setEmptyPlay(char emptyPlayIn)
{
    emptyPlay = emptyPlayIn;
}
char TicTacToe::getEmptyPlay()
{
    return emptyPlay;
}
void TicTacToe::setPlayAtPosition(int row, int column, char play)
{
    board[row][column] = play;
    playCount++;
}
char TicTacToe::getPlayAtPosition(int row, int column)
{
    return board[row][column];
}
/*
    This method check if a user win by column rule or row rule
*/
char TicTacToe::checkGameEndByColumnOrRow(int checkBy)
{
    char play;
    /*
        Set firstDimesion(rows): 
            if we are checking by column, firstDimension is equal to the board array second dimension length
            if we are checking by row, firstDimension is equal to the board array first dimension length
        Set secondDimensionSize(columns):
            if we are checking by column, firstDimension is equal to the board array first dimension length
            if we are checking by row, firstDimension is equal to the board array second dimension length
    */
    int firstDimensionSize = ((checkBy == CHECK_BY_COLUMN) ? SECOND_DIMENSION_SIZE : FIRST_DIMENSION_SIZE);
    int secondDimensionSize = ((checkBy == CHECK_BY_COLUMN) ? FIRST_DIMENSION_SIZE : SECOND_DIMENSION_SIZE);
    for(int i=0; i<firstDimensionSize; i++)
    {
        playCount = 0;
        /*
            Set play(the sign returned by this method) from board specific position:
                if we are checking by column, board's firstDimension offset is equal to 0 and board's secondDimension offset is equal to i
                if we are checking by row, board's firstDimension offset is equal to i and board's secondDimension offset is equal to 0           
        */
        play = board[((checkBy == CHECK_BY_COLUMN) ? 0 : i)][((checkBy == CHECK_BY_COLUMN) ? i : 0)];
        if(play == emptyPlay) //Skip this loop cicle if play is equal to empty
        {
            continue;
        }
        for(int j=0; j<secondDimensionSize; j++) //This loop continue verifing board position that represent play var
        {
            //Verify if next board position to be checked is equal to play var
            if(board[((checkBy == CHECK_BY_COLUMN) ? j : i)][((checkBy == CHECK_BY_COLUMN) ? i : j)] == play)
            {
                playCount++;    
            }
            else
            {
                break;
            }
        }
        if(playCount == firstDimensionSize)
        {
          break;
        }
    }
    if(playCount < firstDimensionSize)
    {
        play = emptyPlay;
    }
    return play;
}
char TicTacToe::checkGameEndByDiagonal()
{
    if(FIRST_DIMENSION_SIZE == SECOND_DIMENSION_SIZE){
        int fromLeftToRightDiagonalCount = 0;
        char fromLeftToRightPlay = emptyPlay;
        int fromRightToLeftDiagonalCount = 0;
        char fromRightToLeftPlay = emptyPlay;
        for(int i=0; i<FIRST_DIMENSION_SIZE; i++)
        {
            //From left to right first step
            if(board[i][i] != emptyPlay && i == 0)
            {
                fromLeftToRightPlay = board[i][i];
                fromLeftToRightDiagonalCount++;
            }
            //From left to right second step
            else if(board[i][i] == fromLeftToRightPlay && i > 0)
            {
                fromLeftToRightDiagonalCount++;
            }
            if(fromLeftToRightDiagonalCount == FIRST_DIMENSION_SIZE)
            {
                return fromLeftToRightPlay;
            }
            //From right to left first step
            if(board[i][(FIRST_DIMENSION_SIZE-1)-i] != emptyPlay && i == 0)
            {
                fromRightToLeftPlay = board[i][(FIRST_DIMENSION_SIZE-1)-i];
                fromRightToLeftDiagonalCount++;
            }
            //From right to left second step
            else if(board[i][(FIRST_DIMENSION_SIZE-1)-i] == fromRightToLeftPlay && i > 0)
            {
                fromRightToLeftDiagonalCount++;
            }
            if(fromRightToLeftDiagonalCount == FIRST_DIMENSION_SIZE)
            {
                return fromRightToLeftPlay;
            }
        }
    }
    return emptyPlay;
}
int TicTacToe::checkGameEnd(string user)
{
    //Verify if game is tied
    if(playCount == (FIRST_DIMENSION_SIZE * SECOND_DIMENSION_SIZE))
    {
        cout<<"Game tied\n";
        return 1;
    }
    //Verify if a user win by row or colum or diagonal
    if(checkGameEndByColumnOrRow(CHECK_BY_COLUMN) != emptyPlay || 
       checkGameEndByColumnOrRow(CHECK_BY_ROW) != emptyPlay ||
       checkGameEndByDiagonal() != emptyPlay)
    {
        cout<<user<<" wins\n";
        return 1;
    }
    
    return 0;
}
//This method run the main loop 
void TicTacToe::run()
{
    printBoard(); //Print initial board
    int userTurn = X_USER;
    int row = 0, column = 0;
    char play;
    string userTurnName;
    while(checkGameEnd(userTurnName) != 1)
    {
        userTurnName = ((userTurn == X_USER) ? xUserName : oUserName);
        play = ((userTurn == X_USER) ? xUserPlay : oUserPlay);
        cout<<"User "<<userTurnName<<" enter row location: ";
        cin>>row;
        if(verifyCinInput(cin)) //Verify integer input
            continue;
        cout<<"User "<<userTurnName<<" enter column location: ";
        cin>>column;
        if(verifyCinInput(cin))
            continue;
        if(getPlayAtPosition(row, column) == emptyPlay)
        {
            setPlayAtPosition(row, column, play);
        }
        else
        {
            cout<<"Position is not available, try another one\n";
            continue;
        } 
        printBoard();
        userTurn = ((userTurn == X_USER) ? O_USER : X_USER);
    }
}
//Print the board
void TicTacToe::printBoard()
{
    for(int i=0; i<FIRST_DIMENSION_SIZE; i++)
    {
        for(int j=0; j<SECOND_DIMENSION_SIZE; j++)
        {
            cout<<setw(5)<<board[i][j];
        }
        cout<<endl;
    }   
}
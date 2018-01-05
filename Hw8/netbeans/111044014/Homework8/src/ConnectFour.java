import java.util.Random;

class ConnectFour
{
    final private  int USER1PLAYERID = 0;
    final private  int USER2PLAYERID = 1;
    final private  int COMPUTERPLAYERID = 2;
    final private  char USER1 = 'X';
    final private  char USER2 = 'O';
    final private  char EMTHY = '.';

    private  Cell[][] gameCells ;
    private int gameSizeRow = 4; //default size
    private int gameSizeColumn = 4; //default size
    private int GameMode = 1; //default game mode
    private int WhoIsWillPlay = 1;
    private Boolean isEnded = false;

    public ConnectFour(int row,int column,int mode){
        gameSizeRow = row;
        gameSizeColumn = column;
        GameMode = mode;
        InitialBoard(gameSizeRow, gameSizeColumn);
        PrintGameBoard();
    }
    void SetWhoIsWillPlay( int who) { WhoIsWillPlay = who; }
    int GetWhoIsWillPlay() { return WhoIsWillPlay; }

    int getGameSizeRow() { return gameSizeRow; }

    void setGameisEnded( Boolean end) { isEnded = end; }
    Boolean getGameisEnded() { return isEnded; }

    int getGameSizeColumn() { return gameSizeColumn; }

    Cell GetGameBoard( int row,  int column) { return gameCells[row][column]; }
    void SetGameBoard( int row,  int column, char value) { gameCells[row][column].SetCellValue(value);	 }
    void SetGameBoard(Cell c) {
        gameCells[c.GetPosRow()][c.GetPosColumn()].SetCellValue(c.GetCellValue());
    }
     /*
     *	Desciription : This function it dont take parameter playing for computer is taking parameter will play for user
     *	Input		   : no parameter
     *	Return Value   : no return value
     */
    int  ComputerMove() {
        int row = 0, column = 0;
        SmallCell MaxEnem = new SmallCell(0,0,"00000000");

        int rowSize = getGameSizeRow();  int columnSize = getGameSizeColumn();
        Boolean isPlayeable = true;
        for ( column = columnSize - 1; column >= 0; --column) {
            if (GetGameBoard(rowSize - 1, column).GetCellValue() == USER2) {
                break;
            }
        }

        if (true == isPlayeable) {
            Random r=new Random(); //random sınıfı
            while (true) {
                column = r.nextInt(100000) % columnSize;
                if (column < 0)
                    column *= -1;
                for (row = rowSize - 1; row >= 0 &  column >= 0 & column < columnSize; --row) {
                    if (GetGameBoard(row, column).GetCellValue() == EMTHY) {
                        SetGameBoard(row, column, USER2);
                        System.out.println("Movement For Computer " + "Position is row ->  " + row + "\tColumn is " + column );
                        return column;
                    }
                }
            }
        }
        PrintGameBoard();
        return 0;
    }
    /*
     *	Desciription : This function checking is game ended or not
     *	Input		   : no input
     *	Return Value : return interger if 1 user one won if  2 user2 won  if -1 game is not ender
     */
    int IsGameOver() {
    if (false == AnyMoveMore()) {
        System.out.println("Game is Ended " );
        System.out.println("Game is draw play new game" );
        return -1;
    }
    if (true == IsGameOverOneSide(USER1, USER2)) {
        System.out.println("<---------------->USER1 WON<---------------->" );
        return -1;
    }
    if (true == IsGameOverOneSide(USER2, USER1)) {
        System.out.println("<---------------->USER2 WON<----------------> " );
        return -1;
    }
    return 0;
}
    Boolean AnyMoveMore() {
        int row = getGameSizeRow();
        int column = getGameSizeColumn();
        for (int i = row - 1; i >= 0; --i) {
            for (int j = column - 1; j >= 0; --j) {
                if (GetGameBoard(i, j).GetCellValue() == EMTHY)
                    return true;
            }
        }
        return false;
    }
    /*
     *	Desciription	: This function controlling given direction and size of element
     *	Input			:
     *	Return Value	: return String 1 or 0
     */
    String PartnerCheck( int direction,  int posX,  int posY,  char comparator,  char othercomparator,  int WinCounter,  Boolean flag) {
    int row = getGameSizeRow();
    int column = getGameSizeColumn();
    int counter = 0, i = 0, j = 0, l = 0;
    int k = 0;
    for (i = posX, j = posY; ;) {
        if (i < 0 || i >= row)
            break;
        if (j < 0 || j >= column)
            break;
        counter = CheckCounter(comparator, othercomparator, counter, i, j);
        if (counter == WinCounter) {
            if (flag) {
                int t = 0;
                switch (direction) {
                    case 1:
                        for (; t < WinCounter; ++t)
                            SetGameBoard(i + t, j + t,  comparator );
                    case 2:
                        for (; t < WinCounter; ++t)
                            SetGameBoard(i - t, j + t, comparator );
                        break;
                    case 3:
                        for (; t < WinCounter; ++t)
                            SetGameBoard(i + t, j - t, comparator );
                        break;
                    case 4:
                        for (; t < WinCounter; ++t)
                            SetGameBoard(i - t, j - t, comparator );
                        break;
                    case 5:
                        for (; t < WinCounter; ++t)
                            SetGameBoard(i + t, j, comparator );
                        break;
                    case 6:
                        for (; t < WinCounter; ++t)
                            SetGameBoard(i - t, j, comparator );
                        break;
                    case 7:
                        for (; t < WinCounter; ++t)
                            SetGameBoard(i, j + t, comparator );
                        break;
                    case 8:
                        for (; t < WinCounter; ++t)
                            SetGameBoard(i, j - t, comparator );
                        break;
                    default:
                        break;
                }
                PrintGameBoard();
            }
            return "1";
        }
        switch (direction) {
            case 1://LeftUpCross
                --i; --j;
            case 2://LeftDownCross
                ++i; --j;
                break;
            case 3://RightUpCross
                --i; ++j;
                break;
            case 4://RightDownCross
                ++i; ++j;
                break;
            case 5://Up
                --i;
                break;
            case 6://Down
                ++i;
                break;
            case 7://Left
                --j;
                break;
            case 8://Right
                ++j;
                break;
            default:
                break;
        }
    }
    return "0";
}
    /*
     *	Desciription : This function checking is game ended for one side
     *	Input		   : no input
     *	Return Value : return interger if 1 user one won if  2 user2 won  if -1 game is not ender
     */
    Boolean IsGameOverOneSide( char User,  char other) {
        int row = getGameSizeRow();
        int column = getGameSizeColumn();
        String controller = "";
        String EndControl = new String("00000000");
        for (int i = row - 1; i >= 0; --i) {
            for (int j = column - 1; j >= 0; --j) {
                controller = "";
                for (int direction = 1; direction <= 8; direction++)//8 is number of direction
                    controller += PartnerCheck(direction, i, j, User, other, 4, true);
                if (!controller.equals(EndControl))
                    return true;
            }
        }
        return false;
    }

    int CheckCounter( int CurComp,  int OtherComp, int count,  int i,  int j) {
        if (GetGameBoard(i, j).GetCellValue() == CurComp)
            ++count;
        if (GetGameBoard(i, j).GetCellValue() == OtherComp)
            count = 0;
        return count;
    }
     /*
     *	Desciription : This function taking one move without computer and make a move
     *	Input		   : int curren player id
     *					   char current move to make a move
     *	Return Value   : No return value
     */
    void PlayerMove( int player_id,  int CurrentMove) {
	    int rowSize = getGameSizeRow();
        char CurrentComparor = 'X';
        if (player_id == USER1PLAYERID)
            CurrentComparor = USER1;
        else if (player_id == USER2PLAYERID)
            CurrentComparor = USER2;
        if (player_id != COMPUTERPLAYERID) {
            if (CurrentMove >= 0  & CurrentMove <=  getGameSizeColumn()-1) {
                int column = CurrentMove ;
                for (int i = rowSize - 1; i >= 0; --i) {
                    if (gameCells[i][column].GetCellValue() == EMTHY) {
                        SetGameBoard(new Cell(column,i,CurrentComparor));
                        break;
                    }
                }
            }
        }
    }
    /*	Desciription : Printing screen current status of game board
     *	Input		 : no input parameter
     *	Return Value : no return value
     */
    void PrintGameBoard() {
        char a = 'A', b = 'A';
        int row = getGameSizeRow();
        int column = getGameSizeColumn();
        while (a < b + column) {
            System.out.print("  " + a + " ");
            a++;
        }
        System.out.print("\n");
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++)
                System.out.print("  " + gameCells[i][j].GetCellValue() + " ");
            System.out.print("\n");
        }
    }
    /*
     *	Desciription : This function initial board
     *	Input		   : no input parameter
     *	Return Value : no return value
     */
    void InitialBoard( int row,  int column) {
        gameCells = new Cell[row][column];
        for (int i = 0; i <row ; i++) {
            for (int j = 0; j <column ; j++) {
                gameCells[i][j] =new Cell(i,j,EMTHY);
            }
        }
    }

}


import sun.net.www.ParseUtil;

import java.util.Random;
import java.util.Scanner;

import java.util.Vector;

class ConnectFour
{
    final private  int USER1PLAYERID = 1;
    final private  int USER2PLAYERID = 2;
    final private  int COMPUTERPLAYERID = 3;
    final private  int TWO_PLAYER = 1;
    final private  int ONE_PLAYER_VERSUS_COMPUTER = 2;
    final private  char USER1 = 'X';
    final private  char USER2 = 'O';
    final private  char EMTHY = '.';
    
    private Vector< Vector<Cell> > gameCells;
    private int gameSizeRow = 4; //default size
    private int gameSizeColumn = 4; //default size
    private int GameMode = 1; //default game mode
    private int WhoIsWillPlay = 1;
    private int CurrentElementCounter = 0;// 4 l� yapmaya ne kadar yak�n oldu�unu tutan bir  de�i�ken
    private Boolean isEnded = false;

    class Cell
    {
        private int PosColumn = 0;
        private int  PosRow = 0;
        private char CellValue = '.';

        public Cell(int PosC, int PosR, char val)
        {
            PosColumn = PosC;
            PosRow= PosR;
            CellValue = val;
        }
        public  Cell( Cell cell){
            PosColumn = cell.PosColumn ;
            PosRow  = cell.PosRow;
            CellValue = cell.CellValue; }

        public Cell() {

        }

        void SetPosRow( int row) { PosRow = row; }
          void SetPosColumn( int col) { PosColumn = col; }
          int GetPosRow() { return PosRow; }
          int GetPosColumn() { return PosColumn; }
          void SetCellValue( char col) { CellValue = col; }
          char GetCellValue() { return CellValue; }

    };

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
    
    void setCurrentElementCounter( int count) { CurrentElementCounter = count; }
    int getCurrentElementCounter() { return CurrentElementCounter; }

    void setGameSizeColumn( int size) { gameSizeColumn = size; }
    int getGameSizeColumn() { return gameSizeColumn; }

    void SetGameMode( int mode) { GameMode = mode; }
    int GetGameMode() { return GameMode; }

       Vector <Vector<Cell>> GetGameBoard() { return gameCells;}

      Cell GetGameBoard( int row,  int column) { return gameCells.get(row).get(column); }
      void SetGameBoard( int row,  int column, char value) { gameCells.get(row).get(column).SetCellValue(value);	 }

    void SetGameBoard(Cell c) {
        int row = c.GetPosRow();
        int column = c.GetPosColumn();
        gameCells.get(row).set(column, c);
    }

    /*
     *	This input file first line 1 element is game mode
     *	second element is game board size and
     *	3 element is which player will play  after loading game*/

    /*
     *	Desciription : This function saving gameboard status
     *	Input		   : conts String file name
     *	Return Value   : no return value
     */
    
    void Play() {
        char command = '.';
        /*Boolean isEnded = GameManager();
        if (isEnded) {
            System.out.println("if you want to quit enter q or enter different character" );
            cin >> command;
            if (command == 'q' || command == 'Q')
                --GameCount;
            else {
                System.out.println("\n\n************************************New Game*******************\\n" );
                NewGame();
            }
        }*/
    }
    /*
     *	Desciription : This function playing game respectively until one of the player win or moveable
     *					position when end
     *	Input		   : no input
     *	Return Value   : if return true game is over if return false game is not ended
     */
    Boolean GameManager() {
    int control = 0, check = 0;
    if (GetWhoIsWillPlay() == 1) {
        //Player1
        control = AllMoveOperation(USER1PLAYERID);
        if (control != 2  &  control != -1)
            SetWhoIsWillPlay(2);
    }
    else if (GetWhoIsWillPlay() == 2) {
        //System.out.println("GetGameMode\t" + GetGameMode());
        //System.out.println("GetWhoIsWillPlay()\t" + GetWhoIsWillPlay() );
        if (ONE_PLAYER_VERSUS_COMPUTER == GetGameMode())
            control = AllMoveOperation(COMPUTERPLAYERID);
        else if (TWO_PLAYER == GetGameMode())
            control = AllMoveOperation(USER2PLAYERID);
        if (control != 2 &  control != -1)
            SetWhoIsWillPlay(1);
    }
    check = IsGameOver();
    if (check == -1) {
        setGameisEnded(true);
        return true;
    }
    PrintGameBoard();
    return false;
}
    /*
     *	Desciription : This function managing all player move operation
     *	Input		   : Interger for which player playing
     *	Return Value   : if return integer if return 2 is load or save operation if return -1 wrong input if zero moving true
     */
    int AllMoveOperation( int PlayerID) {
    Boolean flag = false;
    int move = TakeMove(PlayerID);


     if(PlayerID != 3 ){
         return PlayMove(move, PlayerID);
     }
        else if (PlayerID == 3) {
            return PlayMove();
        }
    return -1;
}
    /*
     *	Desciription : This function taking move
     *	Input		   : no input
     *	Return Value   : returing legal move if return '-' move is not legal taking new move
     */
    int TakeMove( int PlayerID) {

        return 0;
    }
    /*
     *	Desciription : This function it dont take parameter playing for computer is taking parameter will play for user
     *	Input		   : no parameter
     *	Return Value   : no return value
     */
    int  PlayMove() {
    SmallCell MaxEnem = new SmallCell(0,0,"00000000");

    int  control = 0, MaxControl = 0, index = 0;
	 int rowSize = getGameSizeRow();  int columnSize = getGameSizeColumn();
    Boolean flag = true, isPlayeable = true;
    char pos;
    String controller = "00000000";
    for (int column = columnSize - 1; column >= 0; --column) {
        if (GetGameBoard(rowSize - 1, column).GetCellValue() == USER2) {
            flag = false;
            break;
        }
    }
    if (flag) {//First Move in game
        pos = MoveComputer();
        int column = (int)(pos - 'A');
        for (int row = rowSize - 1; row >= 0; --row) {
            if (GetGameBoard(row, column).GetCellValue() == EMTHY) {
                SetGameBoard(row, column, 'O');
                System.out.println("Movement For Computer " + "Position is row ->  " + row + "\tColumn is " + column );
                break;
            }
        }
    }
    else {
        for (int row = 0; row < rowSize; ++row) {
            for (int column = 0; column < columnSize; ++column) {
                for (int i = 3; i >= 2; --i) {
                    controller = "";
                    for (int direction = 1; direction <= 8; ++direction)//8 is number of direction
                        controller += PartnerCheck(direction, row, column, 'X', 'O', i, false);
                    control = MyStringCompare(controller);
                    if (control > MaxControl) {
                        MaxControl = control;
                        MaxEnem.posX = row;
                        MaxEnem.posY = column;
                        MaxEnem.CellCounter = controller;
                        setCurrentElementCounter(i);
                        break;
                    }
                }
            }
        }
        int row = 0, column = 0;
        System.out.println(MaxControl + " MaxEnem.posX " + MaxEnem.posX + " MaxEnem.posY " + MaxEnem.posY + " MaxEnem.CellCounter\t" + MaxEnem.CellCounter );
        if (MaxEnem.posX - 1 >= 0)
            if (GetGameBoard(MaxEnem.posX - 1, MaxEnem.posY).GetCellValue() == USER1  &  isPlayeable)
                isPlayeable = PlayIsPlayeable(1, isPlayeable, MaxEnem, MaxEnem.posX - 1, MaxEnem.posY);
        if (MaxEnem.posX - 1 >= 0 &  MaxEnem.posY - 1 >= 0)
            if (GetGameBoard(MaxEnem.posX - 1, MaxEnem.posY - 1).GetCellValue() == USER1   & isPlayeable)
                isPlayeable = PlayIsPlayeable(2, isPlayeable, MaxEnem, MaxEnem.posX - 1, MaxEnem.posY - 1);
        if (MaxEnem.posY - 1 >= 0)
            if (GetGameBoard(MaxEnem.posX, MaxEnem.posY - 1).GetCellValue() == USER1 & isPlayeable)
                isPlayeable = PlayIsPlayeable(3, isPlayeable, MaxEnem, MaxEnem.posX, MaxEnem.posY - 1);
        if (MaxEnem.posY + 1 < columnSize)
            if (GetGameBoard(MaxEnem.posX, MaxEnem.posY + 1).GetCellValue() == USER1 &  isPlayeable)
                isPlayeable = PlayIsPlayeable(4, isPlayeable, MaxEnem, MaxEnem.posX, MaxEnem.posY + 1);
        if (true == isPlayeable) {
             column = 0;

            Random r=new Random(); //random sınıfı

            while (true) {
                column = r.nextInt(100000) % columnSize;
                if (column < 0)
                    column *= -1;
                for (row = rowSize - 1; row >= 0 &  column >= 0 & column < columnSize; --row) {
                    if (GetGameBoard(row, column).GetCellValue() == EMTHY) {
                        SetGameBoard(row, column, USER2);
                        System.out.println("Movement For Computer " + "Position is row ->  " + row + "\tColumn is " + column );
                        isPlayeable = false;
                        break;
                    }
                }
                if (isPlayeable == false)
                    break;
            }
        }

    }
    return 0;
}
    int PlayMove( int move,  int PlayerID) {
    Boolean flag = false;

    System.out.println("MoveInputCheck is correct\n");
        //if flag true this can true input i will checking position is playable
        if (IsPositionPlayable(PlayerID, move) ) {// play move
            MovePlayer(PlayerID, move);
            return 0;
        }
        else {
            System.out.println(" <--->ILLEGAL<---> Position Cannot play enter another move " );
            return -1;
        }
    }


    void NewGame() {
    playGame();
    InitialBoard(gameSizeRow, gameSizeColumn);
    PrintGameBoard();
    SetWhoIsWillPlay(USER1PLAYERID);
}
    /*
     *	Desciription : This function computer automatic playin move
     *	Input		   : no parameter
     *	Return Value   : returnin if u find placable positon or returning '.' for error
     */
    char MoveComputer() {
    char pos;
        Random r=new Random(); //random sınıfı
        while (true) {

        pos = (char) ('A' + r.nextInt(100000) % getGameSizeColumn());
        if (IsPositionPlayable(COMPUTERPLAYERID, pos))
            return pos;
        }
    }
    /*
     *	Desciription : returning isPlaceable
     *	Input		   : no input parameter
     *	Return Value : if return false means move is played
     */
    Boolean PlayIsPlayeable( int direction, Boolean isPlayeable,  SmallCell MaxEnem, int row, int column) {
	 int rowSize = getGameSizeRow();
	 int columnSize = getGameSizeColumn();
    for (; ; ) {
        if (row < 0 || row >= rowSize)
            break;
        if (column < 0 || column >= columnSize)
            break;
        if (direction != 4) {//özel durum
            if (GetGameBoard(row, column).GetCellValue() == EMTHY) {
                SetGameBoard(row, column, USER2);
                System.out.println("Movement For Computer " + "Position is row ->  " + row + "Column is " + column );
                return false;
            }
        }
        else if (direction == 4) {
            if (MaxEnem.posX + 1 < rowSize &  MaxEnem.posX + 1 >= 0) {
                if(GetGameBoard(MaxEnem.posX, column).GetCellValue() == EMTHY   & GetGameBoard(MaxEnem.posX + 1, column).GetCellValue() != EMTHY){
                    SetGameBoard(MaxEnem.posX, column, USER2);
                    System.out.println("Movement For Computer " + "Position is row ->  " + MaxEnem.posX + "Column is " + column );
                    return false;
                }
            }
        }
        if (direction == 1)
            --row;
        else if (direction == 2){
            --row;
            --column;
        }
        else if (direction == 3)
            --column;
        else if (direction == 4)
            ++column;
        else if (direction == 5) {}
    }
    return true;
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
    if (IsGameOverOneSide(USER1, USER2)) {
        System.out.println("<---------------->USER1 WON<---------------->" );
        return -1;
    }
    if (IsGameOverOneSide(USER2, USER1)) {
        System.out.println("<---------------->USER2 WON<----------------> " );
        return -1;
    }
    System.out.println("Game is not ended " );
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
    for (int i = row - 1; i >= 0; --i) {
        for (int j = column - 1; j >= 0; --j) {
            controller = "";
            for (int direction = 1; direction <= 8; direction++)//8 is number of direction
                controller += PartnerCheck(direction, i, j, User, other, 4, true);
            if (controller != "00000000")
                return true;
        }
    }
    return false;
}
    /*
     *	Desciription : This function returnin number of '1' in your String
     *	Input		   :  String s1
     *	Return Value   : intger counter of "1"
     */
    int MyStringCompare( String s1) {
    int counter = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (s1.charAt(i) == '1')
            ++counter;
    }
    return counter;
}
    int CheckCounter( int CurComp,  int OtherComp, int count,  int i,  int j) {
    if (GetGameBoard(i, j).GetCellValue() == CurComp)
        ++count;
    if (GetGameBoard(i, j).GetCellValue() == OtherComp)
        count = 0;
    return count;
}
    /*
     *	Desciription : This function checking move legal ol illegal
     *	Input		   : position
     *	Return Value : if return true position is legal if false its illegal
     */
    Boolean IsPositionPlayable( int player_id,  int pos) {
    for (int i = getGameSizeRow() - 1; i >= 0; --i) {
        if (GetGameBoard(i, pos ).GetCellValue() == EMTHY)
            return true;
    }
    return false;
}

    /*	Desciription : Printing screen current status of game board
     *	Input		 : no input parameter
     *	Return Value : no return value
     */
    void PrintGameBoard() {
    char a = 'A', b = 'A';
    int row = getGameSizeRow();
    int column = getGameSizeColumn();
    //System.out.println("GameBoard row -> " + row );
    //System.out.println("GameBoard column -> " + column );
    while (a < b + column) {
        System.out.println("  " + a + " ");
        a++;
    }
    System.out.println("\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
            System.out.println("  " + GetGameBoard(i, j).GetCellValue() + " ");
        System.out.println("\n");
    }
}
    /*
     *	Desciription : This function initial board
     *	Input		   : no input parameter
     *	Return Value : no return value
     */
    void InitialBoard( int row,  int column) {
    Cell c = new Cell(0,0,'.');//no parameter contructor
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            c.SetPosRow(i);
            c.SetPosColumn(j);
            gameCells.get(i).set(j, c);
        }
    }
    }

    /*
     *	Desciription : This function checking game board size and game mode
     *					Cheking interger or not and for size 6x6, 8x8, 10x10, 20x20
     *					Cheking game mode  should be 1 or 2
     *	Input		 : no input parameter
     *	Return Value : no return value */
    void playGame() {/*
    int row = 0, column = 0;
    while (true) {
        System.out.println("Enter Game Row Size  \n" + "Game board can be any size \n";
        cin >> row;
        System.out.println("Enter Game Column Size  \n" + "Game board can be any size \n";
        cin >> column;
        if (cin.fail()) {
            cin.clear(); //This corrects the stream.
            cin.ignore(); //This skips the left over stream data.
            System.out.println(" <--->ILLEGAL<---> Wrong input enter integer \n";
        }
        else {
            setGameSizeColumn(column);
            setGameSizeRow(row);
            break;
        }
    }
    int mode = 0;
    while (1) {
        System.out.println("Enter Game mode \n" + "Game mode  1 : two player game \n 2: User versus computer game \n";
        cin >> mode;
        if (cin.fail()) {
            cin.clear(); //This corrects the stream.
            cin.ignore(); //This skips the left over stream data.
            System.out.println(" <--->ILLEGAL<---> Wrong input enter integer \n";
        }
        else {
            if (mode == 1 || mode == 2) {
                SetGameMode(mode);
                break;
            }
            else
                System.out.println("<--->ILLEGAL<---> Wrong Game Mode \n");
        }
    }*/
}

    /*
     *	Desciription : This function taking one move without computer and make a move
     *	Input		   : int curren player id
     *					   char current move to make a move
     *	Return Value   : No return value
     */
    void MovePlayer( int player_id,  int CurrentMove) {
	 int rowSize = getGameSizeRow();
    char CurrentComparor = '\0';
    if (player_id == USER1PLAYERID) {
        CurrentComparor = USER1;
    }
    else if (player_id == USER2PLAYERID) {
        CurrentComparor = USER2;
    }
    if (player_id != COMPUTERPLAYERID) {
        if (CurrentMove >= 0  & CurrentMove <=  getGameSizeColumn()-1) {
            int column = (int )(CurrentMove - 'A');
            for (int i = rowSize - 1; i >= 0; --i) {
                if (GetGameBoard(i, column).GetCellValue() == EMTHY) {
                    Cell temp= new Cell(column,i, CurrentComparor);
                    SetGameBoard(temp);
                    break;
                }
            }
        }
    }
}
};


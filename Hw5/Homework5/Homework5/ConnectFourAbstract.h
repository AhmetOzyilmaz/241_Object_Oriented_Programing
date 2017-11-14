#include "Cell.h"

namespace Ozyilmaz_Ahmet_111044014 {
	struct NeigborEnemy
	{
		int posX;
		int posY;
		string NeighborEnemyCounter;
	};

	class ConnectFourAbstract {

	public:
		ConnectFourAbstract();
		~ConnectFourAbstract();

		void LoadFileNew(const string& filename, const int useles) ;
		void LoadFile(const string& filename);
		void SaveFile(const string& filename);

		void PrintBoard();
		virtual void PlayMove(char move, const int& PlayerID) = 0;
		virtual void PlayMove() = 0;
		virtual void IsEnd() = 0;
		virtual void playGame() = 0;
		virtual void Play() = 0;

	private:
		inline void SetWhoIsWillPlay(const int who) { WhoIsWillPlay = who; }
		inline const int GetWhoIsWillPlay() { return WhoIsWillPlay; }
		inline void setRow(const int size) { BoardRow = size; }
		inline const int getRow() { return BoardRow; }
		inline void setGameisEnded(const bool end) { isEnded = end; }
		inline const bool getGameisEnded() { return isEnded; }
		inline void setGameID(const int id) { GameID = id; }
		inline int getGameID() const { return GameID; }
		inline void setCurrentElementCounter(const int count) { CurrentElementCounter = count; }
		inline const int getCurrentElementCounter() { return CurrentElementCounter; }
		inline void setColumn(const int size) { BoardColumn = size; }
		inline const int getColumn() { return BoardColumn; }
		inline void SetGameMode(const char mode) { GameMode = mode; }
		inline const char GetGameMode() { return GameMode; }
		inline Cell GetCell(const int& row, const int& column) { return gameCells[row][column]; }
		inline void SetGameBoard(const int& row, const int& column, const char& value) { gameCells[row][column].SetCellValue(value); }

		void SetGameBoard(Cell c) {
			int row = c.GetPosRow();
			int column = c.GetPosColumn();
			gameCells[row][column] = c;
		}
		void ParseFirstLine(const string& line, int& mode, int& row, int& column, int& play);

		void ReSizeGameBoard(const int& row, const int& column);
		void InitialBoard(const int& row, const int& column);
		void InitialBoard();

		bool MoveInputCheck(const string& command);
		char TakeMove(const int& PlayerID);
		bool CommandSelector(const string& command);
		int MyStringCompare(const string& s1);
		int CheckCounter(const int& CurComp, const int& OtherComp, int count, const int& i, const int& j);
		string PartnerCheck(const int direction, const int& posX, const int& posY, const char& comparator, const char& othercomparator, const int& WinCounter, const bool& flag = false);
		bool PlayIsPlayeable(const int& direction, bool isPlayeable, const NeigborEnemy& MaxEnem, int row, int column);
		bool IsPositionPlayable(const int& player_id, const char& pos);
		bool IsEndOneSide(const char& User, const char& other);
		int AllMoveOperation(const int& PlayerID);
		bool AnyMoveMore();
		bool GameManager();
		void MovePlayer(const int&, const char&);
		char MoveComputer();
		void NewGame();
		void SetStartPlayer();

	private:
		Cell** gameCells;
		int BoardRow = 5;
		int BoardColumn = 5;
		char GameMode = 'S';
		int WhoIsWillPlay = 1;
		int CurrentElementCounter = 0;// 4 lü yapmaya ne kadar yakýn olduðunu tutan bir  deðiþken 
		bool isEnded = false;
		int GameID = 0;

	};
}
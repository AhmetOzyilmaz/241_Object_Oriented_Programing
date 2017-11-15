#ifndef CONNECTFOURABSTRACT_H
#define CONNECTFOURABSTRACT_H
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
		virtual void Play();
		void LoadFileNew(const string& filename, const int useles) ;
		void LoadFile(const string& filename);
		void SaveFile(const string& filename);
		void PrintBoard();
		inline void setColumn(const int size) { BoardColumn = size; }
		inline const int getColumn() { return BoardColumn; }
		inline void setRow(const int size) { BoardRow = size; }
		inline const int getRow() { return BoardRow; }
		inline void SetWhoIsWillPlay(int who) { WhoIsWillPlay = who; }
		inline int GetWhoIsWillPlay() const { return WhoIsWillPlay; }
		inline void setGameisEnded(const bool end) { isEnded = end; }
		inline const bool getGameisEnded() { return isEnded; }
		inline void setGameID(const int id) { GameID = id; }
		inline int getGameID() const { return GameID; }
		inline void setCurrentElementCounter(const int count) { CurrentElementCounter = count; }
		inline const int getCurrentElementCounter() { return CurrentElementCounter; }
		inline void setMode(const char mode) { GameMode = mode; }
		inline const char GetGameMode() { return GameMode; }
		inline Cell getCell(const int& row, const int& column) { return gameCells[row][column]; }
		inline void SetGameBoard(const int& row, const int& column, const char& value) { gameCells[row][column].SetCellValue(value); }

		void SetGameBoard(Cell c) {
			int row = c.GetPosRow();
			int column = c.GetPosColumn();
			gameCells[row][column] = c;
		}
		void playGame();
		void InitialBoard();
		bool MakeMove(const int& PlayerID);
		bool IsEnd();
		virtual bool IsEndOneSide(const char& User, const char& other) = 0;
		string PartnerCheck(const int direction, const int& posX, const int& posY, const char& comparator, const char& othercomparator, const int& WinCounter, const bool& flag = false);
		void ParseFirstLine(const string& line, int& mode, int& row, int& column, int& play);
		void ReSizeGameBoard(const int& row, const int& column);
		void InitialBoard(const int& row, const int& column);

		bool MoveInputCheck(char command);
		char TakeMove(const int& PlayerID);
		bool CommandSelector(const string& command);
		int CheckCounter(const int& CurComp, int count, int row, int column);
		bool PlayIsPlayeable(const int& direction, bool isPlayeable, const NeigborEnemy& MaxEnem, int row, int column);
		bool IsPositionPlayable(const int& player_id, const char& pos);
		bool AnyMoveMore();
		void MovePlayer(const int&, const char&);
		char MoveComputer();
		void NewGame();
		void SetStartPlayer();

		bool PlayMove();
		bool PlayMove(char move, const int& PlayerID);
		int OneCounter(const string& s1); // change it
	
	private:
		Cell** gameCells;
		int BoardRow = 5;
		int BoardColumn = 5;
		char GameMode = ' ';
		int WhoIsWillPlay = 1;
		int CurrentElementCounter = 0;// 4 lü yapmaya ne kadar yakýn olduðunu tutan bir  deðiþken 
		bool isEnded = false;
		int GameID = 0;

	};
}

#endif

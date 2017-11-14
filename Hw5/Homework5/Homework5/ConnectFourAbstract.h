#include "Cell.h"

namespace Ozyilmaz_Ahmet_111044014 {
	class ConnectFourAbstract {

	public:
		ConnectFourAbstract();
		~ConnectFourAbstract();
		void LoadFileNew(const string& filename, const int useles) ;
		void LoadFile(const string& filename);
		void SaveFile(const string& filename);

		virtual void PrintBoard() = 0;
		virtual void PlayMove(char move, const int& PlayerID) = 0;
		virtual void PlayMove() = 0;
		virtual void IsEnd() = 0;
		virtual void playGame() = 0;

	private:

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
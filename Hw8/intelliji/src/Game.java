import javax.swing.*;

public class Game {
    private Integer height = 8;//default;
    private Integer width = 8;//default;

    private Integer mode = 2;// PLAYER VS COMPUTER;

    private ConnectFour game;

    Game(int _w , int _h , int _m){
        height = _h;
        width  = _w;
        mode = _m;

        game = new ConnectFour(height,width,mode);
    }
    //if game is ended return true else return false
    public boolean Play(int move,int PlayerID,int ForComputerMove){

        System.out.println(PlayerID);
        if(game.getGameisEnded() == true){
            System.out.println("GAME IS ENDED");
            return true;

        }

        if(mode == 0){

            game.PlayMove(PlayerID ,move);
        }else if(mode == 1)
        {


        }
        game.PrintGameBoard();

        int check = game.IsGameOver();
        if (check == -1) {
            game.setGameisEnded(true);
            return true;
        }
    /*    //if(PlayerID)
        if(PlayerID == 3){
            //Play computer
            ForComputerMove = game.PlayMove();
        }
        else
            game.PlayMove(PlayerID ,move);
        game.PrintGameBoard();


*/
        return false;
    }



}

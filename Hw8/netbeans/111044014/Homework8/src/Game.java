import javax.swing.*;

public class Game {
    private Integer height = 8;//default;
    private Integer width = 8;//default;

    private Integer mode = 2;// PLAYER VS COMPUTER;

    private ConnectFour game;
    private int ComputerMove = 0;
    Game(int _w , int _h , int _m){
        height = _h;
        width  = _w;
        mode = _m;

        game = new ConnectFour(height,width,mode);
    }
    public int getComputerMove(){return ComputerMove;}
    //if game is ended return true else return false
    public boolean Play(int move,int PlayerID){

        System.out.println(PlayerID);
        if(game.getGameisEnded() == true){
            System.out.println("GAME IS ENDED");
            return true;
        }
        if(mode == 0){
            game.PlayerMove(PlayerID ,move);
        }
        else if(mode == 1)
        {
            game.PlayerMove(PlayerID ,move);
            ComputerMove = game.ComputerMove();

        }
        int check = game.IsGameOver();
        if (check == -1) {
            game.setGameisEnded(true);
            return true;
        }
        game.PrintGameBoard();

        return false;
    }



}

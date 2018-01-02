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
    public boolean Play(int move,int PlayerID){

        if(game.getGameisEnded() == true){
            System.out.println("GAME IS ENDED");
            return true;

        }
        //if(PlayerID)
        if(PlayerID == 3){
            //Play computer
            game.PlayMove();
        }
        else
            game.PlayMove(PlayerID ,move);
        game.PrintGameBoard();

        int check = game.IsGameOver();
        System.out.println("GAME CHECK" + check);
        if (check == -1) {
            game.setGameisEnded(true);
            return true;
        }

        return false;
    }



}

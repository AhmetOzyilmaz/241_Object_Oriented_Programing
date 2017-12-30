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
    public void LoadGameBoard(){

    }



}

import javafx.application.Application;

import javax.swing.*;
import javax.swing.border.LineBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Main {
    final static String[] gameMode = {"PLAYER VS PLAYER", "PLAYER VS COMPUTER"};
    String SizeText =" X ";
    String[] sizeOption ;

    private JFrame frame = new JFrame("connect four");
    private JLabel[][] slots;
    private JButton[] buttons;
    private int xSize = 8;//
    private int ySize = 7;

    public Main(String[] text) {
        sizeOption = text;
        final JPanel SelectPanel = new JPanel();
        final JPanel gamePanel = new JPanel();

        JLabel pVSc = new JLabel("PLAYER VS COMPUTER:");
        JLabel pVSp = new JLabel("PLAYER VS PLAYER:");
        JButton start = new JButton( "START GAME");

        SelectPanel.setVisible(true);
        SelectPanel.setBackground(Color.blue);

        JComboBox gOptions = new JComboBox(gameMode);
        JComboBox size = new JComboBox(sizeOption);
        SelectPanel.add(pVSc);
        SelectPanel.add(size);
        SelectPanel.add(pVSp);
        SelectPanel.add(gOptions);
        start.setBackground(Color.yellow);
        start.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent event)
            {
                System.out.println("GAME " +  size.getSelectedIndex() +" game mode " + gOptions.getSelectedIndex());
                System.out.println("GAME " +  size.getSelectedItem() +" game mode " + gOptions.getSelectedItem());
                xSize = (size.getSelectedIndex() +5 );
                ySize = (size.getSelectedIndex() +5) ;

                Game game= new Game(xSize,ySize, gOptions.getSelectedIndex() );
                gamePanel.setBackground(Color.red);
                gamePanel.setLayout(new GridLayout(xSize+1, ySize+1));
                slots = new JLabel[xSize][ySize];
                buttons = new JButton[xSize];
                final boolean[] flag = {false};
                final boolean[] control = {false};

                for (int i = 0; i < xSize; i++) {
                    final int b= i;
                    buttons[i] = new JButton("" + (i + 1));
                    buttons[i].setActionCommand("" + i);
                    buttons[i].addActionListener( new ActionListener() {
                        public void actionPerformed(ActionEvent e) {
                            System.out.println("gOptions.getSelectedIndex()" +gOptions.getSelectedIndex());
                            int playerId = 0;
                            String print = "X";

                            if(true == flag[0] &&  gOptions.getSelectedIndex() == 0){
                                flag[0] = false;
                                print="O";
                                playerId = 1;
                            }
                            else if (false == flag[0]){
                                flag[0] = true;
                                print="X";
                                playerId = 0;
                            }
                            if(false == control[0] && playerId != 2){
                                for(int j = ySize-1; j >=0 ; --j) {
                                    if (slots[b][j].getText() == "") {
                                        slots[b][j].setText(print );
                                        control[0] = game.Play(b,playerId);
                                        System.out.println("game.getComputerMove()-->" + game.getComputerMove());
                                        for(int i =  xSize-1; i >=0; -- i ){
                                            if (gOptions.getSelectedIndex()== 1 && slots[game.getComputerMove()][i].getText() == "") {
                                                slots[game.getComputerMove()][i].setText("O" );
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                }
                            }
                            if(control[0] == true){
                                System.out.println("GAME IS ENDED");
                                start.setVisible(true);
                                SelectPanel.setVisible(true);
                                gamePanel.setVisible(false);
                                gamePanel.removeAll();
                            }
                        }

                    });
                    gamePanel.add(buttons[i]);
                }
                for (int column = 0; column < ySize; column++) {
                    for (int row = 0; row < xSize; row++) {
                        slots[row][column] = new JLabel();
                        slots[row][column].setHorizontalAlignment(SwingConstants.CENTER);
                        slots[row][column].setBorder(new LineBorder(Color.black));
                        gamePanel.add(slots[row][column]);
                    }
                }
                 start.setVisible(false);
                 SelectPanel.setVisible(false);
                 gamePanel.setVisible(true);
            }
        });
        frame.add(start,BorderLayout.SOUTH);
        frame.add(SelectPanel, BorderLayout.NORTH);
        frame.add(gamePanel, BorderLayout.CENTER);
        frame.setSize(1080, 720);
        frame.setVisible(true);
        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
       public static void main(String[] args) {
           String text[] = new String[80];
           for (int i = 5; i <85 ; i++) {
               text[i-5]= Integer.toString(i)+ " X "+ Integer.toString(i);
           }
           Main Gui = new Main(text);

       }
}
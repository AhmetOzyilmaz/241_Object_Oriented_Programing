import javafx.application.Application;

import javax.swing.*;
import javax.swing.border.LineBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Main {
    final static String[] gameMode = {"PLAYER VS PLAYER", "PLAYER VS COMPUTER"};
    final static String[] sizeOption = {"5 X 5","6 X 6","7 X 7","8 X 8","9 X 9","10 X 10","11 X 11"};

    private JFrame frame = new JFrame("connect four");

    private JLabel[][] slots;
    private JButton[] buttons;

    private int xsize = 8;//
    private int ysize = 7;


    public Main() {


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
                xsize = (size.getSelectedIndex() + 5 );
                ysize = (size.getSelectedIndex() + 5 ) ;

                Game game= new Game(xsize,ysize, gOptions.getSelectedIndex() + 1);

                gamePanel.setBackground(Color.red);

                gamePanel.setLayout(new GridLayout(xsize+1, ysize+1));
                slots = new JLabel[xsize][ysize];
                buttons = new JButton[xsize];
                final boolean[] flag = {false};

                for (int i = 0; i < xsize; i++) {
                    final int b= i;
                    buttons[i] = new JButton("" + (i + 1));
                    buttons[i].setActionCommand("" + i);
                    buttons[i].addActionListener( new ActionListener() {
                        public void actionPerformed(ActionEvent e) {
                            boolean control= false;
                            String print = "";
                            int CurrentPlayerID = 0;
                            //Player vs Player
                            if(gOptions.getSelectedIndex() == 0){
                                if(true == flag[0])
                                    CurrentPlayerID = 2;
                                else
                                    CurrentPlayerID = 1;
                            }
                            else{//else Playet vs computer
                                if(true == flag[0])
                                    CurrentPlayerID = 3;
                                else
                                    CurrentPlayerID = 1;
                            }
                            if(true == flag[0]){
                                print = "O ";
                                flag[0] = false;
                            }
                            else{
                                print = "X ";
                                flag[0] = true;
                            }
                            boolean endOfGame =false;
                            for(int j = ysize-1; j >=0 ; --j){
                                if( slots[b][j].getText() == ""){
                                    slots[b][j].setText(print+j);
                                    if(flag[0]){
                                        control= game.Play(b,CurrentPlayerID);
                                    }
                                    else{
                                        control = game.Play(b,CurrentPlayerID);
                                    }
                                    break;
                                }
                            }
                            if(control == true){
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
                for (int column = 0; column < ysize; column++) {
                    for (int row = 0; row < xsize; row++) {
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
        Main Gui = new Main();
    }
}
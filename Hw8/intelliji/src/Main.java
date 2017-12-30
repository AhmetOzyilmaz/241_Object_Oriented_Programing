
import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;
import java.awt.event.*;

public class Main {
    final static String[] gameMode = {"PLAYER VS PLAYER", "PLAYER VS COMPUTER"};
    final static String[] sizeOption = {"2 X 2","3 X 3","4 X 4","6 X 6","10 X 10","11 X 11","20 X 20"};

    private JFrame frame = new JFrame("connect four");

    private JLabel[][] slots;
    private JButton[] buttons;
    //variables used in grid
    private int xsize = 8;//
    private int ysize = 7;
    private int currentPlayer = 1;

    //game variables to communicate with top program
    private boolean hasWon = false;
    private boolean hasDraw = false;
    private boolean quit = false;
    private boolean newGame = false;

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
                //Game game= new Game(size.getSelectedIndex(),gOptions.getSelectedIndex());
                //System.out.println("SİZE " +  size.getSelectedIndex() +" game mode " + gOptions.getSelectedIndex());
               // System.out.println("SİZE " +  size.getSelectedItem() +" game mode " + gOptions.getSelectedItem());

                //JPanel panel = (JPanel) frame.getContentPane();
                gamePanel.setBackground(Color.red);

                gamePanel.setLayout(new GridLayout(xsize+1, ysize+1));
                slots = new JLabel[xsize][ysize];
                buttons = new JButton[xsize];

                for (int i = 0; i < xsize; i++) {
                    final int b= i;
                    buttons[i] = new JButton("" + (i + 1));
                    buttons[i].setActionCommand("" + i);
                    buttons[i].addActionListener( new ActionListener() {
                                public void actionPerformed(ActionEvent e) {
                                    System.out.println("CLİCKED");
                                    System.out.println(slots[2][2].getText());
                                        for (int y = ysize-1; y >=0 ;--y ) {
                                            if( slots[b][y].getText().isEmpty() == true ){
                                                slots[b][y].setText("X");
                                                break;
                                            }
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
        frame.setVisible(true);
        frame.setSize(1080, 720);
        frame.setVisible(true);
        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

       public static void main(String[] args) {
        Main Gui = new Main();
    }
}
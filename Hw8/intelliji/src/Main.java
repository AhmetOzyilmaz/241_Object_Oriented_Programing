//Imports are listed in full to show what's being used
//could just import javax.swing.* and java.awt.* etc..
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JComboBox;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JList;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class Main {
    final static String[] gameMode = {"PLAYER VS PLAYER", "PLAYER VS COMPUTER"};
    final static String[] sizeOption = {"2 X 2","3 X 3","4 X 4","6 X 6","10 X 10","11 X 11","20 X 20"};

    //Note: Typically the main method will be in a
    //separate class. As this is a simple one class
    //example it's all in the one class.
    public static void main(String[] args) {

        new Main();
    }

    public Main()
    {
        JFrame guiFrame = new JFrame();
        final JPanel SelectPanel = new JPanel();
        final JPanel gamePanel = new JPanel();
        JLabel comboLbl = new JLabel("PLAYER VS PLAYER:");
        JButton start = new JButton( "START GAME");
        JLabel listLbl = new JLabel("PLAYER VS COMPUTER:");
        guiFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        guiFrame.setTitle("AHMET ÖZYILMAZ  Connect Four ");
        guiFrame.setSize(1080,720);
        guiFrame.setLocationRelativeTo(null);

        SelectPanel.setVisible(true);
        SelectPanel.setBackground(Color.blue);

        JComboBox gOptions = new JComboBox(gameMode);
        JComboBox size = new JComboBox(sizeOption);

        SelectPanel.add(listLbl);
        SelectPanel.add(size);

        SelectPanel.add(comboLbl);
        SelectPanel.add(gOptions);

        start.setBackground(Color.yellow);
        start.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent event)
            {
                gamePanel.setVisible(true);
                gamePanel.setBackground(Color.red);
                Game game= new Game(size.getSelectedIndex(),gOptions.getSelectedIndex());
                System.out.println("SİZE " +  size.getSelectedIndex() +" game mode " + gOptions.getSelectedIndex());
                System.out.println("SİZE " +  size.getSelectedItem() +" game mode " + gOptions.getSelectedItem());

                start.setVisible(false);
                SelectPanel.setVisible(false);
            }
        });
        guiFrame.add(start,BorderLayout.SOUTH);
        guiFrame.add(SelectPanel, BorderLayout.NORTH);
        guiFrame.add(gamePanel, BorderLayout.CENTER);
        guiFrame.setVisible(true);
    }

}
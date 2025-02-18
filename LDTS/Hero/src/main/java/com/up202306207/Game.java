package com.up202306207;

import com.googlecode.lanterna.TerminalSize;
import com.googlecode.lanterna.TextCharacter;
import com.googlecode.lanterna.input.KeyStroke;
import com.googlecode.lanterna.input.KeyType;
import com.googlecode.lanterna.screen.Screen;
import com.googlecode.lanterna.screen.TerminalScreen;
import com.googlecode.lanterna.terminal.DefaultTerminalFactory;
import com.googlecode.lanterna.terminal.Terminal;
import com.googlecode.lanterna.terminal.swing.SwingTerminalFontConfiguration;

import java.awt.*;
import java.io.IOException;

public class Game {
    static final int ASPECT_SCALING = 4;
    static final int WIDTH = 16 * ASPECT_SCALING;
    static final int HEIGHT = 5 * ASPECT_SCALING;
    private Player player;
    private Screen screen;
    private MainMenu mainMenu;
    private boolean playing = true;

    Game() throws IOException {
        double height = Toolkit.getDefaultToolkit().getScreenSize().getHeight();
        int fontSize = (int) (height * 0.8 / HEIGHT);

        System.out.println(fontSize);

        Terminal terminal = new DefaultTerminalFactory()
                .setInitialTerminalSize(new TerminalSize(WIDTH, HEIGHT))
                .setTerminalEmulatorFontConfiguration(
                        SwingTerminalFontConfiguration.getDefaultOfSize(fontSize)
                )
                .createTerminal();
        this.screen = new TerminalScreen(terminal);
        this.screen.setCursorPosition(null);
        this.screen.startScreen();
        this.screen.doResizeIfNecessary();
        this.mainMenu = new MainMenu();
        this.player = new Player(10,10);
    }

    private void processKey(KeyStroke key) {
        if (key.getCharacter() != null && key.getCharacter() == 'q' || key.getKeyType() == KeyType.EOF) {
            playing = false;
            return;
        }
        switch (key.getKeyType()) {
            case ArrowUp:
                player.moveUp();
                break;
            case ArrowDown:
                player.moveDown();
                break;
            case ArrowLeft:
                player.moveLeft();
                break;
            case ArrowRight:
                player.moveRight();
                break;
        }
    }

    private void draw() throws IOException{
        screen.clear();
        player.draw(screen);
        screen.refresh();
    }

    public void run() throws Exception{
        boolean playSelected = mainMenu.runMenu(screen);

        if (playSelected) {
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            while (playing) {
                draw();
                KeyStroke key = screen.readInput();
                processKey(key);
            }
        }

        screen.close();
    }
}

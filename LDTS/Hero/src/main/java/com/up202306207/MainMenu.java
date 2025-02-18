package com.up202306207;

import com.googlecode.lanterna.TerminalPosition;
import com.googlecode.lanterna.TerminalSize;
import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.input.KeyStroke;
import com.googlecode.lanterna.screen.Screen;
import java.io.File;  // Import the File class
import java.io.FileNotFoundException;  // Import this class to handle errors
import java.util.Scanner; // Import the Scanner class to read text files

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

public class MainMenu {
    private static final String[] options = {"Play", "Settings", "Quit"};
    private static int selectedOption = 0;

    public boolean runMenu(Screen screen) throws Exception {
        boolean menuRunning = true;
        SettingsMenu settingsMenu = new SettingsMenu();

        while (menuRunning) {
            drawMenu(screen);

            KeyStroke keyStroke = screen.readInput();
            if (keyStroke != null) {
                switch (keyStroke.getKeyType()) {
                    case ArrowUp -> selectedOption = (selectedOption - 1 + options.length) % options.length;
                    case ArrowDown -> selectedOption = (selectedOption + 1) % options.length;
                    case Enter -> menuRunning = selectOption(screen, settingsMenu);
                    case Escape -> menuRunning = false;
                }
            }
        }
        return selectedOption == 0;
    }

    public void drawMenu(Screen screen) throws Exception {
        screen.clear();
        int centerX = screen.getTerminalSize().getColumns() / 2;
        int centerY = screen.getTerminalSize().getRows() / 2;

        drawTitle(screen,centerX,centerY);

        for (int i = 0; i < options.length; i++) {
            String option = options[i];
            if (i == selectedOption) {
                screen.newTextGraphics().setForegroundColor(TextColor.ANSI.YELLOW).putString((centerX - option.length() / 2) - 2, centerY + i, "> " + option + " <");
            } else {
                screen.newTextGraphics().setForegroundColor(TextColor.ANSI.WHITE).putString(centerX - option.length() / 2, centerY + i, option);
            }
        }
        screen.refresh();
    }

    private void drawTitle(Screen screen,int centerX,int centerY) {
        try{
            int i = 0;
            File myFile = new File("src\\main\\resources\\MainTittle.txt");
            Scanner myReader = new Scanner(myFile);
            while(myReader.hasNextLine()){
                String line = myReader.nextLine();
                screen.newTextGraphics().putString(centerX - 20, centerY - 8 + i++, line);
            }
        }
        catch (FileNotFoundException e){
            System.out.println("an error occurred");
            e.printStackTrace();
        }
    }

    private boolean selectOption(Screen screen, SettingsMenu settingsMenu) throws Exception{
        switch (selectedOption) {
            case 0 -> {
                System.out.println("Starting Game...");
                return false;
            }
            case 1 -> {
                System.out.println("Opening Settings...");
                settingsMenu.runSettingsMenu(screen);
            }

            case 2 -> {
                System.out.println("Closing game...");
                return false;
            }
        }
        return true;
    }
}


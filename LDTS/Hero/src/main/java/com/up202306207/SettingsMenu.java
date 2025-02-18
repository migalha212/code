package com.up202306207;

import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.input.KeyStroke;
import com.googlecode.lanterna.input.KeyType;
import com.googlecode.lanterna.screen.Screen;

public class SettingsMenu {
    private static final String[] settingsOptions = {"Arrow Up", "Arrow Down", "Arrow Left", "Arrow Right", "Back"};
    private static int selectedSetting = 0;
    private KeyType arrowUpKey = KeyType.ArrowUp;
    private KeyType arrowDownKey = KeyType.ArrowDown;
    private KeyType arrowRightKey = KeyType.ArrowRight;
    private KeyType arrowLeftKey = KeyType.ArrowLeft;

    public void runSettingsMenu(Screen screen) throws Exception {
        boolean inSettings = true;

        while (inSettings) {
            drawSettingsMenu(screen);
            KeyStroke keyStroke = screen.readInput();
            if (keyStroke != null) {
                switch (keyStroke.getKeyType()) {
                    case ArrowUp -> selectedSetting = (selectedSetting - 1 + settingsOptions.length) % settingsOptions.length;
                    case ArrowDown -> selectedSetting = (selectedSetting + 1) % settingsOptions.length;
                    case Enter -> inSettings = handleSettingsSelection(screen);
                }
            }
        }
    }

    private void drawSettingsMenu(Screen screen) throws Exception {
        screen.clear();
        int centerX = screen.getTerminalSize().getColumns() / 2;
        int centerY = screen.getTerminalSize().getRows() / 2;

        String title = "Settings";
        screen.newTextGraphics().putString(centerX - title.length() / 2, centerY - 4, title);

        for (int i = 0; i < settingsOptions.length; i++) {
            String option = settingsOptions[i];
            if (i == selectedSetting) {
                screen.newTextGraphics().setForegroundColor(TextColor.ANSI.YELLOW).putString(centerX - option.length() / 2 - 2, centerY + i, "> " + option + " <");
            } else {
                screen.newTextGraphics().setForegroundColor(TextColor.ANSI.WHITE).putString(centerX - option.length() / 2, centerY + i, option);
            }
        }
        screen.refresh();
    }

    private boolean handleSettingsSelection(Screen screen) throws Exception {
        switch (selectedSetting) {
            case 0 -> configureKey(screen, "Arrow Up", (keyType) -> arrowUpKey = keyType);
            case 1 -> configureKey(screen, "Arrow Down", (keyType) -> arrowDownKey = keyType);
            case 2 -> configureKey(screen, "Arrow Left", (keyType) -> arrowLeftKey = keyType);
            case 3 -> configureKey(screen, "Arrow Right", (keyType) -> arrowRightKey = keyType);
            case 4 -> {
                System.out.println("Back to Main Menu...");
                return false;
            }
        }
        return true;
    }

    private void configureKey(Screen screen, String action, java.util.function.Consumer<KeyType> keyConsumer) throws Exception {
        screen.clear();
        int centerX = screen.getTerminalSize().getColumns() / 2;
        int centerY = screen.getTerminalSize().getRows() / 2;
        screen.newTextGraphics().putString(centerX - (action.length() + 19)/ 2, centerY, "Press a key for " + action + "...");
        screen.refresh();

        KeyStroke keyStroke = screen.readInput();
        if (keyStroke != null) {
            keyConsumer.accept(keyStroke.getKeyType());
            System.out.println(action + " key set to: " + keyStroke.getKeyType());
        }
    }
}

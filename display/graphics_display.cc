#include "graphics_display.h"


GraphicsDisplay::GraphicsDisplay(int rowNum, int colNum, int cellSize) : rowNum{rowNum}, colNum{colNum}, cellSize{cellSize}, theWindow{2 * colNum * cellSize + 100, rowNum * cellSize + 300} {
    theWindow.drawString(25, 25, "Player 1");
    theWindow.drawString(colNum * cellSize + 75, 25, "Player 2");
    theWindow.drawString(25, 50, "Level: ");
    theWindow.drawString(colNum * cellSize + 75, 50, "Level: ");
    theWindow.drawString(25, 75, "Score: ");
    theWindow.drawString(colNum * cellSize + 75, 75, "Score: ");
    theWindow.drawString(25, 100, "Highest Score: ");
    theWindow.drawString(colNum * cellSize + 75, 100, "Highest Score: ");
    
    theWindow.fillRectangle(24, 124, colNum * cellSize + 2, 1);
    theWindow.fillRectangle(24, 124, 1, rowNum * cellSize + 2);
    theWindow.fillRectangle(colNum * cellSize + 25, 124, 1, rowNum * cellSize + 2);
    theWindow.fillRectangle(24, rowNum * cellSize + 125, colNum * cellSize + 2, 1);
    
    theWindow.fillRectangle(colNum * cellSize + 74, 124, colNum * cellSize + 2, 1);
    theWindow.fillRectangle(colNum * cellSize + 74, 124, 1, rowNum * cellSize + 2);
    theWindow.fillRectangle(2 * colNum * cellSize + 75, 124, 1, rowNum * cellSize + 2);
    theWindow.fillRectangle(colNum * cellSize + 74, rowNum * cellSize + 125, colNum * cellSize + 2, 1);
    
    theWindow.drawString(25, rowNum * cellSize + 150, "Next: ");
    theWindow.drawString(colNum * cellSize + 75, rowNum * cellSize + 150, "Next: ");
}

void GraphicsDisplay::fillCell(int x, int y, std::string color) {
    theWindow.fillRectangle(x, y, cellSize, cellSize);
    if (color == "") {
        theWindow.fillRectangle(x, y, cellSize, cellSize, Xwindow::White);
    }
    else if (color == "J") {
        theWindow.fillRectangle(x, y, cellSize, cellSize, Xwindow::Black);
    }
    else if (color == "L") {
        theWindow.fillRectangle(x + 1, y + 1, cellSize - 2, cellSize - 2, Xwindow::Red);
    }
    else if (color == "O") {
        theWindow.fillRectangle(x + 1, y + 1, cellSize - 2, cellSize - 2, Xwindow::Green);
    }
    else if (color == "S") {
        theWindow.fillRectangle(x + 1, y + 1, cellSize - 2, cellSize - 2, Xwindow::Blue);
    }
    else if (color == "T") {
        theWindow.fillRectangle(x + 1, y + 1, cellSize - 2, cellSize - 2, Xwindow::Aquamarine);
    }
    else if (color == "Z") {
        theWindow.fillRectangle(x + 1, y + 1, cellSize - 2, cellSize - 2, Xwindow::Bisque);
    }
    else if (color == "*") {
        theWindow.fillRectangle(x + 1, y + 1, cellSize - 2, cellSize - 2, Xwindow::Coral);
    }
    else if (color == "pink") {
        theWindow.fillRectangle(x + 1, y + 1, cellSize - 2, cellSize - 2, Xwindow::Pink);
    }
    else if (color == "aqua") {
        theWindow.fillRectangle(x + 1, y + 1, cellSize - 2, cellSize - 2, Xwindow::Aqua);
    }
    else if (color == "teal") {
        theWindow.fillRectangle(x + 1, y + 1, cellSize - 2, cellSize - 2, Xwindow::Teal);
    }
    else {
        theWindow.fillRectangle(x + 1, y + 1, cellSize - 2, cellSize - 2, Xwindow::Firebrick);
    }
}

void GraphicsDisplay::setColor(int xPos, int yPos, std::string color, int player) {
    int x, y;
    if (player == 0) {
        x = xPos * cellSize + 25;
    }
    else {
        x = colNum * cellSize + xPos * cellSize + 75;
    }
    y = yPos * cellSize + 125;
    GraphicsDisplay::fillCell(x, y, color);
}

void GraphicsDisplay::setLevel(int level, int player) {
    std::string s = std::to_string(level);
    if (player == 0) {
        theWindow.drawString(50, 50, s);
    }
    else {
        theWindow.drawString(colNum * cellSize + 100, 50, s);
    }
}

void GraphicsDisplay::setCurrentScore(int score, int player) {
    std::string s = std::to_string(score);
    if (player == 0) {
        theWindow.drawString(50, 75, s);
    }
    else {
        theWindow.drawString(colNum * cellSize + 100, 75, s);
    }
}

void GraphicsDisplay::setHighestScore(int score) {
    std::string s = std::to_string(score);
    theWindow.drawString(60, 100, "Highest Score: ");
    theWindow.drawString(colNum * cellSize + 110, 100, "Highest Score: ");
}

void GraphicsDisplay::setNext(int xPos, int yPos, std::string color, int player) {
    int x, y;
    if (player == 0) {
        x = xPos * cellSize + 25;
    }
    else {
        x = colNum * cellSize + xPos * cellSize + 75;
    }
    y = rowNum * cellSize + yPos * cellSize + 175;
    GraphicsDisplay::fillCell(x, y, color);
}

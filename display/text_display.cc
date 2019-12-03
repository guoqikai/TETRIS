#include "text_display.h"

TextDisplay::TextDisplay(int rowNum, int colNum) : rowNum{rowNum}, colNum{colNum} {
    players = "Player 1          Player 2";
    levels = "Level:            Level:  ";
    scores = "Score:            Score:         ";
    highestScores = "Highest:          Highest:       ";
    boundary = "-----------       -----------";
    next = "Next:             Next:";
    
    theDisplay = std::vector<std::vector<char>>();
    for (int r = 0; r < rowNum; r++) {
        std::vector<char> row{};
        for (int c = 0; c < colNum; c++) {
            row.emplace_back(' ');
        }
        theDisplay.emplace_back(row);
    }
    
    theNext = std::vector<std::vector<char>>();
    for (int r = 0; r < 4; r ++) {
        std::vector<char> row{};
        for (int c = 0; c < 4; c ++) {
            row.emplace_back(' ');
        }
        theDisplay.emplace_back(row);
    }
}

void TextDisplay::fillCell(int x, int y, std::string color) {
    if (color == "") {
         theDisplay[x][y] = ' ';
    }
    else {
        theDisplay[x][y] = color[0];
    }
}
    
void TextDisplay::setColor(int xPos, int yPos, std::string color, int player) {
    int x, y;
    if (player == 0) {
        x = xPos;
    }
    else {
        x = xPos + 18;
    }
    y = yPos;
    TextDisplay::fillCell(x, y, color);
}
    
void TextDisplay::setLevel(int level, int player) {
    std::string s = std::to_string(level);
    if (player == 0) {
        levels.replace(7, 1, s);
    }
    else {
        levels.replace(26, 1, s);
    }
}
    
void TextDisplay::setCurrentScore(int score, int player) {
    std::string s = std::to_string(score);
    if (player == 0) {
        scores.replace(7, s.length(), s);
    }
    else {
        scores.replace(26, s.length(), s);
    }
}
    
void TextDisplay::setHighestScore(int score) {
    std::string s = std::to_string(score);
    highestScores.replace(9, s.length(), s);
    highestScores.replace(27, s.length(), s);
}
    
void TextDisplay::setNext(int xPos, int yPos, std::string color, int player) {
    int x, y;
    if (player == 0) {
        x = xPos;
    }
    else {
        x = xPos + 18;
    }
    y = yPos;
    TextDisplay::fillCell(x, y, color);
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td) {
    out << td.players << std::endl;
    out << td.levels << std::endl;
    out << td.scores << std::endl;
    out << td.highestScores << std::endl;
    out << td.boundary << std::endl;
    for (int r = 0; r < td.rowNum; r++) {
        for (int c = 0; c < td.colNum; c++) {
            out << td.theDisplay[r][c];
        }
        out << std::endl;
    }
    out << td.boundary << std::endl;
    out << td.next << std::endl;
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            out << td.theDisplay[r][c];
        }
        out << std::endl;
    }
    return out;
}

#ifndef TEXT_DISPLAY_H
#define TEXT_DISPLAY_H
#include <string>
#include <iostream>
#include <vector>
#include "display.h"

// TextDisplay class inheritants from GridDisplay class
class TextDisplay: public Display {
    
    const int rowNum, colNum;
    
    std::string players;
    
    std::string levels;
    
    std::string scores;
    
    std::string highestScores;
    
    std::string next;
    
    std::string boundary;
    
    std::vector<std::vector<char>> theDisplay;
    
    std::vector<std::vector<char>> theNext;
    
    void fillCell(int x, int y, std::string color);
    
public:
    
    TextDisplay(int rowNum = 15, int colNum = 11);
  
    void setColor(int xPos, int yPos, std::string color, int player) override;
    
    void setLevel(int level, int player) override;
    
    void setCurrentScore(int score, int player) override;
    
    void setHighestScore(int score) override;
    
    void setNext(int xPos, int yPos, std::string color, int player) override;
    
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif

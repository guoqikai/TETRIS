#ifndef GRAPHICS_DISPLAY_H
#define GRAPHICS_DISPLAY_H
#include <string>
#include "window.h"
#include "display.h"

// GraphicsDisplay class inheritants from GridDisplay class
class GraphicsDisplay: public Display {
    
    const int rowNum, colNum, cellSize;
    
    Xwindow theWindow;
    
    void GraphicsDisplay::fillCell(int x, int y, std::string color);
    
public:
    
    GraphicsDisplay(int rowNum = 15, int colNum = 11, int cellSize = 25);
  
    void setColor(int xPos, int yPos, std::string color, int player) override;
    
    void setLevel(int level, int player) override;
    
    void setCurrentScore(int score, int player) override;
    
    void setHighestScore(int score) override;
    
    void setNext(int xPos, int yPos, std::string color, int player) override;
};

#endif


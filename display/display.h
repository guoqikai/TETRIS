#ifndef DISPLAY_H
#define DISPLAY_H
#include <string>

struct Display {
    
    virtual void setColor(int xPos, int yPos, std::string color, int player) = 0;
    
    virtual void setLevel(int level, int player) = 0;
    
    virtual void setCurrentScore(int score, int player) = 0;
    
    virtual void setHighestScore(int score) = 0;
    
    virtual void setNext(int xPos, int yPos, std::string color, int player) = 0;
   
    virtual ~Display();
};

#endif


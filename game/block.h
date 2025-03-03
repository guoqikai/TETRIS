#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <memory>
#include <string>

struct Grid;

class Block {
    int shapeIndex = 0;
    int heaviness = 0;
    int lifetime = -1;
    int level = 0;
    int xPos = 0;
    int yPos = 0;
    friend class MovementController;
    friend class BlockConfigurator;
    
protected:
    int getShapeIndex() const;
    
public:
    virtual std::unique_ptr<std::vector<std::vector<bool> > > getShape() const = 0;
    virtual std::string getType() const = 0;
    void rotateCounterClockwise();
    void rotateClockwise();
    int getLevel() const;
    void setLevel(int level);
};

struct IBlock: public Block {
    std::string getType() const override;
    std::vector<std::vector<bool> > getShape() const override;
};

struct JBlock: public Block {
    std::string getType() const override;
    std::vector<std::vector<bool> > getShape() const override;
};

struct LBlock: public Block {
    std::string getType() const override;
    std::vector<std::vector<bool> > getShape() const override;
};

struct OBlock: public Block {
    std::string getType() const override;
    std::vector<std::vector<bool> > getShape() const override;
};

struct SBlock: public Block {
    std::string getType() const override;
    std::vector<std::vector<bool> > getShape() const override;
};

struct TBlock: public Block {
    std::string getType() const override;
    std::vector<std::vector<bool> > getShape() const override;
};

struct ZBlock: public Block {
    std::string getType() const override;
    std::vector<std::vector<bool> > getShape() const override;
};

struct StarBlock: public Block {
    std::string getType() const override;
    std::vector<std::vector<bool> > getShape() const override;
};

#endif

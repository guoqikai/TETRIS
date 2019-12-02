#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <memory>

struct Grid;

class Block {
    int shapeIndex = 0;
    int heaviness;
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
    void rotateCounterClockwise();
    void rotateClockwise();
    int getLevel() const;
};

struct IBlock: public Block {
    std::vector<std::vector<bool> > getShape() const override;
};

struct JBlock: public Block {
    std::vector<std::vector<bool> > getShape() const override;
};

struct LBlock: public Block {
    std::vector<std::vector<bool> > getShape() const override;
};

struct OBlock: public Block {
    std::vector<std::vector<bool> > getShape() const override;
};

struct SBlock: public Block {
    std::vector<std::vector<bool> > getShape() const override;
};

struct TBlock: public Block {
    std::vector<std::vector<bool> > getShape() const override;
};

struct ZBlock: public Block {
    std::vector<std::vector<bool> > getShape() const override;
};


#endif

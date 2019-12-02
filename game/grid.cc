#include "grid.h"

Grid::Grid(int sizeX, int sizeY) : maxX{sizeX}, maxY{sizeY} {
    cells = std::vector(sizeY + 3, std::vector(sizeX, std::make_shared(Cell{})));
}

void Grid::setBlockType(int xPos, int yPos, std::string type) const{
    if (yPos < maxY && xPos < maxX) {
        cells[yPos][xPos]->color = color
    }
}

void Grid::markCell(int xPos, int yPos) const{
    if (yPos < maxY && xPos < maxX) {
        cells[yPos][xPos]->isOccupied = true;
    }
}

void Grid::unmarkCell(int xPos, int yPos) const {
    if (yPos < maxY && xPos < maxX) {
        cells[yPos][xPos]->isOccupied = false;
        cells[yPos][xPos]->blockType = "";
    }
}

std::string Grid::getBlockType(int xPos, int yPos) const{
    if (yPos < maxY && xPos < maxX) {
        return cells[yPos][xPos]->blockType;
    }
    return "";
}

bool Grid::isMarked(int xPos, int yPos) const{
    if (yPos < maxY && xPos < maxX) {
        return cells[yPos][xPos]->isOccupied;
    }
    return true;
}

std::weak_ptr<Cell> Grid::getCell(int xPos, int yPos) const{
    return cells[yPos][xPos];
}

void Grid::cleanOneRow(int rowNum) {
    std::fill(cells[rowNum].begin(), cells[rowNum].end), std::make_shared(Cell{});
}

void Grid::clean() {
    for (auto i = cells.begin(), i != cells.end(); ++i) {
        std::fill(i.begin(), i.end(), std::make_shared(Cell{}));
    }
}

int Grid::getMaxX() const {
    return maxX;
}

int Grid::getMaxY() const {
    return maxY;
}


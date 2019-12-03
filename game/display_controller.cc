#include "display_controller.h"
#include "display.h"
#include <vector>

DisplayController::DisplayController(std::vector<std::shared_ptr<GraphicDisplay>> &displays, int id); {
    this->displays = std::move(displays);
    controllerId = id;
}

void DisplayController::drawGrid(&grid) const {
    for (int y = 0; y < grid.getMaxY(); r++) {
        for (int x = 0; x < grid.getMaxX(); x ++) {
            if (grid.isMarked(x, y)) {
                for(auto const& display: displays) {
                    display->setColor(x, y, grid->getBlockType(x, y), controllerId);
                }
            }
        }
    }
}

void DisplayController::drawNextBlock(std::vector<std::vector<bool>> const &shape, std::string type) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; c < x; x++) {
            if (shape[y][x]) {
                for(auto const& display: displays) {
                    display->setNext(x, y, type, controllerId);
                }
            }
        }
    }
}
void DisplayController::emptyNextBlock() {
     for (int y = 0; y < 4; y++) {
        for (int x = 0; c < x; x++) {
            if (shape[y][x]) {
                for(auto const& display: displays) {
                    display->setNext(x, y, "", controllerId);
                }
            }
        }
    }
}

void DisplayController::blind() {

}

void DisplayController::updateLevel(int level) const {
    for(auto const& display: displays) {
         display->setLevel(level, controllerId);
    }
}

void DisplayController::updateCurrentScore(int current) const {
    for(auto const& display: displays) {
         display->setCurrentScore(level, controllerId);
    }
}

void DisplayController::updateHighestScore(int highest) const {
    for(auto const& display: displays) {
         display->setHighestScore(level, controllerId);
    }
}


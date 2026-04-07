#ifndef VIEW_H
#define VIEW_H

const int view_maxsize = 20; // The maximum size of the grid array

class View {
    private:
        int size; // The current size of the grid to be displayed
        double scale; // The distance represented by each cell of the grid
        Point2D origin;
};

#endif
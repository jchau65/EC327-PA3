#ifndef VIEW_H
#define VIEW_H

#include "Model.h"

const int view_maxsize = 20; // The maximum size of the grid array

class View {
    private:
        int size; // The current size of the grid to be displayed
        double scale; // The distance represented by each cell of the grid
        Point2D origin; // The coordinates of the lower left-hand corner of the grid
        char grid[view_maxsize][view_maxsize][2]; // An array to hold the characters that make up the display grid
        
        /**
         * Calculates the column and row subscripts of the grid array that correspond to the supplied location.l
         * 
         * The x and y values corresponding to the subscripts can be calculated by (location - origin) / scale.
         * These will be assigned to integers to truncate the fractional part to get the integer subscripts, which are returned in the two reference parameters.
         * 
         * This function returns true if the subscripts are valid, that is within the size of the grid being displayed. 
         * If not, the function prints a message: "An object is outside the display" and returns false.
         */
        bool GetSubscripts(int& out_x, int& out_y, Point2D location);

    public:
        /**
         * Sets the size to 11, scale to 2, and the origin to default (0, 0).
         */
        View();

        /**
         * Sets all the cells of the grid to a background output.
         */
        void Clear();

        /**
         * Plots the pointed-to object in the proper cell of the grid. It calls get_subscripts and if the subscripts are
         * valid, it calls DrawSelf() for the object to insert the appropriate characters in the cell of the grid. However,
         * if there is already an object plotted in that cell of the grid, the characters are replaced with '*' and '' (space)
         * to indicate that there is more than one object in that cell of the grid.
         */
        void Plot(GameObject* ptr);

        /**
         * Outputs the grid array to produce a display. 
         * 
         * The size, scale, and origin are printed first, then each row and column, for the current size of the display.
         * 
         * The x and y values are labelled with values for every alternate column and row.
         * 
         * Allows two characters for each numeric value of the axis labels, with no decimal points, otherwise the axis labels will be out of alignment and rounded off.
         */
        void Draw();
};

#endif
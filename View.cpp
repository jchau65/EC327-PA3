#include "View.h"

bool View::GetSubscripts(int& out_x, int& out_y, Point2D location) {
    Vector2D subscript = (location - origin) / scale;
    out_x = subscript.x;
    out_y = subscript.y;

    if (out_x >= size || out_y >= size || out_x < 0 || out_y < 0) {
        cout << "An object is outside the display" << endl;
        return false;
    }

    return true;
}

View::View() : size(11), scale(2), origin(Point2D(0, 0)) {
    Clear();
}

void View::Clear() {
    // Set every point in the grid to '.' or ' '
    for (int col = 0; col < view_maxsize; col++) {
        for (int row = 0; row < view_maxsize; row++) {
            grid[row][col][0] = '.';
            grid[row][col][1] = ' ';
        }
    }
}

void View::Plot(GameObject* ptr) {
    int sub_x;
    int sub_y;

    if (GetSubscripts(sub_x, sub_y, ptr->GetLocation())) {
        // If there is no object there, draw object
        if (grid[sub_y][sub_x][0] == '.') {
            ptr->DrawSelf(grid[sub_y][sub_x]);
        }

        // If there is an object there, draw '* '
        else {
            grid[sub_y][sub_x][0] = '*';
            grid[sub_y][sub_x][1] = ' ';
        }
    }
}

void View::Draw() {
    for (int row = size - 1; row >= 0; row--) {
        // Print the axis labels on the left side
        if (row % 2 == 0) {
            if (row >= 10) {
                cout << row << " ";
            }
            else {
                cout << row << "  ";
            }
        }
        else {
            cout << "   ";
        }

        // Print the characters
        for (int col = 0; col < size; col++) {
            cout << grid[row][col][0] << grid[row][col][1];
        }

        // Create a new line
        cout << endl;
    }

    // Create horizontal axis labels
    cout << "   ";
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            if (i < 10) {
                cout << i << " ";
            }
            else {
                cout << i << "";
            }
        }

        else {
            cout << "  ";
        }
    }

    // End the last line
    cout << endl;
}
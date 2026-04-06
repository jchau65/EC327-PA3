#include "GameCommand.h" 

int main() {
    // Create a model and an empty view
    Model* model = new Model();
    View* view = new View();

    // Set up input loop
    char input;

    while (input != 'q') {
        HandleCommand(model, view, input);
    }
}
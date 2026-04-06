#include "GameCommand.h" 

int main() {
    // Create a model and an empty view
    Model* model = new Model();
    View* view = new View();

    // Set up input loop
    char input;

    while (input != 'q') {
        cout << "Enter command: ";
        cin >> input;
        HandleCommand(*model, *view, input);
    }
}
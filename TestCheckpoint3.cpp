#include "Mage.h"

using namespace std;

int main() {
    // Default construct mage
    Mage m1 = Mage();
    m1.ShowStatus();

    // Construct mage with code
    Mage m2 = Mage('M');
    m2.ShowStatus();

    // Construct mage with all parameters
    Mage m3 = Mage("Gandalf", 5, 'M', 5, Point2D(0, 0));
    m3.ShowStatus();

    // Test out moving function
    m3.StartMoving(Point2D(5, 5));
    m3.Update();
    m3.ShowStatus();

    // Make another step so Gandalf makes it to destination
    m3.Update();
    m3.ShowStatus();

    // Create a DemonHideout d1
    DemonHideout d1 = DemonHideout();
    cout << "D1's Location: " << d1.GetLocation() << endl;
    
    // Make the mage start moving to d1
    m3.StartMovingToHideout(&d1);
    m3.Update();
    m3.Update();
    m3.ShowStatus();

    // Create a ManaSpire s1
    ManaSpire s1 = ManaSpire(1, 0.01, 100, Point2D(-5, -5));
    cout << "S1's Location: " << s1.GetLocation() << endl;

    // Make the mage start moving to s1
    m3.StartMovingToSpire(&s1);
    m3.Update();
    m3.Update();
    m3.ShowStatus();

    // Start recovering mana
    m3.StartRecoveringMana(100);
    m3.ShowStatus();
    m3.Update();
    m3.ShowStatus();

    // Make the mage start moving to d1
    m3.StartMovingToHideout(&d1);
    m3.Update();
    m3.Update();
    m3.ShowStatus();

    // Make the mage battle in d1
    m3.StartBattling(1);
    m3.Update();
    m3.ShowStatus();
}
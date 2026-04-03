#include "ManaSpire.h"
#include "DemonHideout.h"

using namespace std;

int main() {
    // Default Building
    Building b1 = Building();
    b1.ShowStatus();

    // Parameter Building
    Building b2 = Building('U', 2, Point2D());
    b2.ShowStatus();

    // Add one mage
    b2.AddOneMage();
    b2.ShowStatus();

    // Remove one mage
    b2.RemoveOneMage();
    b2.ShowStatus();

    // Check should be visible function
    cout << b2.ShouldBeVisible() << endl;

    // Default ManaSpire
    ManaSpire m1 = ManaSpire();
    m1.ShowStatus();

    // Parameter ManaSpire
    ManaSpire m2 = ManaSpire(10, 10, 1500, Point2D());
    m2.ShowStatus();

    // Check crystals
    cout << "m2 has crystals: " << m2.HasCrystals() << endl;

    // Get Num Crystals Remaining
    cout << "m2 crystals remaining: " << m2.GetNumCrystalsRemaining() << endl;

    // CanAffordCrsytal() 
    cout << "Can afford crystal: " << m2.CanAffordCrystal(5, 50) << endl;

    // GetCrystalCost()
    cout << "Crystal cost for 10 crystals: " << m2.GetCrystalCost(10) << endl;

    // DistributeCrystals() 
    cout << "crystals distributed: " << m2.DistributeCrystals(1500) << endl;
    cout << "m2 after 1500 crystals distributed: " << m2.GetNumCrystalsRemaining() << endl;

    // Update()
    cout << "m2 update: " << m2.Update() << endl;
    m2.ShowStatus();
    cout << "m2 update 2: " << m2.Update() << endl;

    // Default DemonHideout
    DemonHideout d1 = DemonHideout();
    d1.ShowStatus();

    // Parameter DemonHideout
    DemonHideout d2 = DemonHideout(100, 10, 5, 6, 10, Point2D(3, 5));
    d2.ShowStatus();

    // GetGoldCost()
    cout << "d2 cost for 10 battles: " << d2.GetGoldCost(10) << endl;

    // GetManaCost()
    cout << "d2 mana cost for 10 battles: " << d2.GetManaCost(10) << endl;

    // GetNumBattlesRemaining()
    cout << "d2 num battles remaining: " << d2.GetNumBattlesRemaining() << endl;

    // IsAbleToBattle()
    cout << "d2 able to battle: " << d2.IsAbleToBattle(100000000, 1000, 1000) << endl;

    // DemonBattle()
    cout << "d2 demon battle: " << d2.DemonBattle(1000) << endl;

    // GetExperiencePerBattle()
    cout << "d2 exp per battle: " << d2.GetExperiencePerBattle() << endl;

    // Update()
    cout << "d2 update: " << d2.Update() << endl;
    d2.ShowStatus();
    cout << "d2 update 2: " << d2.Update() << endl;
}
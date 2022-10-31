#include <iostream>
#include <Windows.h>
#include "PokerHand.hpp"

using namespace std;

/*
enum class GAME {
    STRAIGHTFLUSH = 9,
    FOUROFAKIND = 8,
    FULLHOUSE = 7,
    FLUSH = 6,
    STRAIGHT = 5,
    THREEOFKIND = 4,
    TWOPAIR = 3,
    ONEPAIR = 2,
    HIGHCARD = 1
};
*/

int main() {
    SetConsoleOutputCP(CP_UTF8);

    //GAME ONE
    PokerHand a(C3, C4, D6, D7, DA);
    PokerHand b(C2, C5, C7, DQ, DK);
    a.printAll();
    b.printAll();

    if (a < b) {
        cout << "GAME B IS BETTER";
    } else {
        cout << "GAME A IS BETTER";
    }

    cout << (a<b) << endl;

    //GAME TWO
    PokerHand nothing72(C2, C3, C4, C5, D7);
    PokerHand nothing73(D2, D4, D5, D6, C7);
    nothing72.printAll();
    nothing73.printAll();

    if (nothing72 < nothing73) {
        cout << "GAME B IS BETTER";
    } else {
        cout << "GAME A IS BETTER";
    }

    cout << (nothing72<nothing73) << endl;

    //GAME TWO
    PokerHand a2(C3, C4, C7, CJ, DJ);
    PokerHand b2(D2, D5, D7, D10, S10);
    a2.printAll();
    b2.printAll();

    if (a2 < b2) {
        cout << "GAME B IS BETTER";
    } else {
        cout << "GAME A IS BETTER";
    }

    cout << (a2<b2) << endl;

    //GAME THREE
    PokerHand a3(C2, S2, CQ, CK, CA);
    PokerHand b3(C3, H3, H4, H5, S6);
    a3.printAll();
    b3.printAll();

    if (a3 < b3) {
        cout << "GAME B IS BETTER";
    } else {
        cout << "GAME A IS BETTER";
    }
    cout << (a3<b3) << endl;

    //GAME FOUR
    PokerHand a4(C2, CK, HK, H7, S7);
    PokerHand b4(C3, D8, DQ, SQ, C8);
    a4.printAll();
    b4.printAll();

    if (a4 < b4) {
        cout << "GAME B IS BETTER";
    } else {
        cout << "GAME A IS BETTER";
    }
    cout << (a4<b4) << endl;

    //GAME FIVE
    PokerHand a5(CK, C3, H7, HQ, S2);
    PokerHand b5(C6, D8, D3, SA, C9);
    a5.printAll();
    b5.printAll();

    if (a5 < b5) {
        cout << "GAME B IS BETTER";
    } else {
        cout << "GAME A IS BETTER";
    }
    cout << (a5<b5) << endl;

    //GAME FOUR
    PokerHand a6(C6, C4, H5, HQ, S2);
    PokerHand b6(C6, DA, D3, SQ, C8);
    a6.printAll();
    b6.printAll();

    if (a6 < b6) {
        cout << "GAME B IS BETTER";
    } else {
        cout << "GAME A IS BETTER";
    }
    cout << (a6<b6) << endl;

    return 0;
}

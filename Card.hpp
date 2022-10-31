/*
 * File: Card.hpp
 * Author: Rick Mercer and Felipe Lopez
 * Description: Card object with a suit and rank and icons to represent
 *the toString version of a card like 2♣ When sorted, a vector<card> has
 * all cards sorted: K♣ < A♥, A♣ == A♥, 2♥ < 3♣, ...
 * The rank in getValue() is an integer from 2 (DEUCE) through 14 (ACE).
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;

enum class Rank {
    DEUCE = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK = 11,
    QUEEN = 12,
    KING = 13,
    ACE = 14
};

enum class Suit {
    SPADES, HEARTS, DIAMONDS, CLUBS
};

// No enum is greater than another.  Thses are just names of the suits you
// will have to check to see if you have a flush, 5 card with the same suit


class Card {

private:
    // suits have the card icons when printed. These work on Windows and the MAc
    vector<string> suits{"\xe2\x99\xa0", "\xe2\x99\xa5", "\xe2\x99\xa6", "\xe2\x99\xa3"};
    Rank cardRank;
    Suit cardSuit;

public:
    // Construct a Card object
    Card(Rank rank, Suit suit) {
        cardRank = rank;
        cardSuit = suit;
    }

    // Return the RANK as an integer.  A cast is needed necessary
    int getValue() const {
        return static_cast<int>(cardRank);
    }

    // Return the rank of this card object, which is an enum
    Rank getRank() const {
        return cardRank;
    }

    // Return the suit of this card object, which is an enum
    Suit getSuit() const {
        return cardSuit;
    }

    string toString() const {
        return to_string(getValue()) + suits[static_cast<int>(cardSuit)];
    }

    // Overload tne < operator so a vector of cards can be sorted by the getValue method
    bool operator<(const Card &other) const {
        if (this->getValue() < other.getValue()) {
            return true;
        } else {
            return false;
        }
    }
};

//
// Author: Felipe Lopez
//
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include "52Cards.hpp"

// !TODO I HAVE DOUBTS ON HOW THE < OVERLOAD OPERATOR PERFROMS WITH TWO PAIRS AND OTHERS. BECAUSE WHEN I
// CALCULATE THE OCCURANCE OF THE KEY VALUE MAP IT IS POSSIBLE THAT THE VECTOR IS ONLY SORTED BY OCCURANCE AND NOT
// RANK.
using namespace std;

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

class PokerHand {

private:
    // suits have the card icons when printed. These work on Windows and the MAc
    vector<Card> cards;
    int gameType = static_cast<int>(GAME::HIGHCARD);
    int total;
    vector<pair<int, int>> allPairs;
    vector <int> values;

public:
    PokerHand(Card first, Card second, Card third, Card fourth, Card fifth) {
        cards.push_back(first);
        cards.push_back(second);
        cards.push_back(third);
        cards.push_back(fourth);
        cards.push_back(fifth);
        total = 5;
        sort(cards.begin(), cards.begin()+total);

        map<int, int> all;

        for (int x = 0; x < total; x++) {
            all[static_cast<int>(cards.at(x).getRank())] = 0;
        }
        for (int x = 0; x < total; x++) {
            all[static_cast<int>(cards.at(x).getRank())] = all[static_cast<int>(cards.at(x).getRank())] + 1;
        }

        for(map<int,int>::iterator it = all.begin(); it != all.end(); ++it ) {
            values.push_back(it->second);
        }

        sort(values.begin(), values.end());

        for (auto& x : all) {
            allPairs.push_back(x);
        }

        sort(allPairs.begin(), allPairs.end(), valueCompare);


        if (isOnePair()) {
            gameType = static_cast<int>(GAME::ONEPAIR);
        }

        if (isTwoPair()) {
            gameType = static_cast<int>(GAME::TWOPAIR);
        }

        if (isThreeOfAKind()) {
            gameType = static_cast<int>(GAME::THREEOFKIND);
        }

        if (isStraight()) {
            gameType = static_cast<int>(GAME::STRAIGHT);
        }

        if (isFlush()) {
            gameType = static_cast<int>(GAME::FLUSH);
        }

        if (isFullHouse()) {
            gameType = static_cast<int>(GAME::FULLHOUSE);
        }

        if (isFourOfAKind()) {
            gameType = static_cast<int>(GAME::FOUROFAKIND);
        }

        if (isStraightFlush()) {
            gameType = static_cast<int>(GAME::STRAIGHTFLUSH);
        }
    }

    static bool valueCompare(pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    }

    int getGameType() {
        return static_cast<int>(gameType);
    }

    int getCardRank(int index) {
        return static_cast<int>(cards.at(index).getRank());
    }

    vector<pair<int,int>> getCardDict() {
        return allPairs;
    }

    void printAll() {
        for (int x = 0; x < total; x++) {
            cout << cards.at(x).toString() << " ";
        }
        cout << getGameType();
        cout << endl;
    }

    bool isStraightFlush() {
        int lastRank = -1;
        int lastSuit = -1;
        for (int x = 0; x < total; x++) {
            if (x == 0) {
                lastRank = static_cast<int>(cards.at(x).getRank());
                lastSuit = static_cast<int>(cards.at(x).getSuit());
            } else {
                if (static_cast<int>(cards.at(x).getRank()) != lastRank+1 || static_cast<int>(cards.at(x).getSuit()) != lastSuit) {
                    return false;
                } else {
                    lastRank = static_cast<int>(cards.at(x).getRank());
                }
            }
        }
        return true;
    }

    bool isStraight() {
        int lastRank = -1;
        for (int x = 0; x < total; x++) {
            if (x == 0) {
                lastRank = static_cast<int>(cards.at(x).getRank());
            } else {
                if (static_cast<int>(cards.at(x).getRank()) != lastRank+1) {
                    return false;
                } else {
                    lastRank = static_cast<int>(cards.at(x).getRank());
                }
            }
        }
        return true;
    }

    bool isFlush() {
        int lastSuit = -1;
        for (int x = 0; x < total; x++) {
            if (x == 0) {
                lastSuit = static_cast<int>(cards.at(x).getSuit());
            } else {
                if (static_cast<int>(cards.at(x).getSuit()) != lastSuit) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isFourOfAKind() {
        vector<int> fourOfAKind{1,4};
        if (values == fourOfAKind) {
            return true;
        }

        return false;
    }

    bool isFullHouse() {
        vector<int> fullHouse{1,2,2};

        if (values == fullHouse) {
            return true;
        }

        return false;
    }

    bool isThreeOfAKind() {
        vector<int> threeOfAKind{1,1,3};

        if (values == threeOfAKind) {
            return true;
        }

        return false;
    }

    bool isTwoPair() {
        vector<int> twoPairs{1,2,2};

        if (values == twoPairs) {
            return true;
        }

        return false;
    }

    bool isOnePair() {
        vector<int> onePair{1,1,1,2};
        if (values == onePair) {
            return true;
        }

        return false;
    }

    bool operator < (PokerHand &other){
        // SHOULD BE ABLE TO REMOVE ELSE IFS WITH A SIMPLE ELSE USING SECOND DICTIONARY STRATEGY.
        if (this->getGameType() != other.getGameType()) {
            if (this->getGameType() < other.getGameType()) {
                return true;
            } else {
                return false;
            }
        } else if (this->gameType == static_cast<int>(GAME::FLUSH) || this->gameType == static_cast<int>(GAME::STRAIGHT) || this->gameType == static_cast<int>(GAME::STRAIGHTFLUSH)) {
            for (int x = total-1; x > -1; x--) {
                if (getCardRank(x) < other.getCardRank(x)) {
                    return true;
                } else if (getCardRank(x) > other.getCardRank(x)) {
                    return false;
                }
            }
            return true;
        } else if (this->gameType == static_cast<int>(GAME::FULLHOUSE) || this->gameType == static_cast<int>(GAME::FOUROFAKIND) || this->gameType == static_cast<int>(GAME::FLUSH) || this->gameType == static_cast<int>(GAME::THREEOFKIND) || this->gameType == static_cast<int>(GAME::TWOPAIR) || this->gameType == static_cast<int>(GAME::ONEPAIR) || this->gameType == static_cast<int>(GAME::HIGHCARD)) {
            vector<pair<int,int>> thisDict = getCardDict();
            vector<pair<int,int>> otherDict = other.getCardDict();

            // DEBUG PURPOSES
            for (auto & x: thisDict) {
                cout << x.first << " " << x.second << endl;
            }

            for (int x = thisDict.size()-1; x != -1; x--) {
                if (thisDict.at(x).first < otherDict.at(x).first) {
                    return true;
                } else if (thisDict.at(x).first > otherDict.at(x).first) {
                    return false;
                }
            }
            return true;
        } else {
            throw "THIS SHOULD NEVER HAPPEN";
        }

    }

};
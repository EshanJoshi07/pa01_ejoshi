// main.cpp
// NAME: ESHAN JOSHI

#include <iostream>
#include <fstream>
#include <string>

#include "cards.h"

using namespace std;

int CardToInt(string card){
    int val;
    string type = card.substr(2,2);
    char num = card[2];
    char suite = card[0];
    card.substr(2,2);

    //edge cases for ace, jackm, queenm, king
    switch (num) {
        case 'a':
            val = 1;
            break;
        case 'j':
            val = 11;
            break;
        case 'q':
            val = 12;
            break;
        case 'k':
            val = 13;
            break;
        default:
            val = stoi(card.substr(2,2));
            break;
    }

    // edge cases for diamonds, spades, and hearts
    switch (suite) {
        case 'd':
            val += 13;
            break;
        case 's':
            val += 26;
            break;
        case 'h':
            val += 39;
            break;
        default:
            val += 0;
            break;
    }
    return val;
}

string IntToCard(int val){
    string card = "";
    string value;

    if (val < 14) {
        if (val == 1) {
            value = "a";
        }
        else if (val == 11) {
            value = "j";
        }
        else if (val == 12) {
            value = "q";
        }
        else if (val == 13) {
            value = "k";
        }
        else {
            value = to_string(val);
        }
        card = card + "c " + value;
    }
    else if (val < 27) {
        if (val - 13 == 1) {
            value="a";
        }
        else if (val - 13 == 11) {
            value = "j";
        }
        else if (val - 13 == 12) {
            value = "q";
        }
        else if (val - 13 == 13) {
            value = "k";
        }
        else {
            value = to_string(val - 13);
        }
        card = card + "d " + value;
    }
    else if (val < 40) {
        if (val - 26 == 1) {
            value = "a";
        }
        else if (val - 26 == 11) {
            value = "j";
        }
        else if (val - 26 == 12) {
            value = "q";
        }
        else if (val - 26 == 13) {
            value = "k";
        }
        else {
            value = to_string(val - 26);
        }
        card = card + "s " + value;
    }
    else {
      if (val - 39 == 1) {
          value = "a";
      }
      else if (val - 39 == 11) {
          value = "j";
      }
      else if (val - 39 == 12) {
          value = "q";
      }
      else if (val - 39 == 13) {
          value = "k";
      }
      else {
          value = to_string(val - 39);
      }
      card = card + "h " + value;
    }
    return card;
}


int main(int argv, char** argc){
    // prompt lines
    if(argv < 3){
      cout << "Please provide 2 file names" << endl;
      return 1;
    }
    
    ifstream cardFile1 (argc[1]);
    ifstream cardFile2 (argc[2]);
    string line;

    //check to make sure file can be read
    if (cardFile1.fail() || cardFile2.fail() ){
      cout << "Could not open file " << argc[2];
      return 1;
    }

    //Read hand A
    Cards a;
    while (getline (cardFile1, line) && (line.length() > 0)) {
      a.insert(CardToInt(line));
    }
    cardFile1.close();

    // Read hand B
    Cards b;
    while (getline (cardFile2, line) && (line.length() > 0)){  
      b.insert(CardToInt(line));
    }
    cardFile2.close();
    
    // working game code
    int total = 0;
    int minA = a.minValue();
    int maxB = b.maxValue();
    int temp;
    while (minA != a.maxValue() && maxB != b.minValue()) {  
      
      //A check
      if (total == 0) {
        if (b.contains(minA)) {
            cout << "Alice picked matching card " << IntToCard(minA) << endl;
            temp = minA;
            minA = a.getSuccessor(minA);
            a.remove(temp);
            b.remove(temp);
            total += 1;
        }
        else {
          if(!a.contains(minA)) {
              break;
          }
          minA = a.getSuccessor(minA);
        }
      }

      //B check
      else{
        if (a.contains(maxB)) {
            cout << "Bob picked matching card " << IntToCard(maxB) << endl;
            temp = maxB;
            maxB = b.getPredecessor(maxB);
            b.remove(temp);
            a.remove(temp);
            total -= 1;
        }
        else {
          if(!b.contains(maxB)) {
              break;
          }
          maxB = b.getPredecessor(maxB);
        } 
      }
    }

    cout << endl;
    cout << "Alice's cards:" << endl;
    
    
    int val = a.minValue();
    for (int i = 0; i < a.count(); i++) {
        cout << IntToCard(val) << endl;
        val = a.getSuccessor(val);
    }

    cout << endl;
    cout << "Bob's cards:" << endl;
    
    val = b.minValue();
    for (int j = 0; j < b.count(); j++) {
        cout << IntToCard(val) << endl;
        val = b.getSuccessor(val);
    }
    return 0;
}

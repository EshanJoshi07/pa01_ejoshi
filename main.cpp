#include <map>
#include <iostream>
#include <fstream>
#include <string>

#include "cards.h"

using namespace std;

// static enum StringValue { evNotDefined,
//                           evStringValue1,
//                           evStringValue2,
//                           evStringValue3,
//                           evEnd };

// static std::map<std::string, StringValue> s_mapStringValues;


int CardToInt(string card){
    int val;
    // char num = card[2];
    // char suite = card[0];
    // card.substr(2,2);

    // edge cases for ace, jackm, queenm, king
    // switch (num) {
    //     case 'a':
    //         val = 1;
    //         break;
    //     case 'j':
    //         val = 11;
    //         break;
    //     case 'q':
    //         val = 12;
    //         break;
    //     case 'k':
    //         val = 13;
    //         break;
    //     default:
    //         val = stoi(card.substr(2,2));
    //         break;
    // }

    if (card.substr(2,2) == "a") {
      val = 1;
    }
    else if (card.substr(2,2) == "j") {
        val = 11;
    }
    else if (card.substr(2,2) == "q") {
        val = 12;
    }
    else if (card.substr(2,2) == "k") {
        val = 13;
    }
    else {
        val = stoi(card.substr(2,2));
    }


    // edge cases for diamonds, spades, and hearts
    // switch (suite) {
    //     case 'd':
    //         val += 13;
    //         break;
    //     case 's':
    //         val += 26;
    //         break;
    //     case 'h':
    //         val += 39;
    //         break;
    //     default:
    //         val += 0;
    //         break;
    // }


    if (card.substr(0,1) == "d") {
        val += 13;
    }
    else if (card.substr(0,1) == "s") {
        val += 26;
    }
    else if (card.substr(0,1) == "h") {
        val += 39;
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
    else if(val<27){
      if(val-13==1) value="a";
      else if(val-13==11){ value="j"; }
      else if(val-13==12){ value="q"; }
      else if(val-13==13){ value="k"; }
      else{ value=to_string(val-13); }
      card=card+"d "+value;
    }
    else if(val<40){
      if(val-26==1) value="a";
      else if(val-26==11){ value="j"; }
      else if(val-26==12){ value="q"; }
      else if(val-26==13){ value="k"; }
      else{ value=to_string(val-26); }
      card=card+"s "+value;
    }
    else{
      if(val-39==1) value="a";
      else if(val-39==11){ value="j"; }
      else if(val-39==12){ value="q"; }
      else if(val-39==13){ value="k"; }
      else{ value=to_string(val-39); }
      card=card+"h "+value;
    }
    return card;
}


int main(int argv, char** argc){
  
  //prompt lines
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

  //Read each file
  Cards aHand;
  while (getline (cardFile1, line) && (line.length() > 0)){
    aHand.insert(CardToInt(line));
  }
  cardFile1.close();

  Cards bHand;
  while (getline (cardFile2, line) && (line.length() > 0)){  
    bHand.insert(CardToInt(line));
  }
  cardFile2.close();
  
  //game
  int count=0;
  int val1min=aHand.minValue();
  int val2max=bHand.maxValue();
  int valDel;
  while(val1min!=aHand.maxValue() && val2max!=bHand.minValue()){  
    //Alice
    if(count==0){
      if(bHand.contains(val1min)){
        cout << "Alice picked matching card " << IntToCard(val1min) << endl;
        valDel=val1min;
        val1min=aHand.getSuccessor(val1min);
        aHand.remove(valDel);
        /*if(val2max==val1min){
          val2max=bHand.getPredecessor(val2max);
        }*/
        bHand.remove(valDel);
        count++;
      }
      else{
        if(!aHand.contains(val1min)){ break;}
        val1min=aHand.getSuccessor(val1min);

      }
      
    }
    //Bob
    else{
      if(aHand.contains(val2max)){
        cout << "Bob picked matching card " << IntToCard(val2max) << endl;
        valDel=val2max;
        val2max=bHand.getPredecessor(val2max);
        bHand.remove(valDel);
        /*if(val1min==val2max){
          val1min=aHand.getSuccessor(val1min);
        }*/
        
        aHand.remove(valDel);
        count--;
      }
      else{
        if(!bHand.contains(val2max)){ break;}
        val2max=bHand.getPredecessor(val2max);
      }
      
    }
  }

  cout << endl;
  int printVal=aHand.minValue();
  cout << "Alice's cards:" << endl;
  for(int i=0;i<aHand.count();i++){
    cout << IntToCard(printVal) << endl;
    printVal=aHand.getSuccessor(printVal);
  }

  cout << endl;
  printVal=bHand.minValue();
  cout << "Bob's cards:" << endl;
  for(int i=0;i<bHand.count();i++){
    cout << IntToCard(printVal) << endl;
    printVal=bHand.getSuccessor(printVal);
  }
  

  return 0;
}

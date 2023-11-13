#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;

void sixteendigit(const char*);
void fifteendigit(char*);
vector<string> split(const string &s, char delim){
  vector<string> result;
  stringstream ss (s);
  string item;

  while(getline(ss,item,delim)){
    result.push_back(item);
  }
  return result;
}



int main(int argc, char *argv[]){
  if(argc<2){
    cout << "Correct Usage: " << argv[0] << " <card#>" << endl;
    return 0;
  } 
  string s = (string)argv[1];
  cout << "get into cpp from luhnTest" << endl;
  vector<string> args = split(argv[1],' ');
  for(auto j: args)cout << j << endl;

  const char* st = args.at(0).c_str();
  /*if(b){
    fifteendigit(argv[1]);
  }else{*/
    sixteendigit(st);
 // }

  return 0;
}

void sixteendigit(const char* number){
  cout << "gets to 16d" << endl;
  int sum = 0;
  //max index = 15, lowest index = 0
  for(int i = 15; i>-1; i--){
    cout << (number[i]) << ";";
    if(i%2 == 0){
        switch((int)number[i]-48){
          case 1:
          case 2:
          case 3:
          case 4:
            sum+= ((int)number[i]-48)*2;  
            break;        
          case 5:
            sum+=1;
            break;
          case 6:
            sum+=3;
            break;          
          case 7:
            sum+=5;
            break;          
          case 8:
            sum+=7;
            break;
          case 9:
            sum+=9;
            break;
        }
    }else{
      cout << "else" << ";";
      sum+=(int)number[i]-48;
    }
    cout << sum << endl;
  }
  string t = sum%10 == 0? "Valid Card" : "Invalid Card";
  cout << t << endl;
}
void fifteendigit(char* number){

}
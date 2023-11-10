#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void sixteendigit(char*);
void fifteendigit(char*);

int main(int argc, char *argv[]){
  if(argc<2){
    cout << "Correct Usage: " << argv[0] << " <card#>" << endl;
    return 0;
  } 
  bool b = argv[1][15] == '\0';
  if(b){
    fifteendigit(argv[1]);
  }else{
    sixteendigit(argv[1]);
  }

  return 0;
}

void sixteendigit(char* number){
  cout << "gets to 16d" << endl;
  int sum = 0;
  //max index = 15, lowest index = 0
  for(int i = 0; i< 16; i++){
    if(i%2 == 0){
      if(number[i] >4){
        switch(number[i]){
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
        sum += number[i]*2;
      }
    }else{
      sum+=number[i];
    }
  }
  cout << sum << endl;
}
void fifteendigit(char* number){

}
#include <iostream>
#include <string>
#include "util.h"

using namespace std;

void StringExplode(string str, string separator, vector<string>* results){
     int found;
     found = str.find_first_of(separator);
     while(found != string::npos){
         if(found > 0){
             results->push_back(str.substr(0,found));
         }
         str = str.substr(found+1);
         found = str.find_first_of(separator);
     }
     if(str.length() > 0){
         results->push_back(str);
     }
}

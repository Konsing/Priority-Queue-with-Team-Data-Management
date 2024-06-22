#include "priorityqueue.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include "json.hpp"
#include <ifsteam>
#include "teamdata.h"

int main(int argc, char** argv) {
  if(argc != 2){
    cerr<< "Usage: createteams file.json" << endl;
    return -1;
  }
  ifstream inFile;
  string fileName = argv[1];
  inFile.open(fileName);
  if(inFile.fail()){
    cerr<< "Usage: createteams file.json" << endl;
    return -1;
  }
  
}

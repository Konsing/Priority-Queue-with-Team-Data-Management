#include <iostream>
#include <fstream>
#include "json.hpp"
#include "priorityqueue.h"
#include <iomanip>
#include <sstream>
using namespace std;

int main(int argc, char** argv) {
  if(argc != 2){
    cerr << "Usage: buildheap file.json" << endl;
    return -1;
  }
  string fileName, opNum;
  stringstream ss;
  size_t max_size, totalOpNum;
  double keyValue;
  
  fileName = argv[1];
  ifstream inFile;
  inFile.open(fileName);
  
  if (inFile.fail()) {
    //display an error message since wrong # of args provided
    cerr << "Usage: buildheap file.json" << endl;
    //end the program if file not open
    return 1;
  }
  
  nlohmann::json data = nlohmann::json::parse(inFile);
  max_size = data["metadata"]["maxHeapSize"];
  totalOpNum = data["metadata"]["numOperations"];
  
  PriorityQueue heap = PriorityQueue(max_size) ;
  for(size_t i = 0 ; i < totalOpNum; ++i){
    ss.str();
    ss.clear();
    ss << "Op" << setw(2) << setfill('0')<< i + 1;
    ss >> opNum;
    cout << opNum;
    ss.str();
    ss.clear();
    if(data[opNum]["operation"] == "insert"){
      ss << data[opNum]["key"];
      ss >> keyValue;
      heap.insert(keyValue);
    }
    if(data[opNum]["operation"] == "removeMin"){
      ss << data[opNum]["key"];
      ss >> keyValue;
      heap.removeMin();
    }
  }
  nlohmann::json result = heap.JSON();
  result["metadata"]["numOperations"] = totalOpNum;
  cout << result.dump(2);
}
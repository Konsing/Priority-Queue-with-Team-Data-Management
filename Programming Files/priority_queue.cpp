#include <iostream>
#include "json.hpp"
#include <algorithm>
#include "priorityqueue.h"

//constructor
PriorityQueue::PriorityQueue(std::size_t max_size) :
	nodes_(max_size + 1, KeyValuePair()),
	max_size_(max_size),
	size_(0) {
}

void PriorityQueue::insert(Key k) {
	insert(std::make_pair(k, std::make_pair(0, 0)));
}

void PriorityQueue::insert(KeyValuePair kv) { //done
  if(size_ + 1 > max_size_){
    //std::error << "Size can't be bigger than max size.\n"
    //do nothing
  } else{
    nodes_[size_ + 1] = kv;
    size_ += 1;
    heapifyUp(size_);
  }
}

KeyValuePair PriorityQueue::min() { //done
  if(size_ != 0){ //if not null, return the root
    return nodes_[ROOT];
  } else {
    return KeyValuePair();
/*
b/c we don't really delete a node, we just decrease the size, and hoping insert will override, so we need to return a new null node which is zero in this case
*/  
  }
}

KeyValuePair PriorityQueue::removeMin() { //done
  if(size_ != 0){ //if queue is not null
    KeyValuePair temp = nodes_[ROOT] ;
    nodes_[ROOT] = nodes_[size_];
    size_ -= 1;
    heapifyDown(ROOT);
    return temp;
  }
  else {
    return KeyValuePair();
  }
}

bool PriorityQueue::isEmpty() const { //done
  if(size_ == 0){
    return true;
  } else {
    return false;
  }
}

size_t PriorityQueue::size() const { //done
  return size_;
}

nlohmann::json PriorityQueue::JSON() const {
	nlohmann::json result;
  for (size_t i = 1; i <= size_; i++) {
      nlohmann::json node;
      KeyValuePair kv = nodes_[i];
      node["key"] = kv.first;
      node["value"] = kv.second;
      if (i != ROOT) {
          node["parent"] = std::to_string(i / 2);
      }
      if (2 * i <= size_) {
          node["leftChild"] = std::to_string(2 * i);
      }
      if (2 * i + 1 <= size_) {
          node["rightChild"] = std::to_string(2 * i + 1);
      }
      result[std::to_string(i)] = node;
  }
  result["metadata"]["max_size"] = max_size_;
  result["metadata"]["size"] = size_;
	return result;
}

void PriorityQueue::heapifyUp(size_t i) { //done
  while(nodes_[i].first < nodes_[i / 2].first){
    swap(nodes_[i], nodes_[i / 2]);
    i = i / 2;
    if(i == 1){ //if i is already 1 at root
      break;
    }
  } 
}

void PriorityQueue::heapifyDown(size_t i) { //done
  if(i * 2 > size_){ // no child
    return;
  } else if( (i * 2 + 1) > size_ ){ // one child exist
    if(nodes_[i].first > nodes_[i * 2].first){
      swap(nodes_[i], nodes_[i * 2]);
      heapifyDown(i * 2);
    } else {
      return;
    }
  } else { // two children exist
    if(nodes_[i * 2].first < nodes_[i * 2 + 1].first){
      if(nodes_[i].first > nodes_[i * 2].first){
        swap(nodes_[i],nodes_[2 * i]);
        heapifyDown(i * 2);
      } else {
        return;
      }
    } else {
      if(nodes_[i].first > nodes_[i * 2 + 1].first){
        swap(nodes_[i], nodes_[i * 2 + 1]);
        heapifyDown(i * 2 + 1);
      } else {
        return;
      }
    }
  }
}

void PriorityQueue::removeNode(size_t i) { //done
  nodes_[i] = nodes_[size_];//replace nodes_[1]
  size_ -= 1; //remove the node
  heapifyUp(i);
  heapifyDown(i);

}

Key PriorityQueue::getKey(size_t i) { //done
  return nodes_[i].first;
}

/*
left child i * 2 + 1
and right child would be i * 2 + 2
and parent would be i / 2
*/


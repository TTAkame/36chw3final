#include <iostream>
#include "json.hpp"

#include "priorityqueue.h"

PriorityQueue::PriorityQueue(std::size_t max_size) :
	nodes_(max_size + 1, KeyValuePair()),
	max_size_(max_size),
	size_(0) {
}

void PriorityQueue::insert(Key k) {
	insert(std::make_pair(k, std::make_pair(0, 0)));
}

void PriorityQueue::insert(KeyValuePair kv) {
	size_++;
    nodes_[size_] = kv;
    heapifyUp(size_);
}

KeyValuePair PriorityQueue::min() {
	return nodes_[ROOT];
}

KeyValuePair PriorityQueue::removeMin() {
	removeNode(ROOT);
    size_ --;
    return nodes_[ROOT];
}

bool PriorityQueue::isEmpty() const {
	return size_==0;
}

size_t PriorityQueue::size() const {
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

void PriorityQueue::heapifyUp(size_t i) {
	size_t j = i/2;
    size_t len = size_;


    while(j>0){
        if((i<=len)&&i>0){
            if(nodes_[i].first<nodes_[j].first){
                std::swap(nodes_[i].first,nodes_[j].first);
                i=j;
                j=i/2;
            }
            else{
                j=-1;
                break;
            }
        }
        else{
            break;
        }
    }

}

void PriorityQueue::heapifyDown(size_t i) {
	size_t j = 2*i+1,x;
    size_t len = size_;
    double smaller;
    while(j<=len){
        smaller = (nodes_[j-1].first<nodes_[j].first) ? nodes_[j-1].first : nodes_[j].first;
        x = (nodes_[j-1].first<nodes_[j].first) ? 2*i : 2*i+1;
        if(nodes_[i].first>smaller){
            std::swap(nodes_[i],nodes_[x]);
            i = x;
            j=2*i+1;
        }
    }
    if(2*i==size_){
        if(nodes_[i].first>nodes_[2*i].first){
            std::swap(nodes_[i],nodes_[2*i]);
            i=2*i;
        }
    }
}

void PriorityQueue::removeNode(size_t i) {
	std::swap(nodes_[i],nodes_[size_]);
    nodes_.erase(nodes_.end());
    heapifyDown(i);
}

Key PriorityQueue::getKey(size_t i) {
    if((i>size_)||(i<1)){
        throw std::out_of_range("no such index");
    }
	return nodes_[i].first;
}

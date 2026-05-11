#include <iostream>
#include "queue.h"
#include <string>


Queue::Queue() : dll(){
    length = 0;
}

Queue::~Queue(){
    length = 0;
}

void Queue::enqueue(int val){
    dll.appendNode(val);
    length++;
}

void Queue::dequeue(){
    if (length >= 1){
        dll.deleteAt(0);
        length--;
    }
    else {
        std::cout << "No elements in the queue to be removed." << std::endl;
    }
}

// if the queue isEmpty then null returned otherwise the front element of the queue is returned
// std::optional<int> Queue::peek(){
//     if (length >= 1){
//         return dll.getNode(0);
//     }
//     else{
//         return std::nullopt;
//     }
// }

std::string Queue::peek(){
    if (length >= 1){
        return std::to_string(dll.getNode(0));
    }
    return "Null";
}

int Queue::isEmpty(){
    return (length == 0) ? 1 : 0;
}

int Queue::size(){
    return length;
}

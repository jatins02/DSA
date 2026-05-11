#include <iostream>
#include "queue.h"
#include <string>

int main(){

    Queue q;
    q.enqueue(22);
    q.dequeue();
    std::cout << q.size() << std::endl;
    q.dequeue();
    std::cout << q.size() << std::endl;
    q.enqueue(12);
    std::cout << q.peek() << std::endl;
    std::string isEmptyResult = (q.isEmpty()) ? "Empty" : "Not Empty";
    std::cout << "The queue is: " << isEmptyResult << std::endl;
    std::cout << "Size of the queue: " << q.size() << std::endl;

    return 0;
}
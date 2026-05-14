#ifndef HASHMAP_H
#define HASHMAP_H

struct Node{
    std::string name;
    std::string rollno;
    std::string branch;
    Node *next;
};

// database type shi, first you enter the branch of the person who's data needs to be added then you enter the
// roll no. of the person, to add them into the hashmap

// HASHING ALGORITHM:
// simply based on the first letter of the branch, for the same letter there will be 4 spaces left, 
// implying the indices 0-3 of the arr will be for "a", 4-7 for "b" and so on.

class Hashmap{
private:
    int length;
    Node **arr;     // pointer to pointer array
    int size;

    void clearBlock(Node *node);
    int hashFunction(std::string branch);

public:
    Hashmap();
    ~Hashmap();
    void put(std::string branch, std::string name, std::string rollno);
    Node *get(std::string branch, std::string rollno);
    void remove(std::string branch, std::string rollno);
    bool contains(std::string branch, std::string rollno);    
    int getSize();
    bool isEmpty();
};

#endif
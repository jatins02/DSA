#include <iostream>
#include <algorithm>
#include <cctype>
#include "hashmap.h"
#include <vector>

int main(){
    Hashmap hash;

    hash.put("cs", "hehehe", "b25cs1069");
    hash.put("civil", "wassp", "b25ci1022");

    Node *res = hash.get("civil", "b25ci1022");
    if (res !=  nullptr){
        std::vector<std::string> results = {res->name, res->rollno, res->branch};
        std::cout << "Record for the student was found..." << std::endl;
        std::cout << "Name: " << results[0] << std::endl;
        std::cout << "Roll No.: " << results[1] << std::endl;
        std::cout << "Branch: " << results[2] << std::endl;
    }
    else{
        std::cout << "Record for the student was not found..." << std::endl;
    }
    
    hash.put("es", "bruhhhh", "b25es1042");
    hash.put("aids", "waddp", "b25cm1019");

    hash.remove("civil", "b25ci1022");
    Node *res2 = hash.get("civil", "b25ci1022");
    if (res2 !=  nullptr){
        std::vector<std::string> results = {res2->name, res2->rollno, res2->branch};
        std::cout << "Record for the student was found..." << std::endl;
        std::cout << "Name: " << results[0] << std::endl;
        std::cout << "Roll No.: " << results[1] << std::endl;
        std::cout << "Branch: " << results[2] << std::endl;
    }
    else{
        std::cout << "Record for the student was not found..." << std::endl;
    }

    std::cout << "Size: " << hash.getSize() << std::endl;
    
    std::string contains = (hash.contains("aids", "b25cm1019")) ? "True" : "False";
    std::cout << "Contains: " << contains << std::endl;

    hash.remove("cs", "b25cs1069");
    hash.remove("es", "b25es1042");
    hash.remove("aids", "b25cm1019");

    std::string emptyres = (hash.isEmpty()) ? "True" : "False";
    std::cout << "Empty: " << emptyres << std::endl;

    return 0;
}

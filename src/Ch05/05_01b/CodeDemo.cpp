// Debugging in C++ with Visual Studio Code
// Exercise 05_01
// Segmentation Faults, by Eduardo Corpeño

#include <iostream>
#include <sstream>
#include <string>

#define MAX_ENTRIES 1000

struct Node{
    std::string name;
    std::string age;
    std::string gender;
    std::string weight;
    Node * next;
};

void appendNode(Node ** head, Node ** tail, const std::string & newName, 
        const std::string & newAge = "", const std::string & newGender = ""){
    Node * newNode = new Node;
    newNode->name = newName;
    newNode->age = newAge;
    newNode->gender = newGender;
    newNode->next = nullptr;
    
    if(*head == nullptr){
        *head = newNode;
        *tail = newNode;
    }
    else{
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void printNames(Node * head){
    Node * current = head;
    while(current != nullptr){
        std::cout << current->name << " "<<current->age<<" "<<current->gender<<std::endl;
        current = current->next;
    }
    std::cout << std::endl;
}

void deleteList(Node * head){
    while(head != nullptr){
        Node * temp = head;
        head = head->next;
        delete temp;
    }
}

int main(){
    std::cout << "Enter data separated by comma: ";
    std::string line, name, age, gender, token;
    std::getline(std::cin, line);
    
    std::stringstream ss(line);
    
    Node * head = nullptr;
    Node * tail = nullptr;
    /*while(iss >> token){
        appendNode(&head, &tail, token);
    }*/

    while(std::getline(ss, token ,','))
    {
        std::istringstream iss(token);
        iss >> name >> age >> gender;
        appendNode(&head, &tail, name, age, gender);
    }
    
    std::cout << "The names in the linked list are: ";
    printNames(head);
    
    deleteList(head);
    std::cout << std::endl << std::endl;
    return 0;
}

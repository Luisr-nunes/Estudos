/*
 * C++ Singly Linked List Implementation
 *
 * This file demonstrates direct memory management using pointers, 
 * object-oriented programming with classes, and foundational data structures.
 */

#include <iostream>
#include <string>

// 1. Node Class Definition (using template for data genericism)
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

// 2. SinglyLinkedList Class Definition
template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Method to insert at the end
    void insert(T value) {
        Node<T>* newNode = new Node<T>(value);
        
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    // Method to search for a value
    bool search(T value) const {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Method to delete a value (removes first occurrence)
    void remove(T value) {
        if (head == nullptr) return;

        // If the head needs to be removed
        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            
            if (head == nullptr) { // List became empty
                tail = nullptr;
            }
            
            delete temp;
            size--;
            return;
        }

        // Searching for the node before the one to remove
        Node<T>* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        // If the value was found
        if (current->next != nullptr) {
            Node<T>* nodeToRemove = current->next;
            current->next = current->next->next;
            
            if (nodeToRemove == tail) { // If we removed the tail
                tail = current;
            }
            
            delete nodeToRemove;
            size--;
        }
    }

    // Method to print the list
    void print() const {
        std::cout << "List [size=" << size << "]: ";
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
    }

    // Destructor to free allocated memory
    ~SinglyLinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        std::cout << "DEBUG: Destructor cleaned memory." << std::endl;
    }
};

// 3. Main Function (Driver Code)
int main() {
    std::cout << "--- C++ Singly Linked List Test ---" << std::endl;

    // Work with Integers
    std::cout << "\nCreating an integer list:" << std::endl;
    SinglyLinkedList<int> intList;
    intList.insert(10);
    intList.insert(20);
    intList.insert(30);
    intList.insert(40);
    intList.print();

    std::cout << "Search for 20: " << (intList.search(20) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 50: " << (intList.search(50) ? "Found" : "Not Found") << std::endl;

    std::cout << "Removing 30..." << std::endl;
    intList.remove(30);
    intList.print();

    // Work with Strings (showcasing templates)
    std::cout << "\nCreating a string list:" << std::endl;
    SinglyLinkedList<std::string> nameList;
    nameList.insert("Alice");
    nameList.insert("Bob");
    nameList.insert("Charlie");
    nameList.print();

    std::cout << "Removing Alice (head)..." << std::endl;
    nameList.remove("Alice");
    nameList.print();

    std::cout << "\n--- End of C++ Linked List Test ---" << std::endl;
    // Destructors will automatically clean up memory here.
    return 0;
}

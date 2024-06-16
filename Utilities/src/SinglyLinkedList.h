#pragma once

#include <stdexcept>

template<typename T>
struct SingleNode {
    T data;
    SingleNode<T>* next;

    SingleNode() = delete;            // Intentionally no default constructor
    SingleNode(const T& element) : data(element), next(nullptr) {}
};


template<typename T>
class SinglyLinkedList {
private:
    SingleNode<T>* head;
    SingleNode<T>* tail;

    int length;
public:
    // Constructors
    SinglyLinkedList();
    SinglyLinkedList(const SinglyLinkedList&);
    SinglyLinkedList& operator=(const SinglyLinkedList&); // assignment operator
    T& operator[](int iterator); // assignment operator
    ~SinglyLinkedList(); // destructor

    // Getters / Setters
    bool empty();
    int size() { return length; }

    void append(const T&);
    void prepend(const T&);
    void insertAfter(SingleNode<T>*, const T&);
    void removeAfter(SingleNode<T>*);

    void pop_front();      // remove element at front of list
    T& front();          // return list's front element
    T& back();           // return list's back element

    void clear();
};

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

template<typename T>
bool SinglyLinkedList<T>::empty() {
    return head == nullptr;
}

template<typename T>
void SinglyLinkedList<T>::append(const T& newData) {
    SingleNode<T>* newNode = new SingleNode<T>(newData);   // create new node

    if (head == nullptr) { // List empty
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    length += 1;
}

template<typename T>
void SinglyLinkedList<T>::prepend(const T& newData) {
    SingleNode<T>* newNode = new SingleNode<T>(newData);   // create new node

    if (head == nullptr) { // list empty
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
    length += 1;
}


template<typename T>
void SinglyLinkedList<T>::insertAfter(SingleNode<T>* curNode, const T& newData) {
    // Construct new node
    SingleNode<T>* newNode = new SingleNode<T>(newData);

    if (head == nullptr) {                // List empty
        head = newNode;
        tail = newNode;
    }
    else if (curNode == tail) {         // Insert after tail
        tail->next = newNode;
        tail = newNode;
    }
    else {
        newNode->next = curNode->next;
        curNode->next = newNode;
    }
    length += 1;
}


template<typename T>
void SinglyLinkedList<T>::removeAfter(SingleNode<T>* curNode) {
    if (empty()) throw std::length_error("empty list");

    // Special case, remove head
    if (curNode == nullptr && head != nullptr) {
        SingleNode<T>* sucNode = head->next;
        head = sucNode;

        if (sucNode == nullptr) { // Removed last item
            tail = nullptr;
        }
    }
    else if (curNode->next != nullptr) {
        SingleNode<T>* sucNode = curNode->next->next;
        curNode->next = sucNode;

        if (sucNode == nullptr) { // Removed tail
            tail = curNode;
        }
    }
    length -= 1;
}


template <typename T>
void SinglyLinkedList<T>::pop_front() {
    removeAfter(nullptr);
}


template <typename T>
T& SinglyLinkedList<T>::front() {
    if (empty()) throw std::length_error("empty list");
    return head->data;
}


template <typename T>
T& SinglyLinkedList<T>::back() {
    if (empty()) throw std::length_error("empty list");
    return tail->data;
}


template<typename T>
void SinglyLinkedList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
    length = 0;
}


template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clear();
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& original) : SinglyLinkedList() {
    // Walk the original list adding copies of the elements to this list maintaining order
    for (SingleNode<T>* position = original.head; position != nullptr; position = position->next) {
        append(position->data);
    }
    length = original.length;
}

template <typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList<T>& rhs) {
    if (this != &rhs) // avoid self assignment
    {
        // Release the contents of this list first
        clear();  // An optimization might be possible by reusing already allocated nodes

        // Walk the right hand side list adding copies of the elements to this list maintaining order
        for (SingleNode<T>* position = rhs.head; position != nullptr; position = position->next) {
            append(position->data);
        }
        this->length = rhs.length;
    }
    return *this;
}

template <typename T>
T& SinglyLinkedList<T>::operator[](int index) {
    SingleNode<T>* position = head;
    for (int i = 0; i < index; ++i) {
        position = position->next;
    }
    return position->data;
}
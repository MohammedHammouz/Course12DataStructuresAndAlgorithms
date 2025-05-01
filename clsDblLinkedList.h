#pragma once
#include<iostream>
#include<stack>
#include<vector>
template<class T>
class clsDblLinkedList
{
protected:
    int _Size = 0;

public:

    class Node {

    public:
        T value;
        Node* next;
        Node* prev;
    };
    Node* head = NULL;
    void InsertAtBeiginList(T value) {
        Node* new_node = new Node();
        new_node->value = value;
        new_node->next = head;
        new_node->prev = NULL;

        if (head != NULL) {
            head->prev = new_node;

        }
        head = new_node;

        _Size++;
    }
    void InsertAtEndList(T value) {
        Node* new_node = new Node();
        new_node->value = value;
        new_node->next = NULL;
        if (head == NULL) {
            new_node->prev = NULL;

            head = new_node;
        }
        else {
            Node* curr = head;
            while (curr->next != NULL) {

                curr = curr->next;
            }

            curr->next = new_node;
            new_node->prev = curr;

        }
        _Size++;
    }
    Node* Find(T value) {
        Node* current = head;
        while (current != NULL) {
            if (current->value == value) {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }
    void InsertAtList(Node*& current, T value) {
        Node* new_node = new Node();
        new_node->value = value;
        new_node->next = current->next;
        new_node->prev = current;

        if (current != NULL) {

            current->next->prev = new_node;
        }

        current->next = new_node;

        _Size++;
    }
    void DeleteFirstNode() {
        if (head == NULL) {
            return;
        }
        Node* temp = head;

        head = head->next;
        if (head != NULL) {

            head->prev = NULL;
        }

        delete temp;

        _Size--;
    }
    void DeleteLastNode() {
        if (head == NULL) {
            return;
        }
        if (head->next == NULL) {
            delete head;

            head = NULL;
            return;
        }
        Node* current = head;
        //we need to find node before last node
        while (current->next->next != NULL) {

            current = current->next;
        }
        Node* temp = current->next;
        current->next = NULL;

        delete temp;
        _Size--;
    }
    void DeleteNode(Node*& NodeToDelete) {
        if (head == NULL || NodeToDelete == NULL) {
            return;
        }
        //8->13->15->8->15->20->20->13->
        if (head == NodeToDelete) {

            head = NodeToDelete->next;
        }
        if (NodeToDelete->next != NULL) {

            NodeToDelete->next->prev = NodeToDelete->prev;
        }
        if (NodeToDelete->prev != NULL) {

            NodeToDelete->prev->next = NodeToDelete->next;
        }

        delete NodeToDelete;

        _Size--;
    }
    void PrintLLinkedList() {
        Node* curr = head;

        while (curr != NULL) {

            std::cout << curr->value << " ";

            curr = curr->next;
        }

        std::cout << '\n';
    }
    void PrintNodeDetails() {
        Node* curr = head;

        while (curr != NULL) {
            if (curr->prev == NULL && curr->next != NULL) {
                std::cout << "\nNULL" << "<-->" << curr->value << "<-->" << curr->next->value << std::endl;
            }
            else if (curr->next == NULL && curr->prev != NULL) {
                std::cout << curr->prev->value << "<-->" << curr->value << "<-->" << "NULL" << std::endl;
            }
            else if (curr->next != NULL && curr->prev != NULL) {
                std::cout << curr->prev->value << "<-->" << curr->value << "<-->" << curr->next->value << std::endl;
            }
            else if (curr->next == NULL && curr->prev == NULL) {
                std::cout << "NULL" << "<-->" << curr->value << "<-->" << "NULL" << std::endl;
            }
            curr = curr->next;
        }
    }
    void PrintLinkedListDetails() {
        Node* curr = head;
        while (curr != NULL) {
            if (curr->prev == NULL) {
                std::cout << "\nNULL" << "<-->" << curr->value << "<-->" << curr->next->value << "<-->";
            }
            else if (curr->next == NULL) {
                std::cout << curr->prev->value << "<-->" << curr->value << "<-->" << "NULL";
            }
            else {
                std::cout << curr->prev->value << "<-->" << curr->value << "<-->" << curr->next->value << "<-->";
            }

            curr = curr->next;
        }
    }
    int Size() {

        return _Size;
    }
    bool IsEmpty() {
        return (_Size == 0 ? true : false);
    }
    void Clear() {
        while (_Size > 0) {
            DeleteFirstNode();
        }
    }
    void Reverse() {
        Node* temp = nullptr;
        Node* current = head;
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != nullptr) {
            head = temp->prev;
        }
    }
    Node* GetNode(int Index) {
        Node* current = head;
        int counter = 0;
        if (Index<0 || Index>_Size - 1) {
            return NULL;
        }
        while (current != NULL && current->next != NULL) {
            if (counter == Index) {
                break;
            }
            current = current->next;
            counter++;
        }
        return current;
    }

    T GetItem(int Index) {
        Node* ItemNode = GetNode(Index);
        if (ItemNode == NULL) {
            return NULL;
        }
        else {
            return ItemNode->value;
        }
    }
    bool UpdateItem(int Index, T value) {
        Node* ItemNode = GetNode(Index);
        if (ItemNode == NULL) {
            return false;
        }
        else {
            ItemNode->value = value;
            return true;
        }
    }
    bool InsertAfter(int Index, T value) {
        Node* ItemNode = GetNode(Index);
        if (ItemNode == nullptr) {
            return false;
        }
        InsertAtList(ItemNode, value);
        return true;
    }
};



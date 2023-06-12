//
//  Class_List.h
//  DB_Of_Students
//
//  Created by Daniil Vilchinskiy on 16.05.2023.
//

#pragma once
#include <iostream>

using namespace std;


struct node {
    string data;
    struct node* next;
};


class ClassList
{
private:
    struct node* myHead;
    int countItem = 0;

public:
    ClassList() {
        myHead;
        countItem = 0;
    }
    ~ClassList() {
        struct node* old = NULL;
        struct node* current = myHead;
        while (current != NULL) {
            old = current;
            current = current->next;
            delete old;
        }
    }

    void addItem(string _data)
    {
        struct node* newItem = new node();
        newItem->data = _data;
        if (countItem == 0)
            newItem->next = NULL;
        else
            newItem->next = myHead;
        myHead = newItem;
        countItem++;
    }

    void insertItem(int index, string _data) {
        if (not (index >= 0 and index <= countItem and countItem >= 0))
            return;
        if (index == 0)
            addItem(_data);
        else {
            struct node* current = myHead;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            struct node* newItem = new node();
            newItem->data = _data;
            newItem->next = current->next;
            current->next = newItem;
            countItem++;
        }
    }

    void push_back(string _data) {
        insertItem(countItem, _data);
    }

    void editItem(int index, string _data) {
        if (index >= 0 and index < countItem and countItem>0) {
            struct node* current = myHead;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            current->data = _data;
        }
        else {
            cout << endl << "Ошибка редактирования";
        }
    }

    void deleteItem(int index) {
        if (index >= 0 and index < countItem and countItem>0) {
            struct node* current = myHead;
            struct node* old;
            if (index == 0) {
                old = myHead;
                myHead = current->next;
                delete old;
                countItem--;
            }
            else {
                int i = 0;
                while (current) {
                    if (i == index - 1) {
                        old = current->next->next;
                        delete current->next;
                        current->next = old;
                        countItem--;
                        break;
                    }
                    i++;
                    current = current->next;
                }
            }
        }

    }
    
    int getCount() {
        return countItem;
    }
    
    string getItem(int index) {
        string _data = "Error";
        if (index >= 0 and index < countItem and countItem>0) {
            struct node* current = myHead;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            _data = current->data;
        }
        else {
            cout << endl << "Элемент не найден";
        }
        return _data;
    }
    
    void printItems4Menu()
    {
        struct node* current = myHead;
        int i = 0;
        while (current != NULL){
            cout << i << ". " << current->data << endl;
            i++;
            current = current->next;
        }
    }
};

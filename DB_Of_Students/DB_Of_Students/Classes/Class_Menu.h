//
//  Class_Menu.h
//  DB_Of_Students
//
//  Created by Daniil Vilchinskiy on 16.05.2023.
//

#pragma once
#include <iostream>
#include <string.h>

#include "Class_Edit_Data.h"
#include "Class_List.h"

using namespace std;

class ClassMenu
{
private:
    string upTitle; 
    ClassList *items;
    string downTitle;
    
public:
    ClassMenu(string _upTitle){
        upTitle = std::move(_upTitle);
        items = new ClassList();
    }
    ClassMenu(): ClassMenu("Меню"){
        downTitle = "Нижний заголовок";
    }
    ~ClassMenu() {
        delete items;
    }
    void addMenuItem(string _item) {
        items->push_back(_item);
    }
    void draw(){
        cout << upTitle << endl;
        items->printItems4Menu();
        cout << downTitle << endl;
    }
    int run() {
        draw();
        ClassEditData* cl = new ClassEditData();
        cl->setLabel("\nВведите число");
        int min=0, max = items->getCount();
        int selectItem = cl->getData(editType::onlyDigit, min, max);
        delete cl;
        return selectItem;
    }
};

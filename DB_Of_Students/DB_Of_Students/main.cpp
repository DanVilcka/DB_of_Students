//
//  main.cpp
//  DB_Of_Students
//
//  Created by Daniil Vilchinskiy on 14.05.2023.
//

#include <iostream>
#include <string>
#include <unistd.h>

#include "Class_Student.h"
#include "Class_Menu.h"


void clean_c(){
    for (int i = 0; i < 30; i++) {
        cout << " " << endl;
    }
}


int main()
{
    
    Student* st = new Student();
    
    ClassMenu* mainMenu = new ClassMenu("\nОсновное меню");
    mainMenu->addMenuItem("Выход"); // 0
    mainMenu->addMenuItem("Отобразить данные о студентах"); // 1
    mainMenu->addMenuItem("Добавить/изменить/удалить данные о студенте"); // 2
    mainMenu->addMenuItem("Выполнить задание"); // 3
    int selectedItem = -1;
    
    ClassMenu* editMenu = new ClassMenu("\nМеню редактирования");
    editMenu->addMenuItem("Выход"); // 0
    editMenu->addMenuItem("Выберите существующего студента"); // 1
    editMenu->addMenuItem("Создать нового студента"); // 2
    editMenu->addMenuItem("Удалить студента"); // 3
    
    int selectedNum = - 1;
    
    
    while (selectedItem != 0){
        selectedItem = mainMenu->run();
        clean_c();
        switch (selectedItem)
        {
            case 1:
                st->getAllInfoFromFile();
                break;
            case 2:
                while (selectedNum != 0 ) {
                    selectedNum = editMenu->run();
                    switch (selectedNum) {
                        case 1:
                            st->editExistStudent();
                            break;
                        case 2:
                            st->createNewStudent();
                            st->addSt2File();
                            break;
                        case 3:
                            st->deleteStudent();
                            break;
                        default:
                            break;
                    }
                }
                break;
            case 3:
                st->filterStudents();
                //st->Marks();
            deafault:
                break;
        }
    }
}

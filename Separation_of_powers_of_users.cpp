ЗПЗ_1.cpp
За этот год
29 Мар.

Вы загрузили 1 объект
Текст
ЗПЗ_1.cpp
﻿#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#define path "file.txt"
using namespace std;

struct User
{
    string userName;
    string password;
    int passwordLength = password.length();
    bool isBlocked = false;                //признак блокування облікового запису
    bool isPasswordLimit = true;           //признак включення обмежень на вибирані паролі
};

vector<User> users;

void Display();
bool CheckPassword(string password);
void ChangePassword(string password);
void adminMenu(User user);
void userMenu(User user);
void WriteToFile();
void PasswordLimit(User user);
void ListOfLimitedPasswordUsers();
void ListOfUnlimitedPasswordUsers();
void ListOfBlockedUsers();
void ListOfUnblockedUsers();
void BlockUser(User user);
void SignIn();
void SignUp();
void About();
void ShowListOfUsers();
void AddUser();

void ListOfLimitedPasswordUsers() {
    User user;

    bool isExistLimitedPasswordUsers = false;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].isPasswordLimit == false) {
            isExistLimitedPasswordUsers = true;
        }
    }
    if (!isExistLimitedPasswordUsers) {
        cout << "Нет пользователей, которым можно установить ограничение пароля!\n";
        system("pause");
        system("cls");
        return;
    }

    cout << "Выберите пользователя которому хотите поставить ограничения на пароль:\n";
    for (int i = 0; i < users.size(); i++) {
        if (users[i].isPasswordLimit == false) {
            cout << " - " << users[i].userName << endl;
        }
    }
    string command;
    cout << "Введите имя пользователя: ";
    cin >> command;
    for (int i = 0; i < users.size(); i++) {
        if (command == users[i].userName) {
            if (users[i].isPasswordLimit == false) {
                PasswordLimit(users[i]);
                cout << "Пользователю " << users[i].userName << " установлено ограничение на пароль\n";
                system("pause");
                system("cls");
                cout << "Кому-то еще хотите дать ограничение на пароль?\n";
                int choise;
            label_1:
                cout << " (1) Да\n" << " (2) Назад\n";
                cout << "Ваши действия: ";
                cin >> choise;
                switch (choise)
                {
                case 1:
                    system("cls");
                    ListOfLimitedPasswordUsers();
                case 2:
                    system("cls");
                    return;
                default:
                    cout << "Неверная команда\n";
                    system("pause");
                    system("cls");
                    goto label_1;
                    break;
                }
                system("pause");
                system("cls");
                return;
            }
            else {
                system("cls");
                cout << "Такого пользователя нет в списках!\n";
                int choise;
            label_2:
                cout << " (1) Повторить\n" << " (2) Отменить\n";
                cout << "Ваши действия: ";
                cin >> choise;
                switch (choise)
                {
                case 1:
                    system("cls");
                    ListOfLimitedPasswordUsers();
                case 2:
                    system("cls");
                    return;
                default:
                    cout << "Неверная команда\n";
                    system("pause");
                    system("cls");
                    goto label_2;
                    break;
                }
            }
        }
    }
    system("cls");
    cout << "Такого пользователя нет в списках!\n";
    int choise;
label_3:
    cout << " (1) Повторить\n" << " (2) Отменить\n";
    cout << "Ваши действия: ";
    cin >> choise;
    switch (choise)
    {
    case 1:
        system("cls");
        ListOfLimitedPasswordUsers();
    case 2:
        system("cls");
        return;
    default:
        cout << "Неверная команда\n";
        system("pause");
        system("cls");
        goto label_3;
        break;
    }
    system("pause");
}

void ListOfUnlimitedPasswordUsers() {
    User user;

    bool isExistUnlimitedPasswordUsers = false;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].isPasswordLimit == true) {
            isExistUnlimitedPasswordUsers = true;
        }
    }
    if (!isExistUnlimitedPasswordUsers) {
        cout << "Нет пользователей, которым можно снять ограничение пароля!\n";
        system("pause");
        system("cls");
        return;
    }

    cout << "Выберите пользователя которому хотите убрать ограничения на пароль:\n";
    for (int i = 0; i < users.size(); i++) {
        if (users[i].isPasswordLimit == true) {
            cout << " - " << users[i].userName << endl;
        }
    }
    string command;
    cout << "Введите имя пользователя: ";
    cin >> command;
    for (int i = 0; i < users.size(); i++) {
        if (command == users[i].userName) {
            if (users[i].isPasswordLimit == true) {
                PasswordLimit(users[i]);
                cout << "Пользователю " << users[i].userName << " снято ограничение на пароль\n";
                system("pause");
                system("cls");
                cout << "Кому-то еще хотите снять ограничение на пароль?\n";
                int choise;
            label_10:
                cout << " (1) Да\n" << " (2) Назад\n";
                cout << "Ваши действия: ";
                cin >> choise;
                switch (choise)
                {
                case 1:
                    system("cls");
                    ListOfUnlimitedPasswordUsers();
                case 2:
                    system("cls");
                    return;
                default:
                    cout << "Неверная команда\n";
                    system("pause");
                    system("cls");
                    goto label_10;
                    break;
                }
                system("pause");
                system("cls");
                return;
            }
            else {
                system("cls");
                cout << "Такого пользователя нет в списках!\n";
                int choise;
            label_11:
                cout << " (1) Повторить\n" << " (2) Отменить\n";
                cout << "Ваши действия: ";
                cin >> choise;
                switch (choise)
                {
                case 1:
                    system("cls");
                    ListOfUnlimitedPasswordUsers();
                case 2:
                    system("cls");
                    return;
                default:
                    cout << "Неверная команда\n";
                    system("pause");
                    system("cls");
                    goto label_11;
                    break;
                }
            }
        }
    }
    system("cls");
    cout << "Такого пользователя нет в списках!\n";
    int choise;
label_12:
    cout << " (1) Повторить\n" << " (2) Отменить\n";
    cout << "Ваши действия: ";
    cin >> choise;
    switch (choise)
    {
    case 1:
        system("cls");
        ListOfUnlimitedPasswordUsers();
    case 2:
        system("cls");
        return;
    default:
        cout << "Неверная команда\n";
        system("pause");
        system("cls");
        goto label_12;
        break;
    }
    system("pause");
}

void ListOfBlockedUsers() {
    User user;

    bool isExistBlockedUsers = false;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].isBlocked == false && users[i].userName != "admin") {
            isExistBlockedUsers = true;
        }
    }
    if (!isExistBlockedUsers) {
        cout << "Нет пользователей, которых можно заблокировать!\n";
        system("pause");
        system("cls");
        return;
    }

    cout << "Выберите пользователя, которого хотите заблокировать:\n";
    for (int i = 0; i < users.size(); i++) {
        if (users[i].isBlocked == false && users[i].userName != "admin") {
            cout << " - " << users[i].userName << endl;
        }
    }
    string command;
    cout << "Введите имя пользователя: ";
    cin >> command;
    for (int i = 0; i < users.size(); i++) {
        if (command == users[i].userName) {
            if (users[i].isBlocked == false && users[i].userName != "admin") {
                BlockUser(users[i]);
                cout << "Пользователь " << users[i].userName << " заблокирован\n";
                system("pause");
                system("cls");
                cout << "Хотите еще кого-то заблокировать?\n";
                int choise;
            label_7:
                cout << " (1) Да\n" << " (2) Назад\n";
                cout << "Ваши действия: ";
                cin >> choise;
                switch (choise)
                {
                case 1:
                    system("cls");
                    ListOfBlockedUsers();
                case 2:
                    system("cls");
                    return;
                default:
                    cout << "Неверная команда\n";
                    system("pause");
                    system("cls");
                    goto label_7;
                    break;
                }

                system("pause");
                system("cls");
                return;
            }
            else {
                system("cls");
                cout << "Такого пользователя нет в списках!\n";
                int choise;
            label_8:
                cout << " (1) Повторить\n" << " (2) Отменить\n";
                cout << "Ваши действия: ";
                cin >> choise;
                switch (choise)
                {
                case 1:
                    system("cls");
                    ListOfBlockedUsers();
                case 2:
                    system("cls");
                    return;
                default:
                    cout << "Неверная команда\n";
                    system("pause");
                    system("cls");
                    goto label_8;
                    break;
                }
            }
        }
    }
    system("cls");
    cout << "Такого пользователя нет в списках!\n";
    int choise;
    label_9:
    cout << " (1) Повторить\n" << " (2) Отменить\n";
    cout << "Ваши действия: ";
    cin >> choise;
    switch (choise)
    {
    case 1:
        system("cls");
        ListOfBlockedUsers();
    case 2:
        system("cls");
        return;
    default:
        cout << "Неверная команда\n";
        system("pause");
        system("cls");
        goto label_9;
        break;
    }
    system("pause");
}

void ListOfUnblockedUsers() {
    User user;

    bool isExistBlockedUsers = false;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].isBlocked == true) {
            isExistBlockedUsers = true;
        }
    }
    if (!isExistBlockedUsers) {
        cout << "Нет пользователей, которых можно разблокировать!\n";
        system("pause");
        system("cls");
        return;
    }

    cout << "Выберите пользователя, которого хотите разблокировать:\n";
    for (int i = 0; i < users.size(); i++) {
        if (users[i].isBlocked == true) {
            cout << " - " << users[i].userName << endl;
        }
    }
    string command;
    cout << "Введите имя пользователя: ";
    cin >> command;
    for (int i = 0; i < users.size(); i++) {
        if (command == users[i].userName) {
            if (users[i].isBlocked == true && users[i].userName != "admin") {
                BlockUser(users[i]);
                cout << "Пользователь " << users[i].userName << "  разблокирован\n";
                system("pause");
                system("cls");
                cout << "Хотите еще кого-то разблокировать?\n";
                int choise;
            label_10:
                cout << " (1) Да\n" << " (2) Назад\n";
                cout << "Ваши действия: ";
                cin >> choise;
                switch (choise)
                {
                case 1:
                    system("cls");
                    ListOfUnblockedUsers();
                case 2:
                    system("cls");
                    return;
                default:
                    cout << "Неверная команда\n";
                    system("pause");
                    system("cls");
                    goto label_10;
                    break;
                }
                system("pause");
                system("cls");
                return;
            }
            else {
                system("cls");
                cout << "Такого пользователя нет в списках!\n";
                int choise;
            label_11:
                cout << " (1) Повторить\n" << " (2) Отменить\n";
                cout << "Ваши действия: ";
                cin >> choise;
                switch (choise)
                {
                case 1:
                    system("cls");
                    ListOfUnblockedUsers();
                case 2:
                    system("cls");
                    return;
                default:
                    cout << "Неверная команда\n";
                    system("pause");
                    system("cls");
                    goto label_11;
                    break;
                }
            }
        }
    }
    system("cls");
    cout << "Такого пользователя нет в списках!\n";
    int choise;
label_12:
    cout << " (1) Повторить\n" << " (2) Отменить\n";
    cout << "Ваши действия: ";
    cin >> choise;
    switch (choise)
    {
    case 1:
        system("cls");
        ListOfUnblockedUsers();
    case 2:
        system("cls");
        return;
    default:
        cout << "Неверная команда\n";
        system("pause");
        system("cls");
        goto label_12;
        break;
    }
    system("pause");
}

void BlockUser(User user) {
    int index;
    if (!user.isBlocked) {
        user.isBlocked = true;
        for (int i = 0; i < users.size(); i++) {
            if (users[i].userName == user.userName) {
                users.erase(users.begin() + i);
                index = i;
            }
        }
        users.insert(users.begin() + index, user);
    }
    else if (user.isBlocked) {
        user.isBlocked = false;
        for (int i = 0; i < users.size(); i++) {
            if (users[i].userName == user.userName) {
                users.erase(users.begin() + i);
                index = i;
            }
        }
        users.insert(users.begin() + index, user);
    }
}

void PasswordLimit(User user) {
    int index;
    if (!user.isPasswordLimit) {
        user.isPasswordLimit = true;
        for (int i = 0; i < users.size(); i++) {
            if (users[i].userName == user.userName) {
                users.erase(users.begin() + i);
                index = i;
            }
        }
        users.insert(users.begin() + index, user);
    }
    else if (user.isPasswordLimit) {
        user.isPasswordLimit = false;
        for (int i = 0; i < users.size(); i++) {
            if (users[i].userName == user.userName) {
                users.erase(users.begin() + i);
                index = i;
            }
        }
        users.insert(users.begin() + index, user);
    }
}

void ShowListOfUsers() {
    cout << " --- Список пользователей ---\n\n";
    int i = 0;
    for (auto user : users) {
        cout << " (" << ++i << ")" << endl;
        cout << " Имя: \t\t\t" << user.userName << endl 
           //  << " Пароль: \t\t" << user.password << endl 
           //  << " Длина пароля: \t\t" << user.passwordLength << endl 
             << " Ограничения на пароль: " << user.isPasswordLimit << endl 
             << " Блокировка аккаунта: \t" << user.isBlocked << endl << endl;
    }
    system("pause");
    system("cls");
}

void AddUser() {
    cout << " --- Добавить нового пользователя ---\n\n";
    string newUser;
    bool isUserExist = false;
    cout << "Введите имя для нового пользователя: ";
    cin >> newUser;
    for (auto user : users) {
        if (user.userName == newUser) {
            isUserExist = true;
            cout << "Такой пользователь уже существует!\n";
            int command;
            cout << " (1) Повторить\n" << " (2) Отмена\n";
            cout << "Ваши действия: ";
            cin >> command;

            switch (command) {
            case 1:
                system("cls");
                AddUser();
            case 2:
                system("cls");
                return;
            }
        }
    }
    if (!isUserExist) {
        User user;
        user.userName = newUser;
        user.password = "";
        user.passwordLength = user.password.length();
        user.isPasswordLimit = true;
        user.isBlocked = false;
        users.push_back(user);
        cout << "Пользователь " << newUser << " успешно добавлен!\n";
    }
        system("pause");
        system("cls");
}

bool CheckPassword(string password)
{
    string letters = "abcdefghijklmnopqrstuvwxyzабвгдеёжзийклмнопрстуфхцчшщьыъэюяіїє";
    string arifmeticSigns = "+-*/^=";
    bool isContainLetters = false;
    bool isContainArifmeticSigns = false;
    for (int i = 0; i < password.length(); i++) {
        for (int j = 0; j < letters.length(); j++) {
            if (password[i] == letters[j]) {
                isContainLetters = true;
                break;
            }
        }
        for (int j = 0; j < arifmeticSigns.length(); j++) {
            if (password[i] == arifmeticSigns[j]) {
                isContainArifmeticSigns = true;
                break;
            }
        }
        if (isContainLetters && isContainArifmeticSigns) {
            return true;
        }
    }
    system("cls");
    cout << "Пароль должен содержать буквы и знаки арифметических операций!\n";
    return false;
}

void ChangePassword(User user) {
    cout << " --- Изменить пароль ---\n\n";
    if (user.passwordLength != 0) {
        string passwordEnter;
        for (int i = 3; i >= 0; i--) {
            if (i < 3) {
                cout << "осталось попыток: " << i << endl;
            }
            if (i < 1) {
                if (user.userName != "admin") {
                    cout << "Вы 3 раза ввели пароль неверно\nВаш аккаут будет заблокирован!\n";
                    BlockUser(user);
                    system("pause");
                    Display();
                }
                else {
                    cout << "Вы 3 раза ввели пароль неверно!\n";
                   // BlockUser(user);
                    system("pause");
                    Display();
                }
            }
            cout << "Введите старый пароль: ";
            cin >> passwordEnter;
            if (passwordEnter == user.password) {
                break;
            }
            else {
                cout << "Пароль неверный!\n";
            }
        }
    }
    string password_1;
    string password_2;
label_13:
    cout << "Введите новый пароль: ";
    cin >> password_1;
    ///////// нужна проверка на ограничение пароля
    if (user.isPasswordLimit == true) {
        if (CheckPassword(password_1)) {
            cout << "Повторите пароль: ";
            cin >> password_2;
            if (password_1 == password_2) {
                cout << "Пароль успешно изменен!\n";
                user.password = password_1;
                user.passwordLength = user.password.length();
                ///////////////////////////////////////////////
                int index;
                for (int i = 0; i < users.size(); i++) {
                    if (users[i].userName == user.userName) {
                        users.erase(users.begin() + i);
                        index = i;
                    }
                }
                users.insert(users.begin() + index, user);
                ////////////////////////////////////////////
                system("pause");
                system("cls");
            }
            else {
                system("cls");
                cout << "Пароли не совпадают. Повторите пожалуйста попытку\n";
                goto label_13;
            }
        }
        else {
            int command;
            cout << " (1) Повторить\n" << " (2) Отмена\n";
            cout << "Ваши действия: ";
            cin >> command;
            switch (command) {
            case 1:
                system("cls");
                goto label_13;
            case 2:
                system("cls");
                return;
            }
        }
    }
    else {
        cout << "Повторите пароль: ";
        cin >> password_2;
        if (password_1 == password_2) {
            cout << "Пароль успешно изменен!\n";
            user.password = password_1;
            user.passwordLength = user.password.length();
            ///////////////////////////////////////////////
            int index;
            for (int i = 0; i < users.size(); i++) {
                if (users[i].userName == user.userName) {
                    users.erase(users.begin() + i);
                    index = i;
                }
            }
            users.insert(users.begin() + index, user);
            ////////////////////////////////////////////
            system("pause");
            system("cls");
        }
        else {
            system("cls");
            cout << "Пароли не совпадают. Повторите пожалуйста попытку\n";
            goto label_13;
        }
    }
}

void adminMenu(User user) {
    cout << " ** admin **\n\n";
    do {
        cout << "  --Команды--\n";
        cout << " (1) Изменение пароля\n"
             << " (2) Список пользователей\n"
             << " (3) Добавить пользователя без пароля\n"
             << " (4) Заблокировать пользователя\n"
             << " (5) Разблокировать пользователя\n"
             << " (6) Включить ограничения на пароль\n"
             << " (7) Выключить ограничения на пароль\n"
             << " (8) Выход\n";
        int command;
        cout << "Выберите действие: ";
        cin >> command;
        if (command == 1) {
            system("cls");
            ChangePassword(user);
            //////////////////////////////////
            for (int i = 0; i < users.size(); i++) {
                if (users[i].userName == user.userName) {
                    user = users[i];
                }
            }
            //////////////////////////////////
        }
        else if (command == 2) {
            system("cls");
            ShowListOfUsers();
        }
        else if (command == 3) {
            system("cls");
            AddUser();
        }
        else if (command == 4) {
            system("cls");
            ListOfBlockedUsers();
        }
        else if (command == 5) {
            system("cls");
            ListOfUnblockedUsers();
        }
        else if (command == 6) {
            system("cls");
            ListOfLimitedPasswordUsers();
            for (int i = 0; i < users.size(); i++) {
                if (users[i].userName == user.userName) {
                    user = users[i];
                }
            }
        }
        else if (command == 7) {
            system("cls");
            ListOfUnlimitedPasswordUsers();
            for (int i = 0; i < users.size(); i++) {
                if (users[i].userName == user.userName) {
                    user = users[i];
                }
            }
        }
        else if (command == 8) {
            cout << "Выход из системы...\n";
            system("pause");
            system("cls");
            Display();
        }
        else {
            cout << "Неверная команда! Повторите заново!";
            system("pause");
            system("cls");
            adminMenu(user);
        }
    } while (true);

}

void userMenu(User user) {
    cout << " ** " << user.userName << " * *\n\n";
    do {
        cout << "  --Команды--\n";
        cout << " (1) Изменение пароля\n" << " (2) Выход\n";
        int command;
        cout << "Выберите действие: ";
        cin >> command;
        if (command == 1) {
            system("cls");
            ChangePassword(user);
            for (int i = 0; i < users.size(); i++) {
                if (users[i].userName == user.userName) {
                    user = users[i];
                }
            }
        }
        else if (command == 2) {
            cout << "Выход из системы...\n";
            system("pause");
            system("cls");
            Display();
        }
        else {
            cout << "Неверная команда! Повторите заново!";
            system("pause");
            system("cls");
            userMenu(user);
        }
    } while (true);
}

void SignIn() {
    cout << " -- Вход --\n\n";
    string userName;
    string passwordEnter;
    cout << "Введите ваше имя: ";
    cin >> userName;
    for (auto user : users) {
        if (userName == user.userName) {
            if (user.isBlocked == false) {
                if (user.passwordLength != 0) {
                    for (int i = 3; i >= 0; i--) {
                        if (i < 3 && i > 0) {
                            cout << "Повторите попытку еще раз! (осталось попыток): " << i << endl;
                        }
                        if (i < 1) {
                            if (userName != "admin") {
                                cout << "Вы 3 раза ввели пароль неверно\nВаш аккаут будет заблокирован!\n";
                                BlockUser(user);
                                system("pause");
                                system("cls");
                                Display();
                            }
                            else {
                                cout << "Вы 3 раза ввели пароль неверно!\n";
                               // BlockUser(user);
                                system("pause");
                                system("cls");
                                Display();
                            }
                        }
                        cout << "Введите пароль: ";
                        cin >> passwordEnter;
                        if (passwordEnter == user.password) {
                            if (userName == "admin") {
                                cout << "Вы вошли как администратор\n";
                                system("pause");
                                system("cls");
                                adminMenu(user);
                            }
                            else {
                                cout << "Вы вошли как обычный пользователь " << userName << endl;
                                system("pause");
                                system("cls");
                                userMenu(user);
                            }
                            break;
                        }
                        else {
                            cout << "Пароль неверный!\n";
                        }
                    }
                }
                if (userName == "admin") {
                    cout << "Вы вошли как администратор\n";
                    system("pause");
                    system("cls");
                    adminMenu(user);
                }
                else {
                    cout << "Вы вошли как обычный пользователь " << userName << endl;
                    system("pause");
                    system("cls");
                    userMenu(user);
                }
            }
            else {
                cout << "Ваш аккаунт заблокирован! Вы не можете войти\n";
                system("pause");
                Display();
            }
        }
    }
    cout << "Вас нет в списках пользователей, попробуйте повторить вход\n";
    int command;
    cout << " (1) Повторить\n" << " (2) Отмена\n";
    cout << "Ваши действия: ";
    cin >> command;
    switch (command) {
    case 1:
        system("cls");
        SignIn();
    case 2:
        Display();
    }
} 

void About() {
    cout << " -- Справка --\n\n";
    string command;
    do {
        cout << " (0) Выход\n" << " (1) Автор программы\n";
        cout << "Выберите действие: ";
        cin >> command;
        if (command == "1") {
            cout << "Автор:\t студентка III курса Гурджия Валерия, группа ФБ-95\nЗадание: Наявнiсть букв i знакiв арифметичних операцiй.\n";
            system("pause");
            system("cls");
        }
        else if (command == "0") {
            Display();
        }
        else {
            cout << "Неверная команда!\n";
            system("pause");
            system("cls");
        }
    } while (true);
}


void Display() {
    system("cls");
    cout << "  --Меню--\n";
    cout << " (1) Вход\n"
        << " (2) Справка\n"
        << " (3) Завершение работы\n";
    int command;
    cout << "Выберите действие: ";
    cin >> command;
    switch (command) {
    case 1:
        system("cls");
        SignIn();
        break;
    case 2:
        system("cls");
        About();
    case 3:
        cout << "Завершение работы...\n";
        WriteToFile();
        exit(0);
    default:
        cout << "Неверная команда! Повторите еще раз!\n";
        system("pause");
        system("cls");
        Display();
        break;
    }
}

void WriteToFile() {
    User user;
    ofstream fout;
    fout.open(path);
    if (fout.is_open())
    {
        int i = 0;
        for (auto user : users) {
           fout << " (" << ++i << ")" << endl
                << " Имя: \t\t\t" << user.userName << endl
                << " Пароль: \t\t" << user.password << endl
                << " Длина пароля: \t\t" << user.passwordLength << endl
                << " Ограничения на пароль: " << user.isPasswordLimit << endl
                << " Блокировка аккаунта: \t" << user.isBlocked << endl << endl;
        }
    }
    fout.close();
}

int main()
{
    SetConsoleCP(1251);                 // установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);           // установка кодовой страницы win-cp 1251 в поток вывода
    //setlocale(LC_ALL, "ru");

    User admin;
    admin.userName = "admin";
    admin.password = "";
    admin.passwordLength = admin.password.length();
    admin.isPasswordLimit = false;
    admin.isBlocked = false;
    users.push_back(admin);

    Display();
 
    return 0;
}
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

class Human { // Класс-предок
public:
    int age;
    string name;
    Human() : age(0), name("") {
        printf("Human()\n");
    }
    Human(int age, string name) {
        printf("Human(int age, string name)\n");
        this->age = age;
        this->name = name;
    }
    Human(const Human &p) {
        printf("Human(const Human &p)\n");
        age = p.age;
        name = p.name;
    }
    ~Human() {
        printf("~Human() => ");
        cout << "age - " << age << " name - " << name << endl;
    }
    void birthday() {
        age++;
        cout << "Сегодня у " << name << " день рождения. Ему исполнилось " << age << ".\n";
    }
};

class Soldier : Human { // Класс-наследник
public:
    string rank;
    Soldier() : rank("") {
        printf("Soldier()\n");
    }
    Soldier(int age, string name, string rank) : Human(age, name) {
        printf("Soldier(int age, string name, string rang)\n");
        this->rank = rank;
    }
    Soldier(const Soldier& p) :Human(p.age, p.name) {
        printf("Soldier(const Soldier &p)\n");
        rank = p.rank;
    }
    Soldier& operator = (Soldier const& p) {
        printf("Soldier& operator = (Soldier const& p)\n");
        age = p.age;
        name = p.name;
        rank = p.rank;
        return *this;
    }
    ~Soldier() {
        printf("~Soldier() => ");
        cout << "age - " << age << " name - " << name << " rank - " << rank << endl;
    }
    void change_rang(string rank) {
        cout << "Ранг солдата изменён с " << this->rank << " на " << rank << ".\n";
        this->rank = rank;
    }
};

class Squad { // Класс с указателем на класс-наследник
public:
    Soldier* soldiers; // массив класса "солдат"
    int quantity; // количество солдат
    Squad() {
        printf("Squad()\n");
        quantity = 0;
        soldiers = nullptr;
    }
    Squad(int quantity) {
        printf("Squad(int quantity)\n");
        this->quantity = quantity;
        soldiers = new Soldier[quantity];
    }
    Squad(const Squad& p) {
        printf("Squad(const Squad& p)\n");
        quantity = p.quantity;
        soldiers = new Soldier[quantity];
        for (int i = 0; i < quantity; i++)
            soldiers[i] = p.soldiers[i];
    }
    ~Squad() {
        printf("~Squad() => ");
        cout << "quantity - " << quantity << endl;
        delete[]soldiers;
    }
    Soldier& operator [] (int index) {
        printf("Soldier& operator [] (int index)\n");
        return soldiers[index];
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    while (1) {
        system("cls");
        printf("Вывод действий с классами:\n1 - Статический объект Human\n2 - Динамический объект Human\n3 - Статический объект Soldier\n4 - Динамический объект Soldier\n5 - Статический объект Squad\n6 - Динамический объект Squad\n0 - Выход");
        char choice = _getch();
        system("cls");
        if (choice == '1') { // Статический объект Human
            printf("Статический объект Human\n");
            Human h1; // пустой объект
            Human h2(20, "Michael"); // пример со значениями
            Human h3 = h2; // пример с конструктором копирования
            h2.birthday();
        }
        else if (choice == '2') { // Динамический объект Human
            printf("Динамический объект Human\n");
            Human* h1 = new Human(); // пустой объект
            Human* h2 = new Human(25, "Anton"); // объект со значениями
            Human* h3 = new Human(*h2); // пример с конструктором копирования
            h2->birthday();
            delete h1;
            delete h2;
            delete h3;
        }
        else if (choice == '3') { // Статический объект Soldier
            printf("Статический объект Soldier\n");
            Soldier s1; // пустой объект
            Soldier s2(65, "Громов А.А.", "Генерал"); // объект со значениями
            Soldier s3 = s2; // пример с конструктором копирования
            s2.change_rang("Генерал армии");
        }
        else if (choice == '4') { // Динамический объект Soldier
            printf("Динамический объект Soldier\n");
            Soldier* s1 = new Soldier();
            Soldier* s2 = new Soldier(35, "Пирожков Р.Р.", "Майор");
            Soldier* s3 = new Soldier(*s2);
            s2->change_rang("Сержант");
            delete s1;
            delete s2;
            delete s3;
        }
        else if (choice == '5') {
            printf("Статический объект Squad\n");
            Squad s1;
            Squad s2(3);
            s2[0].change_rang("Рядовой");
            s2[1].change_rang("Сержант");
            s2[2].change_rang("Старшина");
            Squad s3 = s2;
        }
        else if (choice == '6') {
            printf("Динамический объект Squad\n");
            Squad *s1 = new Squad();
            Squad *s2 = new Squad(3);
            (*s2)[0].change_rang("Рядовой");
            (*s2)[1].change_rang("Сержант");
            (*s2)[2].change_rang("Старшина");
            Squad *s3 = new Squad (*s2);
            delete s1;
            delete s2;
            delete s3;
        }
        else if (choice == '7') {
            printf("Динамический копирует от статического\n");
            
        }
        else if (choice == '0')
            break;
        _getch();
    }
}
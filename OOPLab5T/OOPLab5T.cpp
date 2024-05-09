#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
    string classification;
    int limbs;
    int offspring;

public:
    // Конструктор за замовчуванням
    Animal() : classification(""), limbs(0), offspring(0) {}

    // Конструктор з параметрами
    Animal(string cls, int limbsCount, int offspringCount) : classification(cls), limbs(limbsCount), offspring(offspringCount) {}

    // Деструктор
    ~Animal() {
        cout << "Animal object is being destroyed" << endl;
    }

    void print() {
        cout << "Classification: " << classification << endl;
        cout << "Number of limbs: " << limbs << endl;
        cout << "Number of offspring: " << offspring << endl;
    }
};

class Pet : public Animal {
private:
    string name;

public:
    // Конструктор за замовчуванням
    Pet() : Animal(), name("") {}

    // Конструктор з параметрами
    Pet(string cls, int limbsCount, int offspringCount, string petName) : Animal(cls, limbsCount, offspringCount), name(petName) {}

    // Деструктор
    ~Pet() {
        cout << "Pet object is being destroyed" << endl;
    }
    void print() {
        Animal::print();
        cout << "Name: " << name << endl;
    }

    // Функція зміни ім'я
    void changeName(string newName) {
        name = newName;
    }

    // Функція зміни числа нащадків
    void changeOffspring(int newOffspring) {
        offspring = newOffspring;
    }

    // Функція отримання ім'я
    string getName() {
        return name;
    }

    // Функція отримання числа нащадків
    int getOffspring() {
        return offspring;
    }
};


class Tail {
private:
    int length;
public:
    Tail(int len) : length(len) {}

    int getLength() const {
        return length;
    }
};

class Dog {
private:
    Tail tail;
    char* color;
    int age;
public:
    Dog(int tailLength, const char* col, int a) : tail(tailLength), age(a) {
        color = new char[strlen(col) + 1];
        strcpy_s(color, strlen(col) + 1, col);
    }

    ~Dog() {
        delete[] color;
    }

    void print() const {
        cout << "Color: " << color << ", Age: " << age << ", Tail Length: " << tail.getLength() << endl;
    }
};

class PublicDog : public Dog {
private:
    char* name;
public:
    PublicDog(int tailLength, const char* col, int a, const char* n) : Dog(tailLength, col, a) {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
    }

    ~PublicDog() {
        delete[] name;
    }

    void print() const {
        cout << "Name: " << name << ", ";
        Dog::print();
    }
};

int main() {
    cout << "Choose a class: (1) Animal, (2) Tail" << endl;
    int choice;
    cin >> choice;

    if (choice == 1) {
        Pet pet("Mammal", 4, 2, "Fido"); 
        cout << "Pet information:" << endl;
        pet.print();

        // Тестування функції зміни ім'я
        pet.changeName("Max");
        cout << "New pet name: " << pet.getName() << endl;

        // Тестування функції зміни числа нащадків
        pet.changeOffspring(6);
        cout << "New number of offspring: " << pet.getOffspring() << endl;
    }
    else if (choice == 2) {
        Dog dog(10, "Brown", 3);
        dog.print();


    }
    
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
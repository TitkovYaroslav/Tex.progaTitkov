#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
    double height;
    double weight;

public:
    Animal(double h, double w) : height(h), weight(w) {}

    virtual void eat() {
        weight += 0.2;
    }

    virtual void sleep() {}

    virtual void get_info() {
        cout << "Рост: " << height << " м\n";
        cout << "Вес: " << weight << " кг\n";
    }

    virtual ~Animal() {}
};

class Hedgehog : public Animal {
private:
    bool curled_up;

public:
    Hedgehog(double h, double w) : Animal(h, w), curled_up(false) {}

    void curl_up() {
        curled_up = true;
    }

    void get_info() override {
        cout << "[Ёжик]\n";
        Animal::get_info();
        if (curled_up) cout << "Сейчас в клубке.\n";
    }
};

class Dolphin : public Animal {
public:
    Dolphin(double h, double w) : Animal(h, w) {}

    void jump_through_ring() {
        cout << "Дельфин пролетел через кольцо!\n";
    }

    void get_info() override {
        cout << "[Дельфин]\n";
        Animal::get_info();
    }
};

class Chameleon : public Animal {
private:
    string color;

public:
    Chameleon(double h, double w, const string& c) : Animal(h, w), color(c) {}

    void change_color(const string& new_color) {
        color = new_color;
    }

    void get_info() override {
        cout << "[Хамелеон]\n";
        Animal::get_info();
        cout << "Цвет: " << color << endl;
    }
};

int main() {
    Hedgehog e(0.25, 1.1);
    Dolphin flipper(1.9, 140);
    Chameleon cam(0.3, 0.6, "зелёный");

    e.eat();
    e.curl_up();

    flipper.jump_through_ring();

    cam.change_color("оранжевый");
    cam.eat();

    e.get_info();
    cout << endl;

    flipper.get_info();
    cout << endl;

    cam.get_info();

    return 0;
}

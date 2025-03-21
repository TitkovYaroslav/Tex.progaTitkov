#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    int age;       
    double score;
    Node* next;
    
    Node(string n, int a, double s, Node* nxt = nullptr) {
        name = n;
        age = a;
        score = s;
        next = nxt;
    }
};

class List {     
public:
    Node* head;
    
    List() : head(nullptr) {}

    void addToFront(string name, int age, double score) {    
        head = new Node(name, age, score, head);
    }
    
    void addToEnd(string name, int age, double score) {  
        Node* newNode = new Node(name, age, score);
        if (!head) {
            addToFront(name, age, score);         
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    void addAfter(string targetName, string name, int age, double score) { 
        Node* temp = head;
        while (temp) {
            if (temp->name == targetName) {
                temp->next = new Node(name, age, score, temp->next);
                return;
            }
            temp = temp->next;
        }
    }
    
    void addBefore(string targetName, string name, int age, double score) {  
        if (!head) return;
        if (head->name == targetName) {
            addToFront(name, age, score);
            return;
        }
        Node* temp = head;
        while (temp->next) {
            if (temp->next->name == targetName) {
                temp->next = new Node(name, age, score, temp->next);
                return;
            }
            temp = temp->next;
        }
    }
    
    void remove(string name) {
        if (!head) return;
        
        if (head->name == name) {  
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            if (temp->next->name == name) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                return;
            }
            temp = temp->next;
        }
    }
    
    void display() {
        for (Node* temp = head; temp; temp = temp->next) {
            cout << "Имя: " << temp->name << ", Возраст: " << temp->age << ", Оценка: " << temp->score << endl; //вывод списка 
        }
    }
};

int main() {
    List list;
    list.addToEnd("Ярослав", 25, 85.5);
    list.addToFront("Ярослав2", 35, 85.5);
    list.addToFront("Эмиль", 30, 90.2);
    list.addAfter("Ярослав", "Анна", 22, 78.3);
    list.addBefore("Ярослав", "Дмитрий", 27, 88.1);
    
    cout << "Список:" << endl;
    list.display();
    
    list.remove("Ярослав");
    cout << "\nПосле удаления Ярослава:" << endl;
    list.display();
    
    return 0;
}

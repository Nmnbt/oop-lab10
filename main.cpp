#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T t) : data(t), next(nullptr) {}
    };
    
    Node* head;
    int size;
    
public:
    LinkedList() : head(nullptr), size(0) {}
    
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
    
    void add(T t) {
        Node* newNode = new Node(t);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }
    
    void insert(T t, int index) {
        if (index < 0 || index > size) throw std::out_of_range("Index out of range");
        Node* newNode = new Node(t);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        size++;
    }
    
    T get(int index) {
        if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
        Node* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->data;
    }
    
    void deleteNode(int index) {
        if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
        Node* temp = head;
        if (index == 0) {
            head = head->next;
            delete temp;
        } else {
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete nodeToDelete;
        }
        size--;
    }
    
    int length() const {
        return size;
    }
};
class Shape {
public:
    virtual double area() const = 0;
    virtual void print() const = 0;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14159 * radius * radius;
    }
    void print() const override {
        std::cout << "Circle with radius " << radius << std::endl;
    }
};

class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override {
        return 0.5 * base * height;
    }
    void print() const override {
        std::cout << "Triangle with base " << base << " and height " << height << std::endl;
    }
};

class Square : public Shape {
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override {
        return side * side;
    }
    void print() const override {
        std::cout << "Square with side " << side << std::endl;
    }
};

int main() {
    srand(time(0));
    LinkedList<Shape*> shapes;
    
    int numShapes = 20 + rand() % 11; // Random number between 20 and 30
    for (int i = 0; i < numShapes; ++i) {
        int shapeType = rand() % 3;
        switch (shapeType) {
            case 0:
                shapes.add(new Circle(1 + rand() % 10)); // Radius between 1 and 10
                break;
            case 1:
                shapes.add(new Triangle(1 + rand() % 10, 1 + rand() % 10)); // Base and height between 1 and 10
                break;
            case 2:
                shapes.add(new Square(1 + rand() % 10)); // Side between 1 and 10
                break;
        }
    }
    
    std::vector<Shape*> shapeVector;
    for (int i = 0; i < shapes.length(); ++i) {
        shapeVector.push_back(shapes.get(i));
    }
    
    std::sort(shapeVector.begin(), shapeVector.end(), [](Shape* a, Shape* b) {
        return a->area() < b->area();
    });
    
    for (Shape* shape : shapeVector) {
        shape->print();
        std::cout << "Area: " << shape->area() << std::endl;
    }
    
    for (int i = 0; i < shapes.length(); ++i) {
        delete shapes.get(i);
    }
    
    return 0;
}

#include <iostream>

template<typename T>
class List {
private:
    T* elements; // Элементүүдийг хадгалж буй массив
    int capacity; // Массивын хэмжээ
    int size; // Жагсаалтын хэмжээ
public:
    List() : capacity(10), size(0) {
        elements = new T[capacity];
    }

    ~List() {
        delete[] elements;
    }

    // Element nemeh
    void add(T element) {
        if (size >= capacity) {
            T* temp = new T[2 * capacity];
            for (int i = 0; i < size; ++i) {
                temp[i] = elements[i];
            }
            delete[] elements;
            elements = temp;
            capacity *= 2;
        }
        elements[size++] = element;
    }

    // Element oruulah
    void insert(T element, int index) {
        if (index < 0 || index > size) {
            std::cout << "Invalid index\n";
            return;
        }
        if (size >= capacity) {
            // Массивын хэмжээг 2 дахин дэлгэцнээс хэрэглэж өсгөх
            T* temp = new T[2 * capacity];
            for (int i = 0; i < size; ++i) {
                temp[i] = elements[i];
            }
            delete[] elements;
            elements = temp;
            capacity *= 2;
        }
        // Элементийг оруулж, эцсийн хувилбара нэмэх
        for (int i = size - 1; i >= index; --i) {
            elements[i + 1] = elements[i];
        }
        elements[index] = element;
        ++size;
    }

    // Element avah
    T get(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Invalid index\n";
            return T();
        }
        return elements[index];
    }

    // Element delete
    void remove(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Invalid index\n";
            return;
        }
        // Элементийг устгахад эцсийн хувилбара цуцлана
        for (int i = index; i < size - 1; ++i) {
            elements[i] = elements[i + 1];
        }
        --size;
    }

    // Жагсаалтын уртыг буцаах
    int length() {
        return size;
    }
};

int main() {
    // Int tei list uusgej uzjine
    List<int> Ints;

    // Элемент нэмэх
    Ints.add(1);
    Ints.add(2);
    Ints.add(3);
    Ints.add(4);
    Ints.add(5);
    Ints.add(6);
    Ints.add(7);
    Ints.add(8);

    //remove hiij uzjine
    Ints.remove(3);

    // printlej uzeh
    for (int i = 0; i < 5; i++){
        std::cout << Ints.get(i) << std::endl;
    };
    
    //Хэдэн элемент байгааг хэвлэх
    std::cout << Ints.length() << std::endl;

    // element avj uzjine listnii 1 index deer bgga elementiig ni
    std::cout << Ints.get(1) << std::endl;





    //Stringtei list uusgej uzjine
    List<std::string> Strings;
    
    Strings.add("Balanced");
    Strings.add("as");
    Strings.add("all");
    Strings.add("things");
    Strings.add("should");
    Strings.add("be");

    for (int i = 0; i < 6; i++){
        std::cout << Strings.get(i) << std::endl;
    };




    return 0;
}

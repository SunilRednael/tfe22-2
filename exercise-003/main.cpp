#include <fmt/chrono.h>
#include <fmt/format.h>

#include "vectorint.hpp"
 #include <iostream>

 template <typename T>
class MyVector {
private:
    T* data;
    size_t capacity;
    size_t current_size;

public:
    // Konstruktor
    MyVector() : data(nullptr), capacity(0), current_size(0) {}

    // Destruktor
    ~MyVector() {
        clear();
    }

    // Methode zum Hinzufügen eines Elements ans Ende des Vektors
    void push_back(const T& value) {
        if (current_size == capacity) {
            size_t new_capacity = (capacity == 0) ? 1 : 2 * capacity;
            reserve(new_capacity);
        }
        data[current_size] = value;
        current_size++;
    }

    // Methode zum Zugriff auf ein Element an einer bestimmten Position
    T& at(size_t index) {
        if (index < current_size) {
            return data[index];
        }
        throw std::out_of_range("Index out of range");
    }

    // Methode zur Rückgabe der aktuellen Größe des Vektors
    size_t size() const {
        return current_size;
    }

    // Methode zum Ändern der Größe des Vektors
    void resize(size_t new_size) {
        if (new_size < current_size) {
            current_size = new_size;
        } else if (new_size > current_size) {
            if (new_size > capacity) {
                reserve(new_size);
            }
            while (current_size < new_size) {
                data[current_size] = T();
                current_size++;
            }
        }
    }

    // Methode zum Löschen aller Elemente im Vektor
    void clear() {
        delete[] data;
        data = nullptr;
        capacity = 0;
        current_size = 0;
    }

private:
    // Methode zur Reservierung von Speicherplatz
    void reserve(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < current_size; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
};

auto main(int argc, char **argv) -> int
{
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, World!\n");

 {
    MyVector<int> myVector;
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);

    std::cout << "Size: " << myVector.size() << std::endl;

    myVector.resize(5);
    std::cout << "Size after resizing: " << myVector.size() << std::endl;

    myVector.clear();
    std::cout << "Size after clearing: " << myVector.size() << std::endl;

    return 0;
}

    VectorInt data(20);

    return 0; /* exit gracefully*/
}



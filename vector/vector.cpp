#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <sstream>
#include <string>

/*
MyVector Class Implementation
A custom vector class template that provides dynamic array functionality.

1. Basic Member Functions:
   - Constructor: Initialize vector instance
   - Destructor: Clean up resources to prevent memory leaks
   - Copy Constructor: Create new instance from existing MyVector
   - Copy Assignment Operator: Enable assignment between MyVector instances

2. Core Functions:
   - push_back: Add element to the end
   - size: Return current number of elements
   - capacity: Return total number of elements that can be stored
   - Element Access: Access element at specified index
   - Insert: Insert element at specified position
   - Pop Back: Remove element from the end
   - Clear: Remove all elements and reset state

3. Iteration and Traversal:
   - Iterator Support: Enable traversal from beginning to end
   - Print Elements: Traverse and print all elements using iterator

4. Advanced Features:
   - Dynamic Growth: Automatically expand capacity when more space is needed

Author: [Your Name]
Date: January 27, 2025
*/

template <typename T>
class MyVector {
private:
    T* data_;
    size_t size_;
    size_t capacity_;

public:
    // basic member functions
    MyVector() : data_(nullptr), size_(0), capacity_(0) {}
    MyVector(size_t initialCap) : data_(new T[initialCap]), size_(0), capacity_(initialCap) {}
    ~MyVector() { delete[] data_; }

    //copy constructor
    MyVector(const MyVector& other) : capacity_(other.capacity_), size_(other.size_) { 
        data_ = new T[capacity_];
        for (size_t i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
    }

	//copy assignment operator
    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = new T[capacity_];
            for (size_t i = 0; i < size_; i++) {
                data_[i] = other.data_[i];
            }
        }
        return *this;
    }

	// core functions
    void push_back(const T& data) {
        if (size_ == capacity_) {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        data_[size_++] = data;
    }

    size_t getSize() const { return size_; }
    size_t getCapacity() const { return capacity_; }

	// element access
    T& operator[](size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range!");
        }
        return data_[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range!");
        }
        return data_[index];
    }

    void insert(size_t index, const T& value) {
        if (index > size_) {
            throw std::out_of_range("Index out of range!");
        }
        if (size_ == capacity_) {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        for (size_t i = size_; i > index; i--) {
            data_[i] = data_[i - 1];
        }
        data_[index] = value;
        size_++;
    }

    void pop_back() {
        if (size_ == 0) {
            throw std::out_of_range("Cannot pop_back from empty vector!");
        }
        size_--;
    }

    void clear() { size_ = 0; }

    T* begin() { return data_; }
    const T* begin() const { return data_; }
    T* end() { return data_ + size_; }
    const T* end() const { return data_ + size_; }

    void print() {
        for (size_t i = 0; i < size_; i++) {
            std::cout << data_[i] << " ";
        }
        std::cout << std::endl;
    }

	// dynamic growth
    void reserve(size_t newCapacity) {
        if (newCapacity > capacity_) {
            T* newData = new T[newCapacity];
            for (size_t i = 0; i < size_; i++) {
                newData[i] = data_[i];
            }
            delete[] data_;
            data_ = newData;
            capacity_ = newCapacity;
        }
    }
};



int main() {
	// test MyVector class
    MyVector<int> vector;
    int n;
	std::cin >> n;
	getchar();//skip the newline character
	
    std::string line;
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, line);
		std::istringstream iss(line);
		std::string command;
		iss >> command;

        if (command == "push") { 
			int value;
            iss >> value;
			vector.push_back(value);
        }
		else if (command == "insert") { // insert index value
			int index, value;
			iss >> index >> value;
            vector.insert(index, value);
        }
		else if (command == "pop") {
			vector.pop_back();
		}
        else if (command == "size") {
			std::cout << "size of vector is: " << vector.getSize() << std::endl;
        }
        else if (command == "capacity") {
			std::cout << "capacity of vector is: " << vector.getCapacity() << std::endl;
        }
        else if (command == "print") {
			if (vector.getSize() == 0) {
				std::cout << "vector is empty" << std::endl;
			}
            else {
                std::cout << "print vector elements: ";
                vector.print();
            }
        }
        else if (command == "get") {
			int index;
			iss >> index;
            if (index >= vector.getSize()) {
				std::cout << "index out of range" << std::endl;
            }
			std::cout << "element at index " << index << " is: " << vector[index] << std::endl;
        }
        else if (command == "clear") {
			vector.clear();
        }
        else if (command == "copy") {
			MyVector<int> copy = vector;
			std::cout << "copy vector elements: ";
			copy.print();
        }
        else if (command == "iterator") {
			std::cout << "print vector elements using iterator: ";
			for (auto it = vector.begin(); it != vector.end(); it++) {
				std::cout << *it << " ";
			}
			std::cout << std::endl;
        }
		else if (command == "exit") {
			break;
		}
    }

	//boundary test
 //   try {
 //       vector[-1];
	//}
	//catch (const std::out_of_range& e) {
	//	std::cout << e.what() << std::endl;
	//}

 //   try {
 //       vector.insert(vector.getSize() + 1, 100);
 //   }
 //   catch (const std::out_of_range e) {
	//	std::cout << e.what() << std::endl;
 //   }



	return 0;
}

#include <iostream>
#include "src.hpp"

int main() {
    int **p = nullptr;

    // Test 1: Initialize 3 vectors
    Init(p, 3);
    std::cout << "Initialized 3 vectors" << std::endl;

    // Test 2: Add elements
    Add_element(p, 1, 10);
    Add_element(p, 1, 20);
    Add_element(p, 1, 30);
    std::cout << "Added 3 elements to vector 1" << std::endl;

    Add_element(p, 2, 100);
    Add_element(p, 2, 200);
    std::cout << "Added 2 elements to vector 2" << std::endl;

    // Test 3: Get elements
    std::cout << "Vector 1[1]: " << Get_element(p, 1, 1) << " (expected 10)" << std::endl;
    std::cout << "Vector 1[2]: " << Get_element(p, 1, 2) << " (expected 20)" << std::endl;
    std::cout << "Vector 1[3]: " << Get_element(p, 1, 3) << " (expected 30)" << std::endl;
    std::cout << "Vector 2[1]: " << Get_element(p, 2, 1) << " (expected 100)" << std::endl;
    std::cout << "Vector 2[2]: " << Get_element(p, 2, 2) << " (expected 200)" << std::endl;

    // Test 4: Add more elements to trigger reallocation
    for(int i = 0; i < 10; i++){
        Add_element(p, 3, i * 10);
    }
    std::cout << "Added 10 elements to vector 3" << std::endl;

    std::cout << "Vector 3[1]: " << Get_element(p, 3, 1) << " (expected 0)" << std::endl;
    std::cout << "Vector 3[5]: " << Get_element(p, 3, 5) << " (expected 40)" << std::endl;
    std::cout << "Vector 3[10]: " << Get_element(p, 3, 10) << " (expected 90)" << std::endl;

    // Clean up
    Clear(p, 3);
    std::cout << "Cleaned up all vectors" << std::endl;

    return 0;
}

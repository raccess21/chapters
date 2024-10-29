#include <iostream>
using namespace std;

int main() {
    int age;
    int *page = &age;
    age = 10;
    cout << *page;

    
}
#include <iostream>
using std::cout;

// uses ANSI escape sequences; H to move cursor at home; 2J to clear screen;

int main(){
    cout << "\033[H" << "\033[2J";
}
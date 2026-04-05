#include <iostream>
#include <filesystem>
using std::cout;


// will needa use filing in this

int main(int argc, char* argv[]){
    if (argc == 1){
        cout << "[!] Expected 1+ arguments, got 0. :(";
    }
    else{
        cout << std::filesystem::;
    }
    
    cout << '\n';
}
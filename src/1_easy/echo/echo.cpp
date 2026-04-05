#include <iostream>
#include <filesystem>
using std::cout;


int main(int argc, char* argv[]){
    for (auto arg {1}; arg < argc; ++arg){
        cout << argv[arg];
        cout << " ";
    }
    
    cout << '\n';
}
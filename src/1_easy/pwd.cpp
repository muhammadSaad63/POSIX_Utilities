#include <iostream>
#include <filesystem>
using std::cout;


int main(int argc, char* argv[]){
    if (argc == 1){
        cout << std::filesystem::current_path().string();
    }
    else{
        cout << "[!] Expected 0 arguments, got " << (argc - 1) << " :(";
    }
    
    cout << '\n';
}
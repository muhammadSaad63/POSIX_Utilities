#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
using std::cout;


int main(int argc, char* argv[]){
    if (argc == 1){
        cout << "[!] Expected 1 argument, got " << (argc - 1) << ". :(\n";
    }
    else{
        std::filesystem::path path = argv[1];

        if (!std::filesystem::exists(path)){
            cout << "[!] wc: failed to wordcount '" << path.string() << "': file doesn't exist.\n";
            return 0;
        }
        
        if (!std::filesystem::is_regular_file(path)){
            cout << "[!] wc: failed to wordcount '" << path.string() << "': Arg is not a file.\n";
            return 0;
        }

        std::ifstream file(path);
        if (file.is_open()){
            std::string line;

            while (std::getline(file, line)){
                cout << line << '\n';
            }
        }
    }
}
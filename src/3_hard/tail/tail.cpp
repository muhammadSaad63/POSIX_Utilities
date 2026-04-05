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
            cout << "[!] tail: failed to access '" << path.string() << "': file doesn't exist.\n";
            return 0;
        }
        
        if (!std::filesystem::is_regular_file(path)){
            cout << "[!] tail: failed to access '" << path.string() << "': Arg is not a file.\n";
            return 0;
        }

        std::ifstream file(path);
        if (file.is_open()){
            std::string line;

            auto totalLines {0};
            while (std::getline(file, line)){
                totalLines++;
            }

            file.clear();
            file.seekg(0, std::ios::beg);           // reset file pointer to start of fiel
    
            if (totalLines <= 10){
                while (std::getline(file, line)){
                    cout << line << '\n';
                }
            }
            else{
                auto currLine {0};
                while (std::getline(file, line)){
                    currLine++;
                    
                    if ((totalLines - currLine) < 10){
                        cout << line << '\n';
                    }
                }
            }
        }
    }
}
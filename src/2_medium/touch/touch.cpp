#include <fstream>
#include <iostream>
#include <filesystem>
using std::cout;


int main(int argc, char* argv[]){
    if (argc == 1){
        cout << "[!] Expected atleast 1 argument, got 0. :(\n";
    }
    else{
        std::filesystem::path path;
        
        for (auto arg {1}; arg < argc; ++arg){
            path = argv[arg];
        
            if (std::filesystem::exists(path)){
                continue;
            }
            
            if (std::filesystem::is_directory(path)){
                cout << "[!] touch: failed to touch '" << path.string() << "': Arg is not a file.\n";
                continue;
            }

            std::ofstream file(path);
            
            if (file.is_open()){
                file.close();
            }
        }
    }
}
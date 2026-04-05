#include <iostream>
#include <filesystem>
using std::cout;


int main(int argc, char* argv[]){
    if (argc < 3){
        cout << "[!] Expected atleast 2 arguments, got " << (argc - 1) << ". :(\n";
    }
    else{
        const std::filesystem::path dest = argv[argc - 1];
        if (!std::filesystem::exists(dest)){
            cout << "[!] mv: failed to move to '" << dest.string() << "': No such file or directory\n";
            return 0;
        }

        std::filesystem::path src;
        for (auto arg {1}; arg < (argc - 1); ++arg){
            src = argv[arg];
            
            if (!std::filesystem::exists(src)){
                cout << "[!] mv: failed to move '" << src.string() << "': No such file or directory\n";
                continue;
            }

            std::filesystem::rename(src, dest);
        }
    }
}
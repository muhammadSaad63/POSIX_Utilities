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

            if (!std::filesystem::exists(path)){
                cout << "rmdir: failed to remove '" << path.string() << "': No such file or directory\n";
                continue;;
            }

            if (!std::filesystem::is_empty(path)){
                cout << "rmdir: failed to remove '" << path.string() << "': Directory not empty\n";
                continue;
            }

            std::filesystem::remove(path);
        }
    }
}
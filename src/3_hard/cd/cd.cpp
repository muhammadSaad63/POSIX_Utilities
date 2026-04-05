#include <iostream>
#include <filesystem>
using std::cout;


int main(int argc, char* argv[]){
    if (argc != 2){
        cout << "[!] Expected 1 argument, got " << (argc - 1) << ". :(\n";
    }
    else{
        std::filesystem::path path = argv[argc - 1];

        if (!std::filesystem::exists(path)){
            cout << "rmdir: failed to change directory to '" << path.string() << "': No such directory\n";
            return 0;
        }
        if (!std::filesystem::is_directory(path)){
            cout << "rmdir: failed to change directory to '" << path.string() << "': Dest is not a directory\n";
            return 0;
        }

        std::filesystem::current_path(path);
    }
}
#include <iostream>
#include <filesystem>
using std::cout;


void ls(const std::filesystem::path& path){
    for (const std::filesystem::path& obj : std::filesystem::directory_iterator(path)){
        cout << obj.filename().string() << ((std::filesystem::is_directory(obj))? '/' : '*') << "   ";
    }
    
    cout << "\n";
}


int main(int argc, char* argv[]){
    if (argc == 1){
        ls(std::filesystem::current_path());
    }
    else{
        bool printFileName {false};
        if (argc > 2){ printFileName = true; }

        std::filesystem::path path;

        for (auto arg {1}; arg < argc; ++arg){
            path = argv[arg];

            if (!std::filesystem::exists(path)){
                cout << "[!] ls: cannot access '" << path.string() << "': No such file or directory\n";
                continue;
            }

            if (printFileName){ cout << path.string() << ": \n\t"; }
            ls(path);
        }
    }
}   
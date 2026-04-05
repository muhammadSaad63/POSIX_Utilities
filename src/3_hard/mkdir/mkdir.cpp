#include <iostream>
#include <filesystem>
using std::cout;


// will needa use filing in this

int main(int argc, char* argv[]){
    if (argc == 1){
        cout << "[!] Expected atleast 1 argument, got 0. :(\n";
    }
    else{
        std::filesystem::path path;

        for (auto arg {1}; arg < argc; ++arg){
            path = argv[arg];

            if (!exists(path)){
                std::filesystem::path currDir;

                for (auto& dir : path){                                 // iterates through each dir/node in path
                    currDir /= dir;
                    std::filesystem::create_directory(currDir);         // :D made on me own alhadmulillah
                }
            }
        }
    }
}
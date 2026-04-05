#include <pwd.h>
#include <iostream>
#include <unistd.h>
using std::cout;


int main(){
    auto uid = getuid();
    struct passwd* pw = getpwuid(uid);

    cout << pw->pw_name << '\n';
}
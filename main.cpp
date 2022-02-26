#include "inc/main.h"


int main(int argc, char* argv[]) {
    char* srcPath;
    char* scanPath;
    char* shellPath;

    parseCommandLineArgs(argc, argv, &srcPath, &scanPath, &shellPath);



    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void parseCommandLineArgs(int argc, char* argv[], char** srcPath, char** scanPath, char** shellPath) {
    *srcPath = nullptr;
    *scanPath = nullptr;

    for(int i = 2; i < argc; i++) {
        if(strcmp(argv[i-1], "--source") == 0) {
            *srcPath = argv[i];
        } else if(strcmp(argv[i-1], "--scan") == 0) {
            *scanPath = argv[i];
        } else if(strcmp(argv[i-1], "--shell") == 0) {
            *shellPath = argv[i];
        }
    }
}

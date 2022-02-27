//
// Created by Daniel on 2/26/2022.
//

#include "inc/main.h"
#include "inc/filescanner.h"

int main(int argc, char* argv[]) {
    char* srcPath;
    char* scanPath;
    char* outputPath;

    parseCommandLineArgs(argc, argv, &srcPath, &scanPath, &outputPath);

    if(srcPath == nullptr || scanPath == nullptr || outputPath == nullptr) {
        showHelp();
        return 0;
    }

    FileScanner fs = FileScanner(string(srcPath), string(scanPath));
    auto duplicates = fs.Scan();
    auto spaceSaved = FileScanner::PrintShellScript(duplicates, outputPath);

    printf("Written duplicate-removal shell script to '%s'\n", outputPath);
    printf("Total Potential Space Savings: %.2f GB\n", (double) spaceSaved * BYTES_TO_GB);

    return 0;
}

// parse command-line arguments
void parseCommandLineArgs(int argc, char* argv[], char** srcPath, char** scanPath, char** outputPath) {
    *srcPath = nullptr;
    *scanPath = nullptr;
    *outputPath = nullptr;

    for(int i = 2; i < argc; i++) {
        if(strcmp(argv[i-1], "--source") == 0) {
            *srcPath = argv[i];
        } else if(strcmp(argv[i-1], "--scan") == 0) {
            *scanPath = argv[i];
        } else if(strcmp(argv[i-1], "--output") == 0) {
            *outputPath = argv[i];
        }
    }
}

// show the help menu
void showHelp() {
    printf("Usage: spacelink --source <path> --scan <path> --output <file name>\n\n");
    printf("Locate duplicate files in SCAN by checking inodes of files with the same size located in SOURCE\n");
    printf("Outputs a shell script to file OUTPUT containing commands to run that can eliminate all duplicate files using hardlinks\n");
}
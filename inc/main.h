//
// Created by Daniel on 2/26/2022.
//

#ifndef SPACELINK_MAIN_H
#define SPACELINK_MAIN_H

#include <iostream>
#include <cstring>

#define BYTES_TO_GB 0.000000001

void parseCommandLineArgs(int argc, char* argv[], char** srcPath, char** scanPath, char** outputPath);
void showHelp();

#endif //SPACELINK_MAIN_H

//
// Created by Daniel on 2/26/2022.
//

#ifndef SPACELINK_FILESCANNER_H
#define SPACELINK_FILESCANNER_H

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <unordered_map>

using namespace std;

struct MyFile {
    filesystem::path originalFilePath;
    uintmax_t fileSize;
    ino_t fileInode;
};

class FileScanner {
private:
    string source;
    string target;

    static ino_t getInode(const char* path);
public:
    FileScanner(string source, string target);

    unordered_map<string, pair<string, uintmax_t>> Scan();
    static uintmax_t PrintShellScript(const unordered_map<string, pair<string, uintmax_t>>& duplicates, const string& fileName);
};


#endif //SPACELINK_FILESCANNER_H

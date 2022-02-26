//
// Created by Daniel on 2/26/2022.
//

#ifndef SPACELINK_FILESCANNER_H
#define SPACELINK_FILESCANNER_H

#include <iostream>
#include <string>

using namespace std;

class FileScanner {
private:
    string source;
    string target;
public:
    FileScanner(string source, string target);

    void Scan();
};


#endif //SPACELINK_FILESCANNER_H

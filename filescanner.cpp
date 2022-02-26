//
// Created by Daniel on 2/26/2022.
//

#include "inc/filescanner.h"

#include <utility>

FileScanner::FileScanner(string source, string target) {
    source = std::move(source);
    target = std::move(target);
}

void FileScanner::Scan() {

}


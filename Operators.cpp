

//
// Created by Дмитрий on 20.10.2021.
//

#include "Operations.h"

void readfile::run(std::vector<std::string> *in, std::vector<std::string> *out) {

    std::ifstream file (in_file_name);
    std::string line;

    if(file.is_open()){
        while(getline(file,line)){
            out->push_back(line);
        }
    }
    file.close();
}

readfile::readfile(std::string file_name) {
    in_file_name=(file_name);
}


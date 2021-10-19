#include <iostream>
#include "Worker.h"
#include <map>


int main() {

    std::map<int,std::vector<std::string>> blocks;
    std::vector<Worker> workers = ParseWorkers("D:\\CLion 2021.2.1\\MyProjects\\Factorio\\input.txt",blocks);

   for (auto& c : workers){
       c.run();
   }
    return 0;
}

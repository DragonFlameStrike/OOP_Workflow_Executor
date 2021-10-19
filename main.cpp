#include <iostream>
#include "Worker.h"
#include <map>


int main() {

    std::map<int,std::vector<std::string>> blocks;
    std::vector<Worker> workers = ParseWorkers("input.txt",blocks);

   for (auto& c : workers){
       c.run();
   }
    return 0;
}

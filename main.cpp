#include <iostream>
#include "Worker.h"
#include "ParseWorkers.h"
#include <map>
#include <memory>

int main() {

    std::map<int,std::vector<std::string>> blocks;
    std::vector<std::shared_ptr<Worker>> workers = ParseWorkers(R"(D:\CLion_2021.2.1\MyProjects\lab_2\input.txt)",blocks);
    std::vector<std::vector<std::string>> vin;
    std::vector<std::vector<std::string>> vout;
    for (auto& c : workers){

        c->run(vin, vout);
    }
    return 0;
}

#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <iterator>
#include "Worker.h"
#include "Operators.h"
#include <memory>
#ifndef LAB_2_PARSEWORKERS_H
#define LAB_2_PARSEWORKERS_H
void create_worker(const std::string& name,std::map<int,std::vector<std::string>> blocks,int number, std::vector<std::shared_ptr<Worker>> &workers){
        if(name=="readfile"){
            auto Operator = std::make_shared<Readfile>(blocks[number][3]);
            workers.push_back(Operator);
        }
}
std::vector<std::shared_ptr<Worker>> ParseWorkers (const std::string& filename,std::map<int,std::vector<std::string>> blocks){
    std::vector<std::shared_ptr<Worker>> workers;
    std::ifstream file (filename);
    std::string line;

    if(file.is_open()){

        bool flag_desc=false,flag_csed=false;
        while(getline(file,line)){

            if(line=="desc"){
                flag_desc=true;
                continue;
            }
            if(line=="csed"){
                flag_csed=true,flag_desc=false;
                continue;
            }
            if(flag_desc){
                std::istringstream ss(line);
                std::istream_iterator<std::string> begin(ss), end;

                //putting all the tokens in the vector
                std::vector<std::string> arrayTokens(begin, end);
                int number=std::stoi(arrayTokens[0]);
                blocks[number]=arrayTokens;
            }
            if(flag_csed){
                //take number
                //Who i'm (Operator)
                //Create Operator with args
                std::istringstream ss(line);
                std::istream_iterator<std::string> begin(ss), end;
                //putting all the tokens in the vector
                std::vector<std::string> arrayTokens(begin, end);
                for(int i=0;i<=arrayTokens.size();i+=2){
                    int number=std::stoi(arrayTokens[i]);//take number
                    std::string operator_name = blocks[number][2]; // Operator name by key
                    create_worker( operator_name,blocks, number,workers); // Create Object_Operator with data
                }
            }
            else {
                //error
            }
        }
    }
    file.close();
    return workers;
}

#endif //LAB_2_PARSEWORKERS_H

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
        if(blocks[number].size()==4) {
            auto Operator = std::make_shared<Readfile>(blocks[number][3]);
            workers.push_back(Operator);
        }
        else throw std::string("readfile arguments is wrong\n");

    }
    else if(name=="writefile"){
        if(blocks[number].size()==4) {
            auto Operator = std::make_shared<Writefile>(blocks[number][3]);
            workers.push_back(Operator);
        }
        else throw std::string("writefile arguments is wrong\n");
    }
    else if(name=="sort"){
        auto Operator = std::make_shared<Sort>();
        workers.push_back(Operator);
    }
    else if(name=="grep"){
        if(blocks[number].size()==5) {
            auto Operator = std::make_shared<Grep>(blocks[number][4]);
            workers.push_back(Operator);
        }
        else throw std::string("grep arguments is wrong\n");
    }
    else if(name=="replace"){
        if(blocks[number].size()==5) {
            auto Operator = std::make_shared<Replace>(blocks[number][3], blocks[number][4]);
            workers.push_back(Operator);
        }
        else throw std::string("replace arguments is wrong\n");
    }
    else if(name=="dump"){
        if(blocks[number].size()==4) {
            auto Operator = std::make_shared<Dump>(blocks[number][3]);
            workers.push_back(Operator);
        }
        else throw std::string("dump arguments is wrong\n");
    }
    else throw name + std::string(" realization not found");

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
                flag_csed=true;
                continue;
            }

            if(flag_desc && !flag_csed){
                try{
                    if(line.size()<3){
                        throw -1;
                    }
                }
                catch (int ex) {
                    if(line.empty()){
                        throw std::string("Line in \"") + filename + std::string("\" is empty:\n");
                    }
                    throw std::string("This line in \"") + filename + std::string("\" is wrong:\n")+line;
                }
                std::istringstream ss(line);
                std::istream_iterator<std::string> begin(ss), end;

                //putting all the tokens in the vector
                std::vector<std::string> arrayTokens(begin, end);
                int number;
                try{

                    number=std::stoi(arrayTokens[0]);
                }

                catch(const std::exception&  ex){
                    throw std::string("This line in \"") + filename + std::string("\" is wrong:\n") + line;
                }
                auto search = blocks.find(number);
                if (search != blocks.end()) {
                    throw std::string("This line in \"") + filename + std::string("\" is wrong(redefinition operator):\n") + line;
                } else {
                    blocks[number]=arrayTokens;
                }


            }
            else if(flag_csed){
                //take number
                //Who i'm (Operator)
                //Create Operator with args
                std::istringstream ss(line);
                std::istream_iterator<std::string> begin(ss), end;
                //putting all the tokens in the vector
                std::vector<std::string> arrayTokens(begin, end);
                for(int i=0;i<arrayTokens.size();i+=2){
                    int number;
                    try{
                        number=std::stoi(arrayTokens[i]);
                    }
                    catch(const std::exception&  ex){
                        throw std::string("This line in \"") + filename + std::string("\" is wrong:\n") + line;
                    }
                    //take number
                    auto search = blocks.find(number);
                    if (search != blocks.end()) {
                        std::string operator_name = blocks[number][2];// Operator name by key
                        create_worker( operator_name,blocks, number,workers);// Create Object_Operator with data
                    } else {
                        throw std::string("Operator under the number ") + arrayTokens[i] +std::string(" not found");
                    }


                }
            }
            else {
                throw std::string("This line in \"") + filename + std::string("\" is wrong:\n") + line;
            }
        }
    }
    else{
        throw std::string("File is not open!");
    }
    file.close();
    return workers;
}

#endif //LAB_2_PARSEWORKERS_H

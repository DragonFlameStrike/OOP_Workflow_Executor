#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <iterator>

#ifndef FACTORIO_WORKER_H
#define FACTORIO_WORKER_H

class Worker {
public:


    void run(){};
};

std::vector<Worker> ParseWorkers (const std::string& filename,std::map<int,std::vector<std::string>> blocks){
    std::vector<Worker> workers;
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
                std::istringstream ss(line);
                std::istream_iterator<std::string> begin(ss), end;
                //putting all the tokens in the vector
                std::vector<std::string> arrayTokens(begin, end);
                for(int i=0;i<=arrayTokens.size();i+=2){
                    workers.push_back(arrayTokens[i]);
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



#endif //FACTORIO_WORKER_H

#include <string>
#include <vector>
#include "Worker.h"
#ifndef LAB_2_OPERATORS_H
#define LAB_2_OPERATORS_H

class Readfile: public Worker{
private:
    std::string in_file_name;
public:


    explicit Readfile(std::string file_name):in_file_name(file_name){};

    virtual void run(std::vector<std::string> *in,std::vector<std::string> *out) override {
            std::cout<<in_file_name<<std::endl;
    }

};
class Writefile:Worker{
private:
    std::string out_file_name;
public:
    virtual void run(std::vector<std::string> *in,std::vector<std::string> *out){} //override
};
class Grep:Worker{
private:
    std::string word;
    std::string in_file_name;
public:
    virtual void run(std::vector<std::string> *in,std::vector<std::string> *out) {  }
};
class Sort:Worker{
private:
    std::string in_file_name;
    std::string out_file_name;
public:
    virtual void run(std::vector<std::string> *in,std::vector<std::string> *out) {  }
};
class Replace:Worker{
private:
    std::string word_1;
    std::string word_2;
    std::string in_file_name;
    std::string out_file_name;
public:
    virtual void run(std::vector<std::string> *in,std::vector<std::string> *out) {}
};
class Dump:Worker{
private:
    std::string in_file_name;
public:
    virtual void run(std::vector<std::string> *in,std::vector<std::string> *out){}
};
#endif //LAB_2_OPERATORS_H



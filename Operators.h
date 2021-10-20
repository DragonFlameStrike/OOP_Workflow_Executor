//
// Created by Дмитрий on 20.10.2021.
//

#ifndef OOP_WORKFLOW_EXECUTOR_OPERATIONS_H
#define OOP_WORKFLOW_EXECUTOR_OPERATIONS_H

#include <string>
#include <vector>
#include "Worker.h"


class readfile:Worker{
private:
    std::string in_file_name;
public:
    readfile(std::string file_name);

    void run(std::vector<std::string> *in,std::vector<std::string> *out) override;
};
class writefile:Worker{
private:
    std::string out_file_name;
public:
    void run(std::vector<std::string> *in,std::vector<std::string> *out) override;
};
class grep:Worker{
private:
    std::string word;
    std::string in_file_name;
public:
    void run(std::vector<std::string> *in,std::vector<std::string> *out) override;
};
class sort:Worker{
private:
    std::string in_file_name;
    std::string out_file_name;
public:
    void run(std::vector<std::string> *in,std::vector<std::string> *out) override;
};
class replace:Worker{
private:
    std::string word_1;
    std::string word_2;
    std::string in_file_name;
    std::string out_file_name;
public:
    void run(std::vector<std::string> *in,std::vector<std::string> *out) override;
};
class dump:Worker{
private:
    std::string in_file_name;
public:
    void run(std::vector<std::string> *in,std::vector<std::string> *out) override;
};
#endif //OOP_WORKFLOW_EXECUTOR_OPERATIONS_H






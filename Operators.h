#include <string>
#include <vector>
#include "Worker.h"
#include <algorithm>
#ifndef LAB_2_OPERATORS_H
#define LAB_2_OPERATORS_H




class Readfile: public Worker{
private:
    std::string in_file_name;
public:
    explicit Readfile(std::string file_name):in_file_name(file_name){};
    virtual void run(std::vector<std::vector<std::string>> &in,std::vector<std::vector<std::string>> &out) override {
        std::ifstream in_file (in_file_name);
        std::string line;

        if(in_file.is_open()){

            while(getline(in_file,line)){

                std::istringstream ss(line);
                std::istream_iterator<std::string> begin(ss), end;
                //putting all the tokens in the vector
                std::vector<std::string> arrayTokens(begin, end);
                in.push_back(arrayTokens);

            }
        }
        else{
            throw std::string("File is not open! \n")+in_file_name;
        }
        in_file.close();
    }
};
class Writefile: public Worker{
private:
    std::string out_file_name;
public:
    explicit Writefile(std::string file_name):out_file_name(file_name){};
    virtual void run(std::vector<std::vector<std::string>> &in,std::vector<std::vector<std::string>> &out) override {

        std::ofstream out_file(out_file_name);
        for(auto & string : in){
            for(auto & word : string){
                out_file << word << " ";
            }
            out_file << "\n";
        }
        out_file.close();
    }
};
class Grep: public Worker{
private:
    std::string word;
public:
    explicit Grep(std::string word) : word(word) {};
    virtual void run(std::vector<std::vector<std::string>> &in,std::vector<std::vector<std::string>> &out) override {

        for(auto & string : in) {
            bool word_not_exist=true;
            for (auto & this_word : string) {
                if(this_word==word){
                    word_not_exist=false;
                }
            }
            if(word_not_exist){
                out.push_back(string);
            }

        }
        in=out;
    }
}; //save string only with word
class Sort: public Worker{
public:
    explicit Sort()= default;;
    virtual void run(std::vector<std::vector<std::string>> &in,std::vector<std::vector<std::string>> &out) override {

        for(auto & string : in) {
            std::sort(string.begin(), string.end());
        }
    }
}; //sort tokens
class Replace: public Worker{
private:
    std::string word_1;
    std::string word_2;
public:
    explicit Replace(std::string word1,std::string word2) : word_1(word1),word_2(word2) {};
    virtual void run(std::vector<std::vector<std::string>> &in,std::vector<std::vector<std::string>> &out) override {
        for(auto & string : in) {

            for (auto & word : string) {
                if(word==word_1){
                    word=word_2;
                }
            }
            out.push_back(string);

        }
        in=out;
    }
};
class Dump: public Worker{
private:
    std::string out_file_name;
public:
    explicit Dump(std::string file_name):out_file_name(file_name){};
    virtual void run(std::vector<std::vector<std::string>> &in,std::vector<std::vector<std::string>> &out) override {
        std::ofstream out_file(out_file_name);
        for(auto & string : in){
            for(auto & word : string){
                out_file << word << " ";
            }
            out_file << "\n";
        }
        out_file.close();
    }
};




#endif //LAB_2_OPERATORS_H

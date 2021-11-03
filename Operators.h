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
        for(int i=0;i<in.size();i++){
            for(int j=0;j<in[i].size();j++){
                out_file << in[i][j] << " ";
            }
            out_file << "\n";
        }
        out_file.close();
    }
};
class Grep: public Worker{
private:
    std::string word;
    std::string in_file_name;
public:
    explicit Grep(std::string file_name,std::string word) : in_file_name(file_name) ,word(word) {};
    virtual void run(std::vector<std::vector<std::string>> &in,std::vector<std::vector<std::string>> &out) override {

        for(int i=0;i<in.size();i++) {
            bool word_not_exist=true;
            for (int j = 0; j < in[i].size(); j++) {
                if(in[i][j]==word){
                    word_not_exist=false;
                }
            }
            if(word_not_exist){
                out.push_back(in[i]);
            }

        }
        in=out;
    }
}; //save string only with word
class Sort: public Worker{
public:
    explicit Sort(){};
    virtual void run(std::vector<std::vector<std::string>> &in,std::vector<std::vector<std::string>> &out) override {

        for(int i=0;i<in.size();i++) {
            std::sort(in[i].begin(), in[i].end());
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
        for(int i=0;i<in.size();i++) {

            for (int j = 0; j < in[i].size(); j++) {
                if(in[i][j]==word_1){
                    in[i][j]=word_2;
                }
            }
            out.push_back(in[i]);

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
        for(int i=0;i<in.size();i++){
            for(int j=0;j<in[i].size();j++){
                out_file << in[i][j] << " ";
            }
            out_file << "\n";
        }
        out_file.close();
    }
};




#endif //LAB_2_OPERATORS_H

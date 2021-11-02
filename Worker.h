#include <vector>
#ifndef LAB_2_WORKER_H
#define LAB_2_WORKER_H
class Worker {
public:
     virtual void run(std::vector<std::string> *in,std::vector<std::string> *out) {};
};
#endif //LAB_2_WORKER_H


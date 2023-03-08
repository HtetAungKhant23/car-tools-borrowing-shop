#include <iostream>
using namespace std;

class Categories{
public:
    string automotive_tools[5];
    string hand_tools[5];
    string cordless_tools[5];
    string diagnostic_tools[3];

    void cat_data();
};

class Data_base:public Categories{
public:
    string name;
    string ph_num;
    string nrc;
    string tool;
    int amount;

    void customer_info();

};

void Categories::cat_data() {

    automotive_tools[1] = "socket sets";

}

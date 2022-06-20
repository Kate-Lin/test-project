#include "application.hpp"
#include "json.h"
#include <iostream>
using std::cin;
using std::cout;
using std::string;

int add_key(std::string id,std::string key, std::string &out_json)
{
    Json::Value val1;
    Json::FastWriter writer1;
    Json::Reader reader1;
    //生成json，存储添加的密钥
    val1["action"] = "add_key";
    val1["id"] = id;
    val1["key"] = key;
    out_json.clear();
    out_json.append(writer1.write(val1));
    return 0;
}


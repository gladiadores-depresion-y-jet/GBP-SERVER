//
// Created by dcamachog1501 on 09/03/19.
//


#include "JSONManager.h"
#include <algorithm>
#include <boost/property_tree/json_parser.hpp>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <string>
using namespace std;

using boost::property_tree::ptree;

JSONManager::JSONManager()
{

}
string JSONManager::toJSON(string entrada)
{
    ptree output;
    ptree data;
    vector<string> elementos;
    boost::split(elementos, entrada, boost::is_any_of("$"));

    for (int i = 0; i < elementos.size(); i++)
    {
        vector<string> toAdd;
        boost::split(toAdd, elementos[i], boost::is_any_of("@"));
        output.put(toAdd[0],toAdd[1]);
        //data.push_back(make_pair("",element));
    }
    //output.add_child("Data",data);

    std::ostringstream buf;
    write_json (buf, output, false);
    std::string json = buf.str();
    cout<<json<<endl;
    return json;
}
ptree JSONManager::toPtree(string s) {

    std::istringstream iss(s);
    ptree document;
    read_json(iss, document);
    return document;
}

string JSONManager::askFor(string JSON,string llave)
{
    ptree p= toPtree(JSON);
    string v=p.get<string>(llave);
    return v;
}

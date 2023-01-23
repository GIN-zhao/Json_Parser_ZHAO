/**
 *  Autor: zhao
 *  Date: 2023-1-22
 *  order: json_parser
 */
#include "myjson.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
using namespace My;

void TestWriteJsonFile(const string &path)
{
    ofstream writeFile;
    writeFile.open(path, ios::out);
    if (writeFile.is_open())
    {
        cout << "\nTEST 3 WRITE JSON" << endl;
        // write
        MyJson wjson;
        wjson["name"].Set("liergou");
        wjson["age"].Set(26);
        wjson["handsome"].Set(true);

        MyJson subjson;
        subjson["love1"].Set("book");
        subjson["love2"].Set(666);

        MyJson subjson2;
        subjson2["love1"].Set("book2");
        subjson2["love2"].Set(6662);

        wjson["data"].Set(subjson);
        wjson["data2"].Set(subjson2);

        string str = wjson.WriteJson();
        writeFile << str;
    }
    else
    {
        cout << "fail to open the file";
        return;
    }

    writeFile.close();
}

void TestReadJsonFile(const string &path)
{
    ifstream readFile;
    readFile.open(path, ios::in);
    string test_string = "";
    if (readFile.is_open())
    {

        string str;
        while (getline(readFile, str))
        {
            test_string += str;
        }
    }
    else
    {
        cout << "fail to open the file" << endl;
    }
    readFile.close();
    MyJson json;
    json.ReadJson(test_string);

    string one = json.Get<string>("1");
    string two = json.Get<string>("2");
    string three = json.Get<string>("3");
}

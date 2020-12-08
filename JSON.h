/**
* \class JSON
*
* \Author Alfak
*
* Last time code was modified: 2020/12/07
*
* Created on: 2020/12/07 15:02
*/

#ifndef JSON_H
#define JSON_H

#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <string>
#include <variant>
#include <regex>

/**
* In this class we can see the input reading from .json files.
* The functions are explained further in JSON.cpp.
*/

class JSON {
private:
    std::map <std::string, std::variant<std::string, int, double>> data;
public:
    
    class ParseException : public std::runtime_error
    {
    public:
       ParseException(const std::string& e) : std::runtime_error("Something error went wrong...\n" + e) {}
    };
         JSON(std::map <std::string, std::variant<std::string, int, double>> data) : data(data) {}
   
    /// This function goes through the content of the file.
    static const JSON parseContent(std::istream& file);
    
    /// This function checks if the file is readalbe.
    static const JSON parseFromFile(const std::string& jsonFilePath);
    
    /// This function checks the file structure.
    static const JSON loadInputFromString(std::string data);

    template<typename T> T get(const std::string& key)
    {
        if (!count(key)) throw ParseException("Perhaps the key dose not exist.");
        else return std::get<T>(data[key]);
    }
         const int count(const std::string& key);
};

#endif 
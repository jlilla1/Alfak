
#ifndef JSON_H
#define JSON_H

#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <string>
#include <variant>
#include <regex>

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
   
    static const JSON parseContent(std::istream& file);
    
    static const JSON parseFromFile(const std::string& jsonFilePath);
    
    static const JSON loadInputFromString(std::string data);

    template<typename T> T get(const std::string& key)
    {
        if (!count(key)) throw ParseException("Perhaps the key dose not exist.");
        else return std::get<T>(data[key]);
    }
         const int count(const std::string& key);
};

#endif 
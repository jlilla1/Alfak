/**
* \class JSON
*
* \author Alfak
*
* Last time code was modified: 2020/12/10
*
* Created on: 2020/12/10 16:00
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
#include <list>

/**
* In this class we can see the input reading from .json files.
* The functions are explained further in JSON.cpp.
*/

class JSON {
public:
    typedef std::variant<std::string, int, double> variantValues;
    typedef std::list<variantValues> list;
    typedef std::variant<std::string, int, double, list> listedVariantValues;
    std::map <std::string, listedVariantValues> data;
private:

public:
   
    class ParseException : public std::runtime_error
    {
    public:
        ParseException(const std::string& e) : std::runtime_error("error\n" + e) {}
    };
         JSON(std::map <std::string, listedVariantValues> data) : data(data) {}
    

    /// This function goes through the content of the file and transforms it into a string. It forwards the string to loadInputFromString.
    static const JSON parseContent(std::istream& file);
    
    /// This function checks if the file is readalbe. It forwars the data to parseContent.
    static const JSON parseFromFile(const std::string& jsonFilePath);
    
    /// This function checks the keys in the string and returns the values of the keys.
    static const JSON loadInputFromString(std::string data);

    /// This method gets a list as input and returns the data from it.
    static list parseArray(const std::string& listData);
    static variantValues parseValues(const std::string& data);

    /// The template waits for a string as parameter which will be the key. It checks if there is a key in the data, if the answer is yes it returns the data member associated with the key.
    template<typename T> T get(const std::string& key)
    {
        if (!count(key)) throw ParseException("key error");
        else return std::get<T>(data[key]);
    }
         /// This part checks wether the key is in the data. If it is it returns 1 if not than it returns 0.
         const int count(const std::string& key);

    template <class... Args>
    struct variant_cast_proxy
    {
        std::variant<Args...> v;

        template <class... ToArgs>
        operator std::variant<ToArgs...>() const
        {
            return std::visit(
                [](auto&& arg) -> std::variant<ToArgs...> { return arg; },
                v);
        }
    };

    template <class... Args>
    static auto variant_cast(const std::variant<Args...>& v) -> variant_cast_proxy<Args...>
    {
        return { v };
    }
};

#endif 
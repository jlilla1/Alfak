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
    
    static const JSON parseContent(std::istream& file);
    
    static const JSON parseFromFile(const std::string& jsonFilePath);
    
    static const JSON loadInputFromString(std::string data);

    static list parseArray(const std::string& listData);
    static variantValues parseValues(const std::string& data);

    template<typename T> T get(const std::string& key)
    {
        if (!count(key)) throw ParseException("key error");
        else return std::get<T>(data[key]);
    }
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
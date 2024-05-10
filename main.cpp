#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <boost/algorithm/string.hpp>


// #include <locale>   // locale
// #include <codecvt>  // codecvt_utf8_utf16, codecvt_utf8

// template <size_t bits, std::codecvt_mode mode>
// struct codecvt_utf8_wchar_impl;

// // реализация для Windows: wchar_t - 16-бит, UTF-16
// template <std::codecvt_mode mode>
// struct codecvt_utf8_wchar_impl<16, mode> {
//     using type = std::codecvt_utf8_utf16<wchar_t, 0x10FFFF, mode>;
// };

// // реализация для текущей OS
// template <std::codecvt_mode mode>
// using codecvt_utf8_wchar = typename codecvt_utf8_wchar_impl<sizeof(wchar_t) * 8, mode>::type;

enum class ElementType {
    Node,
    Way,
    Relation
};

class MapElement {
public:
    int id;
    ElementType type;
    std::unordered_map<std::string,std::string> tags;
    MapElement(int id, ElementType type) : id(id), type(type){}
};

class Node : public MapElement {
public:
    double latitude;
    double longitude;
    Node(int id ,const std::vector<std::string>& attr) : MapElement(id, ElementType::Node){
        if(attr.size()<2)
            throw std::runtime_error("Invalid node format, ID: "+std::to_string(id));
        this->latitude=std::stod(attr[0]);
        this->longitude=std::stod(attr[1]);

        //tag handling
        for (const auto& it : attr){
            if(it[0]!='#')
                continue;
            std::size_t found = it.find_first_of("=");
            if(found == std::string::npos)
                throw std::runtime_error("Invalid node format, ID: "+std::to_string(id));
            std::string key = it.substr(1,found-1);
            std::string value = it.substr(found+1);
            tags.insert({key,value});
        }
    }
};

class Way : public MapElement {
public:
    std::vector<int> nodes;
    Way(int id ,const std::vector<std::string>& attr) : MapElement(id, ElementType::Way){
        for (const auto& it : attr){
            if(it[0]=='n'){
                nodes.push_back(std::stoi(it.substr(1)));
            } else if(it[0]=='#') { //tag handling
                std::size_t found = it.find_first_of("=");
                if(found == std::string::npos)
                    throw std::runtime_error("Invalid way format, ID: "+std::to_string(id));
                std::string key = it.substr(1,found-1);
                std::string value = it.substr(found+1);
                tags.insert({key,value});
            }
        }
    }
};

class Relation : public MapElement {
public:
    struct Member {
        ElementType type;
        int id;
        std::string role;
    public:
        Member(ElementType type, int id, const std::string& role) : type(type), id(id), role(role){}
    };

    std::vector<Member> members;
    Relation(int id ,const std::vector<std::string>& attr) : MapElement(id, ElementType::Relation){
        for (const auto& it : attr){
            if(it[0]=='n' || it[0]=='w'){
                int member_id = std::stoi(it.substr(1));
                std::string member_role;
                std::size_t found = it.find_first_of("=");
                if(found != std::string::npos)
                    member_role = it.substr(found+1);
                ElementType member_type = (it[0]=='n') ? ElementType::Node : ElementType::Way;
                members.emplace_back(member_type,member_id,member_role);
            } else if(it[0]=='#') { //tag handling
                std::size_t found = it.find_first_of("=");
                if(found == std::string::npos)
                    throw std::runtime_error("Invalid relation format, ID: "+std::to_string(id));
                std::string key = it.substr(1,found-1);
                std::string value = it.substr(found+1);
                tags.insert({key,value});
            }
        }
    }
};

class MapElementFactory {
public:
    std::shared_ptr<MapElement> createElement(const std::string& line) {
        std::vector<std::string>attr;
        boost::split(attr, line, boost::is_any_of("\t"));
        if(attr.empty()) throw std::runtime_error("Invalid line");
        std::string first_str = attr[0];
        attr.erase(attr.begin());

        int id = stoi(first_str.substr(1));

        switch (first_str[0]) {
        case 'n':
            return std::make_shared<Node>(id,attr);
            break;
        case 'w':
            return std::make_shared<Way>(id,attr);
            break;
        case 'r':
            return std::make_shared<Relation>(id,attr);
            break;
        default:
            throw std::runtime_error("Invalid value");
        }
    }
};

int main() {
    std::string filename = "D:\\repos\\cpp\\Patterns4course\\factorypattern\\data.tsv";
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return 1;
    }

    std::vector<std::shared_ptr<MapElement>> elements;
    MapElementFactory factory;

    try {
        std::string line;
        while (getline(file, line)) {
            elements.emplace_back(factory.createElement(line));
        }
    } catch (std::runtime_error ex){
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    file.close();
    return 0;
}

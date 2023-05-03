#include <iostream>
#include "./include/ImmutableString.hpp"

std::unordered_map<std::string, std::shared_ptr<ImString>> ImString::__stringMap;


int main() {
    auto str1 = ImString::getImString("Hello");
    auto str2 = ImString::getImString("Hello");

    //check address of both string should be same
    std::cout<<"Address one: "<<str1.get()<<std::endl;
    std::cout<<"Address two: "<<str2.get()<<std::endl;
    if(str1 == str2){
        std::cout<<"Both are same\n";
    } 

    //Access the character using []
    for(int i=0;i<str1->size(); i++) {
        std::cout<<(*(str1.get()))[i]<<"\t";
    }
    std::cout<<std::endl;

    {
        auto str3 = str2;
        std::cout<<"Address of str3: "<<str3.get()<<std::endl;
    }
    return 0;
}
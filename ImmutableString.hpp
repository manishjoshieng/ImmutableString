#pragma once

#include<unordered_map>
#include <memory>
#include <string>

using namespace std;

class ImString{

    public:

        //copy constructor
        ImString(ImString* other){
            if(other == nullptr) return;
            if(this->_mString ) {
                throw;
            }
            this->_mString = std::move(other->_mString);
        }

        static shared_ptr<ImString> getImString(const char* stringValue){
            string key(stringValue);
            auto itr = ImString::__stringMap.find(key);
            if (itr == ImString::__stringMap.end()) {
                ImString::__stringMap[key] = make_shared<ImString>(new ImString(key));
                
            }
            shared_ptr<ImString> newPtr(ImString::__stringMap[key]);
            return newPtr;
        }

        static shared_ptr<ImString> getImString(const string& stringValue){
            return ImString::getImString(stringValue.c_str());
        }

        const char operator [] (int index){
           if (_mString->size() < index || index < 0) __throw_out_of_range;
           return (*_mString)[index];
        }

        friend ostream& operator << (ostream& out, const ImString& imString){
            out << (*(imString._mString));
        }

        const char* c_str() {  return (*_mString).c_str(); }
        
        unsigned int size() { return (*_mString).size();}

        ~ImString() {cout<<"Object destructed\n";}

    private:

        //constructor
        ImString(const char* stringValue) : 
        _mString(new string(stringValue)){cout<<"Object constructed\n";}

        ImString(const string& stringValue) : 
        _mString(new string(stringValue)){cout<<"Object constructed\n";}



        //Data
        static unordered_map<string, shared_ptr<ImString>> __stringMap;
        
        unique_ptr<std::string> _mString;
};


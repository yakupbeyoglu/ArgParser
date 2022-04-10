#include <map>
#include "Argument.h"

namespace ArgumentParser {
    
    class Arguments {
        template <typename T>
        bool Add(std::string key, T value) {
            if(IsExist(key))
                return false;
            arguments.insert({key, Argument({value})});
            return true;
        }
        
        template<typename T>
        T GetValue(std::string key) {
            if(!IsExist(key))
                throw std::runtime_error("Can not return not existing key : " + key);
            return arguments[key].GetValue<T>();
        }
        
        bool IsExist(std::string key) {
            if(arguments.find(key) != arguments.end())
                return true;
            return false;
        }
        
        bool Delete(std::string key) {
            if(!IsExist(key))
                return false;
            arguments.erase(key);
            return true;
        }
        
    private:
        std::map<std::string, Argument> arguments;
    }
    
}

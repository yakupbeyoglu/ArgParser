#ifndef ARGUMENTS_H
#define ARGUMENTS_H
#include <memory>
#include <map>
#include "Value.h"

namespace ArgumentParser {
    
    class KeyStore {
    public:
        KeyStore() {
        }
        
        template <typename T>
        void Add(std::string key, T value) {
            if(IsExist(key))
                throw std::runtime_error(key + " is already exist in the argument list");
            store.insert(std::make_pair(key, new Value(value)));
        }
        
        template<typename T>
        T GetValue(std::string key) {
            if(!IsExist(key))
                throw std::runtime_error("Can not return not existing key : " + key);
            return store[key]->GetValue<T>();
        }
        
        bool IsExist(std::string key) {
            if(store.find(key) != store.end())
                return true;
            return false;
        }
        
        void Delete(std::string key) {
            if(!IsExist(key))
                throw std::runtime_error(key + " is not existing in the argument list" );
            auto &value = store[key];
            store.erase(key);
        }
        
    private:
        std::map<std::string, std::unique_ptr<Value>> store;
    };
    
}
#endif

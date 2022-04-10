#ifndef ARGUMENT_H
#define ARGUMENT_H
#include <any>
#include <iostream>
namespace ArgumentParser {
    
 enum class Types {
    String = 0,
    Int,
    Float,
    
};

class Value { 
public:
    template<typename T>
    Value(T value) : value(value) {
        
    }
    
    ~Value() {
            std::cout << "Value is deleted" << std::endl;
    }
    
    
    // delete copy constructor to make read only
    Value (Value const &argument) {
        value = argument.value;
    }
    
    Value& operator = (Value const &argument) {
            value = argument.value;
            return *this;
    }
    
    Value (Value &&) = delete;
    Value& operator = (Value const &&) = delete;
    
    
    // Get value with given type, if any cast error occurs, any_cast will throw bad_cast !
    template<class T>
    T GetValue() {
        return std::any_cast<T>(value);
    }
    
private:
    std::any value;
};   

}
#endif

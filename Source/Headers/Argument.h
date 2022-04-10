#include <any>
namespace ArgumentParser {
    
 enum class Types {
    String = 0,
    Int,
    Float,
    
};

struct Argument { 
    
    template<class T>
    operator T(){
        return std::any_cast<T>(value);
    }
    
    template<class T>
    T GetValue() {
        return std::any_cast<T>(value);
    }

    std::any value;
};   

}

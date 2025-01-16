#ifndef Resource_hpp
#define Resource_hpp

#include <stdio.h>
#include <iostream>
#include <algorithm>


template <typename T>
class Resource{
private:
    T* beginning;
    T* end;
public:
    // Default constructor
    Resource() = delete;
    
    // Constructor to initizlize an object with certain size
    Resource(size_t size) : beginning(new T[size]), end(beginning + size){}
    
    // Constructor to copy data from an array into a new resource
    Resource(const T* source, size_t size) : Resource(size){
        std::copy(source, source + size, beginning);
    }
    
    // Copy constructor
    Resource(const Resource& source) : Resource(source.beginning, source.size()){}
    
    // Destructor
    ~Resource(){
        delete[] beginning;
    }
    
    
    T* get_begin(){
        return beginning;
    }
    
    T* get_end(){
        return end;
    }
    
    size_t size() const {
        return end - beginning;
    }
};
#endif /* Resource_hpp */

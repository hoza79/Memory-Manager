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
protected:
    void swap(Resource& source){
        std::swap(source.beginning, beginning);
        std::swap(source.end, end);
    }
public:
    // Default constructor
    Resource() = delete;
    
    // Constructor to initizlize an object with certain size
    explicit Resource(size_t size) : beginning(new T[size]), end(beginning + size){}
    
    // Constructor to copy data from an array into a new resource
    Resource(const T* source, size_t size) : Resource(size){
        std::copy(source, source + size, beginning);
    }
    
    // Copy constructor
    Resource(const Resource& source) : Resource(source.beginning, source.size()){}
    
    // Move constructor
    Resource(Resource&& source) : beginning(nullptr), end(nullptr){
        swap(source);
    }
    
    // Copy assignment operator
    Resource& operator = (const Resource& source){
        Resource copy = source;
        swap(copy);
        return *this;
    }
    
    // Destructor
    ~Resource(){
        delete[] beginning;
    }
    
    
    // Pointer to the beginning of the dynamically allocated memory
    T* get_begin() const{
        return beginning;
    }
    
    // Pointer to the end of the dynamically allocated memory
    T* get_end() const{
        return end;
    }
    
    // The size of the resource
    size_t size() const {
        return end - beginning;
    }
    
    // Operator[]
    T& operator[](size_t index){
        return beginning[index];
    }
    
    // Operator[] const version
    const T& operator[](size_t index) const{
        return beginning[index];
    }
};
#endif /* Resource_hpp */

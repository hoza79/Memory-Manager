#include <iostream>
#include "Resource.hpp"
#include <random>

int main(int argc, const char * argv[]) {
    // Generating some random numbers to fill in the new resource
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dis(1,100000);
    
    // Testing the constructor that initizlizes an object with certain size
    Resource<int> new_resource(10);
    for(int i = 0; i < new_resource.size(); i++){
        int random_number = dis(mt);
        new_resource[i] = random_number;
    }
    std::cout << "Testing the constructor that initizlizes an object with certain size \n";
    for(auto it = new_resource.get_begin(); it!= new_resource.get_end(); it++){
        std::cout << *it << " ";
    }
    std::cout << "\n";
    
    
    // Testing the constructor that copies data from an array into a new resource
    int numbers[] = {1,2,3,4,5};
    Resource <int> new_copy(numbers, 5);
    for(auto it = new_copy.get_begin(); it!= new_copy.get_end(); it++){
        std::cout << *it << " ";
    }
    std::cout << "Testing the constructor that copies data from an array into a new resource \n";


    // Testing the copy constructor
    Resource new_res(new_resource);
    for(auto it = new_res.get_begin(); it!= new_res.get_end(); it++){
        std::cout << *it << " ";
    }
    std::cout << "Testing the copy constructor \n";
    
    // Testing the assingment operator
    Resource<int> res3(5);
    Resource<int> res4(5);
    for(int i = 0; i < res4.size(); i++){
        int random_number = dis(mt);
        res4[i] = random_number;
    }
    std::cout << "Testing the assingment operator \n";
    std::cout << "res4 \n";
    for(auto it = res4.get_begin(); it!= res4.get_end(); it++){
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "\n";

    res3 = res4;
    std::cout << "res3" << "\n";
    for(auto it = res3.get_begin(); it!= res3.get_end(); it++){
        std::cout << *it << " ";
    }
    std::cout << "\n";
    
  
    return 0;
}

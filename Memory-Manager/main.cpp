#include <iostream>
#include "Resource.hpp"
#include <random>

int main(int argc, const char * argv[]) {
    int numbers[] = {1,2,3,4,5};
    Resource <int> res(numbers, 5);
    for(auto it = res.get_begin(); it!= res.get_end(); it++){
        std::cout << *it << " ";
    }
    std::cout << "\n";
    Resource new_res(res);
    for(auto it = new_res.get_begin(); it!= new_res.get_end(); it++){
        std::cout << *it << " ";
    }
    std::cout << "\n";

    

    
    return 0;
}

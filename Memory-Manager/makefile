run: main.o Resource.o 
	clang++ -std=c++17 main.o Resource.o -o run 

main.o: main.cpp
	clang++ -std=c++17 -c main.cpp 

Resource.o: Resource.cpp
	clang++ -std=c++17 -c Resource.cpp Resource.hpp

clean:
	rm *.o run

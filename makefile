#https://www.youtube.com/watch?v=aw9wHbFTnAQ&t=1079s
CXX = g++
CXXFLAGS = -std=c++11 -fno-stack-protector -pedantic -g -Wall -c

rise: main.o Game.o Fighter.o Ninja.o Space.o MercenaryShop.o \
		Asia.o Americas.o Europe.o Champions.o Validation.o
	$(CXX) main.o Game.o Fighter.o Ninja.o Space.o MercenaryShop.o \
		   Asia.o Americas.o Europe.o Champions.o Validation.o -o rise

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

Game.o: Game.hpp Game.cpp
	$(CXX) $(CXXFLAGS) Game.cpp

Fighter.o: Fighter.hpp Fighter.cpp
	$(CXX) $(CXXFLAGS) Fighter.cpp

Ninja.o: Ninja.hpp Ninja.cpp
	$(CXX) $(CXXFLAGS) Ninja.cpp

Space.o: Space.hpp Space.cpp
	$(CXX) $(CXXFLAGS) Space.cpp

MercenaryShop.o: MercenaryShop.hpp MercenaryShop.cpp
	$(CXX) $(CXXFLAGS) MercenaryShop.cpp

Asia.o: Asia.hpp Asia.cpp
	$(CXX) $(CXXFLAGS) Asia.cpp

Americas.o: Americas.hpp Americas.cpp
	$(CXX) $(CXXFLAGS) Americas.cpp

Europe.o: Europe.hpp Europe.cpp
	$(CXX) $(CXXFLAGS) Europe.cpp

Champions.o: Champions.hpp Champions.cpp
	$(CXX) $(CXXFLAGS) Champions.cpp

Validation.o: Validation.cpp Validation.hpp
	$(CXX) $(CXXFLAGS) Validation.cpp

zip:
	zip FinalProject_Vega_David.zip -D *.cpp *.hpp *.pdf makefile

clean:
	rm *.o rise
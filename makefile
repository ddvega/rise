#https://www.youtube.com/watch?v=aw9wHbFTnAQ&t=1079s
CXX = g++
CXXFLAGS = -std=c++11 -fno-stack-protector -pedantic -g -Wall -c

rise: main.o Game.o Fighter.o Gru.o Space.o MercenaryShop.o \
		ChineseSop.o Seal.o Sas.o WarZone.o Champions.o Validation.o
	$(CXX) main.o Game.o Fighter.o Gru.o Space.o MercenaryShop.o \
		   ChineseSop.o Seal.o Sas.o WarZone.o Champions.o Validation.o -o rise

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

Game.o: Game.hpp Game.cpp
	$(CXX) $(CXXFLAGS) Game.cpp

Fighter.o: Fighter.hpp Fighter.cpp
	$(CXX) $(CXXFLAGS) Fighter.cpp

Gru.o: Gru.hpp Gru.cpp
	$(CXX) $(CXXFLAGS) Gru.cpp

ChineseSop.o: ChineseSop.hpp ChineseSop.cpp
	$(CXX) $(CXXFLAGS) ChineseSop.cpp

Seal.o: Seal.hpp Seal.cpp
	$(CXX) $(CXXFLAGS) Seal.cpp

Sas.o: Sas.hpp Sas.cpp
	$(CXX) $(CXXFLAGS) Sas.cpp

Space.o: Space.hpp Space.cpp
	$(CXX) $(CXXFLAGS) Space.cpp

MercenaryShop.o: MercenaryShop.hpp MercenaryShop.cpp
	$(CXX) $(CXXFLAGS) MercenaryShop.cpp

WarZone.o: WarZone.hpp WarZone.cpp
	$(CXX) $(CXXFLAGS) WarZone.cpp

Champions.o: Champions.hpp Champions.cpp
	$(CXX) $(CXXFLAGS) Champions.cpp

Validation.o: Validation.cpp Validation.hpp
	$(CXX) $(CXXFLAGS) Validation.cpp

zip:
	zip FinalProject_Vega_David.zip -D *.cpp *.hpp *.pdf makefile

clean:
	rm *.o rise
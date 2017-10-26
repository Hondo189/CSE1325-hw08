#Makefile for MICE Management System
CXXFLAGS += --std=c++11

all: div main
rebuild: div clean main

debug: CXXFLAGS += -g
debug: rebuild

main: main.o items.o scoop.o container.o topping.o view.o controller.o
	$(CXX) $(CXXFLAGS) -o MICE main.o view.o controller.o items.o scoop.o container.o topping.o
main.o: main.cpp items.h controller.h
	$(CXX) $(CXXFLAGS) -c main.cpp
view.o: view.cpp view.h
	$(CXX) $(CXXFLAGS) -c view.cpp
controller.o: controller.cpp controller.h view.h scoop.h container.h topping.h items.h
	$(CXX) $(CXXFLAGS) -c controller.cpp
items.o: items.cpp items.h scoop.h container.h topping.h
	$(CXX) $(CXXFLAGS) -c items.cpp
flavor.o: scoop.cpp scoop.h
	$(CXX) $(CXXFLAGS) -c scoop.cpp
container.o: container.cpp container.h
	$(CXX) $(CXXFLAGS) -c container.cpp
topping.o: topping.cpp topping.h
	$(CXX) $(CXXFLAGS) -c topping.cpp

clean: 
	-rm -f *.o MICE
div:
	@echo +++++++++++++++++++++++++++++++++++
	@echo XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
	@echo +++++++++++++++++++++++++++++++++++

#Makefile for MICE Management System
CXXFLAGS += --std=c++11

all: div main
rebuild: div clean main

debug: CXXFLAGS += -g
debug: rebuild

main: main.o items.o scoop.o container.o topping.o view.o controller.o dialogs.o main_window.o
	$(CXX) $(CXXFLAGS) -o MICE main.o view.o controller.o items.o scoop.o container.o topping.o dialogs.o main_window.o `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
main.o: main.cpp items.h controller.h
	$(CXX) $(CXXFLAGS) -c main.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
view.o: view.cpp view.h dialogs.o
	$(CXX) $(CXXFLAGS) -c view.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
controller.o: controller.cpp *h
	$(CXX) $(CXXFLAGS) -c controller.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
items.o: items.cpp items.h scoop.h container.h topping.h
	$(CXX) $(CXXFLAGS) -c items.cpp
flavor.o: scoop.cpp scoop.h
	$(CXX) $(CXXFLAGS) -c scoop.cpp
container.o: container.cpp container.h
	$(CXX) $(CXXFLAGS) -c container.cpp
topping.o: topping.cpp topping.h
	$(CXX) $(CXXFLAGS) -c topping.cpp
dialogs.o: dialogs.cpp dialogs.h
	$(CXX) $(CXXFLAGS) -c dialogs.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
main_window.o: main_window.cpp main_window.h
	$(CXX) $(CXXFLAGS) -c main_window.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

clean: 
	-rm -f *.o MICE
div:
	@echo +++++++++++++++++++++++++++++++++++
	@echo XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
	@echo +++++++++++++++++++++++++++++++++++

#include "items.h"

void Items::add_scoop(Scoop scp) {
	scoops.push_back(scp);
}

void Items::add_container(Container cont) {
	containers.push_back(cont);
}

void Items::add_topping(Topping top) {
	toppings.push_back(top);
}

string Items::scoop_to_string(int scoop_index) {
	return scoops[scoop_index].to_string();
}

string Items::cont_to_string(int cont_index) {
	return containers[cont_index].to_string();
}

string Items::top_to_string(int top_index) {
	return toppings[top_index].to_string();
}

int Items::number_of_scoops() {
	return scoops.size();
}

int Items::number_of_containers() {
	return containers.size();
}

int Items::number_of_toppings() {
	return toppings.size();
}

void Items::test_data() {
	//function automatically populates data with values to test program
}

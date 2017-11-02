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

void Items::add_serving(Serving serv) {
	servings.push_back(serv);
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

string Items::serv_to_string(int serv_index) {
	return servings[serv_index].to_string();
}

string Items::scoop_name(int scoop_index) {
	return scoops[scoop_index].get_name();
}

string Items::cont_name(int cont_index) {
	return containers[cont_index].get_name();
}

string Items::top_name(int top_index) {
	return toppings[top_index].get_name();
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

int Items::number_of_servings() {
	return servings.size();
}

#include "serving.h"
#include <string>
#include <iostream>
using namespace std;

string Serving::to_string() {
	string serv = "\nScoop: "+scoop_name+ " Container: " +cont_name+ " Topping: " +top_name;
	return serv;
}

#ifndef SCOOP_H
#define SCOOP_H

#include <iostream>
#include <string>

using namespace std;

class Scoop {
	public:
		string p_name;
		string p_info;
		double p_wholesale_cost;
		double p_retail_cost;
		int p_stock;
		
	private:
		string name;
		string info;
		double wholesale_cost;
		double retail_cost;
		int stock;
};
#endif

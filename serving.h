#ifndef SERVING_H
#define SERVING_H

#include <iostream>
#include <string>
using namespace std;

class Serving {
	public:
		Serving(string scp_name,
				string cnt_name,
				string tp_name) :
				
				scoop_name(scp_name),
				cont_name(cnt_name),
				top_name(tp_name) { }
			string to_string(); 
	private:
		string scoop_name;
		string cont_name;
		string top_name;
};
#endif

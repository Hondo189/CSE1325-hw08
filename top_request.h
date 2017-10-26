#ifndef TOP_REQUEST_H
#define TOP_REQUEST_H
#include <iostream>
using namespace std;

class Top_request {
	public:
		Top_request(int val) : value(val) { }
		
		static const int light = 0;
		static const int normal = 1;
		static const int extra = 2;
		static const int drenched = 3;
		
		static const int num_request = 4;
		
		string to_string() {
			switch(value) {
				case(light):return "light";
				case(normal):return "normal";
				case(extra):return "extra";
				case(drenched):return "drenched";
				default: return "UNKNOWN";
			}
		}
	private:
		int value;
};
#endif

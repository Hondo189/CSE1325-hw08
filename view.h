#ifndef VIEW_H
#define VIEW_H
#include "items.h"

class View {
	public:
		View(Items& itm) : items(itm) { }
		void show_menu();
		void list_scoops();
		void list_containers();
		void list_toppings();
		void help();
	private:
		Items& items;
};
#endif

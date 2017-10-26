#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "items.h"
#include "view.h"

class Controller {
	public:
		Controller (Items& itm) : items(itm), view(View(items)) { }
		void cli();
		void execute_cmd(int cmd);
	private:
		Items& items;
		View view;
};
#endif

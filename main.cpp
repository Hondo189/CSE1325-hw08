#include "controller.h"
#include "items.h"
#include "main_window.h"
#include <gtkmm.h>

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.lms");
  Items items;
  Controller controller(items);
  Main_window win(controller);
  win.set_title("CSE1325 MICE Management System");
  return app->run(win);
}

/*int main() {
	Items items;
	Controller controller(items);
	controller.cli();
}*/

#include "SimpleUI.h"

int main ()
{
	StudentDb db;
	SimpleUI ui(db);
	ui.run();

	return 0;
}

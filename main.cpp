#include "cli.h"
#include "App.h"
#include <clocale>
#include "Sortable_Unsorted_TableList.h"

int sCompare(const string &a, const string &b) {
	return a.compare(b);
}

int main() {

	setlocale(LC_ALL, "");
	App *app = new App();
	app->initialize();

	Cli cli(app);
	system("cls");
	cli.run();
	return 0;
}
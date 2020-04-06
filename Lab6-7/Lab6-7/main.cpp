#include <iostream>
#include "ui.h"
#include "test.h"

using namespace std;

int main() {
	test();
	
	Service service;
	UI ui;
	ui.run();
	return 0;
}
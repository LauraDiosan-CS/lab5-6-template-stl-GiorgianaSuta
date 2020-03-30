#include "test.h"
#include <assert.h>

void test() {
	Repo rep;
	assert(rep.size() == 0);
	Produs p1("A32", "corn", 5);
	rep.addProdus(p1);
	assert(rep.size() == 1);
	assert(rep.getAll()[0].getPret() == 5);
}
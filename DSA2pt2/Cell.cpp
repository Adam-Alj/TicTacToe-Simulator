// Cell.cpp
// Adam Al-Jumaily
// A00362836

#include "Cell.h"

Cell::Cell() {
	content = 0;
}

int Cell::getContent() const {
	return content;
}

void Cell::setContent(int a) {
	content = a;
}

bool Cell::isEmpty() const {
	return content == 0;
}
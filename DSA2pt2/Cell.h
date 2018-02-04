#ifndef CELL_
#define CELL_

// Cell.h
// Adam Al-Jumaily
// A00362836

class Cell {
private:
	
	/* 
	Variable that stores the content or state
	of the cell as an integer. 
			0  :  The cell is empty.
			1  :  The cell contains 'O'.
			2  :  The cell contains 'X'.
	*/
	int content;

public:
	// Default constructor.
	Cell();

	// Returns the content value of the cell.
	int getContent() const;

	// Sets the content value of the cell.
	void setContent(int a);

	// Determines if the cell has content or not.
	// Returns true if the cell is empty, false otherwise.
	bool isEmpty() const;
};

#endif // !CELL_


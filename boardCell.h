#ifndef __BOARDCELL_H
#define __BOARDCELL_H
class BoardCell
{
	char symbol;
	int color = 15;


public:

	void setColor(int color) { this->color = color; }
	void setSymbol(int symbol) { this->symbol = symbol; }
	int getColor()  { return color; }
	char getSymbol() { return symbol; }

};
#endif 

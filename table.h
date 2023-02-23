class Table
{
public:
	virtual int getRow() = 0;
	virtual int getColumn() = 0;
	virtual void printSheet() = 0;
	virtual void addRow(int) = 0;
	virtual void removeRow(int) = 0;
	virtual void addColumn(int) = 0;
	virtual void removeColumn(int) = 0;
	virtual void swapRows(int, int) = 0;
	virtual void swapColumns(int, int) = 0;
	virtual void writeCoordinatesToFile() = 0;
};
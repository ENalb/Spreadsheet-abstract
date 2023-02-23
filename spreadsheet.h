#include <string>
#include <map>
#include "cell.h"
#include "table.h"

class Spreadsheet : public Table{
public:
	Spreadsheet() = default;
	Spreadsheet(int, int);
	int getRow() override;
	int getColumn() override;
	void printSheet() override;
	void setCellAt(int, int, Cell*);
	Cell* getCellAt(int, int);
	void setCellAt(int, int, const std::string&);
	void addRow(int) override;
	void removeRow(int) override;
	void addColumn(int) override;
	void removeColumn(int) override;
	void swapRows(int, int) override;
	void swapColumns(int, int) override;
	void writeCoordinatesToFile() override;
private:
	std::map<int, std::map<int, Cell*>> m_cells;
	int row;
	int column;
};
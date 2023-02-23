#include "table.h"
#include <vector>
#include <string>

template<typename... types>
class Database : public Table
{
public:
	int getRow() override;
	int getColumn() override;
	void printSheet() override;
	void addRow(int) override;
	void removeRow(int) override;
	void addColumn(int) override;
	void removeColumn(int) override;
	void swapRows(int, int) override;
	void swapColumns(int, int) override;
	void writeCoordinatesToFile() override;
	void Select(const std::string&);
	void Insert(const std::string&);
	void Update(const std::string&);
	void Delete(const std::string&);
private:
	std::vector<std::tuple<types...>> data;
};
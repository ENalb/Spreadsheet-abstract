#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "spreadsheet.h"

Spreadsheet::Spreadsheet(int r, int c) : row{r}, column{c}
{
	for (int i = 0; i < r; ++i) {
        	std::map<int, Cell*> new_row;
        	for (int j = 0; j < c; ++j) {
            		new_row[j] = nullptr;
        	}
        	m_cells[i] = new_row;
    	}
}

int Spreadsheet::getRow()
{
	return m_cells.size();
}

int Spreadsheet::getColumn()
{
	return m_cells[0].size();
}

void Spreadsheet::printSheet()
{
	for(int i = 0; i < row; ++i){
		for(int j = 0; j < column; ++j){
			Cell* cell = getCellAt(i, j);
			if (cell) {
				std::cout << cell->getStringValue() << " ";
			} else {
				std::cout << "0 ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Spreadsheet::setCellAt(int r, int c, Cell* cell)
{
	m_cells[r][c] = cell;
}

Cell* Spreadsheet::getCellAt(int r, int c) 
{
	return m_cells[r][c];
}

void Spreadsheet::setCellAt(int r, int c, const std::string& value)
{
	StringCell* stringCell = new StringCell(value, Color::blue);
    	m_cells[r][c] = stringCell;
}

void Spreadsheet::addRow(int r)
{
	std::map<int, Cell*> new_row;
    	for(int j = 0; j < column; ++j) {
        	new_row[j] = nullptr;
    	}
    	m_cells.insert(m_cells.upper_bound(r), std::make_pair(r, new_row));
    	++row;
}

void Spreadsheet::removeRow(int r)
{
	for(auto& row : m_cells) {
        	row.second.erase(r);
    	}
    	row--;
}

void Spreadsheet::addColumn(int c)
{
	for (auto& row : m_cells) {
        	row.second.insert({c, nullptr});
    	}
    	++column;
}

void Spreadsheet::removeColumn(int c)
{
	for (auto& row : m_cells) {
        	auto it = row.second.find(c);
        	if (it != row.second.end()) {
            		delete it->second;
            		row.second.erase(it);
        	}
    	}
    	--column;
}

void Spreadsheet::swapRows(int r1, int r2)
{
	if (r1 < 0 || r1 >= row || r2 < 0 || r2 >= row) {
        	throw std::out_of_range("Row index out of range");
    	}

    	if (r1 == r2) {
        	return; 
    	}

    	for (int i = 0; i < column; i++) {
        	std::swap(m_cells[r1][i], m_cells[r2][i]);
    	}
}

void Spreadsheet::swapColumns(int c1, int c2)
{
	for (int r = 0; r < row; ++r) {
        	std::swap(m_cells[r][c1], m_cells[r][c2]);
    	}
}

void Spreadsheet::writeCoordinatesToFile()
{
	std::string filename = "coordinates.txt";

    	std::ofstream file(filename);

    	int rowCount = m_cells.size();
    	int columnCount = m_cells[0].size();

    	for (int i = 0; i < rowCount; i++)
    	{
		for (int j = 0; j < columnCount; j++)
		{
			Cell* cell = getCellAt(i, j);
				if (cell) {
					file << "(" << i << ";" << j << ") = " << cell->getStringValue() << "\n";
				} 
				else {
					file << "(" << i << ";" << j << ") = " << m_cells[i][j] << "\n";
				}
		}
    	}

    	file.close();
}

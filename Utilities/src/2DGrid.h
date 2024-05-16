#pragma once
#include <vector>
#include "SinglyLinkedList.h"

template<class T>
class Grid2D {
public:
	Grid2D(T initVal, initRows = 0, initColumns = 0);
	
	void pushBackRow(int num = 1);
	void pushBackColumn(int num = 1);

	void pushFrontRow(int num = 1);
	void pushFrontColumn(int num = 1);

	/*void eraseRow(int num = 1);
	void eraseColumn(int num = 1);

	void swapRow(int row1, int row2);
	void swapColumn(int column1, int column2);

	void flipGridRows();
	void flipGridColumns();*/

	int getRowLength();
	int getColumnLength();

	void setValue(T value, int row, int column);
	T getValue(int row, int column);

	int countValue(T val);
private:
	SinglyLinkedList<SinglyLinkedList<T>> grid_;
	int rows_, columns_;
	T defaultValue_;
};

template<class T>
class Grid3D {
public:
	Grid3D(T initVal);

	void pushBackRow(int num = 1);
	void pushBackColumn(int num = 1);
	void pushBackDepth(int num = 1);

	void pushFrontRow(int num = 1);
	void pushFrontColumn(int num = 1);
	void pushFrontDepth(int num = 1);

	void eraseRow(int num = 1);
	void eraseColumn(int num = 1);
	void eraseDepth(int num = 1);

	void swapRowPlane(int row1, int row2);
	void swapColumnPlane(int column1, int column2);
	void swapDepthPlane(int column1, int column2);

	void flipGridRows();
	void flipGridColumns();
	void flipGridDepths();

	int getRowLength();
	int getColumnLength();
	int getDepthLength();

	T getValue(int row, int column);
	void setValue(T value, int row, int column, int depth);

	int countValue(T val);

private:
	SinglyLinkedList<SinglyLinkedList<SinglyLinkedList<T>>> grid_;
	int rows_, columns_, depths_;
	T defaultValue_;
};


//implementations for the Grid2D
//--------------------------------------------------------------------------------------------
template <typename T>
Grid2D<T>::Grid2D(T initVal, initRows = 1, initColumns = 1) {
	defaultValue_ = initVal;

	SinglyLinkedList<T> column;
	for (int i = 0; i < initColumns; i++) {
		column.append(defaultValue_);
	}

	for (int i = 0; i < initRows; i++) {
		grid_.append(column);
	}
	rows_ = initRows;
	columns_ = initColumns;

	return;
}

template <typename T>
void Grid2D<T>::pushBackRow(int num) {
	SinglyLinkedList<T> column;
	for (int i = 0; i < grid_[0].size(); i++) {
		column.append(defaultValue_);
	}
	grid_.append(column);
	rows_++;

	return;
}

template <typename T>
void Grid2D<T>::pushBackColumn(int num) {
	SinglyLinkedList<T> column;
	for (int i = 0; i < grid_.size(); i++) {
		grid_[i].append(defaultValue_);
	}
	columns_++;

	return;
}

template <typename T>
void Grid2D<T>::pushFrontRow(int num) {
	SinglyLinkedList<T> column;
	for (int i = 0; i < grid_[0].size(); i++) {
		column.prepend(defaultValue_);
	}
	grid_.prepend(column);
	rows_++;

	return;
}

template <typename T>
void Grid2D<T>::pushFrontColumn(int num) {
	SinglyLinkedList<T> column;
	for (int i = 0; i < grid_.size(); i++) {
		grid_[i].prepend(defaultValue_);
	}
	columns_++;

	return;
}

/*template <typename T>
void Grid2D<T>::eraseRow(int num = 1) {

}

template <typename T>
void Grid2D<T>::eraseColumn(int num = 1) {

}

template <typename T>
void Grid2D<T>::swapRow(int row1, int row2) {

}

template <typename T>
void Grid2D<T>::swapColumn(int column1, int column2) {

}

template <typename T>
void Grid2D<T>::flipGridRows() {

}

template <typename T>
void Grid2D<T>::flipGridColumns() {

}*/

template <typename T>
int Grid2D<T>::getRowLength() {
	return rows_;
}

template <typename T>
int Grid2D<T>::getColumnLength() {
	return columns_;
}

template <typename T>
T Grid2D<T>::getValue(int row, int column) {
	return grid_[row][column];
}

template <typename T>
void Grid2D<T>::setValue(T val, int row, int column) {
	grid_[row][column] = val;
}

template <typename T>
int Grid2D<T>::countValue(T val) {
	int count = 0;

	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < columns_; j++) {
			if (grid_[i][j] == val) {
				count += 1;
			}
		}
	}
	return count;
}




//implementations for the Grid3D
//--------------------------------------------------------------------------------------------
template <typename T>
Grid3D<T>::Grid3D(T initVal) {
	std::vector<T> depth;
	depth.append(initVal);

	std::vector<std::vector<T>> column;
	column.append(depth);

	grid_.append(column);
}

template <typename T>
void Grid3D<T>::pushBackRow(int num){

}

template <typename T>
void Grid3D<T>::pushBackColumn(int num){

}

template <typename T>
void Grid3D<T>::pushBackDepth(int num){

}

template <typename T>
void Grid3D<T>::pushFrontRow(int num){

}

template <typename T>
void Grid3D<T>::pushFrontColumn(int num){

}

template <typename T>
void Grid3D<T>::pushFrontDepth(int num){

}

template <typename T>
void Grid3D<T>::eraseRow(int num){

}

template <typename T>
void Grid3D<T>::eraseColumn(int num){

}

template <typename T>
void Grid3D<T>::eraseDepth(int num){

}

template <typename T>
void Grid3D<T>::swapRowPlane(int row1, int row2){

}

template <typename T>
void Grid3D<T>::swapColumnPlane(int column1, int column2){

}

template <typename T>
void Grid3D<T>::swapDepthPlane(int column1, int column2){

}

template <typename T>
void Grid3D<T>::flipGridRows(){

}

template <typename T>
void Grid3D<T>::flipGridColumns(){

}

template <typename T>
void Grid3D<T>::flipGridDepths(){

}

template <typename T>
T Grid3D<T>::getValue(int row, int column){

}

template <typename T>
void Grid3D<T>::setValue(T value, int row, int column, int depth){

}

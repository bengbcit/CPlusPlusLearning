#include <iostream>
using namespace std;


/*********** Array 1D 2D example *****************/
///* 1D array */
//void oneD_array (int theArray[], int sizeofArray);
//
///* 2D array: 1st way*/
//const int r = 3;
//const int c = 2;
//void twoD_array (int theArray[r][c]);
//
///* 2D array: 2nd way*/
//const int col = 3;
//void twoD_array_way2(int theArray[][col], int row);
//
//int main() {
//  /* 1D array */
//  int ary_1[3] = {20,44,323};
//  cout << "Testing array: "<< &ary_1<<". Address after increase by 1 "<<(&ary_1+1)<<endl;
//  int ary_2[5] = {22,34,55,32,78};
//  oneD_array(ary_1,3);
//
//  /* 2D array: 1st way passing variables*/
//  int array_2d_1[3][2] = {{2,3},{13,22},{32,88}};
//  twoD_array(array_2d_1);
//
//  /* 2D array: 2nd way passing variables*/
//  int array_2d_2[4][3] = {{2,3,2},{13,22,33},{32,88,19},{66,78,49}};
//  twoD_array_way2(array_2d_2,4);
//  return 0;
//}
//
///* 1D array: passing array */
//void oneD_array (int theArray[], int sizeofArray){
//  for (int i =0; i<sizeofArray; i++){
//    cout<< theArray[i] <<endl;
//  }
//}
//
//// NOTE: When passing a vector as parameter you must specify all dimensions except the first one.
///* 2D array: 1st way passing array */
//void twoD_array (int theArray[r][c]){
//  for (int i =0; i<r; i++){
//    for (int j =0; j<c; j++){
//      cout<< theArray[i][j]<<" ";
//    }
//    cout<< endl;
//  }
//}
//
///* 2D array: 2nd way passing only colum*/
//void twoD_array_way2 (int theArray[][col], int row){
//  for (int i =0; i<row; i++){
//    for (int j =0; j<col; j++){
//      cout<< theArray[i][j]<<" ";
//    }
//    cout<< endl;
//  }
//}

/*********** Dynamic 2D Array example *****************/
int main() {

	// let user define the desire 2D array size
	cout << "rows, cols" << endl;
	int row, col;
	cin >> row >> col;

	int** table = new int* [row];
	for (int i = 0;i < row;i++) {
		table[i] = new int[col];
	}
	table[2][3] = 99;

	// deallocate back order dynamic array elements-> pointer arrays -> pointer of pointer, variable "table"
	for (int i = 0; i < row; i++) { 
		delete[] table[i];
	}
	delete[] table;
	table = NULL;

	return 0;
}
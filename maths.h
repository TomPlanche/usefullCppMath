/**\
  * @file maths.hpp
  * @author Tom Planche (tomplanche@icloud.com)
  * @brief Header file for maths.cpp
  * @date 08-01-2022
  *
  * @copyright Copyright (c) 2022
  *
\**/

// ! IMPORT OF THE NECESSARY LIBRARIES.
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#ifndef MATHS_H
#define MATHS_H

// ! Importing Necessary Bases (cin, cout, endl) To Avoid `using namespace std`.
using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::ostringstream;
using std::setprecision;
using std::string;
using std::stringstream;
using std::to_string;
using std::vector;

//.
//===============================================================================================
//.                                           MATRICES
//.
//===============================================================================================
class Matrix {
    public:
        int get_n();

        int get_m();

        void show();

        vector<vector<double>> get_matrix();

        void changeMatrix(vector<vector<double>> matrix);

        Matrix(const int x, const int y);

        Matrix(const int i);

        ~ Matrix() {}

    private:
        int n, m;
        vector<vector<double>> matrix;
};







//.
//===============================================================================================
//.                                            NUMBERS
//.
//===============================================================================================
int getSize(double number);

bool isInteger(double N);

double roundTom(double number, int n);

double roundTo(double val, int n);

//.
//===============================================================================================
//.                                            VECTORS
//.
//===============================================================================================
int getMaxVector(vector<int> liste);

int getMinVector(vector<int> liste);

#endif

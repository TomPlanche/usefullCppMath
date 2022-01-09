/**\
  * @file maths.cpp
  * @author Tom Planche (tomplanche@icloud.com)
  * @brief My Maths Usefull Functions
  * @date 07-01-2022
  * 
  * @copyright Copyright (c) 2022
  * 
\**/

// ! IMPORT OF THE NECESSARY LIBRARIES.
#include "maths.h"

//.  ===============================================================================================
//.                                           MATRICES                                              
//.  ===============================================================================================

Matrix::Matrix(const int x, const int y) {
    n = x;
    m = y;
}

Matrix::Matrix(const int i) {
    n = i;
    m = n;
}


void Matrix::show() {
    vector<double> maxValuesByColums;
    
    


    for (int j{}; j < matrix[0].size(); j++) {
        double collumnMax{};
        for (int i = 0; i < matrix.size() ; i++) {
            if (getSize(matrix[i][j]) > collumnMax) {
                collumnMax = getSize(matrix[i][j]);
            }
        }
        maxValuesByColums.push_back(collumnMax);
    }

    for (auto elem: maxValuesByColums) {
        cout << elem << endl;
    }

    for (int i{}; i < matrix.size(); i++) {
        cout << '|';
        for (int j{}; j < matrix[0].size(); j++) {
            if (j == 0) {
                cout << " ";
            }
            for (
                int s{};
                s < (maxValuesByColums[j] - getSize(matrix[i][j]));
                s++
                ) {
                cout << " ";
            }
            cout << matrix[i][j] << " ";
        }
        cout << '|' << endl;
    }
}

void Matrix::changeMatrix(vector<vector<double>> matrixArgument) {
    matrix = matrixArgument;
}

int Matrix::get_n(void) {
    return n;
}


int Matrix::get_m(void) {
    return m;
}

vector<vector<double>> Matrix::get_matrix() { return matrix; }

//.  ===============================================================================================
//.                                            NUMBERS                                              
//.  ===============================================================================================
int getSize(double number) {
    std::ostringstream streamObj;
    streamObj << number;
    
    
    return streamObj.str().size();
}

bool isInteger(double N) {
    return !(double(N - (int)N) > 0);
}

double roundTo(double val, int n) {
    stringstream tmp;
    tmp << setprecision(n) << fixed << val;
    return stod(tmp.str());  
}

double roundTom(double number, int n) {
    return isInteger(number) ? number : roundTo(number, n);
}


//.  ===============================================================================================
//.                                            VECTORS                                              
//.  ===============================================================================================
int getMaxVector(vector<int> liste) {
    int len = liste.size();
    int max = liste.at(0);

    for (int i = 0; i < len; i++) {
        if (liste.at(i) > max) {
            max = liste.at(i);
        }
    }

    return max;
}

int getMinVector(vector<int> liste) {
    int len = liste.size();
    int min = liste.at(0);

    for (int i = 0; i < len; i++) {
        if (liste.at(i) < min) {
            min = liste.at(i);
        }
    }

    return min;
}
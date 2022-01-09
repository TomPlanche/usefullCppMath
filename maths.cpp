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
/**\
  * @brief Construct a new Matrix object. In the case where the number of rows and columns is different.
  * 
  * @param x Number of lines.
  * @param y Number of columns.
\**/
Matrix::Matrix(const int x, const int y) {
    n = x;
    m = y;
}

/**\
  * @brief Construct a new Matrix object. In the case where the number of rows and columns is the same.
  * 
  * @param i Number of lines AND colomns.
\**/
Matrix::Matrix(const int i) {
    n = i;
    m = n;
}


/**\
  * @brief Graphically shows the matrix
  * Exemple :
  * | 1   2 3 |
  * | 4 -54 6 |
  * | 7  84 9 |
  * 
\**/
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

/**\
  * @brief Change or initialize the matrix.
  * 
  * @param matrixArgument Matrix.
\**/
void Matrix::changeMatrix(vector<vector<double>> matrixArgument) {
    matrix = matrixArgument;
    n = matrix.size();
    m = matrix[0].size();
}


/**\
  * @brief Return the number of lines of the matrix.
  * 
  * @return int number of lines of the matrix
\**/
int Matrix::get_n() {
    return n;
}


/**\
  * @brief Return the number of columns of the matrix.
  * 
  * @return int number of columns of the matrix
\**/
int Matrix::get_m(void) {
    return m;
}


/**\
  * @brief Return the matrix.
  * 
  * @return vector<vector<double>> the matrix.
\**/
vector<vector<double>> Matrix::get_matrix() { return matrix; }

//.  ===============================================================================================
//.                                            NUMBERS                                              
//.  ===============================================================================================
/**\
  * @brief Get the number of space that this number is taking for writing it.
  * Ex :
  *     2      -> 1
  *     -3     -> 2
  *     -34.43 -> 6
  * @param number Number whose size we want to know.
  * @return int Size of that number.
\**/
int getSize(double number) {
    std::ostringstream streamObj;
    streamObj << number;
    
    
    return streamObj.str().size();
}


/**\
  * @brief Returns if the double is an integer.
  * 
  * @param number Double number.
  * @return true The double is an integer.
  * @return false The double is not an integer.
\**/
bool isInteger(double number) {
    return !(double(number - (int)number) > 0);
}


/**\
  * @brief Rounding a number to n decimal places.
  * 
  * @param number Number we want to round up.
  * @param n Number of decimal places.
  * @return double Rounded number.
\**/
double roundTo(double number, int n) {
    stringstream tmp;
    tmp << setprecision(n) << fixed << number;
    return stod(tmp.str());  
}


/**\
  * @brief Custom function to round a number
  * 
  * @param number Number we want to round up.
  * @param n Number of decimal places.
  * @return double Rounded number.
\**/
double roundTom(double number, int n) {
    return isInteger(number) ? number : roundTo(number, n);
}


//.  ===============================================================================================
//.                                            VECTORS                                              
//.  ===============================================================================================
/**\
  * @brief Get the max number from a vector.
  * 
  * @param line the vector. 
  * @return double the max number of that vector.
\**/
double getMaxVector(vector<double> line) {
    int len = line.size();
    int max = line.at(0);

    for (int i = 0; i < len; i++) {
        if (line.at(i) > max) {
            max = line.at(i);
        }
    }

    return max;
}


/**\
  * @brief Get the min number from a vector.
  * 
  * @param line the vector. 
  * @return double the min number of that vector.
\**/
double getMinVector(vector<double> line) {
    int len = line.size();
    int min = line.at(0);

    for (int i = 0; i < len; i++) {
        if (line.at(i) < min) {
            min = line.at(i);
        }
    }

    return min;
}
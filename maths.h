/**\
  * @file maths.hpp
  * @author Tom Planche (tomplanche@icloud.com)
  * @brief Header file for maths.cpp
  * @date 08-01-2022
  *
  * @copyright Copyright (c) 2022
  *
\**/

#ifndef MATHS_H
#define MATHS_H

// ! IMPORT OF THE NECESSARY LIBRARIES.
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <assert.h>
#include <numeric>


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
using std::ostream;
using std::size_t;
using std::gcd;
using std::lcm;


//.  ===============================================================================================
//.                                            NUMBERS                                              
//.  ===============================================================================================
/**\
  * @brief Check if the numbers are coprime.
  * 
  * @param nb1 Number one.
  * @param nb2 Number two.
  * @return true They are coprimes.
  * @return false They are coprimes.
\**/
bool areCoprime(const long nb1, const long nb2);


/**\
  * @brief Get the number of space that this number is taking for writing it.
  * Ex :
  *     2      -> 1
  *     -3     -> 2
  *     -34.43 -> 6
  * @param number Number whose size we want to know.
  * @return int Size of that number.
\**/
int getNumberSize(double number);


/**\
  * @brief Returns if the double is an integer.
  * 
  * @param number Double number.
  * @return true The double is an integer.
  * @return false The double is not an integer.
\**/
bool isInteger(double N);


/**\
  * @brief Check if the number is a prime.
  * 
  * @param number Number to check.
  * @return true The number is a prime.
  * @return false The number is not a prime.
\**/
bool isPrime(long number);


bool isPrimeAndOdd(long number);




/**\
  * @brief Rounding a number to n decimal places.
  * 
  * @param number Number we want to round up.
  * @param n Number of decimal places.
  * @return double Rounded number.
\**/
double roundTom(double number, int n);


/**\
  * @brief Custom function to round a number
  * 
  * @param number Number we want to round up.
  * @param n Number of decimal places.
  * @return double Rounded number.
\**/
double roundTo(double val, int n);


//.  ===============================================================================================
//.                                           FRACTION                                              
//.  ===============================================================================================
class Fraction {
    int numerator;
    int denominator;

    public:
        //.  ------------------------------------ FONCTIONS ----------------------------------------
        /**\
         * @brief Simplify a fraction.
         * 
         * @return Fraction The simplified fraction.
        \**/
        Fraction simplify();


        int& getNumerator();


        int& getDenominator();

        // ~ Fraction();


        /**\
         * @brief Construct a new Fraction object with parameters.
         * 
         * @param x The numerator.
         * @param y The denominator.
        \**/
        Fraction(const int x, const int y);


        /**\
         * @brief Construct a new Fraction object without parameters.
         * 
         * -> {1, 1}
        \**/
        Fraction();

        // ! -------------------------- OPERATOR OVERLOAD

        // ! ------------- + OPERATOR

        // ! ------ Fraction + Fraction
        /**\
         * @brief Overload Of The + Operator Allowing To Use The '+' Operator Between Two Fractions.
         * 
         * @param frac The second fraction
         * @return Fraction The fraction resulting from the sum 
        \**/
        Fraction operator+(const Fraction frac);


        // ! ------ Fraction + Integer
        /**\
         * @brief Overload Of The + Operator Allowing To Use The '+' Operator Between A Fraction And An Integer.
         * 
         * @param n Integer to be added to the Fraction
         * @return Fraction The fraction resulting from the sum 
        \**/
        Fraction operator+(const int n);

        // ! ------------- - OPERATOR

            // ! ------ Fraction - Fraction
        /**\
         * @brief Overload Of The - Operator Allowing To Use The '-' Operator Between Two Fractions.
         * 
         * @param frac The second fraction
         * @return Fraction The fraction resulting from the subtraction.
        \**/
        Fraction operator-(const Fraction frac);

        // ! ------ Fraction - Integer
        /**\
         * @brief Overload Of The - Operator Allowing To Use The '-' Operator A Fraction And An Integer.
         * 
         * @param n Integer to be subtracted from the fraction
         * @return Fraction The fraction resulting from the subtraction
        \**/
        Fraction operator-(const int n); // 

        // ! ------------- * OPERATOR

        // ! ------ Fraction * Fraction
        /**\
         * @brief Overload Of The - Operator Allowing To Use The '-' Operator A Fraction And An Integer.
         * 
         * @param frac The second fraction
         * @return Fraction The fraction resulting from the multiplication
        \**/
        Fraction operator* (Fraction frac);

        // ! ------ Fraction * Integer
        /**\
         * @brief Overload Of The * Operator Allowing To Use The '*' Operator Between A Fraction And An Integer.
         * 
         * @param n Integer to multiply with the fraction
         * @return Fraction The fraction resulting from the multiplication
        \**/
        Fraction operator* (const int n);

        // ! ------------- OPERATOR /
        /**\
         * @brief Overloading of the - operator allowing to use the '-' operator between two Fractions
         * 
         * @param frac The second fraction.
         * @return Fraction The fraction resulting from the division.
        \**/
        Fraction operator/ (const Fraction frac);

        // ! ------------- OPERATOR <<
        /**\
         * @brief Allows to cout a fraction.
         * 
         * @param out Do not touch this
         * @param frac The fraction to cout
         * @return ostream& Do not touch this
        \**/
        friend ostream &operator<<(ostream &out, const Fraction frac) {
            if (frac.denominator == frac.numerator) {
                cout << 1;
            } else if (frac.denominator == 1) {
                cout << frac.numerator;
            } else if (frac.numerator == 0) {
                cout << 0;
            } else {
                cout << frac.numerator << "/" << frac.denominator;
            }

            return out;
        };

        // ! ------------- Comparison Operator <
        /**\
         * @brief Allows a < comparison between two functions
         * 
         * @param frac The second fraction, automatically passed
         * @return true 
         * @return false 
        \**/
        bool operator< (const Fraction frac);

        // ! ------------- Comparison Operator >
        /**\
         * @brief Allows a > comparison between two functions
         * 
         * @param frac 
         * @return true 
         * @return false 
        \**/
        bool operator> (const Fraction frac);

        // ! ------------- Comparison Operator =
        /**\
         * @brief Allows an equality comparison between two functions
         * 
         * @param frac 
         * @return true 
         * @return false 
        \**/
        bool operator= (Fraction frac);
};

//.  ===============================================================================================
//.                                           MATRICES                                              
//.  ===============================================================================================
class Matrix {
    public:
        //.  ---------------------------------- CONSTRUCTORS ---------------------------------------
        Matrix(vector<vector<double>> matrix_);

        /**\
         * @brief Construct a new Matrix object. In the case where the number of rows and columns is different.
         * 
         * @param x Number of lines.
         * @param y Number of columns.
        \**/
        Matrix(const int x, const int y);


        /**\
         * @brief Construct a new Matrix object. In the case where the number of rows and columns is the same.
         * 
         * @param i Number of lines AND colomns.
        \**/
        Matrix(const int i);

        /**\
          * @brief Construct a new Matrix object.
          * 
        \**/
        Matrix() {};

        //.  ----------------------------------- DESTRUCTOR ----------------------------------------
        /**\
          * @brief Destroy the Matrix object
          * 
        \**/
        ~Matrix() {}


        //.  ------------------------------ GET MATRIX ATTIBUTES -----------------------------------
        /**\
         * @brief Return the number of columns of the matrix.
         * 
         * @return int number of columns of the matrix
        \**/
        int get_m() const;


        /**\
         * @brief Return the number of lines of the matrix.
         * 
         * @return int number of lines of the matrix
        \**/
        int get_n() const;


        /**\
         * @brief Return the matrix.
         * 
         * @return vector<vector<double> > the matrix.
        \**/
        vector<vector<double>> get_matrix();


        //.  --------------------------------------- PROCEDURES --------------------------------------------    
        
        void clear();

        /**\
         * @brief Change or initialize the matrix.
         * 
         * @param matrixArgument Matrix.
        \**/
        void changeMatrix(vector<vector<double>> matrix);


        /**\
          * @brief Initialize the matrix - Creates the 0(m,n) matrix.
          * 
        \**/
        void initialize();

        
        void inv();


        /**\
          * @brief Permute two lines of the same matrix.
          * 
          * @param line1 Line one to permute with line two.
          * @param line2 Line two to permute with line one.
        \**/
        void permute(unsigned short int line1, unsigned short int line2);


        /**\
          * @brief Permute two lines of the same index of two matrices.
          * 
          * @param matrix2 The second matrix.
          * @param line The line's index to swap.
        \**/
        void permute(Matrix &matrix2, unsigned short int line);


        /**\
          * @brief Permute two lines of different indexes in two matrice.
          * 
          * @param matrix2 
          * @param line1 
          * @param line2 
        \**/
        void permute(Matrix &matrix2, unsigned short int line1, unsigned short int line2);


        //.  ------------------------------------ FUNCTIONS ----------------------------------------
        /**\
          * @brief Check if the matrix is square (-> m == n).
          * 
          * @return true The matrix is squared.
          * @return false The matrix is not squared.
        \**/
        bool isSquare();

        /**\
          * @brief Check if the matrix is triangular.
          * 
          * @return true The matrix is triangular.
          * @return false The matrix is not triangular.
        \**/
        bool isTriangular();


        /**\
          * @brief Determine the determinant of the matrix.
          * 
          * @return double The matrix's determinant.
        \**/
        double det(vector<vector<double>> matrix_ = {{0}});


        //.  ------------------------------- OPERATOR OVERLOADS ------------------------------------
        /**\
          * @brief Overloading of the addition operator to add two matrices.
          * 
          * @param matrix Matrix n°2.
          * @return Matrix The resulting matrix.
        \**/
        Matrix operator+ (const Matrix matrix);


        /**\
          * @brief Overloading of the subtraction operator to subtract two matrices.
          * 
          * @param matrix Matrix n°2.
          * @return Matrix The resulting matrix.
        \**/
        Matrix operator- (const Matrix matrix);

        
        /**\
          * @brief Overloading of the multiplication operator to multiply two matrices.
          * 
          * @param matrix Matrix n°2.
          * @return Matrix The resulting matrix.
        \**/
        Matrix operator* (const Matrix matrix);
        

        /**\
          * @brieg Overloading of the multiplication operator to multiply a matrix with a number.
          * 
          * @param number Number with which the matrix is multiplied.
          * @return Matrix The resulting matrix.
        \**/
        Matrix operator* (const double number);


        /**\
          * @brief Overloading of the square bracket to access the matrix lines and/or columns.
          * 
          * @param i 
          * @return vector<double>& 
        \**/
        vector<double> &operator[](int i);



        Matrix &operator=(const Matrix &matrix_);


        /**\
         *  @brief Graphically shows the matrix
         *  Exemple :
         *  | 1   2 3 |
         *  | 4 -54 6 |
         *  | 7  84 9 |
         *
        \**/
        friend ostream &operator<<(ostream &out, const Matrix matrixx) {
            vector<vector<double>> matrix_final = matrixx.matrix;
            vector<double> maxValuesByColums;
    
            for (int j{}; j < matrixx.matrix[0].size(); j++) {
                double collumnMax{};
                
                for (int i = 0; i < matrixx.matrix.size() ; i++) {
                    if (getNumberSize(matrixx.matrix[i][j]) > collumnMax) {
                        collumnMax = getNumberSize(matrix_final[i][j]);
                    }
                }
                maxValuesByColums.push_back(collumnMax);
            }

            for (int i{}; i < matrixx.matrix.size(); i++) {
                cout << '|';
                
                for (int j{}; j < matrixx.matrix[0].size(); j++) {
                    if (j == 0) {
                        cout << " ";
                    }
                    
                    for (
                        int s{};
                        s < (maxValuesByColums[j] - getNumberSize(matrix_final[i][j]));
                        s++
                        ) {
                        cout << " ";
                    }
                    
                    cout << matrix_final[i][j] << " ";
                }

                cout << '|' << endl;
            }
            return out;
        };

    private:
        int m, n;
        vector<vector<double>> matrix;
};


//.  ===============================================================================================
//.                                            VECTORS                                              
//.  ===============================================================================================
/**\
  * @brief Get the max number from a vector.
  * 
  * @param line the vector. 
  * @return double the max number of that vector.
\**/
int getMaxVector(vector<int> liste);


/**\
  * @brief Get the min number from a vector.
  * 
  * @param line the vector. 
  * @return double the min number of that vector.
\**/
int getMinVector(vector<int> liste);

#endif

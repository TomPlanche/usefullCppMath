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
using std::ostream;


//.  ===============================================================================================
//.                                            NUMBERS                                              
//.  ===============================================================================================
int getSize(double number);

bool isInteger(double N);

int gcd(const int nb1, const int nb2);

double roundTom(double number, int n);

double roundTo(double val, int n);


//.  ===============================================================================================
//.                                           FRACTION                                              
//.  ===============================================================================================
class Fraction {
    public:

    // ! ---------------------------------------------------- FONCTIONS ----------------------------------------------------
    /**\
      * @brief Simplify a fraction.
      * 
      * @return Fraction The simplified fraction.
    \**/
    Fraction simplify();


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
    Fraction operator* (const Fraction frac);

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

    private:
        int numerator;
        int denominator;
};

//.  ===============================================================================================
//.                                           MATRICES                                              
//.  ===============================================================================================
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

        friend ostream &operator<<(ostream &out, const Matrix matrixx) {
            vector<vector<double>> matrix_final = matrixx.matrix;
            vector<double> maxValuesByColums;
    
            for (int j{}; j < matrixx.matrix[0].size(); j++) {
                double collumnMax{};
                
                for (int i = 0; i < matrixx.matrix.size() ; i++) {
                    if (getSize(matrixx.matrix[i][j]) > collumnMax) {
                        collumnMax = getSize(matrix_final[i][j]);
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
                        s < (maxValuesByColums[j] - getSize(matrix_final[i][j]));
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
        int n, m;
        vector<vector<double>> matrix;
};


//.  ===============================================================================================
//.                                            VECTORS                                              
//.  ===============================================================================================
int getMaxVector(vector<int> liste);

int getMinVector(vector<int> liste);

#endif

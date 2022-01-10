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
//.                                           FRACTIONS                                             
//.  ===============================================================================================
Fraction Fraction::simplify() {
    Fraction fractionSimplifiee;
    
    int gcdFrac = gcd(numerator, denominator);

    fractionSimplifiee.numerator = numerator / gcdFrac;
    fractionSimplifiee.denominator = denominator / gcdFrac;

    return fractionSimplifiee;
}

int& Fraction::getNumerator() {
    return numerator;
}

int& Fraction::getDenominator() {
    return denominator;
}

Fraction::Fraction(const int x, const int y) {
    numerator = x;
    denominator = y;
}

Fraction::Fraction() {
    numerator = 1;
    denominator = 1;
}

Fraction Fraction::operator+ (const Fraction frac) {
    Fraction fractionResultat;

    if (denominator == frac.denominator) {
        fractionResultat.numerator = numerator + frac.numerator;
        fractionResultat.denominator = denominator;
    } else {
        fractionResultat.numerator = numerator * frac.denominator + frac.numerator * denominator;
        fractionResultat.denominator = denominator * frac.denominator;
    }

    return fractionResultat.simplify();
}

Fraction Fraction::operator+ (const int n) {
    Fraction fractionResultat;

    fractionResultat.numerator += denominator * (numerator >= denominator ? n + 1 : n);
    fractionResultat.denominator = denominator;

    return fractionResultat.simplify();
}

Fraction Fraction::operator- (const Fraction frac) {
    Fraction fractionResultat;

    if (denominator == frac.denominator) {
        fractionResultat.numerator = numerator - frac.numerator;
        fractionResultat.denominator = denominator;
    } else {
        fractionResultat.numerator = numerator * frac.denominator - frac.numerator * denominator;
        fractionResultat.denominator = denominator + frac.denominator;
    }

    return fractionResultat.simplify();
}

Fraction Fraction::operator- (const int n) {
    Fraction fractionResultat;

    
    fractionResultat.numerator = numerator - (denominator * (numerator >= denominator ? n : n + 1));
    fractionResultat.denominator = denominator ;
    

    return fractionResultat.simplify();
}

Fraction Fraction::operator* (const Fraction frac) {
    Fraction fractionResultat;

    fractionResultat.numerator = numerator * frac.numerator;
    fractionResultat.denominator = denominator * frac.denominator;

    return fractionResultat.simplify();
}

Fraction Fraction::operator* (const int n) {
    Fraction fractionResultat;

    fractionResultat.numerator = numerator * n;
    fractionResultat.denominator = denominator;

    return fractionResultat.simplify();
}

Fraction Fraction::operator/ (const Fraction frac) {
    Fraction fractionBase = {numerator, denominator};
    Fraction fractionBase2 = {frac.denominator, frac.numerator};
    

    return fractionBase * fractionBase2;
}

ostream& operator<<(std::ostream& out, /*const*/ Fraction& frac) {

    int numerator;
    int denominator;

    numerator = frac.getNumerator();
    denominator = frac.getDenominator();

    if (denominator == numerator) {
        cout << 1;
    } else if (denominator == 1) {
        cout << numerator;
    } else if (numerator == 0) {
        cout << 0;
    } else {
        cout << numerator << "/" << denominator;
    }

    return out;
}

bool Fraction::operator< (const Fraction frac) {
    if (frac.denominator == denominator) {
        return (numerator < frac.numerator);
    }

    return ((frac.numerator*denominator) < (numerator*frac.denominator));
}

bool Fraction::operator> (const Fraction frac) {
    if (frac.denominator == denominator) {
        return (numerator > frac.numerator);
    }

    return ((frac.numerator*denominator) > (numerator*frac.denominator));
}

bool Fraction::operator= (Fraction frac) {
    if (frac.denominator == denominator) {
        return (numerator = frac.numerator);
    }

    return (frac.numerator*denominator == numerator*frac.denominator);
}


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

void Matrix::changeMatrix(vector<vector<double> > matrixArgument) {
    matrix = matrixArgument;
    n = matrix.size();
    m = matrix[0].size();
}


int Matrix::get_n() {
    return n;
}


int Matrix::get_m(void) {
    return m;
}


vector<vector<double> > Matrix::get_matrix() { return matrix; }

//.  ===============================================================================================
//.                                            NUMBERS                                              
//.  ===============================================================================================
int getSize(double number) {
    std::ostringstream streamObj;
    streamObj << number;
    
    
    return streamObj.str().size();
}

bool isInteger(double number) {
    return !(double(number - (int)number) > 0);
}


int gcd(const int nb1, const int nb2) {
    int min = (nb1 < nb2) ? nb1 : nb2;

    for (int i = min; i <= min; i--) {
        if ((nb1 % i == 0) && (nb2 % i == 0)) {
            return i;
        }
    }

    return 1;
}

double roundTo(double number, int n) {
    stringstream tmp;
    tmp << setprecision(n) << fixed << number;
    return stod(tmp.str());  
}


double roundTom(double number, int n) {
    return isInteger(number) ? number : roundTo(number, n);
}


//.  ===============================================================================================
//.                                            VECTORS                                              
//.  ===============================================================================================
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

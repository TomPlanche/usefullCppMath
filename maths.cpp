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
    // ! Variables Declaration
    Fraction fractionSimplifiee;
    int gcdFrac;
    
    // ! Variables Definition
    gcdFrac = gcd(numerator, denominator);

    // ! Treatments
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
    // ! Treatments
    numerator = x;
    denominator = y;
}

Fraction::Fraction() {
    // ! Treatments
    numerator = 1;
    denominator = 1;
}

Fraction Fraction::operator+ (const Fraction frac) {
    // ! Variables Declaration
    Fraction fractionResultat;

    // ! Treatments
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
    // ! Variables Declaration
    Fraction fractionResultat;

    // ! Treatments
    fractionResultat.numerator += denominator * (numerator >= denominator ? n + 1 : n);
    fractionResultat.denominator = denominator;

    return fractionResultat.simplify();
}

Fraction Fraction::operator- (const Fraction frac) {
    // ! Variables Declaration
    Fraction fractionResultat;

    // ! Treatments
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
    // ! Variables Declaration
    Fraction fractionResultat;

    // ! Treatments
    fractionResultat.numerator = numerator - (denominator * (numerator >= denominator ? n : n + 1));
    fractionResultat.denominator = denominator ;
    

    return fractionResultat.simplify();
}

Fraction Fraction::operator* (const Fraction frac) {
    // ! Variables Declaration
    Fraction fractionResultat;

    // ! Treatments
    fractionResultat.numerator = numerator * frac.numerator;
    fractionResultat.denominator = denominator * frac.denominator;

    return fractionResultat.simplify();
}

Fraction Fraction::operator* (const int n) {
    // ! Variables Declaration
    Fraction fractionResultat;

    // ! Treatments
    fractionResultat.numerator = numerator * n;
    fractionResultat.denominator = denominator;

    return fractionResultat.simplify();
}

Fraction Fraction::operator/ (const Fraction frac) {
    // ! Treatments
    Fraction fractionBase = {numerator, denominator};
    Fraction fractionBase2 = {frac.denominator, frac.numerator};
    

    return fractionBase * fractionBase2;
}

ostream& operator<<(std::ostream& out, /*const*/ Fraction& frac) {
    // ! Variables Declaration
    int numerator;
    int denominator;

    // ! Variables Definition
    numerator = frac.getNumerator();
    denominator = frac.getDenominator();

    // ! Treatments
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
    // ! Treatments
    if (frac.denominator == denominator) {
        return (numerator < frac.numerator);
    }

    return ((frac.numerator * denominator) < (numerator * frac.denominator));
}

bool Fraction::operator> (const Fraction frac) {
    // ! Treatments
    if (frac.denominator == denominator) {
        return (numerator > frac.numerator);
    }

    return ((frac.numerator*denominator) > (numerator*frac.denominator));
}

bool Fraction::operator= (Fraction frac) {
    // ! Treatments
    if (frac.denominator == denominator) {
        return (numerator = frac.numerator);
    }

    return (frac.numerator*denominator == numerator*frac.denominator);
}


//.  ===============================================================================================
//.                                           MATRICES                                              
//.  ===============================================================================================
Matrix::Matrix(const int x, const int y) {
    // ! Treatments
    n = x;
    m = y;
}

Matrix::Matrix(const int i) {
    // ! Treatments
    n = i;
    m = n;
}

void Matrix::show() {
    // ! Variables Declaration
    vector<double> maxValuesByColums;
    
    // ! Treatments
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
    // ! Treatments
    matrix = matrixArgument;
    n = matrix.size();
    m = matrix[0].size();
}


int Matrix::get_n() {
    // ! Treatments
    return n;
}


int Matrix::get_m(void) {
    // ! Treatments
    return m;
}


vector<vector<double>> Matrix::get_matrix() { return matrix; }

//.  ===============================================================================================
//.                                            NUMBERS                                              
//.  ===============================================================================================
int getSize(double number) {
    // ! Variables Declaration
    std::ostringstream streamObj;

    // ! Variables Definition
    streamObj << number;
    
    // ! Treatments
    return streamObj.str().size();
}

bool isInteger(double number) {
    // ! Treatments
    return !(double(number - (int)number) > 0);
}


int gcd(const int nb1, const int nb2) {
    // ! Variables Declaration
    int min;

    // ! Définition Variables
    min = (nb1 < nb2) ? nb1 : nb2;

    // ! Treatments
    for (int i = min; i <= min; i--) {
        if ((nb1 % i == 0) && (nb2 % i == 0)) {
            return i;
        }
    }

    return 1;
}

double roundTo(double number, int n) {
    // ! Variables Declaration
    stringstream tmp;

    // ! Variables Definition
    tmp << setprecision(n) << fixed << number;
    
    // ! Treatments
    return stod(tmp.str());  
}


double roundTom(double number, int n) {
    // ! Treatments
    return isInteger(number) ? number : roundTo(number, n);
}


//.  ===============================================================================================
//.                                            VECTORS                                              
//.  ===============================================================================================
double getMaxVector(vector<double> line) {
    // ! Variables Declaration
    int len, max;

    // ! Variables Definition
    len = line.size();
    max = line.at(0);

    // ! Treatments
    for (int i = 0; i < len; i++) {
        if (line.at(i) > max) {
            max = line.at(i);
        }
    }

    return max;
}

double getMinVector(vector<double> line) {
    // ! Variables Declaration
    int len, min;

    // ! Variables Definition
    len = line.size();
    min = line.at(0);

    // ! Treatments
    for (int i = 0; i < len; i++) {
        if (line.at(i) < min) {
            min = line.at(i);
        }
    }

    return min;
}

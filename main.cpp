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





// ! SUB-PROGRAMME DECLARATION



//.  ===============================================================================================
//.                                             MAIN                                                
//.  ===============================================================================================

int main(void) {
    // . Variable declarations
    Matrix M1(3);
    vector<vector<double>> matrice1;

    // . Variables Definition



    // . Treatments
    // cout << isInteger(a) << endl;
    // cout << isInteger(b) << endl;
    // cout << isInteger(c) << endl;
    
    // double test = roundTom(c, 1);
    // double test2 = roundTom(b, 0);

    // cout << test << endl;
    // cout << test2 << endl;

    // cout << "-- getSize" << endl;
    // cout << a << "--" << getSize(a) << endl;
    // cout << b << "--" << getSize(b) << endl;
    // cout << c << "--" << getSize(c) << endl;
    // cout << d << "--" << getSize(d) << endl;

    matrice1 = {
        {1, 2, 3},
        {4, -54, 6},
        {7, 84, 9}
    };

    M1.changeMatrix(matrice1);

    M1.show();



    return 0;
}


   // ! SUB-PROGRAMME DEFINITION


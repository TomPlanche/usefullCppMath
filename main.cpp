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

int main() {
    // . Variable declarations
    Matrix M1(3);
    Matrix M2(3, 4);
    Matrix M3(3);

    vector<vector<double>> matrice1;
    vector<vector<double>> matrice2;
    vector<vector<double>> matrice3;


    matrice1 = {
        {1, 2, 3},
        {4, -54, 6},
        {7, 84, 9}
    };

    matrice2 = {
        {1, 3, 5, 7},
        {9, 11, 13, 15},
        {17, 19, 21, 23}//,
        // {25, 27, 29, 31}
    };

    matrice3 = {
        {0, 0, 1},
        {0, 1, 0},
        {1, 0, 0}
    };


    M1.changeMatrix(matrice1);
    M2.changeMatrix(matrice2);
    M3.changeMatrix(matrice3);

    cout << M1 << endl;
    M1.det();


    return 0;
}


   // ! SUB-PROGRAMME DEFINITION


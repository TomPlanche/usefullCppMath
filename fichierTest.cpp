#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

double det(const vector<vector<double>> &matG) {
    const std::size_t nrows{matG.size()}, ncols{matG[0].size()};
    double detG = 0.0;
    if (nrows != ncols)
    {
        std::cout << "Error when using det: matrix is not square.\n";
        return detG;
    }

    const std::size_t nSize{nrows};
    std::size_t i{0}, j{0}, k{0};

    // ******************** Step 1: row permutation (swap diagonal zeros) ********************
    vector<vector<double>> matLU;
    std::vector<std::size_t> permuteLU; // Permute vector
    bool changeSign{false};

    for (i = 0; i < nSize; ++i)
    {
        permuteLU.push_back(i);
    }

    for (j = 0; j < nSize; ++j)
    {
        double maxv{0.0};
        for (i = j; i < nSize; ++i)
        {
            const double currentv{std::abs(matG[permuteLU[i]][j])};
            if (currentv > maxv)
            {
                maxv = currentv;
                if (permuteLU[i] != permuteLU[j]) // swap rows
                {
                    changeSign = !changeSign;
                    const std::size_t tmp{permuteLU[j]};
                    permuteLU[j] = permuteLU[i];
                    permuteLU[i] = tmp;
                }
            }
        }
    }

    for (i = 0; i < nSize; ++i)
    {
        matLU.push_back(matG[permuteLU[i]]);
    }

    // ******************** Step 2: LU decomposition (save both L & U in matLU) ********************
    if (matLU[0][0] == 0.0)
    {
        return detG; // Singular matrix, det(G) = 0
    }

    for (i = 1; i < nSize; ++i)
    {
        matLU[i][0] /= matLU[0][0];
    }

    for (i = 1; i < nSize; ++i)
    {
        for (j = i; j < nSize; ++j)
        {
            for (k = 0; k < i; ++k)
            {
                matLU[i][j] -= matLU[i][k] * matLU[k][j]; // Calculate U matrix
            }
        }
        if (matLU[i][i] == 0.0)
        {
            return detG; // Singular matrix, det(G) = 0
        }
        for (k = i + 1; k < nSize; ++k)
        {
            for (j = 0; j < i; ++j)
            {
                matLU[k][i] -= matLU[k][j] * matLU[j][i]; // Calculate L matrix
            }
            matLU[k][i] /= matLU[i][i];
        }
    }

    detG = 1.0;
    if (changeSign)
    {
        detG = -1.0; // Change the sign of the determinant
    }
    for (i = 0; i < nSize; ++i)
    {
        detG *= matLU[i][i]; // det(G) = det(L) * det(U). For triangular matrices, det(L) = prod(diag(L)) = 1, det(U) = prod(diag(U)), so det(G) = prod(diag(U))
    }

    return detG;
}

int main() {
    vector<vector<double>> matrice1;

    matrice1 = {
        {1, 2, 3},
        {4, -54, 6},
        {7, 84, 9}
    };

    cout << det(matrice1) << endl;

    return 0;
}
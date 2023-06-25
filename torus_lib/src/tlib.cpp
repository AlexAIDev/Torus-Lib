#include "../include/torus_lib/tlib.h"
#include <cmath>

namespace tlib
{
    double determinant(matrix mat, int size)
    {
        if (!mat.is_square())
            throw 2;
        if (size == 1)
            return mat[0][0];
        else if (size == 2)
            return (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);

        int det = 0;
        matrix submatrix(3, 3);

        for (int k = 0; k < size; k++)
        {
            int cofactor_i = 0;
            for (int i = 1; i < size; i++) 
            {
                int cofactor_j = 0;
                for (int j = 0; j < size; j++) 
                {
                    if (j != k) 
                    {
                        submatrix[cofactor_i][cofactor_j] = mat[i][j];
                        cofactor_j++;
                    }
                }
                cofactor_i++;
            }
            det += (std::pow(-1, k) * mat[0][k] * determinant(submatrix, size - 1));
        }
        return det;
    }  
} 

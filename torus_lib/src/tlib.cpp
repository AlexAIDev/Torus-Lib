#include "../include/torus_lib/tlib.h"
#include <cmath>
#include <vector>

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

    matrix& inverse(matrix mat); 

    matrix& dot(matrix mat1, matrix mat2)
    {
        if (mat1.get_cols() != mat2.get_rows())
        {
            printf("<!> Size of matrixes are incompatible\n");
            throw 3;
        }

        std::vector<std::vector<double>> vec(mat1.get_rows(), std::vector<double>(mat2.get_cols()));
        
        for (int i = 0; i < mat1.get_rows(); i++)
        {
            for (int j = 0; j < mat2.get_cols(); j++)
            {
                vec[i][j] = 0;
                for (int k = 0; k < mat1.get_cols(); k++)
                    vec[i][j] += mat1[i][k] * mat2[k][j];
            }
                
        }
        matrix* new_matrix = new matrix(vec);
        return *new_matrix;
    }

    vector& dot(vector, vector);
} 

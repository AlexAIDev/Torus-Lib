#include "../include/torus_lib/tlib.h"
#include <cmath>
#include <vector>

namespace tlib
{
    double determinant(array arr, int size)
    {
        if (!arr.is_square())
            throw 2;
        if (size == 1)
            return arr[0][0];
        else if (size == 2)
            return (arr[0][0] * arr[1][1]) - (arr[0][1] * arr[1][0]);

        int det = 0;
        array subarray(3, 3);

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
                        subarray[cofactor_i][cofactor_j] = arr[i][j];
                        cofactor_j++;
                    }
                }
                cofactor_i++;
            }
            det += (std::pow(-1, k) * arr[0][k] * determinant(subarray, size - 1));
        }
        return det;
    }

    array &inverse(array arr);

    array &dot(array arr1, array arr2)
    {
        if (arr1.get_cols() != arr2.get_rows())
        {
            printf("<!> Size of arrayes are incompatible\n");
            throw 3;
        }

        std::vector<std::vector<double>> vec(arr1.get_rows(), std::vector<double>(arr2.get_cols()));

        for (int i = 0; i < arr1.get_rows(); i++)
        {
            for (int j = 0; j < arr2.get_cols(); j++)
            {
                vec[i][j] = 0;
                for (int k = 0; k < arr1.get_cols(); k++)
                    vec[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
        array *new_array = new array(vec);
        return *new_array;
    }
}

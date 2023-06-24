#include <iostream>
#include <cmath>
#include "../include/torus_lib/matrix.h"

namespace tlib
{
    matrix::matrix(int rows, int cols)
    {
        this->rows = rows;
        this->cols = cols;

        for (int i = 0; i < rows; i++)
        {
            data.push_back({});
            for (int j = 0; j < cols; j++)
                data[i].push_back(1);
        }
    }

    matrix::matrix()
    {
        rows = cols = 0;
        data.push_back({});
    }

    matrix::matrix(const matrix &other)
    {
        this->rows = other.rows;
        this->cols = other.cols;
        this->data = other.data;
    }

    matrix::matrix(std::initializer_list<std::initializer_list<double>> init)
    {
        rows = init.size();
        cols = init.begin()->size();

        int i = 0;
        for (auto &row: init)
        {
            data.push_back({});
            for (auto &e: row)
                data[i].push_back(e);
            ++i;
        }
    }
    
    matrix::~matrix()
    {
        for (int i = 0; i < rows; i++)
            data[i].clear();   
    }

    double matrix::trace()
    {
        int tr = 0;
        if(is_square())
        {
            for (int i = 0; i < rows; i++)
                tr += data[i][i];
        }
        return tr;
    }

    bool matrix::is_square()
    {
        return rows == cols;
    }

    int matrix::get_size()
    {
        if (is_square())
            return rows;
        return 0;
    }

    // Move to other file
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
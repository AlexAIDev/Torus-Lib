#include <iostream>
#include <cmath>
#include "matrix.h"

namespace tlib
{
    matrix::matrix()
    {
        rows = cols = 0;
        data.push_back({});
    }

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

    std::ostream &operator<<(std::ostream &out, matrix &other)
    {
        for (int i = 0; i < other.rows; i++)
        {
            out << "[";
            for (int j = 0; j < other.cols; j++)
                out << " " << other.data[i][j];
            out << " ]\n";
        }
        return out;
    }

    double matrix::trace()
    {
        if (!is_square())
        {
            printf("Matrix is not square! It has size (%d, %d)\n", rows, cols);
            throw 3;
        }
        
        int tr = 0;
        for (int i = 0; i < rows; i++)
                tr += data[i][i];
        return tr;
    }

    bool matrix::is_square() { return rows == cols; }

    int matrix::get_rows() { return rows; }
    
    int matrix::get_cols() { return cols; }
} 
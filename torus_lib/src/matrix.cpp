#include <iostream>
#include <memory>
#include "../include/torus_lib/matrix.h"

namespace tlib
{
    matrix::matrix(int rows, int cols)
    {
        this->rows = rows;
        this->cols = cols;
    }

    matrix::matrix()
    {
        rows = cols = 0;
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
} 

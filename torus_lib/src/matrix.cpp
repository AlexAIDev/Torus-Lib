#include <iostream>
#include <cmath>
#include "../include/torus_lib/array.h"
#include <vector>

namespace tlib
{
    array::array()
    {
        rows = cols = 0;
        data.push_back({});
    }

    array::array(int rows, int cols)
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

    array::array(const array &other)
    {
        this->rows = other.rows;
        this->cols = other.cols;
        this->data = other.data;
    }

    array::array(std::initializer_list<std::initializer_list<double>> init)
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

    array::array(std::vector<std::vector<double>> vec)
    {
        rows = vec.size();
        cols = vec[0].size();
        data = vec;
    }
    
    array::~array()
    {
        for (int i = 0; i < rows; i++)
            data[i].clear();   
    }

    std::ostream &operator<<(std::ostream &out, array &other)
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

    double array::trace()
    {
        if (!is_square())
        {
            printf("array is not square! It has size (%d, %d)\n", rows, cols);
            throw 3;
        }
        
        int tr = 0;
        for (int i = 0; i < rows; i++)
                tr += data[i][i];
        return tr;
    }

    bool array::is_square() { return rows == cols; }

    int array::get_rows() { return rows; }
    
    int array::get_cols() { return cols; }
} 
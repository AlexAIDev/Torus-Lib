#ifndef TLIB_H
#define TLIB_H

#include "matrix.h"
#include "vector.h"

namespace tlib
{
    /*
     * Function to calculate matrix determinant
     * Arguments: (square matrix, matrix size)
    */
    double determinant(matrix, int); 

    /*
     * Function to calculate inverse matrix 
    */
    matrix& inverse(matrix); 

    /*
     * Matrix multiplication
    */
    matrix& dot(matrix, matrix);


    /*
     * Vector dot product
    */
    vector& dot(vector, vector);
} 

#endif
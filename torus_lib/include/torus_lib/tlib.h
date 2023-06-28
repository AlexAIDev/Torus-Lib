#ifndef TLIB_H
#define TLIB_H

#include "array.h"

namespace tlib
{
    /*
     * Function to calculate matrix determinant
     * Arguments: (square matrix, matrix size)
    */
    double determinant(array, int); 

    /*
     * Function to calculate inverse matrix 
    */
    array& inverse(array); 

    /*
     * Matrix multiplication
     * Vector dot product
    */
    array& dot(array, array);

} 

#endif
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <string>

namespace tlib
{
    class matrix
    {
        private:
            int rows;
            int cols;
            std::vector<std::vector<double>> data;

        public:
            /* Default constructor */
            matrix();

            /* Constructor arguments: (rows, columns) */
            matrix(int, int);

            /* Constructor of copying */
            matrix(const matrix &);

            matrix(std::vector<std::vector<double>>);

            /* 
             * Constructor arguments: ({...})
             * For example:
             * tlib::matrix m({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
             */
            matrix(std::initializer_list<std::initializer_list<double>>);

            /* Destructor */
            ~matrix();

            /* 
             * Calculation of matrix trace 
             * Trace - the sum of the elements of the main diagonal 
             */
            double trace();

            /*  Check if matrix is square */
            bool is_square();

            /* Return transopose matrix */
            matrix& transpose();
            
            /* Return number of rows */
            int get_rows();

            /* Return number of cols */
            int get_cols();

        // Operators overloading
        friend std::ostream &operator<<(std::ostream &out, matrix &other);
        
        matrix& operator=(const matrix &other)
        {
            if (this == &other)
               return *this;
            
            std::vector<std::vector<double>>().swap(data);
            std::cout << "Size: " << data.size() << std::endl;

            this->rows = other.rows;
            this->cols = other.cols;

            for (int i = 0; i < rows; i++)
            {
                data.push_back({});
                for (int j = 0; j < cols; j++)
                    data[i].push_back(other.data[i][j]);
            }
            return *this;
        }

        matrix& operator=(std::initializer_list<std::initializer_list<double>> init)
        {
            matrix* new_matrix = new matrix(init);
            return *new_matrix;
        }

        matrix& operator+(matrix &other)
        {
            if ((rows != other.rows) || (cols != other.cols))
            {
                printf("<!> Incorrect size of matrixes! (%d, %d) & (%d, %d) \n", rows, cols, other.rows, other.cols);
                throw 1;
            }
            matrix* new_matrix = this;

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                    new_matrix->data[i][j] += other.data[i][j];   
            }
            return *new_matrix;
        }

        std::vector<double>& operator[](int index)
        {
            if (index < 0 || index >= rows) 
            {
                printf("<!> Out of range! \n");
                throw 2;
            }
            return data[index];
        }
    };  
}
#endif
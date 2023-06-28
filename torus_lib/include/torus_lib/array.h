#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <vector>
#include <string>

namespace tlib
{
    class array
    {
        private:
            int rows;
            int cols;
            std::vector<std::vector<double>> data;

        public:
            /* Default constructor */
            array();

            /* Constructor arguments: (rows, columns) */
            array(int, int);

            /* Constructor of copying */
            array(const array &);

            array(std::vector<std::vector<double>>);

            /* 
             * Constructor arguments: ({...})
             * For example:
             * tlib::array m({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
             */
            array(std::initializer_list<std::initializer_list<double>>);

            /* Destructor */
            ~array();

            /* 
             * Calculation of matrix trace 
             * Trace - the sum of the elements of the main diagonal 
             */
            double trace();

            /*  Check if array is square */
            bool is_square();

            /* Return transopose array */
            array& transpose();
            
            /* Return number of rows */
            int get_rows();

            /* Return number of cols */
            int get_cols();

        // Operators overloading
        friend std::ostream &operator<<(std::ostream &out, array &other);
        
        array& operator=(const array &other)
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

        array& operator=(std::initializer_list<std::initializer_list<double>> init)
        {
            array* new_array = new array(init);
            return *new_array;
        }

        array& operator+(array &other)
        {
            if ((rows != other.rows) || (cols != other.cols))
            {
                printf("<!> Incorrect size of arrayes! (%d, %d) & (%d, %d) \n", rows, cols, other.rows, other.cols);
                throw 1;
            }
            array* new_array = this;

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                    new_array->data[i][j] += other.data[i][j];   
            }
            return *new_array;
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
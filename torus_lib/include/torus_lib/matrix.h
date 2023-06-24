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
            matrix();
            matrix(int, int);
            matrix(const matrix &);
            matrix(std::initializer_list<std::initializer_list<double>>);
            ~matrix();

            double trace();
            bool is_square();
            matrix& transpose();
            matrix& inverse();
            int get_size();

        friend std::ostream &operator<<(std::ostream &out, matrix &other)
        {
            for (int i = 0; i < other.rows; i++)
            {
                out << "|";
                for (int j = 0; j < other.cols; j++)
                    out << " " << other.data[i][j];
                out << " |\n";
            }
            return out;
        }
        
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
                throw std::out_of_range("Index out of range");

            return data[index];
        }
    };  

    double determinant(matrix, int);
} 
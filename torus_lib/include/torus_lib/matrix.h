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

        friend std::ostream &operator<<(std::ostream &out, matrix &other)
        {
            for (int i = 0; i < other.rows; i++)
            {
                out << "{";
                for (int j = 0; j < other.cols; j++)
                    out << " " << other.data[i][j];
                out << " }\n";
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
    };  
} 
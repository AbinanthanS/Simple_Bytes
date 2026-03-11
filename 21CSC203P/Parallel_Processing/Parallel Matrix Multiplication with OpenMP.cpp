#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

void parallel_matrix_multiplication(const vector<vector<int> >& A, 
                                     const vector<vector<int> >& B, 
                                     vector<vector<int> >& C) {
    int n = A.size(); 
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    const int size = 100;
    std::vector<std::vector<int> > A(size, std::vector<int>(size, 1));
    std::vector<std::vector<int> > B(size, std::vector<int>(size, 2));
    std::vector<std::vector<int> > C(size, std::vector<int>(size, 0));

    parallel_matrix_multiplication(A, B, C);

    std::cout << "Parallel Matrix Multiplication Result (C[0][0]): " << C[0][0] << std::endl;

    return 0;
}


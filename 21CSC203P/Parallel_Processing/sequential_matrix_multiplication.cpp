#include <iostream>
#include <vector>

void sequential_matrix_multiplication(const std::vector<std::vector<int> >& A, 
                                       const std::vector<std::vector<int> >& B, 
                                       std::vector<std::vector<int> >& C) {
    int n = A.size(); // assuming A is n x n
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
    const int size = 100; // Change size for larger matrices
    std::vector<std::vector<int> > A(size, std::vector<int>(size, 1));
    std::vector<std::vector<int> > B(size, std::vector<int>(size, 2));
    std::vector<std::vector<int> > C(size, std::vector<int>(size, 0));

    sequential_matrix_multiplication(A, B, C);

    std::cout << "Sequential Matrix Multiplication Result (C[0][0]): " << C[0][0] << std::endl;

    return 0;
}


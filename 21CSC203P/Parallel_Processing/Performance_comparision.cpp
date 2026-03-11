#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>

void sequential_matrix_multiplication(const std::vector<std::vector<int> >& A, 
                                       const std::vector<std::vector<int> >& B, 
                                       std::vector<std::vector<int> >& C) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void parallel_matrix_multiplication(const std::vector<std::vector<int> >& A, 
                                     const std::vector<std::vector<int> >& B, 
                                     std::vector<std::vector<int> >& C) {
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

  
    auto start = std::chrono::high_resolution_clock::now();
    sequential_matrix_multiplication(A, B, C);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> sequential_duration = end - start;

    std::cout << "Sequential Result (C[0][0]): " << C[0][0] << std::endl;
    std::cout << "Time taken (sequential): " << sequential_duration.count() << " seconds" << std::endl;

    
    std::fill(C.begin(), C.end(), std::vector<int>(size, 0));


    start = std::chrono::high_resolution_clock::now();
    parallel_matrix_multiplication(A, B, C);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> parallel_duration = end - start;

    std::cout << "Parallel Result (C[0][0]): " << C[0][0] << std::endl;
    std::cout << "Time taken (parallel): " << parallel_duration.count() << " seconds" << std::endl;

    return 0;
}


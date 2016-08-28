#linclude "summation.cu"

namespace aspl {

int calc(int *A, int n) {
    int *B;
    cudaMalloc(&B, sizeof(int)*n*n);
    cudaMemcpy(B, A, sizeof(int)*n*n, cudaMemcpyHostToDevice);
    apsp(B, n, n);
    return summation::calc(B, n*n);
}
}

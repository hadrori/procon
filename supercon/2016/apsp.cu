#include <cuda_runtime.h>
#include "macro.c"

#define NBS_X 64
#define NBS_Y 8

__global__ void naive_kernel(g_type *A, int n, int all_w) {
    const int i0 = blockIdx.y * blockDim.y + threadIdx.y;
    const int j  = blockIdx.x * blockDim.x + threadIdx.x;
    const int ws = NAIVE_BLOCK_SIZE_X + 1;
    __shared__ g_type B[NAIVE_BLOCK_SIZE_X * ws];
    for(int i = i0; i < n; i += blockDim.y)
        B[i * ws + j] = A[i * all_w + j];
    __syncthreads();
    rep(k,n) {
        for(int i = i0; i < n; i += blockDim.y)
            B[i*ws+j] = min(B[i*ws+j], B[i*ws+k] + B[k*ws+j]);
        __syncthreads();
    }
    for(int i = i0; i < n; i += blockDim.y) A[i*all_w+j] = B[i*ws+j];
}

void naive(int *A, int n, int all_w) {
    const dim3 grid(n/NBS_X, n/NBS_Y), block(NBS_X, NBS_Y);
    naive_kernel<<<grid, block>>>(A, n, all_w);
}

#define BS 256
#define B_W 64
#define B_H 64

__global__ void mul_kernel(g_type *C, g_type *A, g_type *B, int n, int all_w) {
    const int i = blockIdx.y * blockDim.y + threadIdx.y,
              j = blockIdx.x * blockDim.x + threadIdx.x;
    rep(k,n) C[i*n+j] = min(C[i*n+j], A[i*n+k]+B[k*n+j]);
}

void mul(g_type *C, g_type *A, g_type *B, int n, int all_w) {
    const gim3 grid(n/B_W, n/B_H), block(BS);
    mul_kernel<<<grid, block>>>(C, A, B, n, all_w);
}

void apsp(g_type *A, int n, int all_w) {
    if (n <= NBS_X) {
        naive(A, n, all_w);
    }
    else {
        const int h = n/2, a11 = 0, a12 = h, a21 = h*all_w, a22 = a21 + h;
        apsp(A+a11, h, all_w);
        mul(A+a12, A+a11, A+a12, h, all_w);
        mul(A+a21, A+a21, A+a11, h, all_w);
        mul(A+a22, A+a21, A+a12, h, all_w);
        apsp(A+a22, h, all_w);
        mul(A+a21, A+a22, A+a21, h, all_w);
        mul(A+a12, A+a12, A+a22, h, all_w);
        mul(A+a11, A+a12, A+a21, h, all_w);
    }
}

g_type sum(g_type *A) {
}

g_type aspl(g_type *A, int n) {
    g_type *B;
    cudaMalloc(&B, sizeof(g_type)*n*n);
    cudaMemcpy(B, A, sizeof(g_type)*n*n, cudaMemcpyHostToDevice);
    apsp(B, n, n);
    g_type ret = sum(B, n);
    cudaFree(B);
    return ret;
}

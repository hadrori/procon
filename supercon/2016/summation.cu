#include "cuda_runtime.h"
#include "cuda.h"

namespace summation {

template <unsigned int blockSize, bool nIsPow2>
__global__ void reduce(int *in, int *out, unsigned int n) {
    volatile extern __shared__ int s[];
    unsigned int  tid = threadIdx.x;
    unsigned int i = blockIdx.x*(blockSize*2)+tid;
    unsigned int gridSize = blockSize*2*gridDim.x;
    s[tid] = 0;
    while(i < n) {
        if(nIsPow2 || i + blockSize < n)
            s[tid] += in[i] + in[i+blockSize];
        i += gridSize;
    }
    __syncthreads();
    if(blockSize >= 2048) { if(tid < 1024) s[tid] += s[tid+1024]; __syncthreads(); }
    if(blockSize >= 1024) { if(tid <  512) s[tid] += s[tid+ 512]; __syncthreads(); }
    if(blockSize >=  512) { if(tid <  256) s[tid] += s[tid+ 256]; __syncthreads(); }
    if(blockSize >=  256) { if(tid <  128) s[tid] += s[tid+ 128]; __syncthreads(); }
    if(blockSize >=  128) { if(tid <   64) s[tid] += s[tid+  64]; __syncthreads(); }

    if(tid < 32) {
        if (blockSize >= 64) s[tid] += s[tid + 32];
        if (blockSize >= 32) s[tid] += s[tid + 16];
        if (blockSize >= 16) s[tid] += s[tid +  8];
        if (blockSize >=  8) s[tid] += s[tid +  4];
        if (blockSize >=  4) s[tid] += s[tid +  2];
        if (blockSize >=  2) s[tid] += s[tid +  1];
    }
    if(tid == 0) out[blockIdx.x] = s[0];
}

bool isPow2(int size) { return __builtin_popcount(size) == 1; }

void invoke_reduce_kernel(int *in, int *out, int blocks, int threads, int n) {
    int shared = (threads <= 32) ? 2 * sizeof(int) * threads : sizeof(int) * threads;
    dim3 dimBlock(threads, 1, 1);
    dim3 dimGrid(blocks, 1, 1);


    if (isPow2(n)) {
        switch(threads) {
        case 2048: reduce<2048, true><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        case 1024: reduce<1024, true><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        case  512: reduce< 512, true><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        case  256: reduce< 256, true><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        case  128: reduce< 128, true><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        case   64: reduce<  64, true><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        case   32: reduce<  32, true><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        case   16: reduce<  16, true><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        case    8: reduce<   8, true><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        case    4: reduce<   4, true><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        case    2: reduce<   2, true><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        case    1: reduce<   1, true><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        }
    } else {
        switch(threads) {
        case 2048: reduce<2048, false><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        case 1024: reduce<1024, false><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        case  512: reduce< 512, false><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        case  256: reduce< 256, false><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        case  128: reduce< 128, false><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        case   64: reduce<  64, false><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        case   32: reduce<  32, false><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        case   16: reduce<  16, false><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        case    8: reduce<   8, false><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        case    4: reduce<   4, false><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        case    2: reduce<   2, false><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        case    1: reduce<   1, false><<<dimGrid, dimBlock, shared>>>(in, out, n); break;
        }
    }
}

#define NPB (1024)  // number of calculation per block
#define NT (NPB/2) // number of thread

int calc(int *A, int n) {
    int blocks = n/NPB, threads = NT, result;
    while(blocks) {
        invoke_reduce_kernel(A, A, blocks, threads, n);
        blocks /= NPB;
    }
    cudaMemcpy(&result, &A[0], sizeof(int), cudaMemcpyDeviceToHost);
    return result;
}
}

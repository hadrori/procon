#define repi(i,a,b) for(int i = (a); (i) < (b); i++)
#define rep(i,n) repi(i,0,n)
#define INF = 1e8;

typedef int g_type;

#define at(i,j,w) (i*w+j)
int color(int k, int *col) { return k < col[0] ? 0 : (k < col[1] ? 1 : 2); }

void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

import std.stdio, std.string, std.conv;
import std.algorithm, std.array, std.bigint, std.math, std.range;
import core.thread;

//Input
string[] tokens;
int tokenId = 0;
string readToken(){
    for(;tokenId == tokens.length;)
        tokens = readln.split, tokenId = 0;
    return tokens[tokenId++];
}
int readInt(){ return to!int(readToken);}
long readLong(){ return to!long(readToken);}
string readString(){ return readToken;}
double readDouble(){ return to!double(readToken);}

//chmin/chmax
void chmin(T)(ref T t, T f) { if (t > f) t = f; }
void chmax(T)(ref T t, T f) { if (t < f) t = f; }

//Pair
struct Pair(S, T) {
    S x; T y;
    int opCmp(ref const Pair p) const { return (x < p.x) ? -1 : (x > p.x) ? +1 : (y < p.y) ? -1 : (y > p.y) ? +1 : 0; }
    string toString() const { return "(" ~ to!string(x) ~ ", " ~ to!string(y) ~ ")"; }
}
auto pair(S, T)(S x, T y) { return Pair!(S, T)(x, y); }

//Array
int binarySearch(T)(T[] as, bool delegate(T) test) {
    int low = -1, upp = as.length; for (; low + 1 < upp; ) { int mid = (low + upp) >> 1; (test(as[mid]) ? low : upp) = mid; } return upp;
}
int lowerBound(T)(T[] as, T val) { return as.binarySearch((T a){ return (a <  val); }); }
int upperBound(T)(T[] as, T val) { return as.binarySearch((T a){ return (a <= val); }); }
T[] unique(T)(T[] as) { T[] bs; foreach (a; as) if (bs == null || bs[$ - 1] != a) bs ~= a; return bs; }

BigInt n, x;
BigInt[] a;
BigInt sum;

void main(){
    n = (BigInt)readInt;
    x = (BigInt)readInt;
    foreach(i; 0..n){
        a ~= (BigInt)readInt;
        sum += a[i];
    }
    BigInt t = pow(x, sum);
    foreach(i; 0..n)
        s += t / a[i];
    writeln(gcd(s,t) % mod);
}

BigInt gcd(BigInt a, BigInt b){
    BigInt c;
    while( a != 0) {
        c = a;
        a = b % a;
        b = c;
    }
    return b;
}

BigInt pow(BigInt x, long e){
    if(e == 0) return 1;
    if(e % 2 == 0) return pow(x * x, e / 2);
    else return (x * pow(x, e - 1));
}

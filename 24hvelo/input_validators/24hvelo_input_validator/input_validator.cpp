#include "validation.h"

long long max_n = 3 * pow(10,5);

int main(int argc, char *argv[]) {
    InputValidator v(argc, argv);
    int n = v.read_integer("n", 0, 64);
    v.space();
    int k = v.read_integer("k", 0, max_n);
    v.newline();

    long long sum = 0;

    for (int i = 0; i < n; i++) {
       v.read_string("s", 1, 10000);
       v.space();
       int p = v.read_integer("p", 0, max_n);
       sum += p;

       v.newline();
    }

    if (sum > max_n) {
        v.WA("The input is not valid, sum exeed 10^5"); // Print error and exit with code 43.
    }
    return 0;
}

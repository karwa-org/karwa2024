#include "validation.h"

// Check the grammar of the input files.
// You should also check properties of the input.
// E.g., check that a graph is connected.

int main(int argc, char *argv[]) {
    InputValidator v(argc, argv);
    int n = v.read_integer("n", 1, 100000);
    v.space();
    int m = v.read_integer("m", 0, 1000000);
    v.newline();

    for(int i = 0; i < m; i++) {
        int u = v.read_integer("u", 1, 100000);
        v.space();
        int q = v.read_integer("v", 1, 100000);
        v.newline();
    }

    int s = v.read_integer("start", 1, 100000);
    v.newline();
    for(int i = 0; i < s; i++) {
        v.read_integer("s", 1, 100000);
        if(i < s-1) {
            v.space();
        }
    }
    v.newline();

    s = v.read_integer("end", 1, 100000);
    v.newline();
    for(int i = 0; i < s; i++) {
        v.read_integer("e", 1, 100000);
        if(i < s-1) {
            v.space();
        }
    }
    v.newline();
}

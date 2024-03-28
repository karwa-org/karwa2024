#include "validation.h"

// Check the grammar of the input files.
// You should also check properties of the input.
// E.g., check that a graph is connected.

int main(int argc, char *argv[]) {
    InputValidator v(argc, argv);
    int n = v.read_integer("n", 1, 1000000);
    v.newline();
    for (int i = 0; i < n; i++) {
        int a = v.read_integer("a", 1, 1000000000);
        v.space();
        int b = v.read_integer("b", 1, 1000000000);
        v.newline();
    }
    int m = v.read_integer("m", 1, 1000000);
    v.newline();
    for (int i = 0; i < m; i++) {
        int x = v.read_integer("x", 1, 1000000000);
        v.space();
        int y = v.read_integer("y", 1, 1000000000);
        v.newline();
    }

    return 0;
}

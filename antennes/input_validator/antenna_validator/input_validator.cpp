#include "validation.h"

// Check the grammar of the input files.
// You should also check properties of the input.
// E.g., check that a graph is connected.

int main(int argc, char *argv[]) {
    InputValidator v(argc, argv);
    int n = v.read_integer("n", 1, 1000000);
    v.newline();
    for (int i=0; i < n; i++) {
        int b = v.read_integer("b", 1, 1000000);
        v.newline();
    }
    for (int i=0; i < n; i++) {
        int c = v.read_integer("c", 1, 1000000);
        v.newline();
    }
}

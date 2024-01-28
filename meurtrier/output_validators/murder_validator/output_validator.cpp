#include "validation.h"
#include <string>
// For INTERACTIVE PROBLEMS:
// Write your output validator as usual, but make sure to flush all standard
// output. Call `v.set_WA_handler(lambda)` to gracefully handle failures when
// parsing team output. You could e.g. send a '-1' to the submission to tell it
// to stop running.

// Sample file format:
/*
* n_people
* people_1
* ......
* people_n
* mode
* - secret:
*   - murderer
*   - n_vertex
*   - tree with layout
*/


using namespace std;

void validate_secret(std::ifstream& in, OutputValidator& v, int& n_people) {
    string murder; in >> murder;
    int n_vertex; in >> n_vertex;

    int max_querry = (n_people - 1); 

    map<string, map<string,bool>> seen;

    for(int i = 0; i < n_vertex; i++) {
        string u, v; in >> u >> v; // u à vu v
        seen[u][v] = true;
    }

    // Interaction 
    int n_queries = 0;
    while (true) {
        auto op = v.read_string("op", 1, 1, "?!");
        v.space();

        if (op == "?") {
            string person_a = v.read_string("person_a", 1, 10e6);
            v.space();
            string person_b = v.read_string("person_b", 1, 10e6);
            v.newline();

            
            if(seen[person_a][person_b]) {
                cout << "OUI" << endl;
            } else {
                cout << "NON" << endl;
            }

            n_queries++;

            if(n_queries > (max_querry * 2)) {
                v.WA("Used more than ", max_querry * 2, " queries (aborted)");
            }

        } else if (op == "!") {
            string student_ans = v.read_string("student_ans", 1, 10e6, murder);
            v.newline();

            if (n_queries > max_querry) {
                v.WA("Used ", n_queries, " queries, only ", max_querry, " allowed");
            }
            cerr << "Used "<< n_queries  << " queries " << "with " << max_querry << " available" << endl;
            break;
        } else {
            v.WA("Unknown op ", op);
        }
    }
}

int main(int argc, char *argv[]) {
    // Set up the input and answer streams.
    std::ifstream in(argv[1]);
    OutputValidator v(argc, argv);

    // From generated file
    int n_people; in >> n_people;
    cout << n_people << endl;

    for(int i = 0; i < n_people; i++) {
        string people; in >> people;
        cout << people << endl;
    }

    string mode; in >> mode;

    if (mode == "secret") {
        validate_secret(in, v, n_people);
    } else {
        cerr << "Invalid mode: " << mode << endl;
        exit(1);
    }

    return 0;
    
}

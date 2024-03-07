#include "validation.h"

// For FIXED OUTPUT PROBLEMS:
// This program will be called as
// output_validator input < ans
//
// You should verify the grammar of the answer file.
// See input_validator.cpp for information on how to use the Validator class.
// Furthermore you should check simple properties of the answer.

// For DYNAMIC OUTPUT PROBLEMS:
// This program will be called as
// output_validator input answer < team_output
//
// Please check the grammar of the team output using the Validator class.
// See input_validator.cpp for information on how to use the Validator class.
// You should also check the validity of the answer here.
// For example, check that a tree printed by the team is a tree indeed.

// For INTERACTIVE PROBLEMS:
// Write your output validator as usual, but make sure to flush all standard
// output. Call `v.set_WA_handler(lambda)` to gracefully handle failures when
// parsing team output. You could e.g. send a '-1' to the submission to tell it
// to stop running.

// TODO: Remove these comments, and summarize your output validator.
using namespace std;

int main(int argc, char *argv[]) {
    // Set up the input and answer streams.
    std::ifstream in(argv[1]);
    std::ifstream ans(argv[2]); // Only for custom checker.

    OutputValidator v(argc, argv);

    string input;
    ans >> input;

    string first = v.read_string("first", 1, pow(10,4));

    if(input != first) {
        v.WA("First doesn t match got :", first, " expected :", input);
    }

    if(input != "BOOM!"){
        v.space();
        string second = v.read_string("second", 1, pow(10,4));
        string student_sec; ans >> student_sec;
        if(input != first) {
            v.WA("Second doesn t match");
        }
    }
    
    v.newline();
}

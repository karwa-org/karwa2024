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

    int n;
    in >> n;
    vector<int> inside(1e6+1);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int t;
        in >> t;

        inside[sum+t] = true;
        sum += t;
        
    }

    int student_power = v.read_integer("power", 2, (int)1e6);
    v.space();
    int student_cup = v.read_integer("cup", 1, (int)1e6);

    int ans_power; ans >> ans_power;
    int ans_cup; ans >> ans_cup;

    if(ans_cup != student_cup){
        v.WA("the number of cup is different");
    }

    int check_cup = 0;
    //check if the student power is correct and leads to the student_cup;
    for(int i = student_power; i <= sum; i+=student_power){
        if(inside[i]){
            check_cup++;
        }
    }

    if(check_cup != student_cup){
        v.WA("the number of cup is different, student made something strange");
    }

    v.newline();
}

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

using namespace std;

// TODO: Remove these comments, and summarize your output validator.

int main(int argc, char *argv[]) {
    // Set up the input and answer streams.
    std::ifstream in(argv[1]);
    std::ifstream ans(argv[2]); // Only for custom checker.
    OutputValidator v(argc, argv);
    map<string, int> mapper;

    int n, k;
    in >> n >> k;

    for (int i = 0; i < n; i++) {
        string s; in >> s;
        int c; in >> c;
        mapper[s] = c;
    }

    int ans_n; ans >> ans_n;

    int student_n = v.read_integer("answer", -1, 64);
    map<string, int> cnt;
    int sum = 0;
    int target_sum = 0;

    if(student_n == ans_n){
        if(ans_n == -1){
            return 42;
        }

        for (int i = 0; i < ans_n; i++) {
            string s; ans >> s;
            target_sum += mapper[s];
        }

        for(int i = 0; i < student_n; i++ ) {
            string s = v.read_string("item", 1, (int)10e6);

            cnt[s]++;
            if (cnt[s] > 1) {
                return 43;
            }
            sum += mapper[s];
        }

        if(sum != target_sum){
            return 43;
        }

    }else{
        return 43;
    }
    
}

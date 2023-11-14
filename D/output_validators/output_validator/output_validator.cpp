#include "validation.h"

using namespace std;

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

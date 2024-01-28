#include "validation.h"

using namespace std;

int main(int argc, char *argv[]) {
    // Set up the input and answer streams.
    std::ifstream in(argv[1]);
    std::ifstream ans(argv[2]); // Only for custom checker.
    OutputValidator v(argc, argv);

    map<string, int> mapper;
    map<string, int> cnt;

    /*************************************************************************************/
    /*                                  READ INPUT FILE                                  */
    /*************************************************************************************/
    int n, k;
    in >> n >> k;

    for (int i = 0; i < n; i++) {
        string s; in >> s;
        int c; in >> c;
        mapper[s] = c;
    }


     /*************************************************************************************/
    /*                                  READ ANS & student FILE                           */
    /*************************************************************************************/
    int ans_n; ans >> ans_n;

    int student_n = v.read_integer("answer", -1, 64);
    v.newline();
    int sum = 0;
    int target_sum = 0;

    if(student_n == ans_n){
        if(ans_n == -1){
            return 42;
        }

        // read ans target sum
        for (int i = 0; i < ans_n; i++) {
            string s; ans >> s;
            target_sum += mapper[s];
        }

        // check if student target doesn't include more than 1 item
        for(int i = 0; i < student_n; i++ ) {
            string s = v.read_string("item", 1, (int)10e6);
            v.newline();
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
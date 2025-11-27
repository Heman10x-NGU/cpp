#include <iostream>
#include <vector>
#include <numeric>

long long ask(int type, int l, int r) {
    std::cout << type << " " << l << " " << r << std::endl;
    long long response;
    std::cin >> response;
    return response;
}


void solve() {
    int n;
    std::cin >> n;


    long long sum_a_full = ask(2, 1, n);

    long long sum_p_full = ask(1, 1, n);

    int len = sum_a_full - sum_p_full;


    int low = 1, high = n;
    int ans_r = n; 

    while (low <= high) {
        int mid = low + (high - low) / 2;


        long long sum_a_prefix = ask(2, 1, mid);
        long long sum_p_prefix = ask(1, 1, mid);
        long long intersection_len = sum_a_prefix - sum_p_prefix;

        if (intersection_len == len) {

            ans_r = mid;
            high = mid - 1;
        } else {

            low = mid + 1;
        }
    }


    int ans_l = ans_r - len + 1;


    std::cout << "! " << ans_l << " " << ans_r << std::endl;
}

int main() {

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
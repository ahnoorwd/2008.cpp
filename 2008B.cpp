#include <iostream>
#include <cmath>
using namespace std;

// Function to check if n is a perfect square
bool is_perfect_square(int n) {
    int sqrt_n = sqrt(n);
    return (sqrt_n * sqrt_n == n);
}

// Function to check if the string represents a valid beautiful binary matrix
bool is_beautiful_matrix(string s, int size) {
    int n = sqrt(size);  // size of the matrix is n x n

    // Check first and last rows (all ones)
    for (int j = 0; j < n; ++j) {
        if (s[j] != '1' || s[(n - 1) * n + j] != '1') {
            return false;
        }
    }

    // Check first and last columns (all ones)
    for (int i = 0; i < n; ++i) {
        if (s[i * n] != '1' || s[i * n + (n - 1)] != '1') {
            return false;
        }
    }

    // Check interior elements (must be zeros)
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < n - 1; ++j) {
            if (s[i * n + j] != '0') {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int test_cases;  // Number of test cases
    cin >> test_cases;

    while (test_cases--) {
        int length;
        string binary_string;

        // Read the length of the string and the string itself
        cin >> length >> binary_string;

        // Check if length is a perfect square
        if (is_perfect_square(length)) {
            // Check if the string can form a valid beautiful binary matrix
            if (is_beautiful_matrix(binary_string, length)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}

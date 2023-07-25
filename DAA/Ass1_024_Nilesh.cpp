#include <iostream>
using namespace std;

class FibonacciCalculator {
public:
    // Recursive function to calculate Fibonacci numbers
    int fibonacciRecursive(int n) {
        if (n <= 0)
            return 0;
        else if (n == 1)
            return 1;
        else
            return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }

    // Non-recursive function to calculate Fibonacci numbers
    int fibonacciNonRecursive(int n) {
        if (n <= 0)
            return 0;

        int prev = 0;
        int curr = 1;

        cout << "Fibonacci sequence (Non-Recursive): ";
        cout << prev << " " << curr << " ";

        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
            cout << curr << " ";
        }
        cout << endl;
        return curr;
    }

    // Recursive function to print Fibonacci numbers
    void printFibonacciRecursive(int n) {
        cout << "Fibonacci sequence (Recursive): ";
        for (int i = 0; i <= n; i++) {
            cout << fibonacciRecursive(i) << " ";
        }
        cout << endl;
    }
};

int main() {
    int choice, num;
    FibonacciCalculator fibCalculator;

    do {
        cout << "Menu:" << endl;
        cout << "1. Calculate Fibonacci (Recursive)" << endl;
        cout << "2. Calculate Fibonacci (Non-Recursive)" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the number to calculate Fibonacci: ";
            cin >> num;
            fibCalculator.printFibonacciRecursive(num);
            break;
        case 2:
            cout << "Enter the number to calculate Fibonacci: ";
            cin >> num;
            fibCalculator.fibonacciNonRecursive(num);
            break;
        case 3:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    } while (choice != 3);

    return 0;
}

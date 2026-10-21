#include <iostream>
#include <vector>
using namespace std;

int knapsack(int n, int capacity, vector<int>& weight, vector<int>& profit) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w],
                               profit[i - 1] + dp[i - 1][w - weight[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "\nSelected items: ";
    int w = capacity;

    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << i << " ";
            w -= weight[i - 1];
        }
    }

    return dp[n][capacity];
}

int main() {
    int n = 0, capacity = 0;
    vector<int> weight, profit;
    int choice;

    do {
        cout << "\n\n--- 0-1 Knapsack Menu ---";
        cout << "\n1. Enter item details";
        cout << "\n2. Display item details";
        cout << "\n3. Solve Knapsack";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number of items: ";
                cin >> n;

                weight.resize(n);
                profit.resize(n);

                for (int i = 0; i < n; i++) {
                    cout << "Enter weight and profit of item " << i + 1 << ": ";
                    cin >> weight[i] >> profit[i];
                }

                cout << "Enter knapsack capacity: ";
                cin >> capacity;
                break;

            case 2:
                if (n == 0) {
                    cout << "Please enter item details first.";
                } else {
                    cout << "\nItem\tWeight\tProfit\n";
                    for (int i = 0; i < n; i++) {
                        cout << i + 1 << "\t" << weight[i]
                             << "\t" << profit[i] << "\n";
                    }
                    cout << "Capacity: " << capacity;
                }
                break;

            case 3:
                if (n == 0 || capacity < 0) {
                    cout << "Please enter valid item details first.";
                } else {
                    int result = knapsack(n, capacity, weight, profit);
                    cout << "\nMaximum profit: " << result;
                }
                break;

            case 4:
                cout << "Exiting program.";
                break;

            default:
                cout << "Invalid choice. Try again.";
        }
    } while (choice != 4);

    return 0;
}

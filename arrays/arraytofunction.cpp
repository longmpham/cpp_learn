#include <iostream>

// Function prototype
void sumofarray(int arr[], int size);

void sumofarray(int arr[], int size) {
    int sum {0};

    // Use range-based for loop to sum up the elements
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    
    std::cout << sum << std::endl;
}

int main() {
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    // Pass array to function to get the sum
    sumofarray(arr, size);

    // Print the array elements (if you want to display them)
    for (auto i : arr) {
        std::cout << i << " ";
    }

    return 0;
}


// #include <iostream>
// #include <vector>

// int sumofarray(std::vector<int>& arr);

// int main() {
//     std::vector<int> arr = {1, 2, 3, 4, 5};

//     // Pass array to function to get the sum and add it to the end
//     sumofarray(arr);

//     for (const auto& i : arr) {
//         std::cout << i << " ";
//     }

//     return 0;
// }

// int sumofarray(std::vector<int>& arr) {
//     int sum = 0;
//     for (const auto& i : arr) {
//         sum += i;
//     }

//     arr.push_back(sum); // Append the sum to the vector
//     return sum;
// }

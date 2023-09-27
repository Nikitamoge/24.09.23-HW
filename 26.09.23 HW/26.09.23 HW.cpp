#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

//Task 1
#define size 5

int main() {
    int array[size];
    int* negative_left = 0, * negative_right = 0;

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 41 - 20;
        cout << array[i] << " ";
        if (array[i] < 0) {
            if (negative_left == 0) negative_left = &array[i];
            negative_right = &array[i];
        }
    }
    cout << "\n";

    for (int* i = negative_left; i < negative_right; i++) {
        for (int* j = negative_left; j < negative_right; j++) {
            if (*j > *(j + 1)) {
                int prov = *j;
                *j = *(j + 1);
                *(j + 1) = prov;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }


//Task 2
void arr_mix(int arr[], int n) {
    srand(time(0));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(arr[i], arr[j]);
    }
}

int random_num_in_arr(int arr[], int n, int num) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1;
}

void sort_arr(int arr[], int n, bool ascending_and_descending) {
    for (int i = 0; i < n - 1; i++) {
        int min_max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if ((ascending_and_descending && arr[j] < arr[min_max_idx]) || (!ascending_and_descending && arr[j] > arr[min_max_idx])) {
                min_max_idx = j;
            }
        }
        swap(arr[min_max_idx], arr[i]);
    }
}

int main() {
    int arr[20];
    for (int i = 0; i < 20; i++) {
        arr[i] = i + 1;
    }

    arr_mix(arr, 20);

    cout << "mixed array: ";
    for (int i = 0; i < 20; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    int random_num = rand() % 20 + 0;
    cout << "random number: " << random_num << "\n";

    int pos = random_num_in_arr(arr, 20, random_num);
    cout << "positin of the random number in array: " << pos << "\n";

    sort_arr(arr, pos, false);
    sort_arr(arr + pos, 20 - pos, true);

    cout << "sorted array: ";
    for (int i = 0; i < 20; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

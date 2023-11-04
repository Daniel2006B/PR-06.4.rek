#include <iostream>
#include <iomanip>

using namespace std;

int* Create(int n) {
    int* arr = new int[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return arr;
}

void Print(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << setw(4) << arr[i];
    }
    cout << endl;
}

void ZeroIndex(int n, int* arr, int i, int& firsti, int& lasti) {
    if (i == n) {
        return;
    }
    if (arr[i] == 0) {
        if (firsti == -1) {
            firsti = i;
        }
        else {
            lasti = i;
        }
    }
    ZeroIndex(n, arr, i + 1, firsti, lasti);

}
int Sum(int n, int* arr, int i, int lasti) {

  
    if (i != -1 && lasti != -1 && i!=lasti) {
        
           return  arr[i] +Sum(n, arr, i+1, lasti);
        
    }
    else {
        return 0;
    }
}

int Product(int n, int* arr, int i) {
    if (i == n) {
        return 1;
    }
        if (i % 2 == 0) {
            return  arr[i] + Product(n, arr, i + 1);
        }
        else {
            return Product(n, arr, i + 1);
        }
   
}

void Transform(int n, int* arr) {
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] < 0 && arr[j + 1] >= 0) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int* arr = Create(n);

    cout << "Array elements: ";
    Print(arr, n);
    int firsti=-1, lasti=-1;
    ZeroIndex(n, arr, 0, firsti, lasti);
    int product = Product(n, arr,0);
    int sum = Sum(n, arr, firsti, lasti);

    cout << "Product of elements with even indices: " << product << endl;
    cout << "Sum of elements between the first and last zero elements: " << sum << endl;

    Transform(n, arr);
    Print(arr, n);

    delete[] arr;

    return 0;
}

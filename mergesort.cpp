#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

void merge(vector < int > & a, int low, int high, int mid) {
    int i, j, k;

    int c[a.size()];

    i = low;
    k = low;
    j = mid + 1;

    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            c[k] = a[i];
            k++;
            i++;
        } else {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++) {
        a[i] = c[i];
    }
}
void mergeSort(vector < int > & a, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, high, mid);
    }

}
int main(){
    int a,b;
    cin >> a;
    vector<int> vec(a);
    for(int i = 0;i < a;i++){
        vec[i] = rand() % 100 + 1;
    }
    mergeSort(vec,0,a-1);
    cout << "before" << endl;
    cout << '{';
    for(int i = 0;i < vec.size();i++) i == vec.size()-1 ? cout << vec[i] << '}' << endl : cout << vec[i] << " ";
    cout << "after" << endl;
    cout << '{';
    for(int i = 0;i < vec.size();i++) i == vec.size()-1 ? cout << vec[i] << '}' << endl : cout << vec[i] << " ";
}

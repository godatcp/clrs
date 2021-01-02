#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
int main(){
    int a,b;
    cout << "number of elements" << endl;
    cin >> a;
    cout << "enter elements" << endl;
    vector<int> vec;
    for(int i = 0;i < a;i++){
        cin >> b;
        vec.push_back(b);
    }
    for(int j = 1;j < vec.size();j++){
        int key = vec[j];
        int i = j-1;
        while(i >= 0 && vec[i] > key){
            vec[i+1] = vec[i];
            i = i-1;
        }
        vec[i+1] = key;
    }
    cout << "[";
    for(int i = 0;i < vec.size();i++) i == vec.size()-1 ? cout << vec[i] : cout << vec[i] << " ";
    cout << "]" << endl;
}
// Maximize the value of the expression

#include <bits/stdc++.h>
#include "vecsub"
using namespace std;

int maximizeExpression(vector<int>& a){
    int n = a.size();
    if(n < 4) return 0;

    vector<int> first(n+1, INT32_MIN), second(n, INT_MIN), third(n-1, INT_MIN), fourth(n-2, INT_MIN);
    for(int i=n-1; i>=0; i--){
        first[i] = max(first[i+1], a[i]);
    }

    for(int i=n-2; i>=0; i--){
        second[i] = max(second[i+1], first[i+1] - a[i]);
    }

    for(int i=n-3; i>=0; i--){
        third[i] = max(third[i+1], second[i+1] + a[i]);
    }

    for(int i=n-4; i>=0; i--){
        fourth[i] = max(fourth[i+1], third[i+1] - a[i]);
    }

    cout << fourth[0] << "\n";

    return fourth[0];
}



int main(){
    int n;
    cin >> n;
    vector<int> a(n);    
    fill(a, n);
    maximizeExpression(a);
}
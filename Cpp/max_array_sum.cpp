/**
Given an array of integers, find the subset of non-adjacent elements with the maximum sum. Calculate the sum of that subset.
For example, given an array [-2, 1, 3, -4, 5]
we have the following possible subsets:
Subset      Sum
[-2, 3, 5]   6
[-2, 3]      1
[-2, -4]    -6
[-2, 5]      3
[1, -4]     -3
[1, 5]       6
[3, 5]       8
Our maximum subset sum is 8
**/
int maxSubsetSum(vector<int> arr) {
    vector<int> L(arr.size(),0);
    L[0] = max(0,arr[0]);
    L[1] = max(L[0],arr[1]);
    for(int i=2; i < arr.size(); i++) {
        L[i] = max(L[i-1], max(arr[i],L[i-2] + arr[i]));
    }
    return L[arr.size()-1];
}

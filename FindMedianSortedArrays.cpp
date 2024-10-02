#include<iostream>
#include<vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    int i = 0, j = 0;
    int sz_nums1 = nums1.size(), sz_nums2 = nums2.size();
    vector<int> temp;
    while(i < sz_nums1 && j < sz_nums2)
    {
        int nextVal;
        if(nums1[i] < nums2[j])
            nextVal = nums1[i++];
        else
            nextVal = nums2[j++];
        temp.push_back(nextVal);
    }
    
    while(i < nums1.size())
        temp.push_back(nums1[i++]);
    while(j < nums2.size())
        temp.push_back(nums2[j++]);
    
    if(temp.size() % 2 != 0)
        return temp[temp.size() / 2];
    else
    {
        int mid = temp.size() / 2;
        float m1 = temp[mid];
        float m2 = temp[mid-1];
        return (m1 + m2) / 2;
    }
}
/*
void merge(int* arr, int l, int mid, int r)
{
    int i = l, j = mid + 1;
    int k = 0;
    int temp[10000];
    // stored value into 1 array
    while(i <= mid && j <= r)
    {
        int nextVal;
        if(arr[i] < arr[j]) 
            nextVal = arr[i++];
        else 
            nextVal = arr[j++];
        temp[k++] = nextVal;
    }
    // stored remain value
    while(i <= mid) 
        temp[k++] = arr[i++];
    while(j <= r)
        temp[k++] = arr[j++];
    // modify into input array (arr)
    for(int i = 0; i < k; i++)
        arr[l+i] = temp[i];
}

void mergeSort(int* arr, int l, int r)
{
    if(l >= r) return;
    int mid = (l+r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
}
*/
int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = { 3, 4 };
    float result = findMedianSortedArrays(nums1, nums2);
    return 0;
}
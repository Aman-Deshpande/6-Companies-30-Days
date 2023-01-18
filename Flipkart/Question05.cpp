// https://leetcode.com/problems/find-in-mountain-array/description/


// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
  public:
    int get(int index);
    int length();
};


class Solution {
    private:
    int peakEle(MountainArray &mountainArr){
        int n = mountainArr.length();

        int start = 0;
        int end = n-1;

        while(start<end){
            int mid = start+(end-start)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                start=mid+1;
            }else{
                end=mid;
            }
        }

        return start;
    }

    int binarySearch1(int target, MountainArray &mountainArr, int start, int end){
        while(start<=end){
            int mid = start+(end-start)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }else if(mountainArr.get(mid)<target){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }

        return -1;
    }

    int binarySearch2(int target, MountainArray &mountainArr, int start, int end){
        while(start<=end){
            int mid = start+(end-start)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }else if(mountainArr.get(mid)<target){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }

        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peakEleInd = peakEle(mountainArr);
        int n = mountainArr.length();

        int found1 = binarySearch1(target, mountainArr, 0, peakEleInd);
        if(found1==-1){
            return binarySearch2(target, mountainArr, peakEleInd, n-1);
        }
    
        return found1;
    }
};
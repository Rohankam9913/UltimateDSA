class Solution {
public:
    int findPeakIndex(MountainArray &mountainArr) {
        int low = 0, high = mountainArr.length()-1;

        while(low < high) {
            int mid = low + (high-low)/2;
            if(mountainArr.get(mid) > mountainArr.get(mid+1)) {
                high = mid;
            } else {
                low = mid+1;
            }
        }

        return low;
    }

    int findInLeft(int peakIdx,MountainArray &mountainArr,int target) {
        int low = 0, high = peakIdx;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(mountainArr.get(mid) == target) {
                return mid;
            } else if(mountainArr.get(mid) > target) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return -1;
    }

    int findInRight(int peakIdx,MountainArray &mountainArr,int target) {
        int low = peakIdx+1,high = mountainArr.length()-1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(mountainArr.get(mid) == target) {
                return mid;
            } else if(mountainArr.get(mid) > target) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peakIdx = findPeakIndex(mountainArr);
        int targetIdx = findInLeft(peakIdx,mountainArr,target);
        if(targetIdx != -1) {
            return targetIdx;
        }
        targetIdx = findInRight(peakIdx,mountainArr,target);
        return targetIdx;
    }
};
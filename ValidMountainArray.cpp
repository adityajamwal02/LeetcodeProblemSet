class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<=2)
            return false;
        bool peak,valley;
        int maxelement=arr[0], pos=0, countpeak=0, countvalley=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>maxelement){
                maxelement=arr[i];
                pos=i;
            }
        }
        for(int i=0;i<=pos;i++){
            if(arr[i]<arr[i+1])
                countpeak++;
        }
        for(int i=pos;i<arr.size()-1;i++){
            if(arr[i]>arr[i+1])
                countvalley++;
        }
        if(countpeak==pos and countvalley==(arr.size()-pos-1) and countvalley!=0 and countpeak!=0)
            return true;

    return false;
    }
};

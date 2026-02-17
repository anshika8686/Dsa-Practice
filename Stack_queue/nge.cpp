vector<int> nge(vector<int>&nums){
    suffix[n-1]=arr[n-1];{
        for(i=n-2;i>=0;i--)
        {
            suffix[i]=max(suffix[i+1],nums[i]);
        }
    }
    return suffix;
}
vector<int> nse(vector<int>&nums){
    suffix[n-1]=arr[n-1];{
        for(i=n-2;i>=0;i--)
        {
            suffix[i]=min(suffix[i+1],nums[i]);
        }
    }
    return suffix;
}
vector<int> pse(vector<int>&nums){
    prefix[0]=arr[0];{
        for(i=1;i<n;i++)
        {
            prefix[i]=min(prefix[i-1],nums[i]);
        }
    }
    return prefix;
}
vector<int> pge(vector<int>&nums){
    prefix[0]=arr[0];{
        for(i=1;i<n;i++)
        {
            prefix[i]=max(prefix[i-1],nums[i]);
        }
    }
    return prefix;
}

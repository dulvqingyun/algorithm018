void moveZeros(vector<int> nums){
	
	 int i,j;
	for(i=0,j=0;i<nums.size();i++){
		if(nums[i]!=0){
			swap(nums[i],nums[j]);
			j++;
		}
	}
	
}
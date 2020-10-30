    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int sz = nums.size();
        if(!sz||k>sz) return {};
        vector<int> result;
   
        for(int i=0;i<=sz-k;i++){
            int temp = nums[i];
            for(int j =i;j<i+k;j++){
                if(temp<nums[j]) temp = nums[j];
            }   
            result.push_back(temp);
        }
        return result;
    }
	
	
	
	
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> ans;
	deque<int> deq;
	int n = nums.size();
	for (int i = 0; i < n; i++) {
		//新元素入队时如果比队尾元素大的话就替代队尾元素，维持一个递减队列
		while (!deq.empty() && nums[i] > nums[deq.back()]) {
			deq.pop_back();
		}
		//检查队首的index是否在窗口内，不在的话需要出队
		if (!deq.empty() && deq.front() < i - k + 1)
			deq.pop_front();
		deq.push_back(i);
		if (i >= k - 1) 
			ans.push_back(nums[deq.front()]);
	}
	return ans;
}
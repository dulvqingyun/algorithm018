vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> table;
	int length = nums.size();
	if (length < 1) return{};
	for (int i = 0; i < length; i++)
	{
		if (table.count(nums[i]) > 0) {

			return{ table[nums[i]], i };
		}
		else {
			table[target - nums[i]] = i;
		}

	}
	return {};
}
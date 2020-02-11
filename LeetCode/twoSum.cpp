/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		vector<int> index(2, 0);
		if (nums.empty() || nums.size() == 1)
		{
			return index;
		}
		for (size_t i = 0; i < nums.size() - 1; ++i)
		{
			for (size_t j = i + 1; j < nums.size(); ++j)
			{
				if (nums[i] + nums[j] == target)
				{
					index.clear();
					index.push_back(i);
					index.push_back(j);
					break;
				}
			}
		}
		return index;
	}
};
	//hashMap

int main()
{
	vector<int> a = { 2,7,11,15 };
	const int target = 9;
	vector<int> b;
	Solution s;
	b = s.twoSum(a, target);
	cout << b[0] << " " << b[1];
	return 0;
}

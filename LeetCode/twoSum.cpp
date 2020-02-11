/*
����һ���������� nums ��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ���� ���� ���������������ǵ������±ꡣ

����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ��㲻���ظ��������������ͬ����Ԫ�ء�

ʾ��:

���� nums = [2, 7, 11, 15], target = 9

��Ϊ nums[0] + nums[1] = 2 + 7 = 9
���Է��� [0, 1]
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

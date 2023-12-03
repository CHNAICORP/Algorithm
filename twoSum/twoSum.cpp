#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		// 哈希表存储数据元素和对应的索引
		std::unordered_map<int, int> num_map;
		for (int i = 0; i < nums.size(); ++i) {
			int complement = target - nums[i];
			// 查找哈希表中是否存在当前元素对应的补数
			if (num_map.find(complement) != num_map.end()) {
				// 找到对应的补数，放回结果
				return { num_map[complement], i };
			}
			// 没有找到对应的补数，将当前元素和对应的索引加入哈希表
			num_map[nums[i]] = i;
		}
		// 如果没有找到符合条件的元素对，则返回空数组
		return {};
	}
};
int main()
{
	Solution solution;
	std::vector<int> nums = { 2, 7, 11, 15 }; // 示例数组
	int target = 9; // 目标值

	// 调用twoSum方法
	std::vector<int> result = solution.twoSum(nums, target);

	// 打印结果
	if (!result.empty()) {
		std::cout << "Index: " << result[0] << ", " << result[1] << std::endl;
	}
	else {
		std::cout << "No two sum solution found." << std::endl;
	}

	return 0;
}

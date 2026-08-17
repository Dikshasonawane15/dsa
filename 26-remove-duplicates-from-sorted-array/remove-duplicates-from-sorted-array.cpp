class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        // Handle empty array edge case
        if (nums.empty()) {
            return 0;
        }
        
        // 'insertIndex' tracks the position to write the next unique element
        int insertIndex = 1; 
        
        // Iterate through the vector starting from the second element
        for (size_t i = 1; i < nums.size(); ++i) {
            // If the current element is different from the previous one, it's unique
            if (nums[i] != nums[i - 1]) {
                nums[insertIndex] = nums[i];
                insertIndex++;
            }
        }
        
        // Return the count of unique elements
        return insertIndex;
    }
};
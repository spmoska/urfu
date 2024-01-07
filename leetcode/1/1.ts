function twoSum(nums: number[], target: number): number[] {
    // @ts-ignore
    for (let [index, num] of nums.entries())
        { // @ts-ignore
            for (let [sindex, snum] of nums.entries())
                        if (num + snum == target && index !== sindex) return [index, sindex]
        }
};
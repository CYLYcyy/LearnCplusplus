#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include <set>
using namespace std;

/*
* Question:
* 给你一个只包含小写字母的字符串 s ，你需要找到 s 中最多数目的非空子字符串，满足如下条件：
*   1.这些字符串之间互不重叠，也就是说对于任意两个子字符串 s[i..j] 和 s[k..l] ，要么 j < k 要么 i > l 。
*   2.如果一个子字符串包含字符 char ，那么 s 中所有 char 字符都应该在这个子字符串中。
* 请你找到满足上述条件的最多子字符串数目。如果有多个解法有相同的子字符串数目，请返回这些子字符串总长度最小的一个解。可以证明最小总长度解是唯一的。
* 请注意，你可以以 任意 顺序返回最优解的子字符串。
* Solution:
* 关键在于分析符合条件2的子串特点：不可能交叉，只可能互相包含。对于两子串，如果有包含，存在两种情况：单个、多个，多个情况下要将最大的小子串舍弃，取其中那些子串。而为了满足总长最小，单个情况下也应作相同处理。
* 也就是说：对所有符合条件2的子串，如果它还有符合条件2的子串，则应该舍弃它，选择其符合条件的子串。
* Step1:遍历字符串s，记录每个字母首次出现和最后一次出现所在的序号
* Step2:从每个字母第一次出现的序号开始，向后扫描，不断将终点设定成每个遇到字母最后一次出现的序号的最大值，直到扫描完成
*       一旦遇到首次出现序号小于此次起点的字符，就说明不存在以此字母为起点的符合条件2的子串，跳出此次扫描。
*       如果扫描正常完成，则得到以此字母为开头的符合条件2的最短子串。
* Step3:Step2中得到的字串不一定是最多的，总长也不一定是最短的。可以构造这样一个循环：从s的开头开始扫描，对每个首次出现的字母按Step2算法得到字串，将其暂时存入答案队列中。
*       在当前的序号没有超出上次得到的字符串终点时，只要得到了新子串，其终点一定小于上一次得到子串的终点，应该将答案更新成新得到的子串
*       只有当前的序号大于上次得到的字串终点，才能确定上一个取到的是符合题意的子串，将其固定在答案队列中并开始查找下一个答案
* Link:
* https://leetcode-cn.com/problems/maximum-number-of-non-overlapping-substrings/
*/
class Solution1520 {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int first[26], last[26];
        memset(first, -1, sizeof(first));
        memset(last, -1, sizeof(last));

        for (int i = 0; i < s.size(); ++i)
        {
            int index = s[i] - 'a';
            if (first[index] == -1)
                first[index] = i;
            last[index] = i;
        }
        auto get = [&](int start)
        {
            int end = last[s[start] - 'a'];
            for (int j = start + 1; j < end; ++j)
            {
                if (first[s[j] - 'a'] < start)
                    return -1;
                end = max(end, last[s[j] - 'a']);
            }
            return end;
        };

        vector<string> ans = { "" };
        int right = s.size();
        for (int i = 0; i < s.size(); ++i)
        {
            if (first[s[i] - 'a'] == i)
            {
                int end = get(i);
                if (end == -1)
                    continue;
                if (i > right)
                {
                    ans.push_back("");
                }
                right = end;
                ans.back() = s.substr(i, end - i + 1);
            }
        }
        return ans;
    }
};
void t1520();

/*
* Question:
* 假设你有两个数组，一个长一个短，短的元素均不相同。找到长数组中包含短数组所有的元素的最短子数组，其出现顺序无关紧要。
* 返回最短子数组的左端点和右端点，如有多个满足条件的子数组，返回左端点最小的一个。若不存在，返回空数组。
* Solution:
* 使用移动窗口，使用unorderedmap可以快速判断当前窗口中是否有small中全部元素，避免每次移动边界时都要在small中查找
* Link:
* https://leetcode-cn.com/problems/shortest-supersequence-lcci/
*/
class Solution1979 {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        vector<int> ans;
        int numInBig = 0;//窗口内已包含small中不同元素的种数(而不是总个数)
        int i = 0, j = 0;
        unordered_map<int, int> timesInBig;//记录big中所有元素的出现次数

        for (i = 0; i < small.size(); i++)
        {
            timesInBig[small[i]]--;//对small中元素预处理，在small中的元素出现次数最少为-1,否则为0
        }

        for (i = 0; i < big.size(); i++)//i作为右边界开始右移
        {
            timesInBig[big[i]]++;
            if (timesInBig[big[i]] == 0)
                numInBig++;//small中元素首次出现时种数增加
            while (numInBig == small.size())//已全部包含时开始移动左边界j
            {
                timesInBig[big[j]]--;
                if (timesInBig[big[j]] < 0)//若移动后窗口不再包含此元素,说明此时左右边界是可能的答案
                {
                    if (ans.empty())
                    {
                        ans = { j,i };
                    }
                    else if (ans[1] - ans[0] > i - j)//比已经记录的可能解短，则替换记录
                    {
                        ans[0] = j;
                        ans[1] = i;
                    }
                    numInBig--;//不再包含此元素时种数应减少，控制开始移动右边界
                }
                j++;
            }
        }
        return ans;
    }
};
void t1979();

/*
* Question:
* 给定一个偶数长度的数组，其中不同的数字代表着不同种类的糖果，每一个数字代表一个糖果。你需要把这些糖果平均分给一个弟弟和一个妹妹。返回妹妹可以获得的最大糖果的种类数。
* link:
* https://leetcode-cn.com/problems/distribute-candies
*/
class Solution575 {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> st(candyType.begin(), candyType.end());
        return min(st.size(), candyType.size() / 2);
    }
};

/*
* Question:
* 给你一个产品数组 products 和一个字符串 searchWord ，products  数组中每个产品都是一个字符串。
* 请你设计一个推荐系统，在依次输入单词 searchWord 的每一个字母后，推荐 products 数组中前缀与 searchWord 相同的最多三个产品。如果前缀相同的可推荐产品超过三个，请按字典序返回最小的三个。
* 请你以二维列表的形式，返回在输入 searchWord 每个字母后相应的推荐产品的列表。
* link:https://leetcode-cn.com/problems/search-suggestions-system
*/

class Solution1268 {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        vector<vector<string>> ret;
        ans.resize(searchWord.size());
        ret.resize(searchWord.size());
        for (string str : products)
        {
            if (*str.begin() == *searchWord.begin())
            {
                ans[0].push_back(str);
            }
            sort(ans[0].begin(), ans[0].end());
            if (ans[0].size() < 3)
            {
                ret[0] = ans[0];
            }
            else
            {
                ret[0] = { ans[0][0],ans[0][1],ans[0][2] };
            }
        }

        for (int i=1;i<searchWord.size();++i)
        {
            for (string str : ans[i-1])
            {
                if (*(str.begin()+i) == *(searchWord.begin()+i))
                {
                    ans[i].push_back(str);
                }
            }
            sort(ans[i].begin(), ans[i].end());
            if (ans[i].size() < 3)
            {
                ret[i] = ans[i];
            }
            else
            {
                ret[i] = { ans[i][0],ans[i][1],ans[i][2] };
            }
        }
        return ret;
    }
};

/*
* Question:
* 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
* 返回被除数 dividend 除以除数 divisor 得到的商。
* 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
* 被除数和除数均为 32 位有符号整数。
* 除数不为 0。
* 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。
* Link:https://leetcode-cn.com/problems/divide-two-integers
*/

class Solution29 {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0)
            return 0;
        if (dividend == INT32_MIN && divisor == -1)
            return INT32_MAX;
        long big = std::fabs(dividend);
        long small = std::fabs(divisor);

        long ret = 0;
        while (big >= small)
        {
            long ans = 1,tempSmall = small;
            while (big > (tempSmall << 1))
            {
                tempSmall <<= 1;
                ans <<= 1;
            }
            big = big - tempSmall;
            ret += ans;
        }
        if ((dividend < 0) != (divisor < 0))
            ret = -ret;
        return (int)ret;
    }
};

/*
* Question:
* 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
* 返回 你可以获得的最大乘积。
* 2 <= n <= 58
* Link:https://leetcode-cn.com/problems/integer-break/
*/
class Solution343 {
public:
    int integerBreak(int n) {
        int ans = 1;
        
        if (n == 2)
        {
            return ans;
        }
        else if (n == 3)
        {
            ans = 2;
            return ans;
        }
        else if (n == 4)
        {
            ans = 4;
            return ans;
        }

        int numTwo[2] = { 0,2 };
        int numThree[2] = { 0,0 };
        for (int i = 5; i <= n; ++i)
        {
            numTwo[0] = numTwo[1];
            numThree[0] = numThree[1];
            if (numTwo[0] == 0)
            {
                numTwo[1] = 2;
                numThree[1] = numThree[0] - 1;
            }
            else
            {
                numTwo[1] = numTwo[0] - 1;
                numThree[1] = numThree[0] + 1;
            }
        }

        for (int i = 0; i < numTwo[1]; ++i)
            ans *= 2;
        for (int i = 0; i < numThree[1]; ++i)
            ans *= 3;
        return ans;
    }
};

/*
* Question:
* 给定一个整数数组 A，坡是元组 (i, j)，其中  i < j 且 A[i] <= A[j]。这样的坡的宽度为 j - i。
* 找出 A 中的坡的最大宽度，如果不存在，返回 0 。
* Link:https://leetcode.cn/problems/maximum-width-ramp/description/
*/

class Solution962 {
public:
    int maxWidthRamp(vector<int>& nums) {
        int size = nums.size();
        int len = size;
        for (int i = 0; i < size - 1; ++i)
        {
            --len;//移动窗口初始长度
            for (int j = 0; j + len < size; ++j)
            {
                if (nums[j] <= nums[j + len])
                {
                    return len;
                }
            }
        }
        return 0;
    }
};
void t962();
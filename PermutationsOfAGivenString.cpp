/*
Given a string S. The task is to print all unique permutations of the given string in lexicographically sorted order.



Example 1:

Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6
forms as ABC, ACB, BAC, BCA, CAB and CBA .
Example 2:

Input: ABSG
Output:
ABGS ABSG AGBS AGSB ASBG ASGB BAGS
BASG BGAS BGSA BSAG BSGA GABS GASB
GBAS GBSA GSAB GSBA SABG SAGB SBAG
SBGA SGAB SGBA
Explanation:
Given string ABSG has 24 permutations.


Your Task:
You don't need to read input or print anything. Your task is to complete the function find_permutaion() which takes the string S as input parameter and returns a vector of string in lexicographical order.



Expected Time Complexity: O(n! * n)

Expected Space Complexity: O(n)

*/



class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    int n=S.size();
            sort(S.begin(), S.end());
            set<string> result;
    		do{
    		    result.insert(S);
    		}while(next_permutation(S.begin(),S.end()));
    		vector<string> ans;
    		for(auto it : result){
    		    ans.push_back(it);
    		}
    		sort(ans.begin(),ans.end());

    	return ans;
		}
};


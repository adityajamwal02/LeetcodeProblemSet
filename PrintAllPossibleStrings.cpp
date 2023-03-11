/*
Given a string str your task is to complete the function spaceString which takes only one argument the string str and  finds all possible strings that can be made by placing spaces (zero or one) in between them.

For eg .  for the string abc all valid strings will be
                abc
                ab c
                a bc
                a b c

Example 1:
Input:
str = abc
Output: abc$ab c$a bc$a b c$

Example 2:
Input:
str = xy
Output: xy$x y$

Your Task:
Complete the function spaceString() which takes a character array as an input parameter and returns list of all possible answers in lexographically reverse order(largest String first then smaller). The driver code will print the all possible answer '$' separated.

Expected Time Complexity: O(N * 2N)
Expected Auxiliary Space: O(N)
*/

/*You have to complete this function*/

void solve(vector<string> &result, string &output, string temp){
    if(temp.size()==0){
        result.push_back(output);
        return;
    }
    string op1 = output+temp[0];
    string op2 = output+" "+temp[0];
    temp.erase(temp.begin()+0);
    solve(result,op1,temp);
    solve(result,op2,temp);
return;
}

vector<string>  spaceString(char str[])
{
    vector<string> result;
    string temp=str;
    string output="";
    output+=temp[0];
    temp.erase(temp.begin()+0);
    solve(result,output,temp);
return result;
}

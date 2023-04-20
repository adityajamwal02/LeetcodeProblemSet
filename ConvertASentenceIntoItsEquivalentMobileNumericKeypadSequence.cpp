/*
Given a sentence in the form of a string in uppercase, convert it into its equivalent mobile numeric keypad sequence. Please note there might be spaces in between the words in a sentence and we can print spaces by pressing 0.

Example 1:
Input:
S = "GFG"
Output: 43334
Explanation: For 'G' press '4' one time.
For 'F' press '3' three times.

Example 2:
Input:
S = "HEY U"
Output: 4433999088
Explanation: For 'H' press '4' two times.
For 'E' press '3' two times. For 'Y' press '9'
three times. For white space press '0' one time.
For 'U' press '8' two times.

Your Task:
You dont need to read input or print anything. Complete the function printSequence() which takes a string as input parameter and returns its equivalent mobile numeric keypad sequence as a string.

Expected Time Complexity: O(Length of String)
Expected Auxiliary Space: O(Length of String)
*/



string printSequence(string S)
{
    int n=S.size();
    string result="";
    vector<pair<char,int>> collection;
    collection.push_back({'A',2});
    collection.push_back({'B',22});
    collection.push_back({'C',222});
    collection.push_back({'D',3});
    collection.push_back({'E',33});
    collection.push_back({'F',333});
    collection.push_back({'G',4});
    collection.push_back({'H',44});
    collection.push_back({'I',444});
    collection.push_back({'J',5});
    collection.push_back({'K',55});
    collection.push_back({'L',555});
    collection.push_back({'M',6});
    collection.push_back({'N',66});
    collection.push_back({'O',666});
    collection.push_back({'P',7});
    collection.push_back({'Q',77});
    collection.push_back({'R',777});
    collection.push_back({'S',7777});
    collection.push_back({'T',8});
    collection.push_back({'U',88});
    collection.push_back({'V',888});
    collection.push_back({'W',9});
    collection.push_back({'X',99});
    collection.push_back({'Y',999});
    collection.push_back({'Z',9999});
    collection.push_back({'#',0});
    for(int i=0;i<n;i++){
        if(S[i]==' '){
            S[i]='#';
        }
        for(int j=0;j<collection.size();j++){
            if(collection[j].first == S[i]){
                result+=to_string(collection[j].second);
            }
        }
    }
    return result;
}


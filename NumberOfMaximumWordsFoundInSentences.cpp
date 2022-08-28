/*
A sentence is a list of words that are separated by a single space with no leading or trailing spaces.
You are given an array of strings sentences, where each sentences[i] represents a single sentence.
Return the maximum number of words that appear in a single sentence.
*/

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int countspaces=0;
        int maxcount=0;
        for(int i=0;i<sentences.size();i++){
            countspaces=0;
            for(int j=0;j<sentences[i].size();j++){
                if(sentences[i][j]==' ')
                    countspaces++;
            }
            if(countspaces>maxcount)
                maxcount=countspaces;
        }
    return maxcount+1;
    }
};

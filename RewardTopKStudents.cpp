/*
You are given two string arrays positive_feedback and negative_feedback, containing the words denoting positive and negative feedback, respectively. Note that no word is both positive and negative.
Initially every student has 0 points. Each positive word in a feedback report increases the points of a student by 3, whereas each negative word decreases the points by 1.
You are given n feedback reports, represented by a 0-indexed string array report and a 0-indexed integer array student_id, where student_id[i] represents the ID of the student who has received the feedback report report[i]. The ID of each student is unique.
Given an integer k, return the top k students after ranking them in non-increasing order by their points. In case more than one student has the same points, the one with the lower ID ranks higher.

Example 1:
Input: positive_feedback = ["smart","brilliant","studious"], negative_feedback = ["not"], report = ["this student is studious","the student is smart"], student_id = [1,2], k = 2
Output: [1,2]
Explanation:
Both the students have 1 positive feedback and 3 points but since student 1 has a lower ID he ranks higher.

Example 2:
Input: positive_feedback = ["smart","brilliant","studious"], negative_feedback = ["not"], report = ["this student is not studious","the student is smart"], student_id = [1,2], k = 2
Output: [2,1]
Explanation:
- The student with ID 1 has 1 positive feedback and 1 negative feedback, so he has 3-1=2 points.
- The student with ID 2 has 1 positive feedback, so he has 3 points.
Since student 2 has more points, [2,1] is returned.
*/


/// Idea to make a max heap (PQ) and maintain 2 maps (one positive and another negative) to search for occurences of string words in report, accordingly score will be updated and hence, PQ will sort based on max value at top, if two values collide with each other then push the one with smaller index (maintain index with total score inside PQ)

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        vector<int> result;
        priority_queue<pair<int, int>> pq;
        unordered_map<string, int> mp1, mp2;
        for(auto it : positive_feedback){
            mp1[it]++;
        }
        for(auto it: negative_feedback){
            mp2[it]++;
        }

        for(int i=0;i<student_id.size();i++){
            int score=0;
            stringstream s(report[i]);
            while(getline(s, report[i], ' ')){
                if(mp1.find(report[i])!=mp1.end()){
                    score+=3;
                }
                if(mp2.find(report[i])!=mp2.end()){
                    score-=1;
                }
            }
            pq.push({score, student_id[i]});
        }
        int prev=-1, curr=0;
        while(!pq.empty()){
            if(prev==pq.top().first){
                curr++;
            }else{
                curr=0;
            }
            prev=pq.top().first;
            if(result.empty()){
                result.push_back(pq.top().second);
            }else{
                result.insert(result.begin() + result.size() - curr, pq.top().second);
            }
        pq.pop();
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(result[i]);
        }
    return ans;
    }
};

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Submission {
    int uid;
    string time;
    bool is_correct;
    int tid;
};

bool compare_by_time(Submission a, Submission b) {
    int a_hours = stoi(a.time.substr(0, 2));
    int a_minutes = stoi(a.time.substr(3, 2));
    int a_seconds = stoi(a.time.substr(6, 2));
    int b_hours = stoi(b.time.substr(0, 2));
    int b_minutes = stoi(b.time.substr(3, 2));
    int b_seconds = stoi(b.time.substr(6, 2));
    if (a_hours != b_hours) {
        return a_hours < b_hours;
    }
    if (a_minutes != b_minutes) {
        return a_minutes < b_minutes;
    }
    return a_seconds < b_seconds;
}

int main() {
    string start;
    int tid, n;
    cin >> start >> tid >> n;
    vector<Submission> correct_submissions;
    for (int i = 0; i < n; i++) {
        int uid;
        string time, status;
        int task_id;
        cin >> uid >> time >> status >> task_id;
        if (status == "correct" && task_id == tid) {
            Submission submission = {uid, time, true, task_id};
            correct_submissions.push_back(submission);
        }
    }
    sort(correct_submissions.begin(), correct_submissions.end(), compare_by_time);
    cout << correct_submissions.size() << endl;
    for (int i = 0; i < correct_submissions.size(); i++) {
        cout << correct_submissions[i].uid << " " << correct_submissions[i].time << endl;
    }
    return 0;
}

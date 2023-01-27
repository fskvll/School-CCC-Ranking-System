#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string start;
    int n;
    cin >> start >> n;
    vector<pair<int,string>> submissions;
    int correct_submissions = 0;
    for (int i = 0; i < n; i++) {
        string uid, submission, status;
        cin >> uid >> submission >> status;
        int hours = stoi(submission.substr(0, 2));
        int minutes = stoi(submission.substr(3, 2));
        int seconds = stoi(submission.substr(6, 2));
        int start_hours = stoi(start.substr(0, 2));
        int start_minutes = stoi(start.substr(3, 2));
        int start_seconds = stoi(start.substr(6, 2));
        int submission_time = (hours - start_hours) * 3600 + (minutes - start_minutes) * 60 + (seconds - start_seconds);
        if (status == "correct") {
            correct_submissions++;
            submissions.push_back(make_pair(submission_time, uid + " " + submission));
        }
    }
    sort(submissions.begin(), submissions.end()); // sort by submission time
    cout << correct_submissions << endl;
    for (auto s : submissions) {
        cout << s.second << endl;
    }
    return 0;
}

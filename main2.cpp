#include <iostream>
#include <string>
using namespace std;

int main() {
    string start;
    int n;
    cin >> start >> n;
    int earliest_time = INT_MAX;
    string earliest_submission;
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
        if (status == "correct" && submission_time < earliest_time) {
            earliest_time = submission_time;
            earliest_submission = uid + " " + submission;
        }
    }
    cout << earliest_submission << endl;
    return 0;
}

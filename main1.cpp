#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    string start, submission;
    cin >> start >> submission;

    // convert the input strings to integers for hours, minutes, and seconds
    int start_hours = stoi(start.substr(0, 2));
    int start_minutes = stoi(start.substr(3, 2));
    int start_seconds = stoi(start.substr(6, 2));
    int submission_hours = stoi(submission.substr(0, 2));
    int submission_minutes = stoi(submission.substr(3, 2));
    int submission_seconds = stoi(submission.substr(6, 2));

    // compute the time span in seconds
    int time_span = (submission_hours - start_hours) * 3600 + (submission_minutes - start_minutes) * 60 + (submission_seconds - start_seconds);
    cout << time_span << endl;

    return 0;
}

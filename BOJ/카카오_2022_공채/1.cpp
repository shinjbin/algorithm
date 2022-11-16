#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct date{
    int year;
    int month;
    int day;
};

date string_to_date(string str) {
    date result;
    result.year = stoi(str.substr(0, 4));
    result.month = stoi(str.substr(5,2));
    result.day = stoi(str.substr(8,2));

    return result;
}

date date_add_month(date currDate, int add_month) {
    date result = currDate;
    result.month += add_month;
    while (result.month > 12) {
        result.month -= 12;
        result.year++;
    }
    return result;
}

bool cmp_date(date today, date lastDate) {
    cout << today.year << ' ' << today.month << ' ' << today.day << endl;
    cout << lastDate.year << ' ' << lastDate.month << ' ' << lastDate.day << endl;
    if (today.year < lastDate.year) {
        return false;
    }
    else if (today.year > lastDate.year) {
        return true;
    }
    else {
        if (today.month < lastDate.month) {
            return false;
        }
        else if (today.month > lastDate.month) {
            return true;
        }
        else {
            if (today.day < lastDate.day) {
                return false;
            }
            else {
                return true;
            }
        }
    }
}

date last_date(string privacy, vector<string> terms) { // ex) "2021.05.02 A"
    date result = string_to_date(privacy.substr(0,10));

    char term = privacy[11];
    int month_term;
    for (int i = 0 ; i < terms.size(); i++) {
        if (term == terms[i][0]) {
            month_term = stoi(terms[i].substr(2, terms[i].size()));
        }
    }

    result = date_add_month(result, month_term);

    return result;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    date todayDate = string_to_date(today);
    for (int i = 0; i < privacies.size(); i++) {
        string currPrivacy = privacies[i];

        date lastDate = last_date(privacies[i], terms);
        if (cmp_date(todayDate, lastDate)) answer.push_back(i+1);
    }

    return answer;
}

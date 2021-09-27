#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

double average(vector<int> scores, int num_student){
    double total = 0;
    for(int i = 0; i < num_student; i++){
        total += scores[i];
    }

    return total / num_student;
}

int main(){

    int C;
    cin >> C;

    for(int i = 0; i < C; i++){
        int num_student;
        cin >> num_student;

        vector<int> scores;

        for(int j = 0; j < num_student; j++){
            int temp;
            cin >> temp;
            scores.push_back(temp);
            //cout << scores[j];
        }

        double avg = average(scores, num_student);
        //cout << avg << endl;

        int result = 0;
        for(int k = 0; k < num_student; k++){
            if (scores[k] > avg) {
                result++;
            }
        }
        double answer = (double)result / num_student * 100;

        cout << fixed;
        cout.precision(3);
        cout << answer << "%" << endl;
    }
    return 0;
}
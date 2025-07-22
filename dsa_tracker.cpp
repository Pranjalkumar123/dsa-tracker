
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void addQuestion() {
    ofstream file("dsa_questions.txt", ios::app);
    string topic, platform, difficulty, status;

    cout << "Enter Topic: ";
    cin >> topic;
    cout << "Enter Platform (e.g. LeetCode): ";
    cin >> platform;
    cout << "Enter Difficulty (Easy/Medium/Hard): ";
    cin >> difficulty;
    cout << "Enter Status (Solved/Pending): ";
    cin >> status;

    file << topic << "," << platform << "," << difficulty << "," << status << "\n";
    file.close();

    cout << "✅ Question added!\n";
}

void viewQuestions() {
    ifstream file("dsa_questions.txt");
    string line;
    cout << "\n📋 All Questions:\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void filterByTopic() {
    ifstream file("dsa_questions.txt");
    string line, topic;
    cout << "Enter topic to filter: ";
    cin >> topic;
    cout << "\n📂 Questions under topic '" << topic << "':\n";
    while (getline(file, line)) {
        if (line.find(topic) != string::npos) {
            cout << line << endl;
        }
    }
    file.close();
}

void clearAll() {
    ofstream file("dsa_questions.txt", ios::trunc);
    file.close();
    cout << "🗑️ All questions cleared!\n";
}

int main() {
    int choice;
    do {
        cout << "\n------ DSA PRACTICE TRACKER ------\n";
        cout << "1. Add Question\n";
        cout << "2. View All Questions\n";
        cout << "3. Filter by Topic\n";
        cout << "4. Clear All Questions\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addQuestion(); break;
            case 2: viewQuestions(); break;
            case 3: filterByTopic(); break;
            case 4: clearAll(); break;
            case 5: cout << "👋 Exiting...\n"; break;
            default: cout << "❌ Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}

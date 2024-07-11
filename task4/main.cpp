#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ToDoList {
private:
    struct Task {
        string description;
        bool completed;

        Task(string desc) : description(desc), completed(false) {}
    };

    vector<Task> tasks;

    void printMenu() {
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
    }

    void addTask() {
        cout << "Enter the task description: ";
        string desc;
        cin.ignore();
        getline(cin, desc);
        tasks.push_back(Task(desc));
        cout << "Task added.\n";
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks to display.\n";
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description
                 << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
        }
    }

    void markTaskAsCompleted() {
        viewTasks();
        cout << "Enter the task number to mark as completed: ";
        size_t taskNumber;
        cin >> taskNumber;

        if (taskNumber == 0 || taskNumber > tasks.size()) {
            cout << "Invalid task number.\n";
            return;
        }

        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed.\n";
    }

    void removeTask() {
        viewTasks();
        cout << "Enter the task number to remove: ";
        size_t taskNumber;
        cin >> taskNumber;

        if (taskNumber == 0 || taskNumber > tasks.size()) {
            cout << "Invalid task number.\n";
            return;
        }

        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed.\n";
    }

public:
    void run() {
        int choice;
        do {
            printMenu();
            cin >> choice;

            switch (choice) {
                case 1:
                    addTask();
                    break;
                case 2:
                    viewTasks();
                    break;
                case 3:
                    markTaskAsCompleted();
                    break;
                case 4:
                    removeTask();
                    break;
                case 5:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 5);
    }
};

int main() {
    ToDoList toDoList;
    toDoList.run();
    return 0;
}
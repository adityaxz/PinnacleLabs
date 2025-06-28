#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TASKS 100

char tasks[MAX_TASKS][100];
int completed[MAX_TASKS];
int taskCount = 0;

void addTask() {
    int taskNumber;
    printf("Enter Task Number: ");
    scanf("%d", &taskNumber);
    int c; while ((c = getchar()) != '\n' && c != EOF);
    if (taskNumber > 0 && taskNumber <= MAX_TASKS) {
        if (tasks[taskNumber - 1][0] != '\0') {
            printf("Task already exists at this number. Do you want to overwrite? (y/n): ");
            char choice;
            scanf("%c", &choice);
            int c; while ((c = getchar()) != '\n' && c != EOF);
            if (choice == 'y' || choice == 'Y') {
                printf("Enter Task Name: ");
                fgets(tasks[taskNumber - 1], 100, stdin);
                tasks[taskNumber - 1][strcspn(tasks[taskNumber - 1], "\n")] = 0;
                completed[taskNumber - 1] = 0;
                if (taskNumber > taskCount) taskCount = taskNumber;
                printf("Task added successfully!\n");
            } else printf("Task not added.\n");
        } else {
            printf("Enter Task Name: ");
            fgets(tasks[taskNumber - 1], 100, stdin);
            tasks[taskNumber - 1][strcspn(tasks[taskNumber - 1], "\n")] = 0;
            completed[taskNumber - 1] = 0;
            if (taskNumber > taskCount) taskCount = taskNumber;
            printf("Task added successfully!\n");
        }
    } else printf("Invalid task number!\n");
}

void viewTaskList() {
    printf("Your Tasks:\n");
    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i][0] != '\0') printf("%d. %s [%s]\n", i + 1, tasks[i], completed[i] ? "Completed" : "Pending");
    }
}

void viewTask() {
    int taskNumber;
    printf("Enter Task Number to View: ");
    scanf("%d", &taskNumber);
    int c; while ((c = getchar()) != '\n' && c != EOF);
    if (taskNumber > 0 && taskNumber <= MAX_TASKS && tasks[taskNumber - 1][0] != '\0') printf("Task %d: %s [%s]\n", taskNumber, tasks[taskNumber - 1], completed[taskNumber - 1] ? "Completed" : "Pending");
    else printf("Invalid task number!\n");
}

void editTask() {
    int taskNumber;
    printf("Enter Task Number to Edit: ");
    scanf("%d", &taskNumber);
    int c; while ((c = getchar()) != '\n' && c != EOF);
    if (taskNumber > 0 && taskNumber <= MAX_TASKS && tasks[taskNumber - 1][0] != '\0') {
        printf("Enter New Task Name: ");
        fgets(tasks[taskNumber - 1], 100, stdin);
        tasks[taskNumber - 1][strcspn(tasks[taskNumber - 1], "\n")] = 0;
        printf("Task edited successfully!\n");
    } else printf("Invalid task number!\n");
}

void markTaskAsComplete() {
    int taskNumber;
    printf("Enter Task Number to Mark as Complete: ");
    scanf("%d", &taskNumber);
    int c; while ((c = getchar()) != '\n' && c != EOF);
    if (taskNumber > 0 && taskNumber <= MAX_TASKS && tasks[taskNumber - 1][0] != '\0') {
        completed[taskNumber - 1] = 1;
        printf("Task marked as complete!\n");
    } else printf("Invalid task number!\n");
}

int main() {
    int choice;
    while (1) {
        printf("To-Do List Menu:\n");
        printf("1. Add Task\n2. View Task List\n3. View Task\n4. Edit Task\n5. Mark Task as Complete\n6. Quit\n");
        printf("Choose an operation: ");
        scanf("%d", &choice);
        int c; while ((c = getchar()) != '\n' && c != EOF);
        if (choice == 1) addTask();
        else if (choice == 2) viewTaskList();
        else if (choice == 3) viewTask();
        else if (choice == 4) editTask();
        else if (choice == 5) markTaskAsComplete();
        else if (choice == 6) {
            printf("Exiting To-Do List...\n");
            break;
        } else printf("Invalid choice!\n");
    }
    return 0;
}
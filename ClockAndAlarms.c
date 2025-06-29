#include <stdio.h>
#include <time.h>

#define MAX_ALARMS 10

typedef struct {
    int hour;
    int minute;
} Alarm;

Alarm alarms[MAX_ALARMS];
int alarmCount = 0;

void displayTime() {
    time_t currentTime;
    struct tm *timeInfo;
    time(&currentTime);
    timeInfo = localtime(&currentTime);
    printf("%02d:%02d:%02d (GMT)\n", timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);

    int indiaHour = (timeInfo->tm_hour + 5) % 24;
    int indiaMinute = timeInfo->tm_min + 30;
    if (indiaMinute >= 60) {
        indiaHour = (indiaHour + 1) % 24;
        indiaMinute -= 60;
    }
    printf("%02d:%02d:%02d (INDIA)\n", indiaHour, indiaMinute, timeInfo->tm_sec);
}

void setAlarm() {
    if (alarmCount < MAX_ALARMS) {
        printf("Enter alarm time (HH MM): ");
        scanf("%d %d", &alarms[alarmCount].hour, &alarms[alarmCount].minute);
        alarmCount++;
        printf("Alarm set successfully!\n");
    } else {
        printf("Maximum alarms reached!\n");
    }
}

void viewAlarms() {
    if (alarmCount == 0) {
        printf("No alarms set!\n");
    } else {
        printf("Alarms:\n");
        for (int i = 0; i < alarmCount; i++) {
            printf("%d. %02d:%02d\n", i + 1, alarms[i].hour, alarms[i].minute);
        }
    }
}

int main() {
    while (1) {
        time_t currentTime;
        struct tm *timeInfo;
        time(&currentTime);
        timeInfo = localtime(&currentTime);

        printf("Clock and Alarms\n");
        printf("1. View current time\n");
        printf("2. Set alarm\n");
        printf("3. View alarms\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayTime();
                break;
            case 2:
                setAlarm();
                break;
            case 3:
                viewAlarms();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }

        for (int i = 0; i < alarmCount; i++) {
            if (timeInfo->tm_hour == alarms[i].hour && timeInfo->tm_min == alarms[i].minute) {
                printf("Wake Up!\n");
                for (int j = i; j < alarmCount - 1; j++) {
                    alarms[j] = alarms[j + 1];
                }
                alarmCount--;
            }
        }
    }

    return 0;
}
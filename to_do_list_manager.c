#include <stdio.h>

#define MAX 50  //the maximum number of the text that a person can store or add

int main() {
char name[MAX][50];             //here we have stored tasks: names, description, their priority...
char description[MAX][100];
int priority[MAX];
int day[MAX];
int completed[MAX];

int count = 0;      //the counter of the tasks and when it gets to 50 it makes it's work
int choice, i, taskNo;
int today;

    while (1) {     //our main loop

        //the displaied main menu of the TO-DO LIST MANAGER
        printf("\n--- TO-DO LIST MANAGER ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Daily Summary\n");
        printf("5. Weekly Summary\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);   //here it scans or it reads the users choice

    if (choice == 0)    //if choice==0 then...
            break;


        switch (choice) {   //after entering the choice(number), here it comes the switch method

        case 1:
            if (count >= MAX) { //checks the number of TASKS
                printf("Task list is full (maximum %d tasks).\n", MAX);
                break;
            }

            printf("Task Name: ");
            scanf(" %[^\n]", name[count]);

            printf("Description: ");
            scanf(" %[^\n]", description[count]);

            printf("Priority (1=High, 2=Medium, 3=Low): ");
            scanf("%d", &priority[count]);

            printf("Due Day (1–31): ");
            scanf("%d", &day[count]);

            completed[count] = 0;
            count++;

            printf("Task added successfully!\n");
            break;

        case 2:
            if (count == 0) {   //if there are no tasks...
                printf("No tasks available.\n");
                break;
            }

            for (i = 0; i < count; i++) {   //the loops that goes inside or has control in every task that is added
                printf("\nTask %d\n", i + 1);
                printf("Name: %s\n", name[i]);
                printf("Description: %s\n", description[i]);
                printf("Priority: %d\n", priority[i]);
                printf("Due Day: %d\n", day[i]);
                printf("Status: %s\n",
                       completed[i] ? "Completed" : "Pending");
            }
            break;

        case 3:     //which task to complete.
            printf("Enter task number to complete: ");
            scanf("%d", &taskNo);

            if (taskNo < 1 || taskNo > count) {
                printf("Invalid task number!\n");
            } else {
                completed[taskNo - 1] = 1;
                printf("Task marked as completed.\n");
            }
            break;

        case 4:
            printf("Enter today's day (1–31): ");
            scanf("%d", &today);

            printf("\n--- Today's Tasks ---\n");
            for (i = 0; i < count; i++) {
                if (day[i] == today) {
                    printf("%s (%s)\n",
                           name[i],
                           completed[i] ? "Completed" : "Pending");
                }
            }
            break;

        case 5:
            printf("Enter today's day (1–31): ");
            scanf("%d", &today);

            printf("\n--- Weekly Tasks ---\n");

            //asks or displays tasks due in the next 7 days
            for (i = 0; i < count; i++) {
                if (day[i] >= today && day[i] <= today + 7) {
                    printf("%s - Due on day %d (%s)\n",
                           name[i], day[i],
                           completed[i] ? "Completed" : "Pending");
                }
            }
            break;

        default:
            //if there is any invalid choice from user...
            printf("Invalid choice!\n");
        }
    }
    //when user enters 0, than it shows the end of the program
    printf("Program ended.\n");
    return 0;
}


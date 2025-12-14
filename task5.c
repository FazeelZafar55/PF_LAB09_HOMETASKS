#include <stdio.h>

void analyzeAttendance(int (*attendance)[5], int students, int days){
    int defaulters=0;
    for (int i=0;i<students;i++){
        int present=0;
        for (int j=0;j<days;j++){
            present += *(*(attendance + i) + j);
        }
        float percentage = (present/(float) days)*100;
        if (percentage >= 90){
            printf("Student %2d: %.2f %% - Good attendance\n",i+1,percentage);
        } else if (percentage >=75){
             printf("Student %2d: %.2f %% - Average attendance\n",i+1,percentage);
        } else {
             printf("Student %2d: %.2f %% - Poor attendance\n",i+1,percentage);
             defaulters++;
        }
    }
    printf("total number of defaulters are %d\n",defaulters);
}
int main(){
    int students=30;
    int days=5;
    int attendance[30][5];
    printf("Enter attendance data (1 for present, 0 for absent)\n");
    for (int i=0;i<students;i++){
        printf ("Student %d:\n",i+1);
        for (int j=0;j<days;j++){
            printf("Day %d:",j+1);
            scanf("%d",&attendance[i][j]);
        }
    }
    analyzeAttendance(attendance,students,days);
    return 0;
}
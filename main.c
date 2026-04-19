/*
Name: Buyondo Emmanuel
Registration Number: 24/U/BIO/04517/PD
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char code[15];
    char name[30];
    int units;
    int marks;
    char grade[2];
    float gp;
} Course;

// Helper to determine Grade and Grade Point
void setGradeInfo(Course *c) {
    if (c->marks >= 80) { strcpy(c->grade, "A");  c->gp = 5.0; }
    else if (c->marks >= 70) { strcpy(c->grade, "B");  c->gp = 4.0; }
    else if (c->marks >= 60) { strcpy(c->grade, "C");  c->gp = 3.0; }
    else if (c->marks >= 50) { strcpy(c->grade, "D");  c->gp = 2.0; }
    else { strcpy(c->grade, "F");  c->gp = 0.0; }
}

int main() {
    Course sem1[] = {
        {"TEMB 1101", "Eng. Math I", 4}, {"TEMB 1102", "Biochem/Phys", 3},
        {"TEMB 1103", "Elec. Eng", 3},   {"TEMB 1104", "Mechanics I", 3},
        {"TEMB 1105", "Computing I", 3}, {"TEMB 1106", "Mech. Drawing", 3},
        {"TEMB 1107", "Eng. Prof", 2},   {"TEMB 1108", "Anatomy I", 3}
    };

    Course sem2[] = {
        {"TEMB 1201", "Eng. Math II", 4}, {"TEMB 1202", "Computing II", 3},
        {"TEMB 1203", "Mechatron Drw", 3}, {"TEMB 1204", "Fluid Mech", 3},
        {"TEMB 1205", "Thermo", 3},        {"TEMB 1206", "Workshop", 3},
        {"TEMB 1207", "Anatomy II", 3},    {"TEMB 1208", "Electronics I", 3}
    };

    float s1_total_gp = 0, s2_total_gp = 0;
    int s1_units = 0, s2_units = 0;

    // --- STEP 1: SEMESTER I INPUT ---
    printf(">> INPUT DATA: Semester I\n");
    for(int i = 0; i < 8; i++) {
        printf("   Enter marks for %s: ", sem1[i].code);
        scanf("%d", &sem1[i].marks);
        setGradeInfo(&sem1[i]);
        s1_total_gp += (sem1[i].gp * sem1[i].units);
        s1_units += sem1[i].units;
    }

    // --- STEP 2: SEMESTER II INPUT ---
    printf("\n>> INPUT DATA: Semester II\n");
    for(int i = 0; i < 8; i++) {
        printf("   Enter marks for %s: ", sem2[i].code);
        scanf("%d", &sem2[i].marks);
        setGradeInfo(&sem2[i]);
        s2_total_gp += (sem2[i].gp * sem2[i].units);
        s2_units += sem2[i].units;
    }

    // --- STEP 3: COURSE BY COURSE REPORT ---
    printf("\n\n%-12s %-20s %-6s %-6s %-6s\n", "CODE", "SUBJECT", "UNITS", "GRADE", "GP");
    printf("------------------------------------------------------------\n");
    
    printf("Semester I COURSES:\n");
    for(int i = 0; i < 8; i++) 
        printf("%-12s %-20s %-6d %-6s %.1f\n", sem1[i].code, sem1[i].name, sem1[i].units, sem1[i].grade, sem1[i].gp);

    printf("\nSemester II COURSES:\n");
    for(int i = 0; i < 8; i++) 
        printf("%-12s %-20s %-6d %-6s %.1f\n", sem2[i].code, sem2[i].name, sem2[i].units, sem2[i].grade, sem2[i].gp);

    // --- STEP 4: FINAL ACADEMIC SUMMARY ---
    float gpa1 = s1_total_gp / s1_units;
    float gpa2 = s2_total_gp / s2_units;
    float cgpa = (s1_total_gp + s2_total_gp) / (s1_units + s2_units);

    printf("\n============================================================\n");
    printf("                     FINAL ACADEMIC SUMMARY\n");
    printf("============================================================\n");
    printf("  Semester I GPA :  %.2f\n", gpa1);
    printf("  Semester II GPA:  %.2f\n", gpa2);
    printf("  CUMULATIVE GPA :  %.2f\n", cgpa);
    printf("------------------------------------------------------------\n");
    printf("  Classification :  ");
    
    if (cgpa >= 4.40)      printf("FIRST CLASS\n");
    else if (cgpa >= 3.60) printf("SECOND CLASS UPPER\n");
    else if (cgpa >= 2.80) printf("SECOND CLASS LOWER\n");
    else if (cgpa >= 2.00) printf("PASS\n");
    else                   printf("FAIL\n");
    printf("============================================================\n");

    return 0;
}

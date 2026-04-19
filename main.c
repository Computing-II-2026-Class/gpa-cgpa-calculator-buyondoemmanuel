/*
Name: Buyondo Emmanuel
Registration Number: 24/U/BIO/04517/PD
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char code[10];
    char name[30];
    int units;
    int marks;
    char grade[3];
    float gp;
} Course;

// Function to determine Grade and Grade Point
void setGradeInfo(Course *c) {
    if (c->marks >= 80) { strcpy(c->grade, "A");  c->gp = 5.0; }
    else if (c->marks >= 70) { strcpy(c->grade, "B");  c->gp = 4.0; }
    else if (c->marks >= 60) { strcpy(c->grade, "C");  c->gp = 3.0; }
    else if (c->marks >= 50) { strcpy(c->grade, "D");  c->gp = 2.0; }
    else { strcpy(c->grade, "F");  c->gp = 0.0; }
}

// Function to determine Class of Degree
const char* getClassification(float cgpa) {
    if (cgpa >= 4.40) return "FIRST CLASS";
    if (cgpa >= 3.60) return "SECOND CLASS UPPER";
    if (cgpa >= 2.80) return "SECOND CLASS LOWER";
    if (cgpa >= 2.00) return "PASS";
    return "FAIL (DISCONTINUED/RETAKE)";
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

    // Input Phase
    printf("ENTER ACADEMIC SCORES\n---------------------\n");
    for(int i = 0; i < 8; i++) {
        printf("%s Marks: ", sem1[i].code); scanf("%d", &sem1[i].marks);
        setGradeInfo(&sem1[i]);
        s1_total_gp += (sem1[i].gp * sem1[i].units);
        s1_units += sem1[i].units;
    }
    for(int i = 0; i < 8; i++) {
        printf("%s Marks: ", sem2[i].code); scanf("%d", &sem2[i].marks);
        setGradeInfo(&sem2[i]);
        s2_total_gp += (sem2[i].gp * sem2[i].units);
        s2_units += sem2[i].units;
    }

    // Report Generation
    printf("\n\n           FULL ACADEMIC REPORT\n");
    printf("==================================================\n");
    printf("%-10s %-15s %-5s %-5s %-5s\n", "CODE", "SUBJECT", "UNIT", "GRD", "GP");
    printf("--------------------------------------------------\n");
    
    printf("SEMESTER I\n");
    for(int i = 0; i < 8; i++) 
        printf("%-10s %-15s %-5d %-5s %.1f\n", sem1[i].code, sem1[i].name, sem1[i].units, sem1[i].grade, sem1[i].gp);
    printf(">> Semester I GPA: %.2f\n\n", s1_total_gp / s1_units);

    printf("SEMESTER II\n");
    for(int i = 0; i < 8; i++) 
        printf("%-10s %-15s %-5d %-5s %.1f\n", sem2[i].code, sem2[i].name, sem2[i].units, sem2[i].grade, sem2[i].gp);
    printf(">> Semester II GPA: %.2f\n", s2_total_gp / s2_units);

    // Final Summary
    float cgpa = (s1_total_gp + s2_total_gp) / (s1_units + s2_units);
    printf("==================================================\n");
    printf("FINAL CGPA: %.2f\n", cgpa);
    printf("Classification: %s\n", getClassification(cgpa));
    printf("==================================================\n");


    return 0;
}

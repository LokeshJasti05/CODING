#include <stdio.h>

struct students {
    char name[50];
    int regno;
    int m1;
    int m2;
    float cgpa;
};

// Function prototypes
void input(struct students *s);
void calculate(struct students *s);

int main() {
    int total;

    printf("Enter the number of students: ");
    scanf("%d", &total);
   
    struct students list[total];
   
    for(int i = 0; i < total; i++) {
        printf("Entering data for student %d:\n", i + 1);
        input(&list[i]);  
        calculate(&list[i]);
    }
   
    for(int i = 0; i < total; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", list[i].name);
        printf("Registration Number: %d\n", list[i].regno);
        printf("Marks 1: %d\n", list[i].m1);
        printf("Marks 2: %d\n", list[i].m2);
        printf("CGPA: %.2f\n", list[i].cgpa);
1
    }
   
    return 0;
}

void input(struct students *s) {
    printf("Enter name: ");
    scanf("%s", s->name);
    printf("Enter registration number: ");
    scanf("%d", &s->regno);
    printf("Enter marks for subject 1: ");
    scanf("%d", &s->m1);
    printf("Enter marks for subject 2: ");
    scanf("%d", &s->m2);
}

void calculate(struct students *s) {
    s->cgpa = (s->m1 + s->m2) / 2.0;
}

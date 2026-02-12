#include<stdio.h>

struct student
{
    int roll;
    char name[20];
};

void display(struct student *obj_st){
    printf("Roll: %d\n", (*obj_st).roll);
    printf("Name: %s\n", obj_st->name);
}

int main(){
    struct student s,*st;
    st=&s;
    printf("Enter roll and name:\n");
    scanf("%d %s",&(*st).roll,&st->name);
    display(st);    
    return 0;
}

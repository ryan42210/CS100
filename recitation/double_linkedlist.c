#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RES_SIZE 128
#define NAME_SIZE 64

/*****************Struct * declarations*********************/
// It's generally good to put all your structures at the beginning of a single
// file.

typedef struct {
    char name[NAME_SIZE];
    float score;
} Student;

typedef struct node {
    Student* data;
    struct node* next;
    struct node* previous;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} LinkedList;

/***************Part1: comparison and * sorting***************/
//When str1 > str2, return 1; else return 0.
int compare (const char* str1, const char* str2){
    while(*str1 == *str2) {
        if (*str1 == '\0') return 0;
        str1++, str2++;
    }
    if (*str1 > *str2) return 1;
    else return -1;
}

void string_sort(char* strings[], int size) {
    for (int i = 0; i < size; i++){
        for (int j = 1; j < size-i; j++){
            if (compare(strings[j-1],strings[j]) == 1) {
                char *temp = strings[j-1];
                strings[j-1] = strings[j];
                strings[j] = temp;
            }
        }
    }
}

/*****************New student* function*******************/
Student* new_student(const char* _name, float _score) {
    Student* ptr_to_nstu = (Student*)malloc(sizeof(Student));
    strcpy(ptr_to_nstu->name, _name);
    ptr_to_nstu->score = _score;
    return ptr_to_nstu;
}

/*****************Part2: LinkedList & * functions*************/
void list_init(LinkedList* l) {
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
}

void list_insert(LinkedList* l, Student* stu_ptr) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = stu_ptr;
    new_node->next = NULL;
    new_node->previous = l->tail;
    Node* temp_p = l->head;
    if (l->size == 0)
        l->head = new_node;
    else{
        if (l->size == 1)
            temp_p->next = new_node;
        else{
            for (int i = 0; i < l->size-1; i++) {
                temp_p = temp_p->next;
            }
            temp_p->next = new_node;
        }
    }
    l->tail = new_node;
    l->size++;
}

void list_erase(LinkedList* l) {
    Node* free_node =  l->tail;
    for (int i = 0; i < l->size-1; i++) {
        free(free_node->data);
        free_node = free_node->previous;
        free(free_node->next);
    }
    free(l->head->data);
    free(l->head);
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
}

Node* list_remove(LinkedList* l, Node* target) {
    Node* temp_ptr = l->head;
    Node* buffer;
    int origin_size = l->size;
    if (temp_ptr == target) {
        l->head = temp_ptr->next;
        free(temp_ptr->data);
        free(temp_ptr);
        l->size--;
        if (l->size == 0) {
            l->tail = NULL;
        }
        return l->head;
    }
    else {
        for (int i = 0; i < l->size - 1; i++) {
            if (temp_ptr->next == target) {
                l->size--;
                free(temp_ptr->next->data);
                buffer = temp_ptr->next->next;
                free(temp_ptr->next);
                temp_ptr->next = buffer;
                if (buffer == NULL) {
                    l->tail = temp_ptr;
                }
                return temp_ptr->next;
            }
            temp_ptr = temp_ptr->next;
        }
    }

    if (origin_size == l->size)
        return NULL;
}

/***********************Part3: * Searching**********************/
Node* list_search_by_name(LinkedList* l, char* search_name) {
    Node* search = l->head;
    if (search_name != NULL){
        while (search != NULL) {
            int compare_result = compare(search->data->name,search_name);
            if (compare_result == 0)
                return search;
            search = search->next;
        }
    return NULL;
    }
    else
        return NULL;
}

int list_search_by_score(LinkedList* l, float lower_bound, float upper_bound, char* result[RES_SIZE]) {
    Node* search = l->head;
    int count = 0;
    for (int i = 0; i < l->size; i++){
        if (search->data->score >= lower_bound && search->data->score <= upper_bound) {
            result[count] = search->data->name;
            count++;
        }
    search = search->next;
    }
    string_sort(result,count);
    return count;
}

/**********************Your Main * Function***********************/
// DO NOT submit main function to OJ, or compile error may happen!
int main() {
    LinkedList stu_list_name;
    LinkedList* stu_list = &stu_list_name;
    list_init(stu_list);
    Student* geziwang = new_student("Geziwang",51.8);
    Student* xht = new_student("XuHongtu", 90.0);
    Student* wty = new_student("Xiaoyuan", 81.4);
    Student* d = new_student("d", 59.4);
    Student* k = new_student("K", 74.3);
    list_insert(stu_list,geziwang);
    list_insert(stu_list, xht);
    list_insert(stu_list, wty);
    list_insert(stu_list, d);
    list_insert(stu_list, k);

    Node* temp_p = stu_list->head;
    for (int i = 0; i < stu_list->size; i++){
        float f = temp_p->data->score;
        printf("%s got %.1f points\n", temp_p->data->name, temp_p->data->score);
        temp_p = temp_p->next;
    }

    char temp_str[] = "Ga";
    char* name_need_to_search = temp_str;
    Node* name_found = list_search_by_name(stu_list, name_need_to_search);
    if (name_found != NULL)
        printf("find target %s\n", name_found->data->name);
    else
        printf("meet null\n\n");

    int find_result = -1;
    char* result_name[RES_SIZE] = {NULL};
    find_result = list_search_by_score(stu_list, 59.3, 92.0, result_name);
    printf("find %d results.They are :\n",find_result);

    for (int i = 0; i < find_result; i++){
        printf("%s\n",result_name[i]);
    }

    temp_p = list_remove(stu_list,stu_list->head->next->next->next->next);
    if (temp_p != NULL)
        printf("%s got %.1f points!!!\n", temp_p->data->name,temp_p->data->score);
    else
        printf("Oops\n");
    printf("tail is %s\n", stu_list->tail->data->name);

    list_erase(stu_list);
    return 0;
}
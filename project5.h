#ifndef _PROJECT5_H
#define _PROJECT5_H

struct hash{
  int length;
  struct bucket* table[20];
  
};

struct bucket
{
  struct Bnode* head;
};

typedef struct bucket Bucket;

struct Bnode {
  char* word;               //word in node
  int IDnum;                //ID number of the document in which the word is found
  int times;                //number of times it appears in document
  struct Bnode* next;       //node after this one in the bucket
};

// struct bucket* createBucket();

// int hash_code(struct hash* b, char* w)

// void hash_table_insert(struct hash* btable, char* w, int i);

// int parse_list(struct bucket* b, struct Bnode* n);

// void print_bucket(struct bucket *list);
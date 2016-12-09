#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project5.h"
#include "train.c"
#include "functions.c"



// void print_table(struct hash* htable){
//   int i=0;
//   int j=0;
//   char* thisword;
//   int thisID;
//   int thisfrequency;
//   struct hash* h;
//   h = htable;
//   struct Bnode* currnode;
//   for(i;i<htable->length;i++){                    //parse through buckets in hash table
//     for(j;j<sizeof(htable[i]);j++){                         //parse through nodes in buckets
//      // currnode = htable[i];                       //FIXME
//       thisword = currnode->word;
//       thisID = currnode->IDnum;
//       thisfrequency = currnode->times;
//       printf("Bucket #%d: ", i);
//       printf("Node %d: Word: %s\n ID Number: %d\n Times appeared in document: %d\n\n", j, thisword, thisID, thisfrequency);
//       currnode = currnode->next;
//     }
//   }
//   struct Bnode* node = htable->table[0]->head;
// }

void print_bucket(struct bucket* b){
  struct Bnode* n = malloc(sizeof(struct Bnode));
  struct Bnode* currnode = malloc(sizeof(struct Bnode));
  n = b->head;
 
  int i=1;
  while(n->next != NULL){
    char* w = n->word;
    int ID = n->IDnum;
    int t = n->times;
    printf("Bucket %d: \n", i);
    printf("Word: %s\n ID number: %d\n Number of times in document: %d", w, ID, t);
    n = n->next;    
  }
  
}

void read_query(char* string){
  
}

int main(){
  printf("enter search query:\n");
  
  struct hash* table = malloc(sizeof(struct hash));               //size is 8*length; length in bytes
  table->length = 10;
  int n;
  n = hash_code(table, "ok");
  //print_table(table);
  training(table);
  struct bucket* b = malloc(sizeof(struct bucket));
  //print_bucket(b);
  createLList();
  
  return 0;
}

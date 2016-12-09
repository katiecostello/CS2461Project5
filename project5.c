#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project5.h"

int hash_code(struct hash* b, char* w){       //done
  int i=0;
  int sum = 0;
  int mod = b->length;
  
  for(i;i<strlen(w);i++){
     sum += w[i];                               //adds up the ASCII values of each char in input string
  }
  sum = sum % (mod);                            //calculates the modulo of the sum of the ASCII values
                                                //and the length of the hash table  
  return sum;
}

void hash_table_insert(struct hash* btable, char* w, int i){
  struct Bnode* b = malloc(sizeof(struct Bnode));
  struct Bnode* currnode = malloc(sizeof(struct Bnode));
  b->word = w;
  b->IDnum = i;
  int bnum = hash_code(btable, w);                //gives ID of bucket we're about to add to
  currnode = btable->table[bnum]->head;
  if(parse_list(btable[bnum], b)){
    while(1){
      if(currnode->next==NULL){
        currnode->next = b;
        return;
      }
      currnode = currnode->next;
    }
  }
}

int parse_list(struct bucket* b, struct Bnode* n){           //parses through list and tests to see
  struct Bnode* node = malloc(sizeof(struct Bnode));        //if a word and ID match any nodes already in the list
  node = b->head;                                            //create new node and set equal to list's head
  if(strcmp(node->word, n->word)==0){                         //if the head contains the name, test the doc ID
    if(node->IDnum == n->IDnum){
      return 1;                                                //if doc ID matches, return 1- this means the list contains a node
    }                                                          //with the given information.
  }                            
  while(1){                                                    //repeat this process for the rest of the nodes in the list
    if(node->next == NULL){                                    //as long as the next node isn't NULL, keep going
      return 0;                                                //if the next node is NULL, the list does not contain the node matching so return 0
    }
    if(strcmp(node->word,n->word)==0){                          //compare the word of the input node and the current node being tested
      if(node->IDnum == n->IDnum){
        return 1;                                               //if doc ID matches, return 1- this means the list contains a node
      }   
    }
    node = node->next;
  }                       
}

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

void training(struct hash* b){
 // b = malloc(sizeof(struct hash));
  char c = 0;                           //char that will add to string word
  char* thisword1 = malloc(21);                      //string that will keep track of words being added to linked list for doc1
  char* thisword2 = malloc(21);                      //string that will keep track of words being added to linked list for doc2
  char* thisword3 = malloc(21);                      //string that will keep track of words being added to linked list for doc3
  struct Bnode* newnode = malloc(sizeof(struct Bnode));      //node that will be created
  FILE* doc1;
  FILE* doc2;
  FILE* doc3;
  struct bucket* b1 = malloc(sizeof(struct bucket));
  struct bucket* b2 = malloc(sizeof(struct bucket));
  struct bucket* b3 = malloc(sizeof(struct bucket));
  
  doc1 = fopen("D1.txt", "r");          //instantiate all documents by opening them
  doc2 = fopen("D2.txt", "r");          //and loading them into variables doc1, doc2, and doc3
  doc3 = fopen("D3.txt", "r");
  int x = 001;
  int i = 0;
  while(!feof(doc1)){
    char* bufstring = malloc(21);                   //to append a char to a char*, create a new char* with a length of
                                                    //the original plus one.
    c = fgetc(doc1);                                //set c equal to the next char in the file
    thisword1[i] = c;
    if(c==32){                          //if c is a space,
      //printf("%s\n", thisword1);
      //hash_table_insert(b, thisword1, 001);
      
    }
    
    i++;
  }
  i=0;
//   while(!feof(doc2)){
//     char* bufstring = malloc(21);                   //to append a char to a char*, create a new char* with a length of
//                                                     //the original plus one.
//     c = fgetc(doc2);                                //set c equal to the next char in the file
//     thisword2[i] = c;
//     if(c==32){
//       hash_table_insert(b, thisword2, 002);
//       i=0;
//     }
//     i++;
//   }
//   i=0;
//   while(!feof(doc3)){
//     char* bufstring = malloc(21);                   //to append a char to a char*, create a new char* with a length of
//                                                     //the original plus one.
//     c = fgetc(doc3);                                //set c equal to the next char in the file
//     thisword3[i] = c;
//     if(c==32){
//       hash_table_insert(b, thisword3, 003);
//       i=0;
//     }
    
//     i++;
//   }
  
  fclose(doc1);
  fclose(doc2);
  fclose(doc3);
//   int n = hash_code(b, "");
//   printf("%d\n", n);
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
  print_bucket(b);
  
  return 0;
}

#ifndef LAB_11_LIST_H
#define LAB_11_LIST_H

#include "item.h"

typedef struct {
    WoWMounts *head;
    WoWMounts *tail;
    int size;
} List;

/* Init Array */
List *makeList();

/* Create new node */
void add(WoWMounts *mount, List *list);

/* Create new node to prelast */
void addToPreLast(WoWMounts *mount, List *list);

/* Get node by id */
WoWMounts *get(int id, List *list);

/* Delete note by id */
int Delete(int id, List *list);

/* Write all list */
void display(List *list);

/* Destroy List */
void destroy(List *list);
/*Correct Cost*/
void correctCost(List *list);
/*Correct Name*/
void correctName(List *list);
/*Correct Quest*/
void correctQuest(List *list);
/*Correct Achieve*/
void correctAchieve(List *list);
/*Correct Character*/
void correctCharacter(List *list);
/*Correct Chance*/
void correctChance(List *list);
/*Correct Addition*/
void correctAddon(List *list);
/*Correct Location*/
void correctLocation(List *list);
/*Correct Holders*/
void correctHolders(List *list);
/*Correct Rate*/
void correctRate(List *list);

#endif //LAB_11_LIST_H

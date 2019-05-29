#include "stdlib.h"
#include "stdio.h"
#include "list.h"
#include "item.h"

List *makeList()
{
    List *list = malloc(sizeof(List));
    if (!list)
    {
        return NULL;
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

void add(WoWMounts *mount, List *list)
{
    WoWMounts *current = NULL;
    mount->next = NULL;
    mount->id = 0;

    if (list->head == NULL)
    {
        list->head = mount;
    }
    else
    {
        mount->id++;
        current = list->head;
        while (current->next != NULL)
        {
            mount->id++;
            current = (WoWMounts *) current->next;
        }
        mount->prev = (struct WoWMounts *) current;
        current->next = (struct WoWMounts *) mount;
    }
}

void addToPreLast(WoWMounts *mount, List *list)
{
    WoWMounts *current = NULL;
    WoWMounts *nextMount = NULL;
    mount->next = NULL;
    mount->id = 0;

    if (list->head == NULL)
    {
        list->head = mount;
    }
    else
    {
        mount->id++;
        current = list->head;

        if(current->next == NULL)
        {
            nextMount = (WoWMounts *) current;
        }
        else
        {
            nextMount = (WoWMounts *) current->next;
        }

        while (nextMount->next != NULL)
        {
            mount->id++;
            current = (WoWMounts *) current->next;
            nextMount = (WoWMounts *) nextMount->next;
        }

        if(nextMount == current)
        {
            list->head = mount;
            mount->next = (struct WoWMounts *) current;
        }
        else
        {
            current->next = (struct WoWMounts *) mount;
            mount->next = (struct WoWMounts *) nextMount;
        }
        int k = 0;
        current = list->head;
        int l = 0;
        while (current != NULL)
        {
            l++;
            current = (WoWMounts *) current->next;
        }
        current = list->head;
        while (current != NULL)
        {
            if (k == 1)
                current->id = l-1;
            if (current->id == l-2)
                k = 1;
            current = (WoWMounts *) current->next;
        }
    }
}

WoWMounts *get(int id, List *list)
{
    WoWMounts *current = list->head;
    while (current != NULL)
    {
        if (current->id == id)
        {
            return current;
        }
        current = (WoWMounts *) current->next;
    }
    return NULL;
}

int Delete(int id, List *list)
{
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    int c = 0;
    if (id != -1)
    {
        while (current != NULL)
        {
            if (current->id == id)
            {
                previous->next = current->next;
                if (current == list->head)
                    list->head = (WoWMounts *) current->next;
                free(current);
                current = (WoWMounts *) previous;
                c++;
            }
            previous = current;
            current = (WoWMounts *) current->next;
        }
    }
    else
        printf("You can't do it, there is no mount with Id = -1, please choose another Id");
    return c;
}

void correctCost(List *list)
{
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    int kok;
    while (current != NULL)
    {
        printf("%d)%d\n", current->id, current->cost);
        previous = current;
        current = (WoWMounts *) current->next;
    }
    printf("Choose element by it ID:");
    scanf("%d", &kok);
    current = list->head;
    previous = current;
    while (current != NULL)
    {
        if (current->id == kok)
        {
            current->cost = enterInt("Write new cost:");
        }
        previous = current;
        current = (WoWMounts *) current->next;
    }
}

void correctName(List *list)
{
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    int kok;
    while (current != NULL)
    {
        printf("%d)%s\n", current->id, current->name);
        previous = current;
        current = (WoWMounts *) current->next;
    }
    printf("Choose element by it ID:");
    scanf("%d", &kok);
    current = list->head;
    previous = current;
    while (current != NULL)
    {
        if (current->id == kok)
        {
            current->name = enterString("Write new name:");
        }
        previous = current;
        current = (WoWMounts *) current->next;
    }
}

void correctQuest(List *list)
{
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    int kok;
    while (current != NULL)
    {
        printf("%d)%s\n", current->id, current->quest);
        previous = current;
        current = (WoWMounts *) current->next;
    }
    printf("Choose element by it ID:");
    scanf("%d", &kok);
    current = list->head;
    previous = current;
    while (current != NULL)
    {
        if (current->id == kok)
        {
            current->quest = enterString("Write new quest:");
        }
        previous = current;
        current = (WoWMounts *) current->next;
    }
}

void correctAchieve(List *list)
{
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    int kok;
    while (current != NULL)
    {
        printf("%d)%s\n", current->id, current->achieve);
        previous = current;
        current = (WoWMounts *) current->next;
    }
    printf("Choose element by it ID:");
    scanf("%d", &kok);
    current = list->head;
    previous = current;
    while (current != NULL)
    {
        if (current->id == kok)
        {
            current->achieve = enterString("Write new achievement:");
        }
        previous = current;
        current = (WoWMounts *) current->next;
    }
}

void correctCharacter(List *list)
{
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    int kok;
    while (current != NULL)
    {
        printf("%d)%s\n", current->id, current->drop);
        previous = current;
        current = (WoWMounts *) current->next;
    }
    printf("Choose element by it ID:");
    scanf("%d", &kok);
    current = list->head;
    previous = current;
    while (current != NULL)
    {
        if (current->id == kok)
        {
            current->drop = enterString("Write new character:");
        }
        previous = current;
        current = (WoWMounts *) current->next;
    }
}

void correctChance(List *list)
{
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    int kok;
    while (current != NULL)
    {
        printf("%d)%lf\n", current->id, current->chance);
        previous = current;
        current = (WoWMounts *) current->next;
    }
    printf("Choose element by it ID:");
    scanf("%d", &kok);
    current = list->head;
    previous = current;
    while (current != NULL)
    {
        if (current->id == kok)
        {
            current->chance = enterDouble("Write new chance:");
        }
        previous = current;
        current = (WoWMounts *) current->next;
    }
}

void correctAddon(List *list)
{
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    int kok;
    while (current != NULL)
    {
        printf("%d)%s\n", current->id, current->addon);
        previous = current;
        current = (WoWMounts *) current->next;
    }
    printf("Choose element by it ID:");
    scanf("%d", &kok);
    current = list->head;
    previous = current;
    while (current != NULL)
    {
        if (current->id == kok)
        {
            current->addon = enterString("Write new addition:");
        }
        previous = current;
        current = (WoWMounts *) current->next;
    }
}

void correctLocation(List *list)
{
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    int kok;
    while (current != NULL)
    {
        printf("%d)%s\n", current->id, current->where);
        previous = current;
        current = (WoWMounts *) current->next;
    }
    printf("Choose element by it ID:");
    scanf("%d", &kok);
    current = list->head;
    previous = current;
    while (current != NULL)
    {
        if (current->id == kok)
        {
            current->where = enterString("Write new location:");
        }
        previous = current;
        current = (WoWMounts *) current->next;
    }
}

void correctHolders(List *list)
{
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    int kok;
    while (current != NULL)
    {
        printf("%d)%lf\n", current->id, current->holders);
        previous = current;
        current = (WoWMounts *) current->next;
    }
    printf("Choose element by it ID:");
    scanf("%d", &kok);
    current = list->head;
    previous = current;
    while (current != NULL)
    {
        if (current->id == kok)
        {
            current->holders = enterDouble("Write new holders:");
        }
        previous = current;
        current = (WoWMounts *) current->next;
    }
}

void correctRate(List *list)
{
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    int kok;
    while (current != NULL)
    {
        printf("%d)%d\n", current->id, current->rate);
        previous = current;
        current = (WoWMounts *) current->next;
    }
    printf("Choose element by it ID:");
    scanf("%d", &kok);
    current = list->head;
    previous = current;
    while (current != NULL)
    {
        if (current->id == kok)
        {
            current->rate = enterInt("Write new rate:");
        }
        previous = current;
        current = (WoWMounts *) current->next;
    }
}

void searchCost(List *list, int cost)
{
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    while (current != NULL)
    {
        if ( current->cost == cost )
        {
            printf("Id: %d\nCost: %d\nName: %s\nQuest: %s\nAchievement: %s\nCharacter: %s\nDrop chance: %lf\nAddition: %s\nLocation: %s\nPercent of holders: %lf\nSubjective rate: %d\n\n",
                   current->id,current->cost, current->name, current->quest, current->achieve, current->drop, current->chance, current->addon, current->where, current->holders, current->rate);
        }
        previous = current;
        current = (WoWMounts *) current->next;
    }
    printf("Write anything for close correct option: ");
    getch();
}

void searchName(List *list, char *name)
{
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            printf("Id: %d\nCost: %d\nName: %s\nQuest: %s\nAchievement: %s\nCharacter: %s\nDrop chance: %lf\nAddition: %s\nLocation: %s\nPercent of holders: %lf\nSubjective rate: %d\n\n",
                   current->id,current->cost, current->name, current->quest, current->achieve, current->drop, current->chance, current->addon, current->where, current->holders, current->rate);
        }
        previous = current;
        current = (WoWMounts *) current->next;
    }
    printf("Write anything for close correct option: ");
    getch();
}

void searchQuest(List *list, char *quest)
{
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    while (current != NULL)
    {
        if (strcmp(current->quest, quest) == 0)
        {
            printf("Id: %d\nCost: %d\nName: %s\nQuest: %s\nAchievement: %s\nCharacter: %s\nDrop chance: %lf\nAddition: %s\nLocation: %s\nPercent of holders: %lf\nSubjective rate: %d\n\n",
                   current->id,current->cost, current->name, current->quest, current->achieve, current->drop, current->chance, current->addon, current->where, current->holders, current->rate);
        }
        previous = current;
        current = (WoWMounts *) current->next;
    }
    printf("Write anything for close correct option: ");
    getch();
}

void searchAchieve(List *list, char *achieve)
{
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    while (current != NULL)
    {
        if (strcmp(current->achieve, achieve) == 0)
        {
            printf("Id: %d\nCost: %d\nName: %s\nQuest: %s\nAchievement: %s\nCharacter: %s\nDrop chance: %lf\nAddition: %s\nLocation: %s\nPercent of holders: %lf\nSubjective rate: %d\n\n",
                   current->id,current->cost, current->name, current->quest, current->achieve, current->drop, current->chance, current->addon, current->where, current->holders, current->rate);
        }
        previous = current;
        current = (WoWMounts *) current->next;
    }
    printf("Write anything for close correct option: ");
    getch();
}

void searchCharacter(List *list, char *character)
{
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    while (current != NULL)
    {
        if (strcmp(current->drop, character) == 0)
        {
            printf("Id: %d\nCost: %d\nName: %s\nQuest: %s\nAchievement: %s\nCharacter: %s\nDrop chance: %lf\nAddition: %s\nLocation: %s\nPercent of holders: %lf\nSubjective rate: %d\n\n",
                   current->id,current->cost, current->name, current->quest, current->achieve, current->drop, current->chance, current->addon, current->where, current->holders, current->rate);
        }
        previous = current;
        current = (WoWMounts *) current->next;
    }
    printf("Write anything for close correct option: ");
    getch();
}

void searchChance(List *list, double chance)
{
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    while (current != NULL)
    {
        if ( current->chance == chance )
        {
            printf("Id: %d\nCost: %d\nName: %s\nQuest: %s\nAchievement: %s\nCharacter: %s\nDrop chance: %lf\nAddition: %s\nLocation: %s\nPercent of holders: %lf\nSubjective rate: %d\n\n",
                   current->id,current->cost, current->name, current->quest, current->achieve, current->drop, current->chance, current->addon, current->where, current->holders, current->rate);
        }
        previous = current;
        current = (WoWMounts *) current->next;
    }
    printf("Write anything for close correct option: ");
    getch();
}

void searchAddon(List *list, char *addon)
{
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    while (current != NULL)
    {
        if (strcmp(current->addon, addon) == 0)
        {
            printf("Id: %d\nCost: %d\nName: %s\nQuest: %s\nAchievement: %s\nCharacter: %s\nDrop chance: %lf\nAddition: %s\nLocation: %s\nPercent of holders: %lf\nSubjective rate: %d\n\n",
                   current->id,current->cost, current->name, current->quest, current->achieve, current->drop, current->chance, current->addon, current->where, current->holders, current->rate);
        }
        previous = current;
        current = (WoWMounts *) current->next;
    }
    printf("Write anything for close correct option: ");
    getch();
}

void searchLocation(List *list, char *location)
{
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    while (current != NULL)
    {
        if (strcmp(current->where, location) == 0)
        {
            printf("Id: %d\nCost: %d\nName: %s\nQuest: %s\nAchievement: %s\nCharacter: %s\nDrop chance: %lf\nAddition: %s\nLocation: %s\nPercent of holders: %lf\nSubjective rate: %d\n\n",
                   current->id,current->cost, current->name, current->quest, current->achieve, current->drop, current->chance, current->addon, current->where, current->holders, current->rate);
        }
        previous = current;
        current = (WoWMounts *) current->next;
    }
    printf("Write anything for close correct option: ");
    getch();
}

void searchHolders(List *list, double holders)
{
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    while (current != NULL)
    {
        if ( current->holders == holders )
        {
            printf("Id: %d\nCost: %d\nName: %s\nQuest: %s\nAchievement: %s\nCharacter: %s\nDrop chance: %lf\nAddition: %s\nLocation: %s\nPercent of holders: %lf\nSubjective rate: %d\n\n",
                   current->id,current->cost, current->name, current->quest, current->achieve, current->drop, current->chance, current->addon, current->where, current->holders, current->rate);
        }
        previous = current;
        current = (WoWMounts *) current->next;
    }
    printf("Write anything for close correct option: ");
    getch();
}

void searchRate(List *list, int rate)
{
    WoWMounts *current = list->head;
    WoWMounts *previous = current;
    while (current != NULL)
    {
        if ( current->rate == rate )
        {
            printf("Id: %d\nCost: %d\nName: %s\nQuest: %s\nAchievement: %s\nCharacter: %s\nDrop chance: %lf\nAddition: %s\nLocation: %s\nPercent of holders: %lf\nSubjective rate: %d\n\n",
                   current->id,current->cost, current->name, current->quest, current->achieve, current->drop, current->chance, current->addon, current->where, current->holders, current->rate);
        }
        previous = current;
        current = (WoWMounts *) current->next;
    }
    printf("Write anything for close correct option: ");
    getch();
}

void swap(WoWMounts *a, WoWMounts *b)
{
    int id = a->id;
    int cost = a->cost;
    char *name = initStringField(a->name);
    char *quest = initStringField(a->quest);
    char *achieve = initStringField(a->achieve);
    char *character = initStringField(a->drop);
    double chance = a->chance;
    char *addon = initStringField(a->addon);
    char *location = initStringField(a->where);
    double holders = a->holders;
    int rate = a->rate;

    a->id = b->id;
    a->cost = b->cost;
    a->name = b->name;
    a->quest = b->quest;
    a->achieve = b->achieve;
    a->drop = b->drop;
    a->chance = b->chance;
    a->addon = b->addon;
    a->where = b->where;
    a->holders = b->holders;
    a->rate = b->rate;

    a->id = id;
    a->cost = cost;
    a->name = name;
    a->quest = quest;
    a->achieve = achieve;
    a->drop = character;
    a->chance = chance;
    a->addon = addon;
    a->where = location;
    a->holders = holders;
    a->rate = rate;
}

void sortId(List *list)
{
    int swapped;
    WoWMounts *wowMounts;
    WoWMounts *wowMountsNext = NULL;

    if (list->head == NULL)
        return;

    do
    {
        swapped = 0;
        wowMounts = list->head;

        while (wowMounts->next != NULL)
        {
            wowMountsNext = (WoWMounts *) wowMounts->next;
            if (wowMounts->id > wowMountsNext->id)
            {
                swap(wowMounts, (WoWMounts *) wowMounts->next);
                swapped = 1;
            }
            wowMounts = (WoWMounts *) wowMounts->next;
        }
        wowMounts = wowMountsNext;
    }
    while (swapped);
}

void display(List *list)
{
    WoWMounts *current = list->head;
    if (current == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("__________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
    printf("Id\t|Cost\t|Name\t\t\t |Quest\t\t      |Achievement\t   |Drop\t\t    |Addition\t     |Location\t\t  |Chance\t|Percent of holders\t|Subjective rate\t|\n");
    printf("__________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
    int m = 0;
    while (current != NULL)
    {
        if (m == 1)
            printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        m = 1;
        printf("%-8d|%-7d|",current->id,current->cost);

        for(int h = 0; h < 24; h++)
        {
            if (current->name[h] != '\0')
                printf("%c", current->name[h]);
            else
            {
                int z = 24-h;
                h = 25;
                for(int b = 0; b<z; b++)
                    printf(" ");
            }
        }
        printf("|");
        for(int h = 0; h < 20; h++)
        {
            if (current->quest[h] != '\0')
                printf("%c", current->quest[h]);
            else
            {
                int z = 20-h;
                h = 21;
                for(int b = 0; b<z; b++)
                    printf(" ");
            }
        }
        printf("|");
        for(int h = 0; h < 20; h++)
        {
            if (current->achieve[h] != '\0')
                printf("%c", current->achieve[h]);
            else
            {
                int z = 20-h;
                h = 21;
                for(int b = 0; b<z; b++)
                    printf(" ");
            }
        }
        printf("|");
        for(int h = 0; h < 20; h++)
        {
            if (current->drop[h] != '\0')
                printf("%c", current->drop[h]);
            else
            {
                int z = 20-h;
                h = 21;
                for(int b = 0; b<z; b++)
                    printf(" ");
            }
        }
        printf("|");
        for(int h = 0; h < 20; h++)
        {
            if (current->addon[h] != '\0')
                printf("%c", current->addon[h]);
            else
            {
                int z = 20-h;
                h = 21;
                for(int b = 0; b<z; b++)
                    printf(" ");
            }
        }
        printf("|");
        for(int h = 0; h < 20; h++)
        {
            if (current->where[h] != '\0')
                printf("%c", current->where[h]);
            else
            {
                int z = 20-h;
                h = 21;
                for(int b = 0; b<z; b++)
                    printf(" ");
            }
        }
        printf("|");
        printf("%lf\t|%lf\t\t|%d\t\t\t|\n",
               current->chance, current->holders, current->rate);
        current = (WoWMounts *) current->next;
    }
    printf("__________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
    printf("Inscriptions are abbreviated if you want to see completely open the table element separately.(Option find, then id)\n");
}

void destroy(List *list)
{
    WoWMounts *current = list->head;
    WoWMounts *next = current;
    while (current != NULL)
    {
        next = (WoWMounts *) current->next;
        free(current);
        current = next;
    }
    free(list);
}

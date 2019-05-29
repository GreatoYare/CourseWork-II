#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "list.h"
#include "file_manager.h"
#include "checks.h"

// For adaptive clear screen
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

WoWMounts *readItem(WoWMounts *wowMounts)
{
    wowMounts->cost = enterInt("Write cost of mount: ");
    wowMounts->name = enterString("Write name of mount: ");
    wowMounts->quest = enterString("Write quest where you can earn mount: ");
    wowMounts->achieve = enterString("Write achievement where you can earn mount: ");
    wowMounts->drop = enterString("Write from who you can earn mount: ");
    wowMounts->chance = enterDouble("Write chance of mount drop: ");
    wowMounts->addon = enterString("Write addition where mount stand: ");
    wowMounts->where = enterString("Write location where mount stand: ");
    wowMounts->holders = enterDouble("Write percent of mount holders: ");
    wowMounts->rate = enterInt("Write your rate of mount: ");
    return wowMounts;
}

void showAbout()
{
    system(CLEAR);
    puts("================= [About] ===================");
    puts("Title: \"Course work\"");
    puts("Author: Spiridonov Leonid 8307");
    puts("=============================================");
    printf("Press anything to continue: ");
    getch();
}

void showChanges(List *list){
    system(CLEAR);
    int mainU = 0;
    puts("================== [Changes] ====================");
    puts("0. Delete");
    puts("1. Correct");
    puts("================== [Changes] ====================");
    mainU = enterInt("Choose option:");
    if (mainU == 0) showDelete(list);
    if (mainU == 1) showCorrect(list);
}

void showCorrect(List *list){
    system(CLEAR);
    int manU = 0;
    puts("================== [Correct] ====================");
    puts("0. Cost");
    puts("1. Name");
    puts("2. Quest");
    puts("3. Achievement");
    puts("4. Character");
    puts("5. Chance");
    puts("6. Addition");
    puts("7. Location");
    puts("8. Holders");
    puts("9. Rate");
    puts("================== [Correct] ====================");
    manU = enterInt("Choose field:");
    if (manU == 0) correctCost(list);
    if (manU == 1) correctName(list);
    if (manU == 2) correctQuest(list);
    if (manU == 3) correctAchieve(list);
    if (manU == 4) correctCharacter(list);
    if (manU == 5) correctChance(list);
    if (manU == 6) correctAddon(list);
    if (manU == 7) correctLocation(list);
    if (manU == 8) correctHolders(list);
    if (manU == 9) correctRate(list);
}

void showSearch(List *list){
    system(CLEAR);
    int manU = 0;
    puts("================== [Search] ====================");
    puts("0. Cost");
    puts("1. Name");
    puts("2. Quest");
    puts("3. Achievement");
    puts("4. Character");
    puts("5. Chance");
    puts("6. Addition");
    puts("7. Location");
    puts("8. Holders");
    puts("9. Rate");
    puts("================== [Search] ====================");
    manU = enterInt("Choose field:");
    if (manU == 0) {
            int cost = enterInt("Write cost for find:");
            searchCost(list, cost);
    }
    if (manU == 1) {
            char *name = enterString("Write name for find:");
            searchName(list, name);
    }
    if (manU == 2) {
            char *quest = enterString("Write quest for find:");
            searchQuest(list, quest);
    }
    if (manU == 3) {
            char *achieve = enterString("Write achievement for find:");
            searchAchieve(list, achieve);
    }
    if (manU == 4) {
            char *character = enterString("Write character for find:");
            searchCharacter(list, character);
    }
    if (manU == 5) {
            double chance = enterDouble("Write chance for find:");
            searchChance(list, chance);
    }
    if (manU == 6) {
            char *addon = enterString("Write addition for find:");
            searchAddon(list, addon);
    }
    if (manU == 7) {
            char *location = enterString("Write location for find:");
            searchLocation(list, location);
    }
    if (manU == 8) {
            double holders = enterDouble("Write holders for find:");
            searchHolders(list, holders);
    }
    if (manU == 9) {
            int rate = enterInt("Write rate for find:");
            searchRate(list, rate);
    }
    printf("Write anything for close search option: ");
}

void showSort(List *list){
    system(CLEAR);
    int manU = 0;
    puts("================== [Search] ====================");
    puts("0. ID");
    puts("1. Cost");
    puts("2. Name");
    puts("3. Quest");
    puts("4. Achievement");
    puts("5. Character");
    puts("6. Chance");
    puts("7. Addition");
    puts("8. Location");
    puts("9. Holders");
    puts("10. Rate");
    puts("================== [Search] ====================");
    manU = enterInt("Choose field:");
    if (manU == 0) {
            sortId(list);
    }
    /*if (manU == 1) {
            sortCost(list);
    }
    if (manU == 2) {
            sortName(list);
    }
    if (manU == 2) {
            char *quest = enterString("Write quest for find:");
            searchQuest(list, quest);
    }
    if (manU == 3) {
            char *achieve = enterString("Write achievement for find:");
            searchAchieve(list, achieve);
    }
    if (manU == 4) {
            char *character = enterString("Write character for find:");
            searchCharacter(list, character);
    }
    if (manU == 5) {
            double chance = enterDouble("Write chance for find:");
            searchChance(list, chance);
    }
    if (manU == 6) {
            char *addon = enterString("Write addition for find:");
            searchAddon(list, addon);
    }
    if (manU == 7) {
            char *location = enterString("Write location for find:");
            searchLocation(list, location);
    }
    if (manU == 8) {
            double holders = enterDouble("Write holders for find:");
            searchHolders(list, holders);
    }
    if (manU == 9) {
            int rate = enterInt("Write rate for find:");
            searchRate(list, rate);
    }*/
    printf("Write anything for close search option: ");
}

void showDelete(List *list)
{

    system(CLEAR);
    puts("================== [Delete] ====================");
    puts("At this point you can delete a mount\nfrom the library. Follow the instructions.");
    puts("=============================================");

    int id;
    printf("Enter the mount id before which you want to delete:");
    scanf("%d", &id);

    Delete(id, list);
    puts("Item was deleted from library");
    printf("Write anything to continue: ");
    getch();
}

void showAdd(List *list)
{
    WoWMounts *wowMounts = malloc(sizeof(WoWMounts));

    system(CLEAR);
    puts("================== [Add] ====================");
    puts("At this point you can add a new mount\nto the library. Follow the instructions.");
    puts("=============================================");

    readItem(wowMounts);

    addToPreLast(wowMounts, list);
    puts("Mount was added to library");
    printf("Write anything to continue: ");
    getch();
}

void showList(List *list)
{
    system(CLEAR);
    puts("================= [List] ====================");
    display(list);
    puts("=============================================");
    printf("Write anything to continue: ");
    getch();
}

void showMenu(List *list)
{
    int menu = 0;
    while (menu != 6)
    {
        system(CLEAR);
        puts("================= [MENU] ===================");
        puts("0. Abouts");
        puts("1. Add new element");
        puts("2. Print list");
        puts("3. Changes");
        puts("4. Search");
        puts("5. Sort");
        puts("6. Exit");
        puts("============================================");
        menu = enterInt("Write your command: ");

        if (menu == 0)
        {
            showAbout();
        }
        else if (menu == 1)
        {
            showAdd(list);
        }
        else if (menu == 2)
        {
            showList(list);
        }
        else if (menu == 3)
        {
            showChanges(list);
        }
        else if (menu == 4)
        {
            showSearch(list);
        }
        else if (menu == 5)
        {
            showSort(list);
        }
    }
}

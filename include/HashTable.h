#ifndef BASEIS_HASHTABLE_H
#define BASEIS_HASHTABLE_H

#include <stdlib.h>
#include <string.h>
#include <BF.h>
#include "Helper.h"


typedef struct {
    int fileDesc;           /* αναγνωριστικός αριθμός ανοίγματος αρχείου από το επίπεδο block */
    char attrType;          /* ο τύπος του πεδίου που είναι κλειδί για το συγκεκριμένο αρχείο, 'c' ή'i' */
    char* attrName;         /* το όνομα του πεδίου που είναι κλειδί για το συγκεκριμένο αρχείο */
    int attrLength;         /* το μέγεθος του πεδίου που είναι κλειδί για το συγκεκριμένο αρχείο */
    long int numBuckets;    /* το πλήθος των “κάδων” του αρχείου κατακερματισμού */
} HT_info;


int HT_CreateIndex(  char *fileName,    /* όνομα αρχείου */
                    char attrType,      /* τύπος πεδίου-κλειδιού: 'c', 'i' */
                    char* attrName,     /* όνομα πεδίου-κλειδιού */
                    int attrLength,     /* μήκος πεδίου-κλειδιού */
                    int buckets         /* αριθμός κάδων κατακερματισμού*/
                    );

HT_info* HT_OpenIndex(char *fileName);

int HT_CloseIndex(HT_info* header_info );

int HT_InsertEntry(HT_info header_info, Record record);

int HT_DeleteEntry(HT_info header_info, void *value);

int HT_GetAllEntries(HT_info header_info,void *value);

int HT_GetAllEntry(HT_info header_info, void* value, int blockIds[], int numOfBlocks);

int HT_Statistics(HT_info ht_info);

#endif //BASEIS_HASHTABLE_H

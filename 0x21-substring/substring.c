#include "substring.h"
/**
 *
 *
 *
 */
 int *find_substring(char const *s, char const **words, int nb_words, int *n)
 {
   int i, full_loop, x, l, idx = 0;
   int *indices = NULL, *tracker;
   int raw_idx[1024];
   for (i = 0; i < 1024; i++)
   raw_idx[i] = -1;
   i = 0;
   tracker = malloc(sizeof(int) * nb_words);
   reset_tracker(tracker, nb_words);
   while (contains_zeroes(tracker, nb_words) && s[i]) {
     full_loop = 1;
     // printf("&s[i] %s\n", &s[i]);
     for (x = 0; x < nb_words; x++)
     {
       // printf("xword 5ra %s\n", words[x]);


       if (tracker[x] == 0)
       {
         l = compare((char *)&s[i], (char *)words[x]);
       }
       else
       {
         // duble = 1;
         l = -1;
       }
       if (l != -1)
       {
         // printf("I found it\n");
         if (all_zeroes(tracker, nb_words))
         {
           raw_idx[idx] = i;
           // next_word = i + l;
         }
         full_loop = 0;
         i += l;
         tracker[x] = 1;
         break;
       }
       // printf("tracker 5ra 0 %d\n", tracker[0]);
       // printf("tracker 5ra 1 %d\n", tracker[1]);
       // printf("tracker 5ra 2 %d\n", tracker[2]);
       // printf("tracker 5ra 3 %d\n", tracker[3]);
     }
     // printf(".......................\n");
     if (!contains_zeroes(tracker, nb_words))
     {
       idx++;
       reset_tracker(tracker, nb_words);
     }
     if (full_loop || (!s[i] && contains_zeroes(tracker, nb_words)))
     {
       // printf("enter full loop true\n");
       raw_idx[idx] = -1;
       reset_tracker(tracker, nb_words);
       i++;
       // i = s[i] ? next_word: i + 1;
       // printf("&s[next_word] %s\n", &s[next_word]);
       // printf("l %d, i, %d, next_word, %d , &s[i] %s\n",l, i, next_word, &s[i]);

       // if ((s[i] && duble)
       // {
       //   i = next_word;
       //   printf("put next_word");
       // }
       // else
       // {
       //   i++;
       // }
       // i = (duble == 1) ? next_word : i + 1;
       // printf("&s[next_word] %s\n", &s[next_word]);
     }
   }
   indices = fill_indices(raw_idx, indices, n);
   free(tracker);
   return(indices);
 }

 void reset_tracker(int *tracker, int nb_words)
 {
   int i;

   for (i = 0; i < nb_words; i++)
   tracker[i] = 0;
 }

 int contains_zeroes(int *tracker, int nb_words)
 {
   int i;

   for (i = 0; i < nb_words; i++)
   {
     if (tracker[i] == 0)
     return(1);
   }
   return(0);
 }
 int all_zeroes(int *tracker, int nb_words)
 {
   int i;

   for (i = 0; i < nb_words; i++)
   {
     if (tracker[i] == 1)
     return(0);
   }
   return(1);
 }
 int compare(char *s, char *word)
 {
   int i = 0;

   if (!s[i] && !word[i])
   return (0);
   while (word[i])
   {
     if (s[i] != word[i])
     return(-1);
     i++;
   }
   return(i);
 }
 int *fill_indices(int *raw_idx, int *indices, int *n)
 {
   int i = 0;
   while (raw_idx[i] != -1)
   i++;
   *n = i;
   indices = malloc(sizeof(int) * (*n));
   if (!indices)
   {
     *n = 0;
     return (NULL);
   }
   for (i = 0; i < (*n); i++)
   {
     indices[i] = raw_idx[i];
   }
   return(indices);
 }

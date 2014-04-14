#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <glib.h>
#include <glib/gstdio.h>

void printall(char* key, gint* value);
int main (int argc, char **argv)
{
    gchar *namein = "celtic.txt";
    gchar *text;
    gboolean result = 0;
    GString *word = g_string_new("");
    GHashTable *hash = g_hash_table_new(g_str_hash,g_str_equal);
    gchar letter = 'a';
    int i;
    int wordend = 0;

    result = g_file_get_contents (namein, &text, NULL, NULL);
    g_print("test file: %i\n",result);
    for(i=0;i<strlen(text);i++){
        letter = text[i];
        if(isalpha(letter)){
            wordend = 1;
            g_string_append_c(word,letter);
        }
        else if(wordend){
            gchar *key = strdup(word->str);
            gint *val = g_malloc(sizeof(gint));
            *val = 1;
            gint *count = g_hash_table_lookup(hash,key);
            if(count){
                *val = *count+1;
            }
            g_hash_table_insert(hash, key, val);
            g_string_free(word,1);
            word = g_string_new("");
            wordend = 0;
        }
    }

    g_hash_table_foreach(hash,(GHFunc)printall,NULL);
  
    g_string_free(word,1);


    return 0;
}

void printall(char* key, gint* value){
    g_print("%s: %i\n",key,*value);

}

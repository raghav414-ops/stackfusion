/*
 * stackfusion.c
 *
 * Created: 20-02-2021 01:26:39
 *  Author: Raghav
 */ 


#include <avr/io.h>
#include<stdlib>
#include<string.h>
#include<unistd.h>
#include "jsmn.h"

jsmn_t t[512];
char jsonstr[512*1024];
int main(void)
{
    size)_t pos=0;
    int c;
    
    while(1)
    {
        
        while((c=getchar())!=EOF)
        {
            jsonstr[pos]=c;
            ++pos;
            if(pos==sizeof(jsonstr)) break;
        }
        jsonstr[pos]=0;
            jsmn_parser p;
            jsmn_init(&p);
        int tcount=jsmn_parse(&p, jsonstr, strlen(jsonstr),t, sizeof(t)/sizeof(*t));
        
        for(int i=0;i!=tcount;++i)
        {
            jsmntok_t *token=t+i;
            char *type=0;
            switch (token->type)
            {
                case JSMN_PRIMITIVE:
        }
    }
}

#include<stdio.h>                                                               
                                                                                
char a;                                                                         
const int b;                                                                    
volatile int c;                                                                 
static int d;                                                                   
                                                                                
int m = 0;                                                                      
const int n = 0;                                                                
volatile int o = 0;                                                             
static int p = 0;                                                               
                                                                                
int s = 1 ;                                                                     
const int t = 2;                                                                
volatile int u = 3;                                                             
static int v = 4;                                                               
                                                                                
register int var1 asm("ebx");                                                   
                                                                                
int main(void)                                                                  
{                                                                               
    int e;                                                                      
    const int f;                                                                
    volatile int g;                                                             
    static char h;                                                              
                                                                                
    int i = 0;                                                                  
    const int j = 0;                                                            
    volatile int k = 0;                                                         
    static int l = 0;                                                           
                                                                                
    int w = 11;                                                                 
    const int x = 12;                                                           
    volatile int y = 13;                                                        
    static int z = 14;                                                          
                                                                                
    register int reg1;                                                          
    register int reg2 = 100;                                                    
                                                                                
    return 0;                                                                   
"global.c" 41L, 517C                                                                                                            1,1           Top


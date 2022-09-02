#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int ip_checksum(char *data, int length);

int main(char argc, char *argv[])
{

    unsigned short cksum = 0;

    if (argc != 2) {
        printf("Usage: %s <string> \n", argv[0]);
        return -1;
    }

    cksum = ip_checksum(argv[1], strlen(argv[1]));

    printf("CheckSum :0x%x (%s) \n", cksum, argv[1]);

    return 0;

}

unsigned int ip_checksum(char *data, int length) 
{
    unsigned int sum = 0xffff;
    unsigned short word;
 
    int  i;
    
    // Handle complete 16-bit blocks.
    for (i = 0; i+1<length; i+=2) {
        memcpy(&word, data+i, 2);
        sum += word;
        if (sum > 0xffff) {
            sum -= 0xffff;
        }
    }

    // Handle any partial block at the end of the data.
    if (length&1) {
        word=0;
        memcpy(&word, data+length-1, 1);
        sum += word;;
        if (sum > 0xffff) {
            sum -= 0xffff;
        }
    }
   
    // Return the checksum
    return ~sum;
                                                                                                     }
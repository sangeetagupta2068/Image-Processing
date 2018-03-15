#include "bitmap.h"
#include <stdio.h>

/*
 *@author: Sangeeta Gupta
 *@email : tinnigupta1998@gmail.com
 *
 *@objective: To understand processing of images using C language as the platform.
 *
 *@description: This is the file containing all function definitions for bitmap.h.
                The given below code works a for 24-bit pixel .bmp file with 0 compression.
                The reason for opting for a .bmp file is because it is widely spread, well documented and patent free.
 *
 *@created on: 14th March 2018
 *
 *@version: 1.1
 */

boolean ReadUShort(FILE *fptr,short unsigned *n)
{
  /*@description:reads data from fptr and stores it in the unsigned short integer. If read is successful, returns true else
                 returns false
   *@input:File Pointer of the image file to be mirrored,Pointer to an unsigned short of Image Header
   */
   if(fread(n,sizeof(unsigned short),1,fptr) != 1)
      return(TRUE);
   return(FALSE);

}
//ReadUShort ends

boolean ReadUInt(FILE *fptr,unsigned int *n)
{
  /*@description:reads data from fptr and stores it in the unsigned integer. If read is successful, returns true else
                 returns false
   *@input:File Pointer of the image file to be mirrored,Pointer to an unsigned integer of Image Headers
   */
   if(fread(n,sizeof(unsigned int),1,fptr) != 1)
      return(TRUE);
   return(FALSE);

}
//ReadUInt ends

void mirrorWidthWise(FILE *fptr,HEADER *header, INFOHEADER *infoheader)
{
    /*@description:Mirrors the image width wise.
     *@input:File Pointer of the image file to be mirrored,Pointer to the Image Header,Pointer to the Image Information Header
     */

    fseek(fptr,header->offset,SEEK_SET);

    char image[infoheader->height][infoheader->width][3];

    for(int count1=0;count1<infoheader->height;count1=count1+1)
    {
        for(int count2=0;count2<infoheader->width;count2=count2+1)
        {

         image[count1][infoheader->width-count2][0] = getc(fptr);
         image[count1][infoheader->width-count2][1] = getc(fptr);
         image[count1][infoheader->width-count2][2] = getc(fptr);

       }
    }

    fseek(fptr,header->offset,SEEK_SET);

    for (int count1=0;count1<infoheader->height;count1=count1+1)
    {
        for (int count2=0;count2<infoheader->width;count2=count2+1)
        {

              putc(image[count1][count2][0],fptr);
              putc(image[count1][count2][1],fptr);
              putc(image[count1][count2][2],fptr);

        }
    }

}
//mirrorWidthWise ends

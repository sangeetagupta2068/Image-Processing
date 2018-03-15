#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"

/*
 *@author: Sangeeta Gupta
 *@email : tinnigupta1998@gmail.com
 *
 *@objective: To understand processing of images using C language as the platform.
 *
 *@description: This is the main file.
                Illustration of mirroring a image file using C code. The given below code works a for 24-bit pixel .bmp file with 0 compression.
                The reason for opting for a .bmp file is because it is widely spread, well documented and patent free.
                The given below code expects the .bmp file to be processed as a command line arguement.

 *@created on: 14th March 2018
 *
 *@version: 1.0
 *
 */

int main(int argc,char **varArg)
{
      HEADER header;
      INFOHEADER infoheader;

      FILE *fptr;

      //checking if the .bmp file is specified as a command line arguement
      if (argc < 2)
      {
          fprintf(stderr,"Usage: %s filename\n",varArg[0]);
          exit(-1);
      }

      //opening the .bmp file
      if ((fptr = fopen(varArg[1],"r+")) == NULL)
      {
          fprintf(stderr,"Unable to open BMP file \"%s\"\n",varArg[1]);
          exit(-1);
      }

      //reading and displaying some of the content from the Header of a .bmp file
      ReadUShort(fptr,&header.type);
      fprintf(stderr,"ID is: %d, should be %d\n",header.type,'M'*256+'B');
      ReadUInt(fptr,&header.size);
      fprintf(stderr,"File size is %d bytes\n",header.size);
      ReadUShort(fptr,&header.reserved1);
      ReadUShort(fptr,&header.reserved2);
      ReadUInt(fptr,&header.offset);
      fprintf(stderr,"Offset to image data is %d bytes\n",header.offset);

      //reading content from the Information header
      if (fread(&infoheader,sizeof(INFOHEADER),1,fptr) != 1)
      {
        fprintf(stderr,"Failed to read BMP info header\n");
        exit(-1);
      }

      //displaying some of the content read the Information Header of a .bmp file
      fprintf(stderr,"Image size = %d x %d\n",infoheader.width,infoheader.height);
      fprintf(stderr,"Number of colour planes is %d\n",infoheader.planes);
      fprintf(stderr,"Bits per pixel is %d\n",infoheader.bits);
      fprintf(stderr,"X resolution %d and Y resolution %d \n",infoheader.xResolution,infoheader.yResolution);
      fprintf(stderr,"Compression type is %d\n",infoheader.compression);
      fprintf(stderr,"Number of colours is %d\n",infoheader.nColours);
      fprintf(stderr,"Number of required colours is %d\n",infoheader.importantColours);

      //function call to mirror the image
      mirrorWidthWise(fptr,&header,&infoheader);
      fprintf(stderr, "Successfully mirrored!\n");

      fclose(fptr); //closing the .bmp file

      return EXIT_SUCCESS;
}
//main ends

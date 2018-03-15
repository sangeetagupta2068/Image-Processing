#include <stdio.h>
/*
 *@author: Sangeeta Gupta
 *@email : tinnigupta1998@gmail.com
 *
 *@objective: To understand processing of images using C language as the platform.
 *
 *@description: This is the header file containing the structure definitions and function prototypes used for image processing.
                The given below information works a for 24-bit pixel .bmp file with 0 compression.
                The reason for opting for a .bmp file is because it is widely spread, well documented and patent free.
 *
 *@created on: 14th March 2018
 *
 *@version: 1.2
 *
 */

    #ifndef BMP_FILE_H

        #define BMP_FILE_H 1

        typedef enum
        {

            FALSE=1,TRUE=0

        }
        boolean;
        //defining the boolean type

        typedef struct
        {

           unsigned short type;
           unsigned int size;
           unsigned short reserved1, reserved2;
           unsigned int offset;

        } HEADER;
        //defining the structure for Image Header

        typedef struct
        {

           unsigned int size;
           int width,height;
           unsigned short int planes;
           unsigned short int bits;
           unsigned int compression;
           unsigned int imageSize;
           int xResolution,yResolution;
           unsigned int nColours;
           unsigned int importantColours;

        } INFOHEADER;
        //defining the structure for Image Information Header

        //function prototypes
        boolean ReadUShort(FILE *,unsigned short *);

        boolean ReadUInt(FILE *,unsigned int *);

        void mirrorWidthWise(FILE *,HEADER *, INFOHEADER *);
        
        void mirrorHeightWise(FILE *,HEADER *, INFOHEADER *);

    #endif


// Recovers JPG images from a file of raw data

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	// ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover infile\n");
        return 1;
    }

    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // Declare variables
    char filename[8];
    int file = 1;
    unsigned char buffer[512];
    int start = 0;
    sprintf(filename, "%03i.jpg", file);
    FILE* img = fopen(filename, "w");

    // While fread successfully returns 512 bytes, indicating we have not yet reached the end of the file...
    while (fread(&buffer, 512, 1, inptr) == 1)
    {
        //fread(&buffer, 512, 1, inptr);
		/*if (start == 0 &&
			buffer[0] == 0xff &&
			buffer[1] == 0xd8 &&
			buffer[2] == 0xff &&
			(buffer[3] & 0xf0) == 0xe0)
		{
			fwrite(&buffer, 512, 1, img);
			start = 1;
		}*/
		// If we're already writing out to a JPG, continue doing so until another header is reached
		/*else if (start == 1 &&
			buffer[0] != 0xff &&
			buffer[1] != 0xd8 &&
			buffer[2] != 0xff &&
			(buffer[3] & 0xf0) != 0xe0)
		{
			fopen(filename, "a");
			fwrite(&buffer, 512, 1, img);
		}*/
		/* This finds the JPG image headers and writes them out. If it's
		 * not the first JPG, it closes the preceding image, increments
		 * the file number and updates the filename to open, then starts
		 * writing in the new file.
		*/
		if (start == 0 || 1 &&
			buffer[0] == 0xff &&
			buffer[1] == 0xd8 &&
			buffer[2] == 0xff &&
			(buffer[3] & 0xf0) == 0xe0)
		{
			if (start == 1)
			{
				fclose(img);
				file++;
				sprintf(filename, "%03i.jpg", file);
				img = fopen(filename, "w");	
			}
			fwrite(&buffer, 512, 1, img);
			if (start == 0)
			{
				start = 1; // found the first JPG, so set to 1 (true)
			}
		}
		else if (start == 1 &&
			buffer[0] != 0xff ||
			buffer[1] != 0xd8 ||
			buffer[2] != 0xff ||
			(buffer[3] & 0xf0) != 0xe0)
		{
			fwrite(&buffer, 512, 1, img);
		}
		/*else if (start == 0)
		{
			// do nothing, since we haven't reached the jpgs yet
		}
		}
		else
		{
		}*/
    }

    fclose(img);
    fclose(inptr);
	return 0;
}

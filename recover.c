
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
        // Read into buffer and compare the first 4 bytes of the buffer with the JPG header signature
        fread(&buffer, 512, 1, inptr);
            // This finds the first JPG, allowing the loop to throw away garbage data at the beginning of the raw file
            if (start == 0 &&
                buffer[0] == 0xff &&
                buffer[1] == 0xd8 &&
                buffer[2] == 0xff &&
                (buffer[3] & 0xf0) == 0xe0)
            {
                // Header matches, so write buffer to file and set Start of JPGs to true (1)
                fwrite(&buffer, 512, 1, img);
                start = 1;
            }
            // If we've already writing out to a JPG, continue doing so until another header is reached
            else if (start == 1 &&
                buffer[0] != 0xff &&
                buffer[1] != 0xd8 &&
                buffer[2] != 0xff &&
                (buffer[3] & 0xf0) != 0xe0)
            {
                fopen(filename, "a");
                fwrite(&buffer, 512, 1, img);
            }
            // This finds the 2nd and succeeding JPG image headers, where it needs to close the preceding image,
            // increment the file number and update the filename to open, then start writing in the new file.
            else if (start == 1 &&
                buffer[0] == 0xff &&
                buffer[1] == 0xd8 &&
                buffer[2] == 0xff &&
                (buffer[3] & 0xf0) == 0xe0)
            {
                fclose(img);
                file++;
                sprintf(filename, "%03i.jpg", file);
                img = fopen(filename, "w");
                fwrite(&buffer, 512, 1, img);
            }
    }

    fclose(img);
    fclose(inptr);
	return 0;
}

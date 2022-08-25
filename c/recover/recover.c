#include <stdio.h>
#include <stdlib.h>


//command line argument: ./recover IMAGE
int main(int argc, char* argv[]) {

    //check for correct command line argument
    if(argc != 2)
    {
        printf("Correct command line argument is: ./recover IMAGE\n");
        return 1;
    }
    //forensic image can't be opened
    char* infile = argv[1];
    FILE *inputFileptr = fopen(infile, "r");

    if(inputFileptr == NULL)
    {
        printf("Cannot open %s\n", infile);
        return 1;
    }


    unsigned char buffer[512];
    char* filename = malloc(8 * sizeof(char)); //###.jpg + \0
    int numberOfJPEGS = 0;
    FILE *outputFile = NULL;

    //read in blocks of 512 bytes

    while (fread(buffer, 512, 1, inputFileptr))
    {
        //first byte of a jpeg is 0xff, 0xd8, 0xff, and 0xe0-f
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //is the start of a jpeg

            //format of naming ###.jpg
            sprintf(filename, "%03i.jpg", numberOfJPEGS);

            outputFile = fopen(filename, "w");
            numberOfJPEGS++;
        }
        //check file has not already been written to
        if (outputFile != NULL)
        {
            fwrite(buffer, sizeof(char), 512, outputFile);
        }
    }
    free(filename);
    fclose(outputFile);
    fclose(inputFileptr);
    return 0;
}

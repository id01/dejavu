#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include <time.h>

#include "config.h"

const uint32_t chanceOfDejaVu = RAND_MAX/16; // One over the denominator chance every block of triggering dejaVu
const uint32_t maxLengthOfDejaVu = 1048576; // Maximum length of each dejaVu file. This is 1MB
const uint32_t maxLengthOfBlock = 33554432/4096; // Maximum length of each block with no dejaVu divited by 4096. This is 32MB

int main() {
	// Seed random and get info
	srandom(clock()+time(NULL)*CLOCKS_PER_SEC);
	uint32_t fileTypeChosen, randomishData, dataLength, randomNumber; // Other variables
	unsigned char* nullBuffer = calloc(4096, 1);
	// Open urandom
	FILE * urandom = fopen("/dev/urandom", "r");
	// Main loop
	while (1) {
		// Generate a random number
		randomNumber = rand();
		if (randomNumber < chanceOfDejaVu) { // Activate dejaVu
			// Choose a file type and put its start header
			fileTypeChosen = (randomNumber >> 16) % numberOfFileTypes;
			for (uint8_t i=0; i<fileTypeOptions[fileTypeChosen][0]; i++) {
				fputc(fileTypes[fileTypeChosen][0][i], stdout);
			}
			// Put random-ish data of random-ish length.
			dataLength = randomNumber % maxLengthOfDejaVu;
			for (uint32_t i=0; i<dataLength; i++) {
				if (fileTypeOptions[fileTypeChosen][2] == 0) { // Any data
					fputc(fgetc(urandom), stdout);
				} else { // ASCII only
					printf("%.2x", fgetc(urandom)); // Just hex for now
				}
			}
			// Put the file type's end header.
			for (uint8_t i=0; i<fileTypeOptions[fileTypeChosen][1]; i++) {
				fputc(fileTypes[fileTypeChosen][1][i], stdout);
			}
		} else {
			// Fill this block with 0's
			dataLength = randomNumber % maxLengthOfBlock;
			for (uint32_t i=0; i<dataLength; i++) {
				write(1, nullBuffer, 4096);
			}
		}
	}
}
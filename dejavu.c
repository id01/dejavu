#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>

#include "config.h"

const uint32_t chanceOfDejaVu = RAND_MAX/64; // One over the denominator chance every block of triggering dejaVu
const uint32_t lengthOfBlock = 16384; // Length of each block with no dejaVu

int main() {
	// Seed random and get info
	srandom(clock()+time(NULL)*CLOCKS_PER_SEC);
	uint32_t fileTypeChosen, lengthOfData, randomishData; // Other variables
	// Main loop
	while (1) {
		if (rand() < chanceOfDejaVu) { // Activate dejaVu
			// Choose a file type and put its start header
			fileTypeChosen = rand() % numberOfFileTypes;
			for (uint8_t i=0; i<fileTypeOptions[fileTypeChosen][0]; i++) {
				fputc(fileTypes[fileTypeChosen][0][i], stdout);
			}
			// Put random-ish data of random-ish length.
			lengthOfData = rand() % 16384;
			for (uint32_t i=0; i<lengthOfData; i++) {
				if (fileTypeOptions[fileTypeChosen][2] == 0) { // Any data
					randomishData = rand();
					printf("%.4s", (char*)(&randomishData));
				} else { // ASCII only
					randomishData = rand();
					printf("%.8x", randomishData); // Just hex for now
				}
			}
			// Put the file type's end header.
			for (uint8_t i=0; i<fileTypeOptions[fileTypeChosen][1]; i++) {
				fputc(fileTypes[fileTypeChosen][1][i], stdout);
			}
		} else {
			// Fill this block with 0's
			for (uint32_t i=0; i<lengthOfBlock; i++) {
				fputc('\0', stdout);
			}
		}
	}
}
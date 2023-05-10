/*Ben Elleman*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/vfs.h>

#include "define.h"

#include "unmount.h"

int main() {
	/*Search for more than one file location? Arr loc - Fill with include of locs?*/
	int r;
	struct statfs s;
	if (DEBUG) printf ("Searching for file system: %s\n", LOC); 
	while (1) {
		r = statfs(LOC, &s);
		if (DEBUG) {
			printf("STATFS OUTPUT: %i", r);
			printf("/t-/t%s\n",explain_statfs(LOC, &s));
			printf("\n");
		}
		if (!r) {
			if (COPYFILES) copyFiles(s);
			unmount(LOC, s);
		}
	}
	return 0;
}

void unmount(const char* loc, struct statfs s) {
	char cmdstr[BUFFERSIZE];
	if (DEBUG) printf("Detected file system at %s: %s\n Proceeding to unmount\n", loc, s.f_type);
	if (snprintf(cmdstr, sizeof(cmdstr), "umount %s", loc) < BUFFERSIZE) system(cmdstr);
}

void copyFiles(struct statfs s) {
	char cmdstr[BUFFERSIZE];
	snprintf(cmdstr, sizeof(cmdstr), "mkdir %s", PASTELOC);
	system(cmdstr);
	snprintf(cmdstr, sizeof(cmdstr), "cp %s %s", LOC, PASTELOC);
	system(cmdstr);
}

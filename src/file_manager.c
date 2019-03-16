#include "main.h"
#include "file_manager.h"


int open_files(struct str_files *files)
{
	files->fSequence = fopen("./Data/sequence.data", "w");
	if (files->fSequence == NULL) {
		printf("File sequence.data coult not be opened.\n");
		return 1;
	}

	files->fPlot = fopen("./Data/plot.data", "w");
	if (files->fPlot == NULL) {
		printf("File plot.data coult not be opened.\n");
		return 1;
	}

	files->fStats = fopen("./Data/stats.data", "w");
	if (files->fStats == NULL) {
		printf("File stats.data coult not be opened.\n");
		return 1;
	}

	files->fLog = fopen("./Data/knight.log", "w");
	if (files->fLog == NULL) {
		printf("File knight.log coult not be opened.\n");
		return 1;
	}

	return 0;
}

void close_files(struct str_files *files)
{
	fclose(files->fSequence);
	fclose(files->fPlot);
	fclose(files->fStats);
	fclose(files->fLog);

	return;
}

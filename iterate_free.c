#include "main.h"
/**
 * iterate_free - frees an array and its components
 * @array: the array
 */

void iterate_free(char **array)
{
	int i;

	if (!array || array == NULL)
		return;
	for (i = 0 ; array[i] != NULL ; i++)
		free(array[i]);
	free(array);
}

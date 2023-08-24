#include "main.h"

/**
 * str_concat - Concatenate two strings
 * @s1: First string
 * @s2: Second string
 * Return: Pointer to the concatenated string
 */
char *str_concat(char *s1, char *s2)
{
	char *concatenated_string;
	unsigned int len_s1;
	unsigned int len_s2;
	unsigned int index;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (len_s1 = 0; s1[len_s1] != '\0'; len_s1++)
		continue;

	for (len_s2 = 0; s2[len_s2] != '\0'; len_s2++)
		continue;

	len_s2 = len_s2 + 1;

	concatenated_string = malloc((len_s1 + len_s2) * sizeof(char));

	if (concatenated_string == NULL)
		return (0);

	for (index = 0; index < (len_s1 + len_s2); index++)
	{
		if (index < len_s1)
			concatenated_string[index] = s1[index];
		if (index >= len_s1)
			concatenated_string[index] = s2[index - len_s1];
	}
	return (concatenated_string);
}

/**
 * _realloc - Reallocate a memory block
 * @ptr: Pointer to memory
 * @old_size: Old size
 * @new_size: New size
 * Return: A pointer to the allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_memory;
	char *original_memory;
	unsigned int copy_index;

	original_memory = (char *)ptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	new_memory = malloc(new_size * sizeof(char));
	if (new_memory == NULL)
	{
		free(new_memory);
		return (NULL);
	}

	if (new_size > old_size)
	{
		for (copy_index = 0; copy_index < old_size; copy_index++)
			new_memory[copy_index] = original_memory[copy_index];
	}
	if (new_size < old_size)
	{
		for (copy_index = 0; copy_index < new_size; copy_index++)
			new_memory[copy_index] = original_memory[copy_index];
	}
	free(original_memory);
	return (new_memory);
}

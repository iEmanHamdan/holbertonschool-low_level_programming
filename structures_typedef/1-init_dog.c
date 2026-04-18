#include "dog.h"
#include <stddef.h>

/**
 * init_dog - Initializes a variable of type struct dog
 * @d: Pointer to struct dog to initialize
 * @name: Name to set for the dog
 * @age: Age to set for the dog
 * @owner: Owner to set for the dog
 *
 * Description: This function takes a pointer to a struct dog and
 * assigns the provided name, age, and owner to its members.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}

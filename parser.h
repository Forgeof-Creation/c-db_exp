#include <stdarg.h>
#include "primitive.h"
#include "type.h"

int row(FILE* db, int argc, ...)
{
	va_list valist;

	va_start(valist, argc);

	if (argc > 0)
	{
		int row = va_arg(valist, int);
		select_row(row, db);
		return -1;
	}
	else
	{
		print_row(db);
		return row_count(db);
	}
}

void get_val(FILE *db, char buffer[], int argc, ...)
{
	va_list valist;
	va_start(valist, argc);

	if (argc > 0)
	{
		char *key = va_arg(valist, char *);
		if (verify_from_key(db, key) == 0)
		{
			value_from_key(buffer, key, db);
		}
	}
	else
	{
		if (verify(db) == 0)
		{
			get_value(buffer, db);
		}
	}
}

void key(FILE *db, char buffer[])
{
	get_key(buffer, db);
}

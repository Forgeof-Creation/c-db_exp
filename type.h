#include <ctype.h>

int verify(FILE *db)
{
	Type type = get_type(db);
	
	char buffer[128];
	get_value(buffer, db);

	if (type == STRING)
	{
		int buff_ptr = 0;
		while (buffer[buff_ptr] != '\0')
		{
			if (isalpha(buffer[buff_ptr]) != 0)
			{
				return 0;
			}
			buff_ptr++;
		}
	}

	if (type == INT)
	{
		int buff_ptr = 0;

		while (buffer[buff_ptr] != '\0')
		{
			if (isdigit(buffer[buff_ptr]) == 0)
			{
				return 1;
			}
			buff_ptr++;
		}
	}

	if (type == FLOAT)
	{
		int buff_ptr = 0;

		while (buffer[buff_ptr] != '\0')
		{
			if ((isdigit(buffer[buff_ptr]) == 0) || (buffer[buff_ptr] != '.'))
			{
				return 1;
			}
			buff_ptr++;
		}
	}
	
	if (type == NONE)
	{
		if (buffer[0] != '\0')
		{
			return 1;
		}
	}

	return 0;
}

int verify_from_key(FILE *db, char key[])
{
	Type type = get_type_with_key(key, db);
	
	char buffer[128];
	value_from_key(buffer, key, db);

	if (type == STRING)
	{
		int buff_ptr = 0;
		while (buffer[buff_ptr] != '\0')
		{
			if (isalpha(buffer[buff_ptr]) != 0)
			{
				return 0;
			}
			buff_ptr++;
		}
	}

	if (type == INT)
	{
		int buff_ptr = 0;

		while (buffer[buff_ptr] != '\0')
		{
			if (isdigit(buffer[buff_ptr]) == 0)
			{
				return 1;
			}
			buff_ptr++;
		}
	}

	if (type == FLOAT)
	{
		int buff_ptr = 0;

		while (buffer[buff_ptr] != '\0')
		{
			if ((isdigit(buffer[buff_ptr]) == 0) || (buffer[buff_ptr] != '.'))
			{
				return 1;
			}
			buff_ptr++;
		}
	}
	
	if (type == NONE)
	{
		if (buffer[0] != '\0')
		{
			return 1;
		}
	}

	return 0;
}

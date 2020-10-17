typedef struct DB
{
	FILE *db;
	int size;
}
DB;

int size(DB *db)
{
	fseek(db->db, 0, SEEK_END);
	int size_file = ftell(db->db);
	rewind(db->db);
	return size_file;
}

DB *init(char file_name[])
{
	DB *db = malloc(sizeof(DB));
	
	db->db = fopen("file_name", "a+");
	db->size = size(db);

	return db;
}

void close_db(DB *db)
{
	fclose(db->db);
	free(db);
}

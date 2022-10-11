#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

static int callback(void* data, int numSections, char** values, char** columnNames)
{
  for (int i = 0; i < numSections; ++i) {
    const char* valueStr = values[i] ? values[i] : "NULL";

    printf("%s = %s\n", columnNames[i], valueStr);
  }

  printf("\n");

  return EXIT_SUCCESS;
}

void execute_statement(
  sqlite3* db,
  char* sql_statement,
  char* executionErrorMessage,
  int* rc
) {
  *rc = sqlite3_exec(db, sql_statement, callback, NULL, &executionErrorMessage);

  if (*rc == SQLITE_OK) {

  }
  else {
    fprintf(stderr, "SQL error: %s\n", executionErrorMessage);
    sqlite3_free(executionErrorMessage);
  }
}

int main(int argc, char** argv)
{
#if TARGETING_WINDOWS
  // https://www.sqlite.org/c3ref/temp_directory.html
  sqlite3_temp_directory = getenv("TEMP");
#endif

  sqlite3* db;
  char*    executionErrorMessage = NULL;
  int      rc                    = sqlite3_open("resources/USING_SQLITE/test-database.sqlite", &db);

  if (rc) {
    fprintf(stderr, "Unable to open database: %s\n", sqlite3_errmsg(db));
    return EXIT_FAILURE;
  }

  char* sql_statement = "CREATE TABLE PERSON( ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL );";

  execute_statement(db, sql_statement, executionErrorMessage, &rc);
  sql_statement = "INSERT INTO PERSON (ID, NAME)" \
                  " VALUES (1, 'Sky');";

  execute_statement(db, sql_statement, executionErrorMessage, &rc);

  printf("Nice, it works");
  sqlite3_close(db);

  return EXIT_SUCCESS;
}

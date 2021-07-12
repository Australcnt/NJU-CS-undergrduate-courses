#include "Login.h"
#include "AdministratorWindow.h"
#include "StudentWindow.h"

Course* head = NULL;
Student* stuhead = NULL;
Student* stutail = NULL;
int administrator_first = 0;

int main()
{
	welcome();
	begin();
	return 0;
}
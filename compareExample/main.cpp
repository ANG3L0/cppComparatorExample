#include <iostream>
using namespace std;

struct User{
	char* name;
	char* id;
	int dept;
};
User heads[] = {
	"Ritchie D.M",	"dmr", 11271,
	"Sethi R.",		"ravi",11272,
	"Szymanski T.G.","tgs",11273,
	"Schryer N.L.",	"nls", 11274,
	"Schryer N.L.",	"nls", 11275,
	"Kernighan B.W.","bwk",11726
};

void print_id(User* v, int n){
	for (int i=0; i<n; i++){
		cout << v[i].name << '\t' << v[i].id << '\t' << v[i].dept << '\n';
	}
}

int cmp1(const void* p, const void* q) //compare name strings
{
	return strcmp(static_cast<const User*>(p)->name,
		static_cast<const User*>(q)->name);
}

int cmp2(const void* p, const void* q) //compare dept number
{
	return static_cast<const User*>(p)->dept - static_cast<const User*>(q)->dept;
}

int main() {
	cout << "unorganized heads:\n";
	print_id(heads,6); //unsorted.
	cout << endl;

	cout << "heads in alphabetical order:\n";
	qsort(heads,6,sizeof(User),cmp1);
	print_id(heads,6);
	cout << endl;

	cout << "Heads in order of departmental number:\n";
	qsort(heads,6,sizeof(User),cmp2);
	print_id(heads,6);
	return 0;
}
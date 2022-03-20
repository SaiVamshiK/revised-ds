*************************** 	stoi(string)		***************************
int main()
{
	string str1 = "45";

	int myint1 = stoi(str1);

	cout << "stoi(\"" << str1 << "\") is "
		<< myint1 << '\n';
	// 45 integer it is converted into

	return 0;
}
***************************		atoi(char*)			***************************

int main()
{
	const char *str1 = "42";
	
	int num1 = atoi(str1);
	
	cout << "atoi(\"" << str1
			<< "\") is " << num1 << '\n';
	// 42 integer it is converted into
	
return 0;
}


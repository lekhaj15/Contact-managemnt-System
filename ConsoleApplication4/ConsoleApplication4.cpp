#include<iostream>
#include<string>
using namespace std;
// maximun number of contact stored
#define Max 1000 
//define contact structure
struct Contacts
{
	string cName;
	int cGender = 1;
	int cAge = 0;
	string cPhone;
	string cAdd;
};

struct AddressBooks
{
	Contacts contactsArry[Max];
	int aCount = 0;
};
void showMenu()
{
	cout << "********************************" << endl;
	cout << "***** contact management system *****" << endl;
	cout << "********************************" << endl;
	cout << "*****    1、add contacts     *****" << endl;
	cout << "*****    2、show contacts    *****" << endl;
	cout << "*****    3、delete contacts    *****" << endl;
	cout << "*****    4、find a contact     *****" << endl;
	cout << "*****    5、edit contact   *****" << endl;
	cout << "*****    6、clear contacts     *****" << endl;
	cout << "*****    0、exit     *****" << endl;
	cout << "********************************" << endl;
	cout << "***********Version1.0***********" << endl;
	cout << "********************************" << endl;
}

void AddContacts(AddressBooks* abs)
{

	if (abs->aCount == Max)
	{
		cout << "contact book is full cannot be added!" << endl;
		return;
	}
	else
	{
		//name
		string name;
		cout << "enter the name： " << endl;
		cin >> name;
		abs->contactsArry[abs->aCount].cName = name;

		//gender
		int gender;
		cout << "please enter gender： " << endl;
		cout << "1 ---- male " << endl;
		cout << "2 ---- female " << endl;

		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				abs->contactsArry[abs->aCount].cGender = gender;
				break;
			}
			cout << "incorrect input please try again！" << endl;
		}

		int age;
		cout << "enter the age： " << endl;
		cin >> age;
		abs->contactsArry[abs->aCount].cAge = age;


		string phone;
		cout << "enter the phone number： " << endl;
		cin >> phone;
		abs->contactsArry[abs->aCount].cPhone = phone;

		//address
		string add;
		cout << "enter the address： " << endl;
		cin >> add;
		abs->contactsArry[abs->aCount].cAdd = add;

		//plus one
		abs->aCount += 1;
		cout << "added successfully" << endl;
		system("pause");

		system("cls");
	}

}

//display contacts
void ShowContacts(AddressBooks* abs)
{
	if (abs->aCount == 0)
	{
		cout << "No contact, please add it first!" << endl;
	}
	else
	{
		//show all contacts
		for (int i = 0; i < abs->aCount; i++)
		{
			cout << "Name：" << abs->contactsArry[i].cName << " gender：" << (abs->contactsArry[i].cGender != 2 ? "male" : "Female") << " age：" << abs->contactsArry[i].cAge << " phone number：" << abs->contactsArry[i].cPhone << " address：" << abs->contactsArry[i].cAdd << endl;
		}
	}
	system("pause");
	system("cls");
}

//check if exist
int IsExit(AddressBooks* abs, string name)
{
	for (int i = 0; i < abs->aCount; i++)
	{
		if (abs->contactsArry[i].cName == name)
		{
			return i;
		}
	}
	return -1;
}

//delete contact
void DeleteContacts(AddressBooks* abs)
{
	//Record the name entered by the user
	string name;
	cout << "enter the user name you want to delete:" << endl;
	cin >> name;
	//Check if a contact exists
	int index = IsExit(abs, name);
	//exist
	if (index > -1)
	{
		for (int i = index; i < abs->aCount - 1; i++)
		{
			//forward shift operation
			Contacts temp = abs->contactsArry[i];
			abs->contactsArry[i] = abs->contactsArry[i + 1];
			abs->contactsArry[i + 1] = temp;
		}
		//delete one record 
		abs->aCount--;
		cout << "successfully deleted!" << endl;
	}
	else
	{
		cout << "no such person" << endl;
	}
	system("pause");
	system("cls");
}

//find a contact
void GetContacts(AddressBooks* abs)
{

	string name;
	cout << "Please enter the name of the user you are looking for" << endl;
	cin >> name;
	//Check if a contact exists
	int index = IsExit(abs, name);
	if (index > -1)
	{
		//exist
		cout << "name：" << abs->contactsArry[index].cName << endl;
		cout << "gender：" << abs->contactsArry[index].cGender << endl;
		cout << "age：" << abs->contactsArry[index].cAge << endl;
		cout << "phone number：" << abs->contactsArry[index].cPhone << endl;
		cout << "address：" << abs->contactsArry[index].cAdd << endl;
	}
	else
	{
		//does not exist
		cout << "no such contact exist" << endl;
	}
	system("pause");
	system("cls");

}

//Edit contacts
void ModifyContacts(AddressBooks* abs)
{
	//Record the name entered by the user
	string name;
	cout << "enter the user name you want to edit" << endl;
	cin >> name;
	//Check if a contact exists
	int index = IsExit(abs, name);
	if (index > -1)
	{
		//exist
		//Name
		string name;
		cout << "Please enter your revised name： " << endl;
		cin >> name;
		abs->contactsArry[index].cName = name;

		//gender
		int gender;
		cout << "Please enter modified gender： " << endl;
		cout << "1 ---- male " << endl;
		cout << "2 ---- female " << endl;

		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				abs->contactsArry[index].cGender = gender;
				break;
			}
			cout << "Please re-enter if there is an error in the input!" << endl;
		}

		//age
		int age;
		cout << "please enter modified age： " << endl;
		cin >> age;
		abs->contactsArry[index].cAge = age;

		//phone number
		string phone;
		cout << "plese enter modified phone number： " << endl;
		cin >> phone;
		abs->contactsArry[index].cPhone = phone;

		//address
		string add;
		cout << "please enter modified address： " << endl;
		cin >> add;
		abs->contactsArry[index].cAdd = add;
		cout << "Successfully modified!" << endl;
	}
	else
	{
		//does not exist
		cout << "no such person" << endl;
	}
	system("pause");
	system("cls");
}


//clear contacts
void ClearContacts(AddressBooks* abs)
{
	string choose = "N";
	cout << "Are you sure you want to clear your contacts？(Y yes/N no)" << endl;

	while (true)
	{
		cin >> choose;
		if (choose == "Y" || choose == "N")
		{
			break;
		}
		else
		{
			cout << "Incorrect input, please re-enter!!" << endl;
		}
	}

	if (choose == "Y")
	{
		abs->aCount = 0;
		cout << "Cleared successfully!!" << endl;
	}
	else
	{
		cout << "Operation cancelled!!" << endl;
	}
	system("pause");
	system("cls");
}

int main()
{
	//Record the information entered by the user
	int select = 0;
	//Define an address book structure
	AddressBooks abs;
	//Set the current number to zero
	abs.aCount = 0;

	while (true)
	{
		//display main menu
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1://1、add contacts
			AddContacts(&abs);
			break;
		case 2://2、show contacts
			ShowContacts(&abs);
			break;
		case 3://3、delete contacts
			DeleteContacts(&abs);
			break;
		case 4://4、find the contact
			GetContacts(&abs);
			break;
		case 5://5、edit contacts
			ModifyContacts(&abs);
			break;
		case 6://6、clear contact
			ClearContacts(&abs);
			break;
		case 0://0、Exit Contacts
			cout << "Welcome to use next time, see you later!" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}


	system("pause");//Press any key to continue
	return 0;
}
#include "../headers/contact.hpp"

int menu()
{
    std::string choice;

    if (std::cin.eof() || std::cin.fail()) 
        return 0;
    std::cout << "ADD\nSEARCH\nEXIT\n"
    << "your choice : \n";
    std::cin >> choice;
    if (choice.compare("ADD") == 0)
        return (std::cout << "\033c", 1);
    else if (choice.compare("SEARCH") == 0)
        return (std::cout << "\033c",2);
    else if (choice.compare("EXIT") == 0)
        return (std::cout << "\033c",0);
    else
    {
        // std::cout << "enter a valid input !\n";
        return (menu());
    }
}

Contact Contact::fill_form(int *i)
{
    Contact contact;

    
    std::cout << "first name : ";
    std::cin >> contact.firstName;
	*i == 8 ? contact.id = 0 : contact.id = *i;
    std::cout << "nickname : ";
    std::cin >> contact.nickName;
    // std::cout << "phone : ";
    // std::cin >> contact.phone;
    // std::cout << "secret : ";
    // std::cin >> contact.secret;
    std::cout << "\033c";
    if (std::cin.eof() || std::cin.fail())
        return (contact);
    std::cout << "successfully added contact !\n";
    return (contact);
}

void    Phonebook::add_contact(Contact contact, Phonebook *phonebook, int *i)
{

	(void)phonebook;
    if (*i > 7)
    {
        this->contacts[0] = contact;
    }
    else
    {
        this->contacts[*i] = contact;
        *i += 1;
    }
}



void Phonebook::show_list(Phonebook *phonebook, int *i)
{
    Contact contact;

   for (int j = 0; j < *i; j++)
   {
        contact.display_index(phonebook->contacts[j]);
   }
}

int choose_index(int *i)
{
    int index;
    Contact contact;
    std::cout << "enter index : ";
    std::cin >> index;
	std::cout << "leo : "<< index << std::endl;
    if (index <= (*i - 1) && (index >= 0 && index <= (*i - 1)))
    {
		std::cout << "here\n";
		//std::cout << "\033c";
		return (index);
    }
	else
		return (choose_index(i));
}

void Contact::all_infos(Contact contact)
{
    std::cout << contact.firstName << "\n";
    std::cout << contact.nickName << "\n";
    std::cout << "\n";
}

void Phonebook::display_all_infos(Phonebook *phonebook, int index)
{
    Contact contact;

    contact.all_infos(phonebook->contacts[index]);
}

int    manage_choice(int choice, Phonebook *phonebook, int *i)
{
    Contact contact;
    int index;

    if (choice == 1)
    {
        phonebook->add_contact(contact.fill_form(i), phonebook, i);
        return(1);
    }
    if (choice == 2)
    {
        std::cout << "i: "<< *i << std::endl;
        if (*i == 0)
        {
            std::cout << "no contacts yet !" << std::endl;
            return (1);
        }
        phonebook->show_list(phonebook, i);
        index = choose_index(i);
        phonebook->display_all_infos(phonebook, index);
        return (1);
    }
    if (choice == 3)
        return (1);
    return (0);
}
void Contact::display_index(Contact contact)
{
    
    std::string fName;

    fName = contact.firstName;
    if (fName.length() > 10)
        fName = fName.substr(0, 9) + ".";
    
    std::cout << contact.id; 
    std::cout << "| ";
    std::cout << fName << std::endl;

}

int main(void)
{
    int choice;
    int i;
    int loop;
    Contact contact;
    Phonebook phonebook;
    loop = 1;

    i = 0;
    while (loop)
    {
        choice = menu();
        if (!choice)
            return (1);
        loop = manage_choice(choice, &phonebook, &i);
    }
    return (0);
}
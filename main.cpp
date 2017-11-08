#include <iostream>
#include <cstring>
#include <string>
#include <limits>

using namespace std;

struct Node {
	int data;
	Node *next;
};
void show_list(Node *first) {
	Node *curr=first;
	do {
		cout<<curr->data;
		if(curr->next!=nullptr)
			cout<<" -> ";
		curr=curr->next;
	} while (curr!=nullptr);
	cout<<endl;
}
void check_numbers(const char *argv,int *&numbers_array,int &numbers_count) {
	for(int i=0; i<strlen(argv); i++) {
		if(argv[i]>='0'&& argv[i]<='9')
			;
		else numbers_count++;
	}
	numbers_count++;

	numbers_array=new int[numbers_count];

	for(int i=0; i<numbers_count; i++) {
		numbers_array[i]=0;
	}
	int y=0;
	for(int i=0; i<strlen(argv)+1; i++)
		if(argv[i]>='0'&&argv[i]<='9')
			numbers_array[y]=numbers_array[y]*10+argv[i]-'0';
		else y++;
}
void fill_array(int numbers_array[],int argc,char **argv) {
	for(int i=0; i<argc-1; i++)
		numbers_array[i]=atoi(argv[i+1]);
}
void fill_list(int numbers_array[],int numbers_count,Node **first,Node **last) {
	for(int i=0; i<numbers_count; i++) {
		Node *node=new Node {numbers_array[i],nullptr};
		if((*last) == nullptr) {
			(*last)=node;
			(*first)=(*last);
			continue;
		}
		(*last)->next = node;
		(*last) = node;
	}
}
void add_list(Node **first,Node **last) {
	int *numbers_array=nullptr;
	int numbers_count=0;
	string str;
	cout<<"Please enter elements"<<endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin,str);
	check_numbers(str.c_str(),numbers_array,numbers_count);
	fill_list(numbers_array,numbers_count,first,last);
}
void print_menu() {
	cout<<"choise operation"<<endl;
	cout<<"1: show list"<<endl;
	cout<<"2: add element to list"<<endl;
	cout<<"3: delete element from list"<<endl;
	cout<<"4: find an element of list"<<endl;
	cout<<"5: Replace the item with another one"<<endl;
	cout<<"6: sort list"<<endl;
	cout<<"7: finish programm"<<endl;
	cout<<endl;
}
int main(int argc,char *argv[]) {
	int *numbers_array=nullptr;
	int numbers_count=0;
	if(argc == 2) {
		check_numbers(argv[1],numbers_array,numbers_count);
	} else if(argc>2) {
		numbers_count=argc-1;
		numbers_array=new int[numbers_count];
		fill_array(numbers_array,argc,argv);
	}
	Node *last=nullptr;
	Node *first=nullptr;
	fill_list(numbers_array,numbers_count,&first,&last);
	int choice=0;
	string choice_exit;
	do {
		print_menu();
		cin>>choice;
		switch(choice) {
			case 1:
				if(first != nullptr)
					show_list(first);
				else
					cerr<<"list is empty"<<endl;
				break;
			case 2:
				add_list(&first,&last);
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				cout<<"Do you want finish programm? Please enter: yes or no! "<<endl;
				cin>>choice_exit;
				if(choice_exit =="yes" || choice_exit == "YES" || choice_exit == "Yes" || choice_exit == "Y" || choice_exit == "y")
					cout<<"Good bye!"<<endl;
		}
		cout<<endl;
	} while(choice_exit !="yes" && choice_exit != "YES" && choice_exit != "Yes" && choice_exit != "Y" && choice_exit != "y");
	return 0;
}

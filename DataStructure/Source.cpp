#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
 using namespace std;

class room {

public:

	int length;
	int initial;

	// Enum class for different types of rooms
	enum class roomType { main_hall, exam_hall, lecture_room, tutorial_room, design_studio, meeting_room };
	// struct 
	struct node {

		string data;
		int id;
		int memId;
		int capacity;
		int year, month, day;
		int hour, minute;
		roomType type;
		node* next;
	};
	node* front;
	node * tail;

	// Constructor
	room() {
		length=0;
		initial=1;
		
		//------------
		front = NULL;
		tail = NULL;
	}

	// check number of rooms (not exceeding 15)
	bool isFull () { return length>=15; }


	// Add Rooms
	void room::addRoom() {
		system("cls");
		
   if (isFull()) {

       cout<<"    No more than 15 rooms are allowed\n"<<endl;
       return;
   }
		
		cout << "Enter the capacity" << endl;
		int a;
		cin >> a;

		node* temp = new node();
		temp->data = "Not_Reserved";
		temp->id = initial;
		temp->year = 0;
		temp->month = 0;
		temp->day = 0;
		temp->hour = 0;
		temp->minute = 0;

		initial++;
		temp->capacity = a;
		temp->next = NULL;
		if (front == NULL && tail == NULL)
		{
			front = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
		cout << "Choose The type" << endl;
		cout << "1- Main Hall \t 2- Lecture Room \t 3- Exam Hall \t 4- Meeting Room \t 5- Design Studio \t 6- Tutorial Room" << endl;
		int t;
		cin >> t;
		if (t == 1)
		{
			temp->type = roomType::main_hall;

		}
		else if (t == 2)
		{
			temp->type = roomType::lecture_room;

		}
		else if (t == 3)
		{
			temp->type = roomType::exam_hall;


		}
		else if (t == 4)
		{
			temp->type = roomType::meeting_room;


		}
		else if (t == 5)
		{
			temp->type = roomType::design_studio;


		}
		else if (t == 6)
		{
			temp->type = roomType::tutorial_room;


		}
		else {cout << "Wrong Input!" << endl;}
		length++;
		cout<<"\n Successfully Created!\n\n";
		system("pause");
		save();
	}
	
	// Delete Room
	void deleteRoom()
	{
		system("cls");
		room::show();
		cout << "================================================" << endl;
		cout << "Enter the room ID you want to delete!";
		int x;
		cin >> x;
		node* tmp = front;
		node* prv = NULL;
		while (tmp != NULL)
		{
			if (tmp->id == x)
			{
				if (prv != NULL)
				{
					prv->next = tmp->next;
				}
				else
				{
					front = tmp->next;
				}
				delete tmp;
				break;
			}
			prv = tmp;
			tmp = tmp->next;
		}
		cout << "-------------------Successfully Deleted ----------------" << endl;
		system("pause");
		save();
	}

// room type to string coversion
 string typeToText (roomType type) {

    switch (type) {

	case roomType::design_studio:
	    return "Design_Studio";
	    break;
	case room::roomType::exam_hall:
	    return "Exam_Hall";
	    break;
	case roomType::lecture_room:
	    return "Lecture_Room";
	    break;
	case roomType::main_hall:
	    return "Main_Hall";
	    break;
	case roomType::meeting_room:
	    return "Meeting_Room";
	    break;
	case roomType::tutorial_room:
	    return "Tutorial_Room";
	    break;
	
    }
}

 
	room::roomType room::textToType(string text)
{
		

	if(text == "Design_Studio")
	{
	    return roomType::design_studio ;
	}
	else if(text == "Exam_Hall")
	{
	    return room::roomType::exam_hall ;
	}
	else if(text == "Lecture_Room")
	{
	    return roomType::lecture_room ;
	}
	else if(text == "Main_Hall")
	{
	    return  roomType::main_hall ;
	}
	else if(text == "Meeting_Room")
	{
	    return roomType::meeting_room ;
	}
	else if(text == "Tutorial_Room")
	{
	    return roomType::tutorial_room ;
	}
}

 // show Rooms
	void room::show()
	{

		node* tmp = front;
		while (tmp != NULL)
		{
			cout << "ID " << tmp->id << "\t" << tmp->data << "\t Date: " << tmp->year<<"/"<<tmp->month<<"/"<<tmp->day << "\t Time: "<< tmp->hour<< " : " << tmp->minute <<"\t"<< typeToText(tmp->type) << "\t" << tmp->capacity << "\n";
			tmp = tmp->next;
		}
	}

// Reserve Room
	
	void reserveRoom()
	{
		system("cls");
		show();
		cout << "=============================================================" << endl;
		cout << "Enter the room ID you want to Book !" << endl;
		int id;
		cin >> id;
		node* tmp = front;
		
		while (tmp != NULL) {
			if (tmp->id == id) {
				if(tmp->data == "Not_Reserved"){
				tmp->data = "Reserved";
				int y,m,d;
				int min, hr;

				cout << "Enter the year " << endl;
				cin >> y;
				
				cout << "Enter the month " << endl;
				cin >> m;
				
				cout << "Enter the day " << endl;
				cin >> d;

				cout << "Enter the Hour " << endl;
				cin >> hr;

				cout << "Enter the Minute " << endl;
				cin >> min;



				tmp->year = y;
				tmp->month = m;
				tmp->day = d;
				tmp->hour = hr;
				tmp->minute = min;

				
				cout << "Room Reserved!" << endl;
				}
				else{
					cout << "This room has been reserved!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

				}
			}
			tmp = tmp->next;
		}
		system("pause");
		room::save();

	}

	// save file
	void save()
	{
		system("cls");
		cout << "Do you want to Save it? " << endl;
		int i;
		cout << "1- Yes \t" << "2- No" << endl;
		cin >> i;
		ofstream file;
		file.open("Room.txt");
		node* tmp = front;

		switch (i)
		{
		case 1:
			while (tmp != NULL)
			{


				file << tmp->id << "-" << tmp->data << "-" << tmp->year<<"-"<<tmp->month<<"-"<<tmp->day << "-"<< typeToText(tmp->type) << "-" << tmp->capacity << "-" << tmp->hour << "-" << tmp->minute <<"\n";
				tmp = tmp->next;
			}
			file.close();
			break;
		case 2:
			
			cout << "Operation Canceled!" << endl;
			break;
		}

	}


	// delete the previous records by giving a date
	void delPreviousBooking(){
		//loadRecords();
		show();
		cout << "Enter the date to delete the previous days record" << endl;
		cout << "Enter the year" << endl;
		int ye,mo, da;
		//int idate;
		cin >> ye;
		cout << "Enter the month" << endl;
		cin >> mo;
		cout << "Enter the day" << endl;
		cin >> da;
		//idate = ye+mo+da;

		node* tmp = front;
		while (tmp != NULL)
		{
			//tmp->deleteDate <= idate
			if (tmp->year <= ye  )
			{
				if(tmp->month <= mo){

					if(tmp->day <= da || (tmp->month -1 <= mo && tmp->month < mo ) ){
					tmp->data = "Not_Reserved";
					tmp->year =0;
					tmp->month =0;
					tmp->day = 0;
					tmp->hour = 0;
					tmp->minute = 0;
					}

				}
			}
			tmp = tmp->next;
		}
		
		save();
		

	}

	// modify a room
	void updateRoom()
	{
		system("cls");
		room::show();

		int x;
		cout << "Enter the Room ID You want to update it: " << endl;
		cin >> x;

		
		node* tmp = front;
		while (tmp != NULL)
		{
			if (tmp->id == x)
			{
				
				int c;
				int t;

				cout << "Enter New Capacity" << endl;
				cin >> c;
				cout << "Choose The type" << endl;
				cout << "1- Main Hall \t 2- Lecture Room \t 3- Exam Hall \t 4- Meeting Room \t 5- Design Studio \t 6- Tutorial Room" << endl;
				cin >> t;

				
				tmp->capacity = c;
				if (t == 1)
				{
					tmp->type = roomType::main_hall;
					cout << "Data Changed!" << endl;
				}
				else if (t == 2)
				{
					tmp->type = roomType::lecture_room;
					cout << "Data Changed!" << endl;
				}
				else if (t == 3)
				{
					tmp->type = roomType::exam_hall;
					cout << "Data Changed!" << endl;

				}
				else if (t == 4)
				{
					tmp->type = roomType::meeting_room;
					cout << "Data Changed!" << endl;
				}
				else if (t == 5)
				{
					tmp->type = roomType::design_studio;
					cout << "Data Changed!" << endl;
				}
				else if (t == 6)
				{
					tmp->type = roomType::tutorial_room;
					cout << "Data Changed!" << endl;
				}
				else cout << "Wrong Input!" << endl;


			}
			tmp = tmp->next;

		}

		save();
	}
	
	// upload records
	void loadRecords(){
		string line;
		ifstream myFile ("Room.txt");
		if(myFile.is_open()){
			while(getline(myFile, line)){
				cout << line << "\n";

			}

			myFile.close();
		}
		else cout << "Unable to open the file" << endl;

	}

	// search a room by id
	void searchBooking(int x)
	{
		node* tmp = front;
		while (tmp != NULL)
		{
			if (tmp->id == x)
			{
				cout << tmp->id << "\t" << tmp->data << "\t Date: " << tmp->year<<"/"<<tmp->month<<"/"<<tmp->day << "\t"<< typeToText(tmp->type) << "\t" << tmp->capacity << "\t Time: " << tmp->hour << " : " << tmp->minute<< "\n";
			}
			tmp = tmp->next;
		}
		system("pause");
	}

	// load records and save them to linked list when application starts
	void loadRooms()
	{
		string line;

		ifstream myFile ("Room.txt");
		if(myFile.is_open())
		{
			std::string word;  /* string to hold words */
			std::string sTemp;
		    std::stringstream s;
			std::stringstream wordstream;
			

			 while (getline (myFile, line))
			 {         /* read each line into line */
				 node* tmp = new node();
				 initial++;
				 s.str(line);

				 getline (s, word, '-');  /* read hyphen separated words */
				 wordstream.str(word);
			     wordstream>>tmp->id;
				 wordstream.clear();

				 getline (s, word, '-');  /* read hyphen separated words */
				 wordstream.str(word);
			     wordstream>>tmp->data;
				 wordstream.clear();

				 getline (s, word, '-');  /* read hyphen separated words */
				 wordstream.str(word);
			     wordstream>>tmp->year;
		
				 wordstream.clear();

				 getline (s, word, '-');  /* read hyphen separated words */
				 wordstream.str(word);
			     wordstream>>tmp->month;
				 
				 wordstream.clear();

				 getline (s, word, '-');  /* read hyphen separated words */
				 wordstream.str(word);
			     wordstream>>tmp->day;
				 
				 wordstream.clear();


				 getline (s, word, '-');  /* read hyphen separated words */
				 wordstream.str(word);
			     wordstream>>sTemp;
				 tmp->type = textToType(sTemp);
				 wordstream.clear();

				 getline (s, word, '-');  /* read hyphen separated words */
				 wordstream.str(word);
			     wordstream>>tmp->capacity;
				 wordstream.clear();

				 getline (s, word, '-');  /* read hyphen separated words */
				 wordstream.str(word);
			     wordstream>>tmp->hour;
				 wordstream.clear();

				 getline (s, word, '-');  /* read hyphen separated words */
				 wordstream.str(word);
				 wordstream>>tmp->minute;
				 wordstream.clear();

				
				 
				 s.clear();
				 tmp->next = NULL;
				 if (front == NULL && tail == NULL)
				 {
					 front = tmp;
					 tail = tmp;
				 }
				 else {
					 tail->next = tmp;
					 tail = tmp;
				 }
			 }


		}

	}

};


class member {


public:
	int pk;

	// Struct
	struct nodetype {
		int id;
		string name;
		string password;
		string type;
		string email;
		nodetype* next;
	};

	// Constructor
	member() {
		start = NULL;
		pk=1;

	}


	// Create a new Member
	void addMember(string n, string p, string t, string e) {
		nodetype* temp = new nodetype();
		temp->id = pk;
		pk++;
		temp->name = n;
		temp->password = p;
		temp->type = t;
		temp->email = e;
		temp->next = start;
		start = temp;
		saveMember();
		system("pause");
	}

	// Showing data
	void showMember()
	{

		nodetype* temp = start;
		while (temp != NULL)
		{
			cout << temp->id << "\t" << temp->name << "\t" << temp->type << "\t" << temp->password << "\t" << temp->email << endl;
			temp = temp->next;
		}
	}


	// Delete a member
	void deleteMember()
	{
		showMember();
		
		cout << "Enter member's id you want to delete" << endl;
		int x;
		cin >> x;
		nodetype* tmp = start;
		nodetype* prv = NULL;
		while (tmp != NULL)
		{
			if (tmp->id == x)
			{
				if (prv != NULL)
				{
					prv->next = tmp->next;
				}
				else
				{
					start = tmp->next;
				}
				delete tmp;
				break;
			}
			prv = tmp;
			tmp = tmp->next;
		}
		saveMember();
		system("pause");
	}


	// Modify a member
	void updateMember()
	{
		loadMember();
		cout << "Enter the member's id you want to modify" << endl;
		int x;
		cin >> x;

		nodetype* tmp = start;
		while (tmp != NULL)
		{
			if (tmp->id == x)
			{
				string n;
				string t;
				string p;
				string e;

				cout << "Enter New Name" << endl;
				cin >> n;
				cout << "Enter New Type" << endl;
				cin >> t;
				cout << "Enter New Password" << endl;
				cin >> p;
				cout << "Enter New Email" << endl;
				cin >> e;

				tmp->name = n;
				tmp->password = p;
				tmp->type = t;
				tmp->email = e;

			}
			tmp = tmp->next;
		}
		
		cout << "--------------Successfully Updated ------------------" << endl;
		system("pause");
		saveMember();
	}


	// Save to text file
	void saveMember(){
		
		system("cls");
		cout << "Do you want to Save it? " << endl;
		int i;
		cout << "1- Yes \t" << "2- No" << endl;
		cin >> i;
		ofstream file;

		// open file
		file.open("Member.txt");
		nodetype* tmp = start;

		switch (i)
		{
		case 1:
			while (tmp != NULL)
			{


				file << tmp->id << "-" << tmp->name << "-" << tmp->type << "-" << tmp->password << "-"<< tmp->email << "\n";
				tmp = tmp->next;
			}
			file.close();
			break;
		case 2:
			// cancel save operation
			cout << "OK!" << endl;
			break;
		}

	}

	// show memeber only
	void loadMember(){
		string line;
		ifstream myFile ("Member.txt");
		if(myFile.is_open()){
			while(getline(myFile, line)){
				cout << line << "\n";

			}

			myFile.close();
		}
		else cout << "Unable to open the file" << endl;
	}


	// load the text file and save each word seperated by "-" to its position
	void MemberloadStarter()
	{
		string line;

		ifstream myFile ("Member.txt");
		if(myFile.is_open())
		{
			std::string word;  /* string to hold words */
			std::string sTemp;
		    std::stringstream s;
			std::stringstream wordstream;

			 while (getline (myFile, line))
			 {         /* read each line into line */
				 nodetype* tmp = new nodetype();
				 pk++;
				 s.str(line);

				 getline (s, word, '-');  /* read hyphen separated words */
				 wordstream.str(word);
			     wordstream>>tmp->id;
				 wordstream.clear();

				 getline (s, word, '-');  /* read hyphen separated words */
				 wordstream.str(word);
			     wordstream>>tmp->name;
				 wordstream.clear();

				 getline (s, word, '-');  /* read hyphen separated words */
				 wordstream.str(word);
			     wordstream>>tmp->type;
				 wordstream.clear();

				 getline (s, word, '-');  /* read hyphen separated words */
				 wordstream.str(word);
			     wordstream>>tmp->password;
				 wordstream.clear();
				 
				 getline (s, word, '-');  /* read hyphen separated words */
				 wordstream.str(word);
			     wordstream>>tmp->email;
				 wordstream.clear();

				 
				 
				 

				 s.clear();
				 
				 tmp->next = start;
				 start = tmp;
			 }


		}

	}

	// check whether the password is correct or not
	bool checkPassword(int i, string pass){
		nodetype* tmp = start;
		int o =0;
		while (tmp != NULL)
		{
			if (tmp->id == i && tmp->password == pass)
			{
				o = 1;
			}
			tmp = tmp->next;
			
		}

		if(o == 1){
			return true;
		}
		else return false;


	}

	// show member without its password to user to choose his/her id
	void showID()
	{
		nodetype* temp = start;
		while (temp != NULL)
		{
			cout << "==================================================" << endl;
			cout <<"   \t"<< temp->id << "\t " << temp->name << "\t " << temp->type  << " "<<endl;
			cout << "==================================================" << endl;
			temp = temp->next;
		}
	}






private:
	nodetype* start;
};


class menu{
public:
	menu(){

	}

	// show the login section
	void logShow(){
		system("cls");
		cout << "=============================================== \n";
		cout << "||  please choose an item on the menu below  || \n";
		cout << "||-------------------------------------------|| \n";
		cout << "||            Log in As:                     || \n";
		cout << "||-------------------------------------------|| \n";
		cout << "||               (1) Administrator           || \n";
		cout << "||               (2) Staff                   || \n";
		cout << "||               (3) Students                || \n";
		cout << "||-------------------------------------------|| \n";
		cout << "||               (4) Quit                    || \n";
		cout << "=============================================== \n";
		cout << "Your Choice: ";
		
	}

	// Staff menu
	void staffShow(){
		system("cls");
		cout << "=============================================== \n";
		cout << "||  please choose an item on the menu below  || \n";
		cout << "||-------------------------------------------|| \n";
		cout << "||               (1) Perform Booking         || \n";
		cout << "||               (2) View All rooms          || \n";
		cout << "||               (3) View My Booking         || \n";
		cout << "||-------------------------------------------|| \n";
		cout << "||               (4) Quit                    || \n";
		cout << "=============================================== \n";
		cout << "Your Choice: ";
	}

	// student menu
	void studentShow(){
		system("cls");
		cout << "=============================================== \n";
		cout << "||  please choose an item on the menu below  || \n";
		cout << "||-------------------------------------------|| \n";
		cout << "||               (1) Perform Booking         || \n";
		cout << "||               (2) View My Booking         || \n";
		cout << "||-------------------------------------------|| \n";
		cout << "||               (3) Quit                    || \n";
		cout << "=============================================== \n";
		cout << "Your Choice: ";
	}

	// admin menu
	void adminShow(){
		system("cls");
		cout << "=============================================== \n";
		cout << "||  please choose an item on the menu below  || \n";
		cout << "||-------------------------------------------|| \n";
		cout << "||               (1) Add Rooms               || \n";
		cout << "||               (2) Delete Room             || \n";
		cout << "||               (3) Modify Rooms            || \n";
		cout << "||               (4) Add Member              || \n";
		cout << "||               (5) Delete Member           || \n";
		cout << "||               (6) Modify Members          || \n";
		cout << "||               (7) Perform Booking         || \n";
		cout << "||               (8) Search the Records      || \n";
		cout << "||               (9) Delete Previous Records || \n";
		cout << "||               (10) View All records       || \n";
		cout << "||-------------------------------------------|| \n";
		cout << "||               (11) Quit                   || \n";
		cout << "=============================================== \n";
		cout << "Your Choice: ";
	}

};

int main() {
	// creating object of each class
	room obj;
	member ins;
	menu me;

	//string for adding a member
	string a,b,c,d;
	// for room id
	int x;

	// for menu condition
	int ym = 1;


	// Because we need to populate the nodes
	
	// upload member and save the parameters so we check each one by its password and id when app starts 
	ins.MemberloadStarter();

	
		me.logShow();
		int logO;
		cin >> logO;
		// Admin section
		if(logO == 1)
		{
			system("cls");
			string password;
			cout << "Enter your Password" << endl;
			cin >> password;
			obj.loadRooms();
			
			// create the check password function
			if(password == "1234"){
				
				
				
				while(ym==1) {
					me.adminShow();
					int adminOp;
					cin >> adminOp;
				switch (adminOp)
				{
				case 1:
					obj.addRoom();
					
					break;
				case 2:
					obj.deleteRoom();
					break;
				case 3: 
					obj.updateRoom();
					break;
				case 4: 
					
					cout << "Enter the name" << endl;
					cin >> a;
					cout << "Enter the password" << endl;
					cin >> b;
					cout << "Enter the type Student || Staff " << endl;
					cin >> c;
					cout << "Enter the Email" << endl;
					cin >> d;

					ins.addMember(a,b,c,d);
					break;
				case 5: 
					ins.deleteMember();
					break;
				case 6: 
					ins.updateMember();
					break;
				case 7: 
					obj.reserveRoom();
					break;
				case 8: 
					
					cout << "Enter the room id you want to check" << endl;
					cin >> x;
					obj.searchBooking(x);
					break;
				case 9:
					system("cls");
					obj.delPreviousBooking();
					break;
				case 10:
					system("cls");
					cout << "----------------------------------------------------------" << endl;
					cout << "-------------------------Rooms----------------------------" << endl;
					cout << "" << endl;
					obj.loadRecords();
					cout << "----------------------------------------------------------" << endl;
					cout << "------------------------Members---------------------------" << endl;
					cout << "" << endl;
					ins.loadMember();
					system("pause");
					break;

				default:
					ym = 0;
					system("exit");
					break;	
				}
				
				
				}
			}

			else{
				cout << "Wrong Password" << endl;
				system("pause");
			}
		}

		// staff section
		else if(logO == 2)
		{
			system("cls");
			ins.showID();
			cout << "enter your id" << endl;
			int mId;
			cin >> mId;
				string password;
				cout << "Enter your Password" << endl;
				cin >> password;
				
			// create the check password function
				if(ins.checkPassword(mId, password)){
				
				while(ym == 1) {
					me.staffShow();
					int stafOp;
					cin >> stafOp;
				switch (stafOp)
				{
				case 1:
					obj.loadRooms();
					obj.reserveRoom();
				
					
					break;
				case 2:
					obj.show();
					system("pause");
					
					break;
				case 3:
					cout << "Enter The room Id you booked" << endl;
					int k;
					cin >> k;
					obj.searchBooking(k);
					break;
				default:
					ym = 0;
					break;
				}
				}
			}

			else{
				cout << "Wrong Password" << endl;
				system("pause");
			}
		}

		//Student section
		else if(logO == 3)
		{
			system("cls");
			ins.showID();
				cout << "enter your id" << endl;
			int mId;
			cin >> mId;
				string password;
				cout << "Enter your Password" << endl;
				cin >> password;
			// create the check password function
				if(ins.checkPassword(mId,password)){
				
				while(ym == 1) {
					me.studentShow();
					int stuOp;
					cin >> stuOp;
				switch (stuOp)
				{
				case 1:
					obj.loadRooms();
					obj.reserveRoom();
				
					//menuLoop = true;
					break;
				case 2:
					cout << "Enter The room Id you booked" << endl;
					int k;
					cin >> k;
					obj.searchBooking(k);
					
					
					break;
				
				default:
					ym = 0;
					break;
				}
				}
			}

			else{
				cout << "Wrong Password" << endl;
				system("pause");
			}
		}

		}	 

		
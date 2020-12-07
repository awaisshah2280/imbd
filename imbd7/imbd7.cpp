// imbd4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//_----------------------------------------Muhammad Awais Shah    CMS 313216
//-----------------------------------------Abdullah Ramzan    

#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include<ios>
#include<limits>
using namespace std;

// forword declaration

class MovieNode;
class ActorNode;
class DirectorNode;
class MoviesDirected;
class MoviesActed;
class MoviesDirectedList;
class MoviesActedList;
class ActorList;
class DirectorList;
class MovieList;
class MovieIndexNode;
class MovieIndex;



// struct
struct Actor {
	string name;
	unsigned short int fb_like;
	MoviesActedList* movies_acted;

};
struct Director {
	string name;
	unsigned short int fb_likes;
	MoviesDirectedList* movies_directed;

};
struct movie {
public:
	string movie_title;

	vector<string> genre;
	unsigned short int title_year;
	float imdb_score;
	DirectorNode* director;
	unsigned short int num_critic_for_review;
	double duration;
	ActorList* actors;
	float gross;
	unsigned short int num_voted_user;
	unsigned short int cast_total_fb_like;
	unsigned short int face_in_poster;
	vector<string> plot_keywords;
	string  movie_imbd_link;
	unsigned short int num_user_for_review;
	string lang;
	string country;
	string content_rating;
	float budget;
	double aspect_ratio;
	unsigned short int movie_fb_like;
	bool color;



};

// class for storing acted movies
class MoviesActed {
public:
	movie* data;
	MoviesActed* next;
	
};
class MoviesActedList {
public:
	MoviesActed* start;
	MoviesActed* last;
	MoviesActed* loc, * ploc;
	// function for checking empty list

	MoviesActedList() {

		start = NULL;
		last = NULL;
		loc = NULL;
		ploc = NULL;
	}

	bool isEmpty() {
		return start == NULL;
	}

	// function for inserting at tail end
	void InsertAtTail(movie* movie_node) {
		MoviesActed* newNode = new MoviesActed();
		newNode->data = movie_node;
		if (isEmpty()) {
			start = newNode;
			last = newNode;

		}
		else {
			last->next = newNode;
			last = newNode;

		}
	}
	int countss() {
		if (isEmpty()) {
			return 0;
		}
		loc = start, ploc = NULL;
		int count = 1;
		while (loc != NULL) {
			ploc = loc;
			loc = loc->next;
			count++;
		}
		return count;

	}
	void printList();
	void  display(movie* temp);
	void printListCoActor(string name);
	void printUniqueCO(string name);


};
//classes for Actor Node
class ActorNode {
public:
	Actor data;	
	ActorNode* next;
	ActorNode(){
		data.movies_acted = new MoviesActedList();

	}
	
};
class ActorList {
public:
	ActorNode* start;
	ActorNode* last;
	ActorNode* loc, * ploc;
	
	// function for checking empty list

	ActorList() {

		start = NULL;
		last = NULL;
		loc = NULL;
		ploc = NULL;
	}

	bool isEmpty() {
		return start == NULL;
	}
	void  InsertAtFront(Actor actor) {
		ActorNode* newNode = new ActorNode();
		newNode->data = actor;
		if (isEmpty()) {
			start = newNode;
			last = newNode;
		}
		else {
			newNode->next = start;
			start = newNode;
		}
	}


	// function for inserting at tail end
	void InsertAtTail(Actor actor) {
		ActorNode* newNode = new ActorNode();
		newNode->data = actor;
		if (isEmpty()) {
			start = newNode;
			last = newNode;

		}
		else {
			last->next = newNode;
			last = newNode;

		}
	}

	// printing list

	// fuction for searching value
	void search(string aname) {
		

		loc = start, ploc = NULL;

		if (isEmpty()) {
			return;

		}
		while (loc != NULL && loc->data.name != aname) {
			ploc = loc;
			loc = loc->next;

		}
		if (loc != NULL && loc->data.name != aname) {
			loc = NULL;

		}

	}
	ActorNode* insert(Actor actor) {
		search(actor.name);
		if (loc != NULL)					//duplicate check
			return loc;
		else {
			if (ploc == NULL) {				//incase poition is at start
				InsertAtFront(actor);
				return start;
			}
			else {
				ActorNode* newnode = new ActorNode();	//new node created
				newnode->data = actor;				//value stored
				newnode->next = ploc->next;			//updating loaction in list
				ploc->next = newnode;
				last = newnode;
				return last;

			}




		}

	}
	
	void display(Actor actor) {

		cout << actor.name << "\t\t\t"<<actor.fb_like<<endl;


	}
	void printList() {
		cout << "Actor Name : "<<"\t\t\t"<<" Actor Fb Like"<<endl;

		
		if (!(isEmpty())) {
			ActorNode* temp = start;
			while (temp != NULL) {
				display(temp->data);
				temp = temp->next;


			}
		}
		else {
			cout << "List is Empty" << endl;
		}

	}
	void SearchActorProfile(string name) {
		loc = start, ploc = NULL;

		int count = 0;
		if (isEmpty()) {
			cout << "Not Popullated" << endl;
			return;
		}
		int yes = -1;


		while (yes != 1) {



			while (loc != NULL && (loc->data.name.find(name))) {
				ploc = loc;
				loc = loc->next;



			}
			if (loc == NULL)
				break;
			system("cls");


			cout << "Actor name" << "\t\t\t" << "Actor fb like" << endl;
			display(loc->data);
			cout << "Number of Movies" << endl;
			cout << loc->data.movies_acted->countss() << endl;
			loc->data.movies_acted->printList();
			

			





			cout << endl;

			


			cout << "Is actor matched? If not press  (-1) :  ";
			cin >> yes;
		}
		if (yes == -1) {
			cout << "Actor doesnt exist" << endl;
		}
		else {
			cout << "Thanks for using";
		}





	}
	void SearchActorCo(string name) {
		loc = start, ploc = NULL;

		int count = 0;
		if (isEmpty()) {
			cout << "Not Popullated" << endl;
			return;
		}
		int yes = -1;


		while (yes != 1) {



			while (loc != NULL && loc->data.name.find(name)) {
				ploc = loc;
				loc = loc->next;



			}
			if (loc == NULL)
				break;
			system("cls");


			cout << "Actor name" << "\t\t\t" << "Actor fb like" << endl;
			display(loc->data);
			cout << "----------------Co-Actors" << endl;
			loc->data.movies_acted->printListCoActor(name);








			cout << endl;

			ploc = loc;
			loc = loc->next;


			cout << "Is actor matched? If not press  (-1) :  ";
			cin >> yes;
		}
		if (yes == -1) {
			cout << "Actor doesnt exist" << endl;
		}
		else {
			cout << "Thanks for using";
		}





	}
	void SearchUniqueCo(string name) {
		loc = start, ploc = NULL;

		int count = 0;
		if (isEmpty()) {
			cout << "Not Popullated" << endl;
			return;
		}
		int yes = -1;


		while (yes != 1) {



			while (loc != NULL && loc->data.name.find(name)) {
				ploc = loc;
				loc = loc->next;



			}
			if (loc == NULL)
				break;
			system("cls");


			cout << "Actor name" << "\t\t\t" << "Actor fb like" << endl;
			display(loc->data);
			cout << "----------------Co-Actors" << endl;
			loc->data.movies_acted->printUniqueCO(name);








			cout << endl;

			ploc = loc;
			loc = loc->next;


			cout << "Is actor matched? If not press  (-1) :  ";
			cin >> yes;
		}
		if (yes == -1) {
			cout << "Actor doesnt exist" << endl;
		}
		else {
			cout << "Thanks for using";
		}





	}
	void CoActorCheck(string actor1, string actor) {
	


	}


};
	// classes for one director
 class MoviesDirected {
	public:
		movie* data;
		MoviesDirected* next;
	};
	class MoviesDirectedList {
	public:
		MoviesDirected* start;
		MoviesDirected* last;
		MoviesDirected* loc;
		MoviesDirected* ploc;
		
		// function for checking empty list

		MoviesDirectedList() {
			

			start = NULL;
			last = NULL;
			loc = NULL;
			ploc = NULL;
			
		}

		bool isEmpty() {
			return start == NULL;
		}

		// function for inserting at tail end
		void InsertAtTail(movie* movie_node)  {
			MoviesDirected* newNode = new MoviesDirected();
			newNode->data = movie_node;
			if ((isEmpty())) {
				start = newNode;
				last = newNode;

			}
			else {
				last->next = newNode;
				last = newNode;

			}
		}
		int count() {
			MoviesDirected* temp = new MoviesDirected();
			temp = start;
			int counts = 0;
			if (isEmpty()) {
				return counts;
			}
			while (temp != NULL) {
				counts++;
				temp = temp->next;

			}
			return counts;
		}
		void printList();
	};
	// classes  for Director list
	class DirectorNode {
	public:
		Director data;		
		DirectorNode* next;
		DirectorNode() {
			data.movies_directed = new MoviesDirectedList();
			next=NULL;
			
		}
	};
	class DirectorList {
	public:
		DirectorNode* start;
		DirectorNode* last;
		DirectorNode* loc, * ploc;

		// function for checking empty list

		DirectorList() {

			start = NULL;
			last = NULL;
			loc = NULL;
			ploc = NULL;
		}

		bool isEmpty() {
			return start == NULL;
		}
		void  InsertAtFront(Director director) {
			DirectorNode* newNode = new DirectorNode();
			newNode->data = director;
			if (isEmpty()) {
				start = newNode;
				last = newNode;
			}
			else {
				newNode->next = start;
				start = newNode;
			}
		}


		// function for inserting at tail end
		void InsertAtTail(Director director) {
			DirectorNode* newNode = new DirectorNode();
			newNode->data = director;
			if (isEmpty()) {
				start = newNode;
				last = newNode;

			}
			else {
				last->next = newNode;
				last = newNode;

			}
		}
		// fuction for searching value
		void search(string aname) {
			

			loc = start, ploc = NULL;

			if (isEmpty()) {
				return;

			}
			while (loc != NULL && loc->data.name != aname) {
				ploc = loc;
				loc = loc->next;

			}
			if (loc != NULL && loc->data.name != aname) {
				loc = NULL;

			}

		}
		DirectorNode* insert(Director director) {
			search(director.name);
			if (loc != NULL)					//duplicate check

				return loc;
			else {
				if (ploc == NULL) {				//incase poition is at start
					InsertAtFront(director);
					
					return start;
				}
				else {
					DirectorNode* newnode = new DirectorNode();	//new node created
					newnode->data = director;				//value stored
					newnode->next = ploc->next;			//updating loaction in list
					ploc->next = newnode;
					last = newnode;
					return last;

				}




			}

		}
		void display(Director director) {

			cout << director.name << "\t\t\t" << director.fb_likes << endl;


		}
		void printList() {
			cout << "Director Name : " << "\t\t\t" << "Diecctor Fb Like" << endl;


			if (!(isEmpty())) {
				DirectorNode* temp = start;
				while (temp != NULL) {
					display(temp->data);
					temp = temp->next;


				}
			}
			else {
				cout << "List is Empty" << endl;
			}

		}
		void SearchDirectorProfile(string name) {
			loc = start, ploc = NULL;

			int count = 0;
			if (isEmpty()) {
				cout << "Not Popullated" << endl;
				return;
			}
			int yes = -1;


			while (yes != 1) {



				while (loc != NULL && loc->data.name.find(name)) {
					ploc = loc;
					loc = loc->next;



				}
				if (loc == NULL)
					break;
				
				system("cls");
				



				cout << "Director Name                        ";
				cout << loc->data.name << endl;
				cout << "Number of Movies                  ";
				cout << loc->data.movies_directed->count() << endl;
				loc->data.movies_directed->printList();
				







				cout << endl;

				ploc = loc;
				loc = loc->next;


				cout << "Is director matched? If not press  (-1) :  ";
				cin >> yes;
			}
			if (yes == -1) {
				cout << "Director doesnt exist" << endl;
			}
			else {
				cout << "Thanks for using";
			}





		}
		void SearchByGenere(string genere) {
			loc = start, ploc = NULL;


			if (isEmpty()) {
				return;
			}

			while (!(loc == last)) {
				loc->data.movies_directed->loc = loc->data.movies_directed->start;
				loc->data.movies_directed->ploc = NULL;

				while (loc->data.movies_directed->loc!=NULL && GenereSearch(genere, loc->data.movies_directed->loc->data->genre)) {
					loc->data.movies_directed->ploc = loc->data.movies_directed->loc;
						loc->data.movies_directed->loc = loc->data.movies_directed->loc->next;
				}


				cout << loc->data.name << endl;;

				cout << endl;
				loc = loc->next;


			}


		}
		bool GenereSearch(string genere, vector<string> temps) {
			for (int i = 0; i < temps.size(); i++) {
				if (temps[i].find(genere))
					return true;
			}

			return false;

		}



		
		


	};
	// classes for printing movies w.r.t rating and date
	// using doubly linked list
	class MovieIndexNode {
	public:
		movie* data;
		MovieIndexNode* next;
		MovieIndexNode* prev;

	};
	class MovieIndex {
	public:
		MovieIndexNode* start;
		MovieIndexNode* last;
		MovieIndexNode* ploc;
		MovieIndexNode* loc;

		MovieIndex() {
			start = NULL;
			last = NULL;
			ploc = NULL;
			loc = NULL;

		}
		bool isEmpty() {
			return start == NULL;
		}
		void  InsertAtFront(movie* temp) {
			MovieIndexNode* newNode = new MovieIndexNode();
			newNode->data = temp;
			if (isEmpty()) {
				start = newNode;
				last = newNode;
			}
			else {
				newNode->next = start;
				start->prev = newNode;
				start = newNode;

			}
		}

		void InsertAtTail(movie* movie_node) {
			MovieIndexNode* newNode = new MovieIndexNode();
			newNode->data = movie_node;
			if (isEmpty()) {
				
				newNode->prev = last;
				last->next = newNode;
				last = newNode;

			}
			else {
				last->next = newNode;
				newNode->prev = last;
				last = newNode;


				

			}
		}
		// search using imbd rating
		void searchimbd(movie* temp) {

			loc = start, ploc = NULL;
			if (isEmpty()) {
				return;
			}
			while (loc != NULL && loc->data->imdb_score < temp->imdb_score) {
				ploc = loc;
				loc = loc->next;

			}
			if (loc != NULL && loc->data->imdb_score != temp->imdb_score) {
				loc = NULL;
			}
		}
		// function for inserting value in sorted list using imbd ratin
		void InsertSortedImbd(movie* temp) {
			if (temp->imdb_score < 0 || temp->imdb_score>10 || isnan(temp->imdb_score)) {
				return;
			}
			searchimbd(temp);
			
				if (ploc == NULL) {				//incase poition is at start
					InsertAtFront(temp);
				}
				else {

					MovieIndexNode* newnode = new MovieIndexNode();	//new node created
					newnode->data = temp;				//value stored
									//value stored

					newnode->next = ploc->next;			//updating loaction in list
					newnode->prev = ploc;

					if (ploc != last)					//incase position of node is at end
						ploc->next->prev = newnode;
					else
						last = newnode;
					ploc->next = newnode;

				}
			


		}
		// printing list in both direction
		// if parameer is true it will print in forward otherwise backward
		void printListimbd(bool direction) {
			if (!isEmpty()) {
				MovieIndexNode* temp;
				if (direction) {
					temp = start;
					while (temp != NULL) {
						cout << temp->data->movie_title << ": ";
						cout << temp->data->imdb_score << endl;
						temp = temp->next;
					}
				}
				else
				{
					temp = last;
					while (temp != NULL) {
						cout << temp->data->movie_title << ": ";
						cout << temp->data->imdb_score << endl;
						temp = temp->prev;
					}
					cout << endl;
				}
			}
			else {
				cout << "List is empty";

			}



		}
		// searching movies using year
		void searchYear(movie* temp) {

			loc = start, ploc = NULL;
			if (isEmpty()) {
				return;
			}
			while (loc != NULL && loc->data->title_year < temp->title_year) {
				ploc = loc;
				loc = loc->next;

			}
			if (loc != NULL && loc->data->title_year != temp->title_year) {
				loc = NULL;
			}
		}
		// inserting in yearly mainted list
		void InsertSortedYearly(movie* temp) {
			double x = double(temp->title_year);
			if (temp->title_year==0 || isnan(x)) {
				return;
			}
			searchYear(temp);

			if (ploc == NULL) {				//incase poition is at start
				InsertAtFront(temp);
			}
			else {

				MovieIndexNode* newnode = new MovieIndexNode();	//new node created
				newnode->data = temp;				//value stored
								//value stored

				newnode->next = ploc->next;			//updating loaction in list
				newnode->prev = ploc;

				if (ploc != last)					//incase position of node is at end
					ploc->next->prev = newnode;
				else
					last = newnode;
				ploc->next = newnode;

			}



		}
		void printListYearly(bool direction) {
			if (!isEmpty()) {
				MovieIndexNode* temp;
				if (direction) {
					temp = start;
					while (temp != NULL) {
						cout << temp->data->movie_title << ": ";
						cout << temp->data->title_year << endl;
						temp = temp->next;
					}
				}
				else
				{
					temp = last;
					while (temp != NULL) {
						cout << temp->data->movie_title << ": ";
						cout << temp->data->title_year << endl;
						temp = temp->prev;
					}
					cout << endl;
				}
			}
			else {
				cout << "List is empty";

			}



		}


		
		








	};
	// classes for MovieList
	class MovieNode {
	public:
		movie data;

		MovieNode* next;
	};
	class MovieList {
	public:
		// pointers
		MovieNode* start;
		MovieNode* last;
		MovieNode* loc;
		MovieNode* ploc;

		ActorList* actor_list;   // for popullating actor list
		DirectorList* director_list;  // for popullating director list
		MovieIndex* movie_index_imbd;  // for indexing using imbd rating
		MovieIndex* movie_index_year;

		// function for checking empty list

		MovieList() {

			start = NULL;
			last = NULL;
			loc = NULL;
			ploc = NULL;
			actor_list = new ActorList();
			director_list = new DirectorList();
			movie_index_imbd = new MovieIndex();
			movie_index_year = new MovieIndex();
			
			Popullating(); // popullating in default constructor
		}

		bool isEmpty() {
			return start == NULL;
		}
		void InsertAtTail(movie temp) {
			MovieNode* newNode = new MovieNode;
			newNode->data = temp;
			if (isEmpty()) {
				start = newNode;
				last = newNode;

			}
			else {
				last->next = newNode;
				last = newNode;

			}
		}
		// reading one record at atime
		movie ReadRecord(ifstream& file,MovieNode* temp_node) {

			movie temp; // for storing movie detail temporarily

			string line;  // storing record as line
			vector<string> row; // for storing fields after breaking line(record)
			string word; // for breaking field to subfield
			// skipping first line
			if (!(file.is_open())) {
				cout << "file not opened" << endl;

			}
			//skipping first lin
			if ((file.tellg() == 0)) {
				getline(file, line, '\n');
				line = " ";
			}

			// getting one record and store it as string in line
			getline(file, line, '\n');
			// breaking line in fields
			stringstream ss(line);
			while (ss.good()) {  // till full line is read
				getline(ss, word, ','); // reading field till comma and store in word
				row.push_back(word); // storing field in vector 
			}


		   // clear stringstream
		   // assigning value in temporay movies struct which are pushed in row
			string title = row[0];
			title.erase(title.length()-2, 2); // removing garbage character from title
			
			temp.movie_title = title;
			line.clear();
			line = row[1];
			// breaking genre string into individuals
			stringstream sep(line);
			while (sep.good()) {
				getline(sep, word, '|');
				temp.genre.push_back(word);
			}

			try {
				temp.title_year = stoi(row[2]);

			}
			catch (...) {
				temp.title_year = NAN;

			}


			try {
				temp.imdb_score = stof(row[3]);

			}
			catch (...) {
				temp.imdb_score = NAN;
			}

			// creating director node for storing data
			DirectorNode* temp_director = new DirectorNode();
			temp_director->data.name = row[4];
			try {
				temp_director->data.fb_likes = stoi(row[5]);
			}
			catch (...) {
				temp_director->data.fb_likes = NAN;
			}
			
			
			
			
			temp.director = temp_director;   // assigning sirector node to director node in temp
			temp.director = director_list->insert(temp.director->data);   // inserting actor in actor list if not exist and return its pointer to director node in temp
			temp.director->data.movies_directed->InsertAtTail(&temp_node->data);  //inserting adress of movie in movie directed list


			
			try {
				temp.num_critic_for_review = stoi(row[6]);
			}
			catch (...) {
				temp.num_critic_for_review = NAN;
			}
			try { temp.duration = stoi(row[7]); }
			catch (...) {
				temp.duration=NAN;
				
			}

			// creating list for actors
			ActorNode* actor=new ActorNode();
			ActorList* actors = new ActorList();
			actor->data.name = row[8];

			try { actor->data.fb_like = stoi(row[9]); }
			catch (...) {
				actor->data.fb_like = NAN;
				
			}
			
			

			actor = actor_list->insert(actor->data);   // getting adress of node after insertinng into actor list if not exits
			actors->InsertAtTail(actor->data);
			actors->start->data.movies_acted->InsertAtTail(&temp_node->data);   // inserting movie pointer in movie acted list
			ActorNode* actor1 = new ActorNode();
			actor1->data.name = row[10];

			try {
				actor1->data.fb_like = stoi(row[11]);
			}
			catch (...) {
				actor1->data.fb_like = NAN;

			}
			
			
			actor1 = actor_list->insert(actor1->data);// getting adress of node after insertinng into actor list if not exits
			actors->InsertAtTail(actor1->data);
			actors->start->next->data.movies_acted->InsertAtTail(&temp_node->data);// inserting movie pointer in movie acted list
			ActorNode* actor2 = new ActorNode();
			actor2->data.name = row[12];

			try {
				actor2->data.fb_like = stoi(row[13]);
			}
			catch (...) {
				actor2->data.fb_like = NAN;
			}
			
			
			actor2 = actor_list->insert(actor2->data);// getting adress of node after insertinng into actor list if not exits
			actors->InsertAtTail(actor2->data);
			actors->last->data.movies_acted->InsertAtTail(&temp_node->data); // inserting movie pointer in movie acted list

			
			temp.actors = actors;
			try {
				temp.gross = stof(row[14]);
			}
			catch (...) {
				temp.gross = NAN;

			}
			try {
				temp.num_voted_user = stoi(row[15]);
			}
			catch (...) {
				temp.num_voted_user = NAN;

			}
			try {
				temp.cast_total_fb_like = stoi(row[16]);
			}
			catch (...) {
				temp.cast_total_fb_like = NAN;

			}

			try { temp.face_in_poster = stoi(row[17]); }
			catch (...) {
				temp.face_in_poster = NAN;
			}

			line = row[18];
			stringstream sep1(line);
			// breaking plot keywords
			while (sep1.good()) {

				getline(sep1, word, '|');
				temp.plot_keywords.push_back(word);

			}

			
			temp.movie_imbd_link = row[19];
			try {
				temp.num_user_for_review = stoi(row[20]);
			}
			catch (...) {
				temp.num_user_for_review = NAN;

			}

			temp.lang = row[21];

			temp.country = row[22];
			temp.content_rating = row[23];
			try { temp.budget = stof(row[24]); }
			catch (...) {
				temp.budget = NAN;

			}
			try {
				temp.aspect_ratio = stof(row[25]);
			}
			catch (...) {
				temp.aspect_ratio = NAN;
			}
			try {
				temp.movie_fb_like = stoi(row[26]);
			}
			catch (...) {
				temp.movie_fb_like = NAN;

			}

			temp.color = row[27] == "Color" || row[27] == "color" ? true : false;   // inserrting true for color and false for black and white
			line.clear();
			row.clear();
			
			

			

			return  temp;
		}
		// populating movielist structure
		void Popullating() {



			ifstream file("datasets.csv");  // opening file
			MovieNode* Movie= new MovieNode(); // struct for storing movie detail from RecordReader() method
			// fileopen check
			if (!file.is_open()) {
				cout << "not opened";

			}
			else {
				cout << endl;
				// reading whole file
				cout << "------------------------------------Wait Data is being inserted in data structure----------------------------" << endl;
				// variables for blinking line
				int count = 0;
				int ch = 0;
				string a = "*";
				string b = "";

				while (file.good()) {  // while end of file
					MovieNode* Movie = new MovieNode(); // struct for storing movie detail from RecordReader() method
			
					Movie->data = ReadRecord(file,Movie);  // store movie instance return by method ReadRecord
					if (isEmpty()) {
						start = Movie;
						last = Movie;

					}
					else {
						last->next = Movie;
						last = Movie;
					}
					// updating value in index classes
					movie_index_imbd->InsertSortedImbd(&Movie->data);
					movie_index_year->InsertSortedYearly(&Movie->data);
					

					
					
					
						
					
					
					
					// for creating blinking lines
					if (count % 50 == 0 && ch != 11)
					{
						cout << a + a;
						if (ch == 10) {
							cout << "\r";
							ch = 0;
						}
						ch++;
					}
					count++;


				}

			}
			
			cout << "\r------------------------------------Insertion is done----------------------------" << endl;
			file.close();// close file					


		}
		// function to be implemented
		// serch profile of actor
	
		// displayig detail of one movie
		void display(movie elements) {
			cout << "Movie title:             ";
			cout << elements.movie_title << endl;
			cout << "Genere:                  ";
			for (int i = 0; i < elements.genre.size(); i++) {
				cout << elements.genre[i] << ",";
			}
			cout << endl;
			cout << "Title Year:              ";
			cout << elements.title_year << endl;
			if (!isnan(elements.imdb_score)) {
				cout << "IMBD Score:              ";
				cout << elements.imdb_score << endl;

			}
			
			cout << "Director:                ";
			cout << elements.director->data.name << endl;
			cout << "Director Fb like:        ";
			cout << elements.director->data.fb_likes << endl;
			cout << "------------------------Actors------------------   " << endl;
			elements.actors->printList();
			cout << "------------------------------------------------   " << endl;
			cout << "Gross:                   ";
			cout << elements.gross << endl;
			cout << "Number of Voted User:    ";
			cout << elements.num_voted_user << endl;
			cout << "Cast Fb like:            ";
			cout << elements.cast_total_fb_like << endl;
			cout << "Face in Poster:          ";

			cout << elements.face_in_poster << endl;
			cout << "Keyword:                 ";
			for (int i = 0; i < elements.genre.size(); i++) {
				cout << elements.plot_keywords[i] << ",";
			}
			cout << endl;
			cout << "Movie Link:              ";
			cout << elements.movie_imbd_link << endl;
			cout << "Number of review         ";
			cout << elements.num_user_for_review << endl;
			cout << "Langauage:               ";
			cout << elements.lang << endl;
			cout << "Country:                 ";
			cout << elements.country << endl;
			cout << "Content Rating:          ";
			cout << elements.content_rating << endl;
			cout << "Budget:                  ";
			cout << elements.budget << endl;
			cout << "Aspect Ratio:            ";
			cout << elements.aspect_ratio << endl;
			cout << "Movie Fb Like:           ";
			cout << elements.movie_fb_like << endl;
			cout << "Colors:                  ";
			elements.color ? cout << "Color" : cout << "Black & White";


		}
		//functins realted to class
		// search by title function
		void SearchbyTitle(string title) {
			loc = start, ploc = NULL;

			int count = 0;
			if (isEmpty()) {
				return;
			}
			int yes = 0;


			while (yes!=-1  ) {



				while (loc!=NULL && loc->data.movie_title != "" && loc->data.movie_title.find(title)) {
					ploc = loc;
					loc = loc->next;
					
						

				}
				if (loc == NULL)
					break;
				system("cls");
				

				



				display(loc->data);

				cout << endl;

				ploc = loc;
				loc = loc->next;


				cout << "Is movie matched? If not press  (1) :  ";
				cin >> yes;
			}
			if (yes == -1) {
				cout << "Movie doesnt exit" << endl;
			}
			else{
				cout << "Thanks for using";
			}
			


		}
		// search by year function
		void SearchByYear(unsigned short int year) {
			


			if (isEmpty()) {
				return;
			}
			loc = start, ploc = NULL;
			while (!(loc == last)) {

				while (loc->data.movie_title != "" && loc->data.title_year == year) {
					ploc = loc;
					loc = loc->next;
				}


				cout << loc->data.movie_title << endl;;

				cout << endl;
				ploc = loc;
				loc = loc->next;


			}

		}
		void SearchByGenere(string genere) {
			loc = start, ploc = NULL;


			if (isEmpty()) {
				return;
			}

			while (!(loc == last)) {


				while ( !GenereSearch(genere,loc->data.genre)) {
					
					ploc = loc;
					loc = loc->next;
					
				}
				cout << loc->data.movie_title << endl;


				

				cout << endl;
				ploc = loc;
				loc = loc->next;


			}


		}
		// search by genre
		bool GenereSearch(string genere, vector<string> temps) {
			for (int i = 0; i < temps.size(); i++) {
				if (!(temps[i].find(genere)))
					return true;
			}
			
			return false;
				
		}
		
		
		

		
		

    };
	// function which we cant defind at beginning becasue of forward declararion error for printing list
	// printing movies ActedList
	void MoviesActedList ::printList() {

		cout << "----------------Movie List------------------" << endl;
		cout << "Movie Title" << ":" << "Title Year" << endl;
		loc = start, ploc = NULL;
		if (!isEmpty()) {

			while (loc != NULL) {
				
				cout <<loc->data->movie_title << "  :   ";
				cout <<loc->data->title_year << endl;
				ploc = loc;
				loc = loc->next;
				





			}
		}
		else {
			cout << "List is Empty" << endl;
		}
	}
	//printing co actors
	void MoviesActedList::printListCoActor(string name) {
		loc = start, ploc = NULL;
		while (loc != NULL) {
			cout << loc->data->movie_title << "   :   ";
			loc->data->actors->loc = loc->data->actors->start;
			loc->data->actors->ploc = NULL;
			while (loc->data->actors->loc != NULL) {
				if ((loc->data->actors->loc->data.name.find(name))) {
					cout << loc->data->actors->loc->data.name << ",";

				}
				loc->data->actors->ploc = loc->data->actors->loc;
				loc->data->actors->loc = loc->data->actors->loc->next;
			}
			cout << endl;
			ploc = loc;
			loc = loc->next;
		}

		
	}
	void MoviesDirectedList::printList() {
		cout << "----------------Movie List------------------" << endl;
		cout << "Movie Title" << ":" << "Title Year" << endl;
		loc = start, ploc = NULL;
		if (!isEmpty()) {

			while (loc != NULL) {

				cout << loc->data->movie_title << "  :   ";
				cout << loc->data->title_year << endl;
				ploc = loc;
				loc = loc->next;






			}
		}
		else {
			cout << "List is Empty" << endl;
		}


	}
	void MoviesActedList::printUniqueCO(string name) {
		loc = start, ploc = NULL;
		vector<string> co;
		while (loc != NULL) {
			
			loc->data->actors->loc = loc->data->actors->start;
			loc->data->actors->ploc = NULL;
			while (loc->data->actors->loc != NULL) {
				if ((loc->data->actors->loc->data.name.find(name)) && !(count(co.begin(), co.end(), loc->data->actors->loc->data.name))) {
					
					cout << loc->data->actors->loc->data.name <<endl;
					co.push_back(loc->data->actors->loc->data.name);

				}
				loc->data->actors->ploc = loc->data->actors->loc;
				loc->data->actors->loc = loc->data->actors->loc->next;
			}
			
			ploc = loc;
			loc = loc->next;
		}


	}
	
	
	
	int main()
	{

		MovieList* master = new MovieList(); // creating  pointer for movielist pointer which also popullate at runtime
		int i = 0; // for selecting choice
		int year;  // for entring year
		string name;
		string actor1;
		string actor2;
		string genere;
		int quit = 0;
		while(quit!=-1){     // condition to quit program
			cout << "1 - Search Movie by Title" << endl;
			cout << "2-    Search Movie by year" << endl;
			cout << "3-  Search Movie by genere" << endl;
			cout << "4- Search Actor Profile" << endl;
			cout << "5 - Search co-Actor with Movie" << endl;
			cout << "6- Search unique Co-Actor " << endl;
			cout << "7-Search Director Profile" << endl;
			cout << "8 - print rating wise(ascendin)" << endl;
			cout << "9-print ratinng wise(desending) " << endl;
			cout << "10- print year wise ascending" << endl;
			cout << "11- print year wise desending" << endl;
			cout << "12- print directors by genere" << endl;
			cin >> i;
			// selecting respective command using choice n
			switch (i) {
			case 1:
				cout << "Enter Movie title" << ":  ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, name);
				master->SearchbyTitle(name);
				break;
			case 2:
				cout << "Enter Year" << ":  ";
				cin >> year;
				master->SearchByYear(year);
				break;
			case 3:
				cout << "Enter Genere" << " :";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, name);
				master->SearchByGenere(name);
				break;
			case 4:
				cout << "Enter name of Actor" << " :";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, name);
				master->actor_list->SearchActorProfile(name);
				break;
			case 5:
				cout << "Enter Actor name" << ":   ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, name);
				master->actor_list->SearchActorCo(name);
				break;
			case 6:
				cout << "Enter Actor name" << ":   ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, name);
				master->actor_list->SearchUniqueCo(name);
				break;
			case 7:
				cout << "Enter director Name" << ":";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				getline(cin, name);
				master->director_list->SearchDirectorProfile(name);
				break;
			case 8:
				master->movie_index_imbd->printListimbd(true);
				break;
			case 9:
				master->movie_index_imbd->printListimbd(false);
				break;
			case 10:
				master->movie_index_year->printListYearly(true);
				break;

			case 11:
				master->movie_index_year->printListYearly(true);
				break;
			case 12:
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				getline(cin, genere);
				master->director_list->SearchByGenere(genere);
				break;




			}
			cout << "Do want to quit (press -1 to quit)" << endl;
			cin >> quit;
			



		}
		
		
		

		

	}
	

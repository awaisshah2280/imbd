# imbdDescription: 
Along, with this document you have been provided a .csv file containing a dataset of 5000 movies downloaded from the website of IMDB. For each of the 5000 movies, details of 28 parameters have been provided like actors, directors, rating etc. You should use this dataset to create a database using various data structures studied in the class. One of your first tasks it to write a parser that extracts information from the csv file for each of the movies. To complete this project, you need to define the below mentioned classes, and implement all operations mentioned in table 1. Note that your approach to the problem in terms of defining classes, and functions and organizing data may be different than what is suggested in the guidelines below. 
 
 
 

 
Course: Data Structures and Algorithms  Instructor: Dr. Yasir Faheem 
As discussed in the class, you shall need the following classes to organize data in various data structures in your application. Figures numbered 1 and 2 present a visual depiction of how you have to organize data. For details, watch the video recording already uploaded on LMS portal. 
=======================Movie ============================= 
A Movie Class that should: 
a) Store data of all the 28 fields for a movie.  b) Remember, some of the fields like actors, plot keywords, genre etc. in the Movie class may contain more than one entry. Such entries should be stored in a suitable data structure such as an array-list or a linked list. You should justify the choice of your data structure during the viva exam. Similarly, plot keywords and genres of a movie are to be stored in a separate data structure. It is better to use enums. 
 
 
============================ MovieNode class =============== 
You have to stores all the movies given in the dataset in a suitable data structure. For doing so, you shall need to define a MovieNode class.    
Class MovieNode{  Movie data;  MovieNode *next;  MovieNode *prev; // in case you use a doubly linked list } 
 
You may declare an array of MovieNode type to store the dataset e.g. MovieNode MoviesArrayList[Size]. Make sure your decision is backed by logical reasons with focus on the reduction of time and space complexity. 
 
================== MovieList class ======================= 
The MovieList class should provide the following functionalities: 
a) A method that:  a. reads the .csv file one line at a time. b. Creates an object of MovieNode class for each movie.  c. Automatically inserts all the entries of that line in various fields of the data part in the MovieNode object. Note that the data field is of type Movie. d. Finally, insert the newly created MovieNode object in your list. b) Once you have populated all your data structures, then you should implement the functionalities mentioned in table-1 
 
 
================= Director Node ===================== 

 
Course: Data Structures and Algorithms  Instructor: Dr. Yasir Faheem 
DirectorNode class which should store 
a) Director’s name  b) A list of movies he has directed.  Hint: store a list of pointers to the objects of the movie nodes a director has directed. c) Provide functionality to  a. Search directors by name. The search should return name of directors along with the details of the movies they have directed. 
Note: You shall store the data of all directors in a suitable data structure. 
 
=====================Actor Node ====================== 
ActorNode class which should store: 
a) The Name of an actor  b) A list of the movies in which he/she has acted. Remember, movies’ data is already stored in a list of type MovieNode class. Thus, the list of actor’s movies should contain only pointers to the MovieNodes in which he/she has acted.  Note: Choose a suitable data structure. ======================================= 
  

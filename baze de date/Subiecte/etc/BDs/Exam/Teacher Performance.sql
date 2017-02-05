create table Categories(
	CategoryID int primary key identity(1,1) not null,
	CategoryName nvarchar(30) not null
	)


create table Teachers(
	TeacherID int primary key identity(1,1) not null,
	TeacherName nvarchar(30) not null
	)


create table Students(
	StudentID int primary key identity(1,1) not null,
	StudentName nvarchar(30) not null
	)


create table Questions(
	QuestionID int primary key identity(1,1) not null,
	QuestionDescription nvarchar(30) not null,
	CategoryID int not null,
	foreign key (CategoryID) references Categories (CategoryID)
	)

create table TeacherQuestionValue(
	StudentID int,
	TeacherID int,
	QuestionID int,
	value int,
	foreign key (StudentID) references Students (StudentID),
	foreign key (TeacherID) references Teachers (TeacherID),
	foreign key (QuestionID) references Questions (QuestionID),
	primary key (StudentID, TeacherID, QuestionID),
	check ((value > 0) and (value <=5))
	)

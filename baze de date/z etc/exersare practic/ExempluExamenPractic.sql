use master
if exists( select* from sys.databases where name = 'examen' )
				drop database examen

create database examen
go 
use examen
create table Pacienti(
		id tinyint Primary Key,
		nume nchar(50) NULL,
		prenume nchar(50) NULL
);
go

create table Specializari(
		id tinyint Primary Key,
		specializare nchar(50) NULL,
		descriere nchar(50) NULL
);
go

create table Doctori(
		id tinyint Primary Key,
		nume nchar(50) NULL,
		prenume nchar(50) NULL,
		id_specializari tinyint constraint Specializari_Doctori foreign key references Specializari(id) 
);
go

create table Diagnostic(
		id tinyint Primary Key,
		denumire nchar(50) NULL,
);
go

create table Consultatii(
		id_Pacient tinyint constraint Consultatii_Pacient foreign key references Pacienti(id),
		id_Doctor tinyint constraint Consultatii_Doctor foreign key references Doctori(id),
		data nchar(50) NULL,
		id_diagnostic tinyint constraint Consultatii_Diagnostic foreign key references Diagnostic(id),
		primary key (id_Pacient, id_Doctor)
		
);

--Cerinta nu o am scrisa, dar din cate stiu trebuia sa creem o baza de date care contine informatii legate de un doctor si pacientii sai,
--entitatile erau Consultatii, Doctori, Pacienti si Specializari
--crearea procedurii stocate
--PS(procedura stocata) care primeste ca parametrii un pacient un doctor un diagnostic si o data si adauga o noua consultatie 
--creati o functie care verifica ca un doctor sa nu aiba mai multe consultatii la aceeasi data si ora
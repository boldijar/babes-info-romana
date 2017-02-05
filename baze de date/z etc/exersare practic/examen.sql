use master
if exists(select * from sys.databases where name='examen')
	drop DataBase examen
create database examen
go 
use examen
create table Pacienti(
	id int Primary Key,
	nume nvarchar(50) Null,
	prenume nvarchar(50) Null
);
go

create table Specializari(
	id tinyint Primary Key,
	specializare nvarchar(50) Null,
	descriere nvarchar(50) Null
);
go

create table Doctori(
	id int Primary Key,
	nume nvarchar(50) Null,
	prenume nvarchar(50) Null,
	id_specializare tinyint constraint Specializare_Doctori Foreign Key References Specializari(id)
);
go

create table Diagnostic(
	id smallint Primary Key,
	denumire nvarchar(50) Null
);
go
create table Consultatii(
	id_Pacient int  constraint Consultatii_Pacient foreign key references Pacienti(id),
	id_Doctor int  constraint Consultatii_Doctor foreign key references Doctori(id),
	data datetime Null,
	id_diagnostic smallint constraint Consultatii_Diagnostic foreign key references Diagnostic(id),
	primary key(id_Pacient,id_Doctor)
	
);
go



create table DetaliiConsultatii(
	id_Pacient int ,
	id_Doctor int,
	id_Medicament tinyint
);
go

create table Medicamente(
	id int Primary Key,
	denumire nvarchar(50) Null
);
go

--creare o procedura stocata--
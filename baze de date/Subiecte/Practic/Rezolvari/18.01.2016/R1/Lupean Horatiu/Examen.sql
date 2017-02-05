USE master;

-- creez baza de date
IF EXISTS(
	SELECT	* 
	FROM	sys.databases AS dbs
	WHERE	dbs.name = 'Examen'
	)
BEGIN
	DROP DATABASE Examen;
END

CREATE DATABASE Examen;

PRINT 'Database Examen was created';


USE Examen;

-- creez tabelul Clienti
IF EXISTS(
	SELECT	*
	FROM	SYS.tables AS tab
	WHERE	tab.name = 'Clienti'
)
BEGIN
	DROP TABLE Clienti;
END

CREATE TABLE Clienti
(
	IdClient		int				IDENTITY(1, 1)		PRIMARY KEY,
	Denumire		nvarchar(100)						NOT NULL,
	CodFiscal		numeric(10, 0)						NOT NULL
);
GO

PRINT 'Tabel Clienti was created';


-- creez tabelul Agenti
IF EXISTS(
	SELECT	*
	FROM	SYS.tables AS tab
	WHERE	tab.name = 'Agenti'
)
BEGIN
	DROP TABLE Agenti;
END

CREATE TABLE Agenti
(
	IdAgent			int				IDENTITY(1, 1)		PRIMARY KEY,
	Nume			nvarchar(50)						NOT NULL,
	Prenume			nvarchar(50)						NOT NULL
);
GO

PRINT 'Tabel Agenti was created';


-- creez tabelul Produse
IF EXISTS(
	SELECT	*
	FROM	SYS.tables AS tab
	WHERE	tab.name = 'Produse'
)
BEGIN
	DROP TABLE Produse;
END

CREATE TABLE Produse
(
	IdProdus		int				IDENTITY(1, 1)		PRIMARY KEY,
	Denumire		nvarchar(50)						NOT NULL,
	UM				nvarchar(50)						NOT NULL
);
GO

PRINT 'Tabel Produse was created';


-- creez tabelul Facturi
IF EXISTS(
	SELECT	*
	FROM	SYS.tables AS tab
	WHERE	tab.name = 'Facturi'
)
BEGIN
	DROP TABLE Facturi;
END

CREATE TABLE Facturi
(
	IdFactura		int				IDENTITY(1, 1)		PRIMARY KEY,
	NumarFactura	int									NOT NULL,
	DataEmiteri		date								NOT NULL,
	IdClient		int									NOT NULL,
	IdAgent			int									NOT NULL,

	FOREIGN KEY (IdClient)			REFERENCES Clienti(IdClient),
	FOREIGN KEY (IdAgent)			REFERENCES Agenti(IdAgent)
);
GO

PRINT 'Tabel Facturi was created';


-- creez tabelul ProduseFacturi
IF EXISTS(
	SELECT	*
	FROM	SYS.tables AS tab
	WHERE	tab.name = 'ProduseFacturi'
)
BEGIN
	DROP TABLE ProduseFacturi;
END

CREATE TABLE ProduseFacturi
(
	IdProdus		int									NOT NULL,
	IdFactura		int									NOT NULL,
	NrOrdine		int									NOT NULL,
	Pret			money								NOT NULL,
	Cantitate		int									NOT NULL,

	
	FOREIGN KEY		(IdProdus)		REFERENCES Produse(IdProdus),
	FOREIGN KEY		(IdFactura)		REFERENCES Facturi(IdFactura),

	PRIMARY KEY(IdProdus, IdFactura),
);
GO

PRINT 'Tabel ProduseFacturi was created';






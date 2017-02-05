----------------- MLENDEA HORATIU
----------------- GRUPA 224
----------------- SUBIECTUL 1
----------------- PUNCTUL 1
----------------- 18/01/2016

USE MASTER
IF EXISTS(SELECT * FROM sys.databases WHERE name='examenMH')
	DROP DATABASE examenMH

CREATE DATABASE examenMH
GO
USE examenMH

CREATE TABLE Clients(
	ClientID	INT				PRIMARY KEY,
	Name		NVARCHAR(50)	NULL,
	FiscalCode	NVARCHAR(50)	NULL);
GO
PRINT 'Table "Clients" created'

CREATE TABLE Agents(
	AgentID		INT				PRIMARY KEY IDENTITY NOT NULL,
	First_Name	NVARCHAR(50)	NULL,
	Second_Name	NVARCHAR(50)	NULL);
GO
PRINT 'Table "Agents" created'

CREATE TABLE Products(
	ProductID	INT				PRIMARY KEY IDENTITY NOT NULL,
	Name		NVARCHAR(50)	NULL,
	MesUnit		NVARCHAR(50)	NULL);
GO
PRINT 'Table "Products" created'

CREATE TABLE Bills(
	BillID		INT				PRIMARY KEY IDENTITY NOT NULL,
	Number		INT				NOT NULL,
	ClientID	INT				NOT NULL,
	AgentID		INT				NOT NULL,
	Date		DATETIME		NOT NULL);
GO
PRINT 'Table "Bills" created'

CREATE TABLE BillProducts(
	BillID		INT				NOT NULL,
	ProductID	INT				NOT NULL,
	Number		INT				NOT NULL,
	Price		BIGINT			NOT NULL,
	Quantity	BIGINT			NOT NULL);
GO
PRINT 'Table "BillProducts" created'

--ALTER TABLE Products
--ADD CONSTRAINT PKConstrProducts
--PRIMARY KEY(ProductID,Name)
--PRINT 'PKConstraint "PKConstrProducts" added to table "Products"'

ALTER TABLE BillProducts
ADD CONSTRAINT PKConstrBillProducts
PRIMARY KEY(BillID,ProductID,Number)
PRINT 'PKConstraint "PKConstrBillProducts" added to table "BillProducts"'

ALTER TABLE Bills
ADD CONSTRAINT FKConstrBillClient
FOREIGN KEY (ClientID)
REFERENCES Clients(ClientID)
PRINT 'FKConstraint "FKConstrBillClient" added to table "Bills"'

ALTER TABLE Bills
ADD CONSTRAINT FKConstrBillAgent
FOREIGN KEY (AgentID)
REFERENCES Agents(AgentID)
PRINT 'FKConstraint "FKConstrBillAgent" added to table "Bills"'

ALTER TABLE BillProducts
ADD CONSTRAINT FKConstrBillProductsBill
FOREIGN KEY (BillID)
REFERENCES Bills(BillID)
PRINT 'FKConstraint "FKConstrBillProductsBill" added to table "BillProducts"'

ALTER TABLE BillProducts
ADD CONSTRAINT FKConstrBillProductsProduct
FOREIGN KEY (ProductID)
REFERENCES Products(ProductID)
PRINT 'FKConstraint "FKConstrBillClient" added to table "BillProducts"'


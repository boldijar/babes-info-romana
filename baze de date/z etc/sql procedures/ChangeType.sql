USE [OnlineLottery]
GO
/****** Object:  StoredProcedure [dbo].[ChangeType]    Script Date: 03.11.2015 12:44:27 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

ALTER PROCEDURE [dbo].[ChangeType]
AS
IF EXISTS(	SELECT * FROM sys.tables
			WHERE name = 'Clients')
	IF EXISTS(	SELECT * FROM sys.columns
				WHERE name = 'Adress' AND OBJECT_ID = OBJECT_ID('Clients'))
		BEGIN
			ALTER TABLE Clients
			ALTER COLUMN Adress char(50)

			PRINT 'Column "Adress" changed type to "char(50)" in table "Clients"!'
		END
	ELSE
		PRINT 'Column "Adress" does not exist in table "Clients"!'
ELSE
	PRINT 'Table "Clients" does not exist!'
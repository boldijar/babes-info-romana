USE [OnlineLottery]
GO
/****** Object:  StoredProcedure [dbo].[CreateColumn]    Script Date: 03.11.2015 12:48:26 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

ALTER PROCEDURE [dbo].[CreateColumn]
AS
IF EXISTS(	SELECT * FROM sys.tables
			WHERE name = 'Clients')
	IF NOT EXISTS(	SELECT * FROM sys.columns
					WHERE name = 'NewlyCreatedColumn' AND OBJECT_ID = OBJECT_ID('Clients'))
		BEGIN
			-- DECLARE @version int = 6

			ALTER TABLE Clients
			ADD NewlyCreatedColumn int

			PRINT 'Column "NewlyCreatedColumn" created in table "Clients"!'

			-- UPDATE dbo.Version SET VersionNumber=@version
		END
	ELSE
		PRINT 'Column "NewlyCreatedColumn" already exists in table "Clients"!'
ELSE
	PRINT 'Table "Clients" does not exist!'
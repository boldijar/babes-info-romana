USE [OnlineLottery]
GO
/****** Object:  StoredProcedure [dbo].[DeleteColumn]    Script Date: 03.11.2015 12:49:45 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

ALTER PROCEDURE [dbo].[DeleteColumn]
AS
IF EXISTS(	SELECT * FROM sys.tables
			WHERE name = 'Clients')
	IF EXISTS(	SELECT * FROM sys.columns
				WHERE name = 'NewlyCreatedColumn' AND OBJECT_ID = OBJECT_ID('Clients'))
		BEGIN
			-- DECLARE @version int = 6

			ALTER TABLE Clients
			DROP COLUMN NewlyCreatedColumn

			PRINT 'Column "NewlyCreatedColumn" deleted from table "Clients"!'

			-- UPDATE dbo.Version SET VersionNumber=@version
		END
	ELSE
		PRINT 'Column "NewlyCreatedColumn" does not exist in table "Clients"!'
ELSE
	PRINT 'Table "Clients" does not exist!'
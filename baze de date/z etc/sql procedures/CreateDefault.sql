USE [OnlineLottery]
GO
/****** Object:  StoredProcedure [dbo].[CreateDefault]    Script Date: 03.11.2015 12:48:52 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

ALTER PROCEDURE [dbo].[CreateDefault]
AS

IF EXISTS(	SELECT * FROM sys.tables
			WHERE name = 'Clients')
	IF NOT EXISTS(	SELECT * FROM sys.default_constraints
					WHERE name = 'constr')
		BEGIN
			-- DECLARE @version int = 3

			ALTER TABLE Clients
			ADD CONSTRAINT constr DEFAULT 'DEFAULTNAME' FOR Name

			PRINT 'Constraint "constr" added to table "Clients"!'

			-- UPDATE dbo.Version SET VersionNumber=@version
		END
	ELSE
		PRINT 'Constraint "constr" already exists in table "Clients"!'
ELSE
	PRINT 'Table "Clients" does not exist!'
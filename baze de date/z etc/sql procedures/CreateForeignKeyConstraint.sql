USE [OnlineLottery]
GO
/****** Object:  StoredProcedure [dbo].[CreateForeignKeyConstraint]    Script Date: 03.11.2015 12:49:06 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

ALTER PROCEDURE [dbo].[CreateForeignKeyConstraint]
AS

IF EXISTS(	SELECT * FROM sys.tables
			WHERE name = 'PhoneNumbers')
	IF NOT EXISTS(	SELECT * FROM sys.foreign_keys
					WHERE name = 'ContClient')
		BEGIN
			-- DECLARE @version int = 7

			ALTER TABLE PhoneNumbers
			ADD CONSTRAINT ContClient
			FOREIGN KEY (ClientID)
			REFERENCES Clients(ID)

			PRINT 'FKConstraint "constr" added to table "PhoneNumbers"!'
	
			-- UPDATE dbo.Version SET VersionNumber=@version
		END
	ELSE
		PRINT 'Constraint "ContClient" already exists in table "PhoneNumbers"!'
ELSE
	PRINT 'Table "PhoneNumbers" does not exist!'
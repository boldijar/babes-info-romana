USE [OnlineLottery]
GO
/****** Object:  StoredProcedure [dbo].[DeleteForeignKeyConstraint]    Script Date: 03.11.2015 12:50:19 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

ALTER PROCEDURE [dbo].[DeleteForeignKeyConstraint]
AS

IF EXISTS(	SELECT * FROM sys.tables
			WHERE name = 'PhoneNumbers')
	IF EXISTS(	SELECT * FROM sys.foreign_keys
				WHERE name = 'ContClient')
		BEGIN
			-- DECLARE @version int = 7

			ALTER TABLE PhoneNumbers
			DROP CONSTRAINT ContClient

			PRINT 'FKConstraint "ContClient" deleted from table "PhoneNumbers"!'
	
			-- UPDATE dbo.Version SET VersionNumber=@version
		END
	ELSE
		PRINT 'Constraint "ContClient" does not exist in table "PhoneNumbers"!'
ELSE
	PRINT 'Table "PhoneNumbers" does not exist!'
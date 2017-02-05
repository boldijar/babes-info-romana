USE [OnlineLottery]
GO
/****** Object:  StoredProcedure [dbo].[DeleteDefault]    Script Date: 03.11.2015 12:50:05 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER PROCEDURE [dbo].[DeleteDefault]
AS
IF EXISTS(	SELECT * FROM sys.tables
			WHERE name = 'Clients')
	IF EXISTS(	SELECT * FROM sys.default_constraints
				WHERE name = 'constr')
		BEGIN
			-- DECLARE @version int = 3

			ALTER TABLE Clients
			DROP CONSTRAINT constr

			PRINT 'Constraint "constr" deleted from table "Clients"!'

			-- UPDATE dbo.Version SET VersionNumber=@version
		END
	ELSE
		PRINT 'Constraint "constr" does not exist in table "Clients"!'
ELSE
	PRINT 'Table "Clients" does not exist!'
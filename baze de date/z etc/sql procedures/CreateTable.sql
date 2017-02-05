USE [OnlineLottery]
GO
/****** Object:  StoredProcedure [dbo].[CreateTable]    Script Date: 03.11.2015 12:49:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

ALTER PROCEDURE [dbo].[CreateTable]
AS
IF NOT EXISTS(	SELECT * FROM sys.tables
				WHERE name = 'NewlyCreatedTable')
	BEGIN
		-- DECLARE @version int = 4

		CREATE TABLE NewlyCreatedTable
		(
			column1 char(50),
			column2 char(50),
			column3 int
		)

		PRINT 'Table "NewlyCreatedTable" created!'

		-- UPDATE dbo.Version SET VersionNumber=@version
	END
ELSE
	PRINT 'Table "NewlyCreatedTable" already exists!'
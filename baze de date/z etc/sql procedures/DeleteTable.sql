USE [OnlineLottery]
GO
/****** Object:  StoredProcedure [dbo].[DeleteTable]    Script Date: 03.11.2015 12:50:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

ALTER PROCEDURE [dbo].[DeleteTable]
AS

IF EXISTS(	SELECT * FROM sys.tables
			WHERE name = 'NewlyCreatedTable')
	BEGIN
		-- DECLARE @version int = 5

		DROP TABLE NewlyCreatedTable

		PRINT 'Table "NewlyCreatedTable" deleted!'

		-- UPDATE dbo.Version SET VersionNumber=@version
	END
ELSE
	PRINT 'Table "NewlyCreatedTable" does not exist!'
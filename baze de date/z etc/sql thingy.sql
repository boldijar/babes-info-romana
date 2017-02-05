USE [OnlineLottery]
GO
/****** Object:  StoredProcedure [dbo].[AddDefault]    Script Date: 14.10.2015 06:52:13 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
ALTER PROCEDURE [dbo].[AddDefault]
AS
BEGIN
	IF EXISTS (SELECT * FROM sys.default_constraints
		WHERE Name='ccc')
		PRINT 'Constrangerea exista'
	ELSE
	BEGIN
		ALTER TABLE Clients
		ADD CONSTRAINT ccc DEFAULT 'Popescu' FOR Name
		PRINT 'Constrangerea creata'	
	END

END

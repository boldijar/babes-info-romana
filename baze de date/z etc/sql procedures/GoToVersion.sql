USE [OnlineLottery]
GO
/****** Object:  StoredProcedure [dbo].[GoToVersion]    Script Date: 03.11.2015 12:50:48 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

ALTER PROCEDURE [dbo].[GoToVersion]
	@newversion int
AS
IF EXISTS(	SELECT * FROM sys.tables
			WHERE name = 'Version')
	IF EXISTS(	SELECT * FROM sys.columns
				WHERE name = 'VersionNumber' AND OBJECT_ID = OBJECT_ID('Version'))
		BEGIN
			DECLARE @curversion int
			SET @curversion = (SELECT VersionNumber FROM Version)
			
			PRINT 'Current version: ' +  CAST(@curversion AS nvarchar(2))
			PRINT 'New version:     ' +  CAST(@newversion AS nvarchar(2))
			
			IF @curversion < @newversion
			BEGIN
				PRINT 'Going forward from version ' + CAST(@curversion AS nvarchar(2)) + ' to version ' + CAST(@newversion AS nvarchar(2))
				WHILE @curversion <> @newversion
				BEGIN
					IF @curversion = 1
						EXEC ChangeType
					ELSE IF @curversion = 2
						EXEC CreateDefault
					ELSE IF @curversion = 3
						EXEC CreateTable
					ELSE IF @curversion = 4
						EXEC CreateColumn
					ElSE IF @curversion = 5
						EXEC CreateForeignKeyConstraint

					SET @curversion = @curversion + 1
				END
			END
			ELSE IF @curversion > @newversion
			BEGIN
				PRINT 'Going backwards from version ' + CAST(@curversion AS nvarchar(2)) + ' to version ' + CAST(@newversion AS nvarchar(2))
				WHILE @curversion <> @newversion
				BEGIN
					IF @curversion = 2
						EXEC ChangeTypeBack
					ELSE IF @curversion = 3
						EXEC DeleteDefault
					ELSE IF @curversion = 4
						EXEC DeleteTable
					ELSE IF @curversion = 5
						EXEC DeleteColumn
					ElSE IF @curversion = 6
						EXEC DeleteForeignKeyConstraint

					SET @curversion = @curversion - 1
				END
			END
			ELSE
				PRINT 'The database is already at version ' + CAST(@newversion AS nvarchar(2))

			UPDATE dbo.Version SET VersionNumber=@newversion
		END
	ELSE
		PRINT 'Column "VersionNumber" does not exist in table "Version"!'
ELSE
	PRINT 'Table "Version" does not exist!'
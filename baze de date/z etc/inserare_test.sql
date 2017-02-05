alter procedure inserare_test (@position int, @nr_of_rows int)
as
begin
	declare @cnt int = 0
	declare @start_at datetime
	declare @end_at datetime
	--select COLUMN_NAME from INFORMATION_SCHEMA.COLUMNS 
	--where TABLE_NAME = @nume_tabela

	--WITH OrderedOrders AS
	--(
	--	SELECT SalesOrderID, OrderDate,
	--	ROW_NUMBER() OVER (ORDER BY OrderDate) AS RowNumber
	--	FROM Sales.SalesOrderHeader 
	--) 
	--SELECT SalesOrderID, OrderDate, RowNumber  
	--FROM OrderedOrders 
	--WHERE RowNumber BETWEEN 50 AND 60;

	set @start_at = SYSDATETIME()
	--print @start_at
	
	while @cnt < 50
		begin
			insert into dbo.Formatii values ('Andra', 'pop')
			insert into dbo.Formatii values ('2AM', 'k-pop')
			insert into dbo.Formatii values ('Fuego', 'muzica populara')
			insert into dbo.Formatii values ('Stefan Banica', 'rock')
			insert into dbo.Formatii values ('Holograf', 'rock')
			insert into dbo.Formatii values ('LaLa Band', 'pop')
			insert into dbo.Formatii values ('Voltaj', 'pop')
			insert into dbo.Formatii values ('O-Zone', 'pop')

			set @cnt = @cnt + 1
		end
	set @end_at = SYSDATETIME()

	declare @test_run_id int
	set @test_run_id = (select max(T.TestRunID) from TestRuns as T)

	declare @table_id int
	set @table_id = (select Tests.TestID from Tests where Tests.Name = 'Formatii')
	
	--if @id_max IS Null 
	--	set @id_max = 1
	--else
	--	set @id_max = @id_max + 1

	--declare @id_tabela int
	--set @id_tabela = (select)
	insert into dbo.TestRuns values ('test1', @start_at, @end_at)
	insert into dbo.TestRunTables values (@test_run_id, @table_id, @start_at, @end_at)

end

exec inserare_test 2, 14



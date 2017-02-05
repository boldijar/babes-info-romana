CREATE FUNCTION Grade_Avg (@group_id int)
RETURNS @ResultSet TABLE
	(
		Name nchar(20)
		, [Final Grade] float
	)
AS

BEGIN
	INSERT INTO @ResultSet
		SELECT s.name AS Name,  AVG(CAST(ISNULL(st.grade,0) AS FLOAT)) AS [Final Grade]
		FROM StudentTasks st, Students s, Tasks t
		WHERE st.student_id = s.id AND st.task_id = t.id
		GROUP BY s.group_id, s.name
		HAVING group_id = @group_id
	RETURN
END

-- SELECT * FROM Grade_Avg (2)
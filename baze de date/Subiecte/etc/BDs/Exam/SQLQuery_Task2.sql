CREATE PROCEDURE StudentTasks_InsertGrade
	@student_id int
	, @task_id int
	, @grade int
	, @status_id int

AS
BEGIN
	DECLARE @duplicate int
	SET @duplicate = 0

	SELECT @duplicate = COUNT(*)
	FROM StudentTasks
	WHERE @student_id = student_id AND @task_id = task_id

	IF @duplicate = 0
		INSERT INTO StudentTasks
		VALUES (@student_id, @task_id, @grade)
	ELSE
		UPDATE StudentTasks
		SET grade = @grade
		WHERE student_id = @student_id AND task_id = @task_id
			
	INSERT INTO CommentsGrades
	VALUES (@student_id, @task_id, @status_id)

END

-- exec StudentTasks_InsertGrade @student_id = 5, @task_id = 1, @grade = 10, @status_id = 2
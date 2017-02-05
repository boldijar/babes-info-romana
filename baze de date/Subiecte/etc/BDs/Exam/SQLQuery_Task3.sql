CREATE VIEW Students_StatusOpened
AS
	SELECT DISTINCT Students.id, Students.name 
	FROM Students 
	JOIN CommentsGrades
		ON Students.id = CommentsGrades.student_id
	JOIN Comments
		ON CommentsGrades.status_id = Comments.id
	WHERE Comments.status = 'opened'

-- SELECT * FROM Students_StatusOpened

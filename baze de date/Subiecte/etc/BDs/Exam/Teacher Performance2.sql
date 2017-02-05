create procedure addGrade(
	@questionID int,
	@studentID int,
	@teacherID int,
	@value int
	)
as
begin
	declare @duplicates int
	set @duplicates = 0
	
	select @duplicates = COUNT(*) from TeacherQuestionValue where @questionID = QuestionID and @studentID = StudentID and @teacherID = TeacherID
	
	if @duplicates = 0
		insert into TeacherQuestionValue values (@studentID, @teacherID, @questionID, @value)
	else
		update TeacherQuestionValue
		set value = @value where StudentID = @studentID and TeacherID = @teacherID and QuestionID = @questionID
end


exec addGrade @questionID = 1, @studentID = 2, @teacherID = 2, @value = 3
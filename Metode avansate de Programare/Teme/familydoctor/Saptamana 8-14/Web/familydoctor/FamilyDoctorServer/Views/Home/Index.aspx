<%@ Page Language="C#" Inherits="System.Web.Mvc.ViewPage" %>
<!DOCTYPE html>
<html>
	<head runat="server">
		<title>FDM</title>
	</head>
	<body>
		<div id="div-add-patient">
			<b>Add a patient</b>
			<form method="post" action="/manager">
				<input name="command" type="hidden" value="addpatient">
				ID: <input name="id" type="text"><br>
				Name: <input name="name" type="text"><br>
				Age: <input name="age" type="text"><br>
				<input type="submit">
			</form>
		</div>
		<br><br>
		<div id="div-add-appointment">
			<b>Add an appointment</b>
			<form method="post" action="/manager">
				<input name="command" type="hidden" value="addappointment">
				ID: <input name="id" type="text"><br>
				Patient ID: <input name="patientid" type="text"><br>
				Diagnostic: <input name="diagnostic" type="text"><br>
				Date: <input name="date" type="text"><br>
				Emergency: <input name="isemergency" type="text"><br>
				<input type="submit">
			</form>
		</div>
		<br><br>
		<div id="div-list-patients">
			<b>List patients</b>
			<form method="post" action="/manager">
				<input name="command" type="hidden" value="listpatients">
				Criteria: <input name="criteria" type="text"><br>
				Value: <input name="value" type="text"><br>
				<input type="submit">
			</form>
		</div>
		<br><br>
		<div id="div-list-appointments">
			<b>List appointments</b>
			<form method="post" action="/manager">
				<input name="command" type="hidden" value="listappointments">
				Criteria: <input name="criteria" type="text"><br>
				Value: <input name="value" type="text"><br>
				<input type="submit">
			</form>
		</div>
	</body>
</html>
